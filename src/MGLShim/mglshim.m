/*
 * mglshim.m  —  VostroXe
 *
 * Desvia o OpenGL de apps nativos do Mac (NSOpenGLContext / NSOpenGLView) para o MGL (OpenGL 4.6 -> Metal
 * na Iris Xe), SEM recompilar o app. Carregado com DYLD_INSERT_LIBRARIES.
 *
 * Duas metades:
 *  1) CICLO DE VIDA do contexto — method swizzling em NSOpenGLContext:
 *       initWithFormat:shareContext:  -> cria um GLMContext do MGL e o guarda no objeto
 *       setView:                      -> amarra o CAMetalLayer do MGL na NSView do app (sublayer)
 *       makeCurrentContext            -> MGLsetCurrentContext (torna o contexto do MGL o corrente)
 *       flushBuffer                   -> MGLswapBuffers (apresenta na janela)
 *     e tira NSOpenGLPFAAccelerated do pixel format (o formato acelerado da Apple falha nesta GPU, issue #21).
 *  2) CHAMADAS gl* — DYLD interposing: cada glXxx que o app chama é redirecionada para a glXxx do MGL.
 *     (A 1a tentativa usava reexport + namespace plano; não pegou, porque o binário é two-level namespace.
 *      Interpose funciona com two-level namespace.)
 *
 * Não linka a libmgl: abre com dlopen (MGLSHIM_LIB ou "libmgl.dylib") e resolve os símbolos. Assim o símbolo
 * glXxx deste arquivo é o da Apple (o "original" do interpose, de -framework OpenGL), sem ambiguidade.
 *
 * MRC (sem ARC) de propósito: mensageria via objc_msgSend e associated objects ficam simples.
 */

#define GL_SILENCE_DEPRECATION 1
#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/Metal.h>
#import <OpenGL/gl3.h>        /* glXxx da Apple (os "originais" do interpose) + tipos GL */
#import <objc/runtime.h>
#import <objc/message.h>
#include "MGLContext.h"        /* GLMContext, createGLMContext, MGLsetCurrentContext, MGLswapBuffers */
#include <dlfcn.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef GL_BGRA
#define GL_BGRA 0x80E1
#endif
#ifndef GL_UNSIGNED_INT_8_8_8_8_REV
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#endif

static void mglshim_log(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    fprintf(stderr, "MGLSHIM: "); vfprintf(stderr, fmt, ap); fprintf(stderr, "\n"); va_end(ap);
}

/* ---------------- ponteiros para as funções do MGL (resolvidos via dlsym) ---------------- */
static void *gMGL;
static GLMContext (*p_createGLMContext)(GLenum,GLenum,GLenum,GLenum,GLenum,GLenum);
static void       (*p_MGLsetCurrentContext)(GLMContext);
static void       (*p_MGLswapBuffers)(GLMContext);

static const GLubyte* (*m_glGetString)(GLenum);
static GLenum (*m_glGetError)(void);
static void (*m_glClear)(GLbitfield);
static void (*m_glClearColor)(GLfloat,GLfloat,GLfloat,GLfloat);
static void (*m_glViewport)(GLint,GLint,GLsizei,GLsizei);
static void (*m_glDrawArrays)(GLenum,GLint,GLsizei);
static GLuint (*m_glCreateShader)(GLenum);
static void (*m_glShaderSource)(GLuint,GLsizei,const GLchar*const*,const GLint*);
static void (*m_glCompileShader)(GLuint);
static void (*m_glGetShaderiv)(GLuint,GLenum,GLint*);
static GLuint (*m_glCreateProgram)(void);
static void (*m_glAttachShader)(GLuint,GLuint);
static void (*m_glLinkProgram)(GLuint);
static void (*m_glGetProgramiv)(GLuint,GLenum,GLint*);
static void (*m_glUseProgram)(GLuint);
static void (*m_glGenVertexArrays)(GLsizei,GLuint*);
static void (*m_glBindVertexArray)(GLuint);
static void (*m_glGenBuffers)(GLsizei,GLuint*);
static void (*m_glBindBuffer)(GLenum,GLuint);
static void (*m_glBufferData)(GLenum,GLsizeiptr,const void*,GLenum);
static void (*m_glEnableVertexAttribArray)(GLuint);
static void (*m_glVertexAttribPointer)(GLuint,GLint,GLenum,GLboolean,GLsizei,const void*);

/* ---------------- wrappers (o que o interpose aponta no lugar da função da Apple) ---------------- */
static const GLubyte* w_glGetString(GLenum n){ return m_glGetString ? m_glGetString(n) : NULL; }
static GLenum w_glGetError(void){ return m_glGetError ? m_glGetError() : 0; }
static void w_glClear(GLbitfield m){ if(m_glClear) m_glClear(m); }
static void w_glClearColor(GLfloat r,GLfloat g,GLfloat b,GLfloat a){ if(m_glClearColor) m_glClearColor(r,g,b,a); }
static void w_glViewport(GLint x,GLint y,GLsizei w,GLsizei h){ if(m_glViewport) m_glViewport(x,y,w,h); }
static void w_glDrawArrays(GLenum mo,GLint f,GLsizei c){ if(m_glDrawArrays) m_glDrawArrays(mo,f,c); }
static GLuint w_glCreateShader(GLenum t){ return m_glCreateShader ? m_glCreateShader(t) : 0; }
static void w_glShaderSource(GLuint s,GLsizei c,const GLchar*const*v,const GLint*l){ if(m_glShaderSource) m_glShaderSource(s,c,v,l); }
static void w_glCompileShader(GLuint s){ if(m_glCompileShader) m_glCompileShader(s); }
static void w_glGetShaderiv(GLuint s,GLenum p,GLint*v){ if(m_glGetShaderiv) m_glGetShaderiv(s,p,v); }
static GLuint w_glCreateProgram(void){ return m_glCreateProgram ? m_glCreateProgram() : 0; }
static void w_glAttachShader(GLuint p,GLuint s){ if(m_glAttachShader) m_glAttachShader(p,s); }
static void w_glLinkProgram(GLuint p){ if(m_glLinkProgram) m_glLinkProgram(p); }
static void w_glGetProgramiv(GLuint p,GLenum n,GLint*v){ if(m_glGetProgramiv) m_glGetProgramiv(p,n,v); }
static void w_glUseProgram(GLuint p){ if(m_glUseProgram) m_glUseProgram(p); }
static void w_glGenVertexArrays(GLsizei n,GLuint*a){ if(m_glGenVertexArrays) m_glGenVertexArrays(n,a); }
static void w_glBindVertexArray(GLuint a){ if(m_glBindVertexArray) m_glBindVertexArray(a); }
static void w_glGenBuffers(GLsizei n,GLuint*b){ if(m_glGenBuffers) m_glGenBuffers(n,b); }
static void w_glBindBuffer(GLenum t,GLuint b){ if(m_glBindBuffer) m_glBindBuffer(t,b); }
static void w_glBufferData(GLenum t,GLsizeiptr s,const void*d,GLenum u){ if(m_glBufferData) m_glBufferData(t,s,d,u); }
static void w_glEnableVertexAttribArray(GLuint i){ if(m_glEnableVertexAttribArray) m_glEnableVertexAttribArray(i); }
static void w_glVertexAttribPointer(GLuint i,GLint sz,GLenum t,GLboolean n,GLsizei st,const void*p){ if(m_glVertexAttribPointer) m_glVertexAttribPointer(i,sz,t,n,st,p); }

/* ---------------- tabela de interpose ---------------- */
#define INTERP(fn) \
  __attribute__((used)) static const struct { const void *repl; const void *orig; } \
  _ip_##fn __attribute__((section("__DATA,__interpose"))) = { (const void*)&w_##fn, (const void*)&fn }
INTERP(glGetString); INTERP(glGetError); INTERP(glClear); INTERP(glClearColor); INTERP(glViewport);
INTERP(glDrawArrays); INTERP(glCreateShader); INTERP(glShaderSource); INTERP(glCompileShader);
INTERP(glGetShaderiv); INTERP(glCreateProgram); INTERP(glAttachShader); INTERP(glLinkProgram);
INTERP(glGetProgramiv); INTERP(glUseProgram); INTERP(glGenVertexArrays); INTERP(glBindVertexArray);
INTERP(glGenBuffers); INTERP(glBindBuffer); INTERP(glBufferData); INTERP(glEnableVertexAttribArray);
INTERP(glVertexAttribPointer);

/* ---------------- ciclo de vida: swizzle de NSOpenGLContext / NSOpenGLPixelFormat ---------------- */
static const void *kCtxKey  = &kCtxKey;
static const void *kRendKey = &kRendKey;

static GLMContext ctxOf(id self){
    NSValue *v = objc_getAssociatedObject(self, kCtxKey);
    return v ? (GLMContext)[v pointerValue] : NULL;
}

@interface NSOpenGLPixelFormat (MGLShim) @end
@implementation NSOpenGLPixelFormat (MGLShim)
- (instancetype)mgl_initWithAttributes:(const NSOpenGLPixelFormatAttribute *)attribs {
    NSOpenGLPixelFormatAttribute copy[64]; int n = 0;
    if (attribs) for (int i = 0; attribs[i] != 0 && n < 62; i++) {
        if (attribs[i] == NSOpenGLPFAAccelerated) continue;   /* bool: um token só */
        copy[n++] = attribs[i];
    }
    copy[n] = 0;
    id me = [self mgl_initWithAttributes:copy];
    if (!me) me = [self mgl_initWithAttributes:attribs];
    return me;
}
@end

@interface NSOpenGLContext (MGLShim) @end
@implementation NSOpenGLContext (MGLShim)

- (instancetype)mgl_initWithFormat:(NSOpenGLPixelFormat *)format shareContext:(NSOpenGLContext *)share {
    id me = [self mgl_initWithFormat:format shareContext:share];
    if (me && p_createGLMContext) {
        GLMContext ctx = p_createGLMContext(GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, GL_DEPTH_COMPONENT, GL_FLOAT, 0, 0);
        objc_setAssociatedObject(me, kCtxKey, [NSValue valueWithPointer:ctx], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        mglshim_log("NSOpenGLContext criado -> GLMContext %p", (void *)ctx);
    }
    return me;
}

- (void)mgl_setView:(NSView *)view {
    [self mgl_setView:view];
    GLMContext ctx = ctxOf(self);
    if (ctx && view && !objc_getAssociatedObject(self, kRendKey)) {
        Class rc = objc_getClass("MGLRenderer");
        if (rc) {
            id r = ((id(*)(id,SEL))objc_msgSend)((id)rc, sel_registerName("alloc"));
            r = ((id(*)(id,SEL))objc_msgSend)(r, sel_registerName("init"));
            ((void(*)(id,SEL,GLMContext,id))objc_msgSend)(r, sel_registerName("createMGLRendererAndBindToContext:view:"), ctx, view);
            objc_setAssociatedObject(self, kRendKey, r, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            mglshim_log("setView -> MGL ligado na NSView %p (%.0fx%.0f)",
                        (void *)view, view.bounds.size.width, view.bounds.size.height);
        } else {
            mglshim_log("ERRO: classe MGLRenderer não encontrada na libmgl");
        }
    }
}

- (void)mgl_makeCurrentContext {
    GLMContext ctx = ctxOf(self);
    if (ctx && p_MGLsetCurrentContext) p_MGLsetCurrentContext(ctx);
    else [self mgl_makeCurrentContext];
}

- (void)mgl_flushBuffer {
    GLMContext ctx = ctxOf(self);
    if (ctx && p_MGLswapBuffers) p_MGLswapBuffers(ctx);
    else [self mgl_flushBuffer];
}

- (void)mgl_update {
    if (!ctxOf(self)) [self mgl_update];
}

@end

/* ---------------- instalação ---------------- */
static void swizzle(Class c, SEL a, SEL b){
    if (!c) return;
    Method m1 = class_getInstanceMethod(c, a), m2 = class_getInstanceMethod(c, b);
    if (m1 && m2) method_exchangeImplementations(m1, m2);
    else mglshim_log("AVISO: não achei método para trocar (%s)", sel_getName(a));
}

#define LOAD(name) do { m_##name = dlsym(gMGL, #name); if(!m_##name) mglshim_log("faltou MGL %s", #name); } while(0)

__attribute__((constructor))
static void mglshim_install(void){
    const char *lib = getenv("MGLSHIM_LIB");
    gMGL = dlopen(lib && *lib ? lib : "libmgl.dylib", RTLD_NOW | RTLD_GLOBAL);
    if (!gMGL) { mglshim_log("ERRO: não consegui abrir a libmgl (%s): %s", lib?lib:"libmgl.dylib", dlerror()); return; }

    p_createGLMContext     = dlsym(gMGL, "createGLMContext");
    p_MGLsetCurrentContext = dlsym(gMGL, "MGLsetCurrentContext");
    p_MGLswapBuffers       = dlsym(gMGL, "MGLswapBuffers");
    if (!p_createGLMContext || !p_MGLsetCurrentContext || !p_MGLswapBuffers)
        mglshim_log("ERRO: faltou createGLMContext/MGLsetCurrentContext/MGLswapBuffers na libmgl");

    LOAD(glGetString); LOAD(glGetError); LOAD(glClear); LOAD(glClearColor); LOAD(glViewport);
    LOAD(glDrawArrays); LOAD(glCreateShader); LOAD(glShaderSource); LOAD(glCompileShader);
    LOAD(glGetShaderiv); LOAD(glCreateProgram); LOAD(glAttachShader); LOAD(glLinkProgram);
    LOAD(glGetProgramiv); LOAD(glUseProgram); LOAD(glGenVertexArrays); LOAD(glBindVertexArray);
    LOAD(glGenBuffers); LOAD(glBindBuffer); LOAD(glBufferData); LOAD(glEnableVertexAttribArray);
    LOAD(glVertexAttribPointer);

    @autoreleasepool {
        Class pf  = objc_getClass("NSOpenGLPixelFormat");
        Class ctx = objc_getClass("NSOpenGLContext");
        swizzle(pf,  @selector(initWithAttributes:),          @selector(mgl_initWithAttributes:));
        swizzle(ctx, @selector(initWithFormat:shareContext:), @selector(mgl_initWithFormat:shareContext:));
        swizzle(ctx, @selector(setView:),                     @selector(mgl_setView:));
        swizzle(ctx, @selector(makeCurrentContext),           @selector(mgl_makeCurrentContext));
        swizzle(ctx, @selector(flushBuffer),                  @selector(mgl_flushBuffer));
        swizzle(ctx, @selector(update),                       @selector(mgl_update));
    }
    mglshim_log("instalado: gl* via interpose + NSOpenGLContext desviado para o MGL");
}
