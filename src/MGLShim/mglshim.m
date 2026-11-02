/*
 * mglshim.m  —  VostroXe
 *
 * Desvia o OpenGL de apps nativos do Mac (NSOpenGLContext / NSOpenGLView) para o MGL (OpenGL 4.6 -> Metal
 * na Iris Xe), SEM recompilar o app. Carregado com DYLD_INSERT_LIBRARIES.
 *
 * Duas metades:
 *  1) CICLO DE VIDA do contexto — method swizzling em NSOpenGLContext (aqui neste arquivo):
 *       initWithFormat:shareContext:  -> cria (ou reaproveita, se shareContext) um GLMContext do MGL
 *       setView:                      -> amarra o CAMetalLayer do MGL na NSView do app
 *       makeCurrentContext            -> MGLsetCurrentContext
 *       flushBuffer                   -> MGLswapBuffers
 *     e tira NSOpenGLPFAAccelerated do pixel format (o formato acelerado da Apple falha nesta GPU, issue #21).
 *  2) CHAMADAS gl* — DYLD interposing (em mgl_gl_interpose.c, gerado por gen-interpose.py): todas as gl* que o
 *     MGL implementa são redirecionadas para a implementação do MGL. mglshim_gl_init() resolve os ponteiros.
 *
 * Contextos compartilhados (shareContext != nil, como o OBS usa) mapeiam para o MESMO GLMContext — o MGL já
 * trabalha com um contexto corrente global, então isso casa com a intenção de compartilhar texturas/buffers.
 *
 * Não linka a libmgl: abre com dlopen (MGLSHIM_LIB ou "libmgl.dylib"). MRC (sem ARC) de propósito.
 */

#define GL_SILENCE_DEPRECATION 1
#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/Metal.h>
#import <OpenGL/gl3.h>        /* tipos GL + GL_BGRA etc. para createGLMContext (TU separada do interpose) */
#import <objc/runtime.h>
#import <objc/message.h>
#include "MGLContext.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef GL_BGRA
#define GL_BGRA 0x80E1
#endif
#ifndef GL_UNSIGNED_INT_8_8_8_8_REV
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#endif

/* definidos em mgl_gl_interpose.c (gerado) */
extern int mglshim_active;                 /* 1 = desvia gl* para o MGL; 0 = repassa para a Apple (RTLD_NEXT) */
extern int mglshim_gl_init(void *mgl);     /* resolve os ponteiros; devolve quantas gl* o MGL tem */

static void mglshim_log(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    fprintf(stderr, "MGLSHIM: "); vfprintf(stderr, fmt, ap); fprintf(stderr, "\n"); va_end(ap);
}

static void *gMGL;
static GLMContext (*p_createGLMContext)(GLenum,GLenum,GLenum,GLenum,GLenum,GLenum);
static void       (*p_MGLsetCurrentContext)(GLMContext);
static void       (*p_MGLswapBuffers)(GLMContext);

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
    if (me) {
        GLMContext ctx = NULL;
        if (share) {                                   /* compartilha com outro contexto -> mesmo GLMContext */
            NSValue *sv = objc_getAssociatedObject(share, kCtxKey);
            if (sv) { ctx = (GLMContext)[sv pointerValue]; mglshim_log("NSOpenGLContext compartilha o GLMContext %p", (void*)ctx); }
        }
        if (!ctx && p_createGLMContext) {
            ctx = p_createGLMContext(GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, GL_DEPTH_COMPONENT, GL_FLOAT, 0, 0);
            mglshim_log("NSOpenGLContext criado -> GLMContext %p", (void *)ctx);
        }
        if (ctx) objc_setAssociatedObject(me, kCtxKey, [NSValue valueWithPointer:ctx], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
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
    if (ctx && p_MGLsetCurrentContext) { mglshim_active = 1; p_MGLsetCurrentContext(ctx); }
    else { mglshim_active = 0; [self mgl_makeCurrentContext]; }   /* contexto não-MGL: as gl* voltam para a Apple */
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

static void swizzle(Class c, SEL a, SEL b){
    if (!c) return;
    Method m1 = class_getInstanceMethod(c, a), m2 = class_getInstanceMethod(c, b);
    if (m1 && m2) method_exchangeImplementations(m1, m2);
    else mglshim_log("AVISO: não achei método para trocar (%s)", sel_getName(a));
}

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

    /* a_* (fallback para a Apple quando o contexto MGL não está corrente) é resolvido via RTLD_NEXT dentro do
       gerado — não precisa abrir a libGL aqui. */
    int n = mglshim_gl_init(gMGL);
    mglshim_log("gl* resolvidas na libmgl: %d", n);

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
