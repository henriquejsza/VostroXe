/*
 * mglshim.m  —  VostroXe
 *
 * Desvia o caminho de OpenGL dos apps nativos do Mac (NSOpenGLContext / NSOpenGLView) para o MGL
 * (OpenGL 4.6 -> Metal na Iris Xe), SEM recompilar o app. É carregado com DYLD_INSERT_LIBRARIES.
 *
 * Como funciona:
 *   - Reexporta a libmgl.dylib (-reexport_library), então, com namespace plano (DYLD_FORCE_FLAT_NAMESPACE=1),
 *     as funções gl* que o app chama passam a vir do MGL em vez do OpenGL.framework da Apple.
 *   - Faz method swizzling em NSOpenGLContext para que o ciclo de vida do contexto vá para o MGL:
 *       initWithFormat:shareContext:  -> cria um GLMContext do MGL e o guarda no objeto
 *       setView:                      -> amarra o CAMetalLayer do MGL na NSView do app (como sublayer)
 *       makeCurrentContext            -> MGLsetCurrentContext
 *       flushBuffer                   -> MGLswapBuffers
 *   - Tira NSOpenGLPFAAccelerated do pixel format pedido: nesta GPU o formato acelerado da Apple falha
 *     (issue #21), então o pedido ainda precisa ser aceito (o MGL é quem acelera, via Metal).
 *
 * Primeira versão do shim: a prova é a sonda NSOpenGLView (tools/mgl-shim.sh), que deve passar de
 * "Apple Software Renderer" para "MGL". Apps reais vêm depois (podem faltar funções/forma de shader no MGL).
 */

#define GL_SILENCE_DEPRECATION 1
#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/Metal.h>
#import <OpenGL/gl3.h>
#import <objc/runtime.h>
#include "MGLContext.h"
#include "MGLRenderer.h"
#include <stdio.h>
#include <stdarg.h>

static const void *kMGLCtxKey  = &kMGLCtxKey;   // GLMContext guardado em cada NSOpenGLContext
static const void *kMGLRendKey = &kMGLRendKey;  // MGLRenderer (mantém o layer vivo)

static void mglshim_log(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    fprintf(stderr, "MGLSHIM: "); vfprintf(stderr, fmt, ap); fprintf(stderr, "\n");
    va_end(ap);
}

#pragma mark - NSOpenGLPixelFormat: aceitar o pedido (sem exigir aceleração da Apple)

@interface NSOpenGLPixelFormat (MGLShim) @end
@implementation NSOpenGLPixelFormat (MGLShim)

- (instancetype)mgl_initWithAttributes:(const NSOpenGLPixelFormatAttribute *)attribs
{
    // Copia os atributos tirando NSOpenGLPFAAccelerated (nesta GPU ele faz o pixel format falhar).
    NSOpenGLPixelFormatAttribute copy[64]; int n = 0;
    if (attribs) {
        for (int i = 0; attribs[i] != 0 && n < 62; i++) {
            if (attribs[i] == NSOpenGLPFAAccelerated) continue;          // bool: um token só
            copy[n++] = attribs[i];
        }
    }
    copy[n] = 0;
    id me = [self mgl_initWithAttributes:copy];                          // chama o original (trocado)
    if (!me) me = [self mgl_initWithAttributes:attribs];                 // se falhar, tenta o pedido original
    return me;
}

@end

#pragma mark - NSOpenGLContext: ciclo de vida -> MGL

@interface NSOpenGLContext (MGLShim) @end
@implementation NSOpenGLContext (MGLShim)

- (instancetype)mgl_initWithFormat:(NSOpenGLPixelFormat *)format shareContext:(NSOpenGLContext *)share
{
    id me = [self mgl_initWithFormat:format shareContext:share];         // original (cria o ctx da Apple, não usado)
    if (me) {
        GLMContext ctx = createGLMContext(GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV,
                                          GL_DEPTH_COMPONENT, GL_FLOAT, 0, 0);
        objc_setAssociatedObject(me, kMGLCtxKey, [NSValue valueWithPointer:ctx], OBJC_ASSOCIATION_RETAIN);
        mglshim_log("NSOpenGLContext criado -> GLMContext %p", (void *)ctx);
    }
    return me;
}

- (void)mgl_setView:(NSView *)view
{
    [self mgl_setView:view];                                             // original
    NSValue *v = objc_getAssociatedObject(self, kMGLCtxKey);
    GLMContext ctx = v ? (GLMContext)[v pointerValue] : NULL;
    if (ctx && view && !objc_getAssociatedObject(self, kMGLRendKey)) {
        MGLRenderer *r = [[MGLRenderer alloc] init];
        [r createMGLRendererAndBindToContext:ctx view:view];             // amarra o CAMetalLayer do MGL na view
        objc_setAssociatedObject(self, kMGLRendKey, r, OBJC_ASSOCIATION_RETAIN);
        mglshim_log("setView -> MGL ligado na NSView %p (%.0fx%.0f)",
                    (__bridge void *)view, view.bounds.size.width, view.bounds.size.height);
    }
}

- (void)mgl_makeCurrentContext
{
    NSValue *v = objc_getAssociatedObject(self, kMGLCtxKey);
    if (v) { MGLsetCurrentContext((GLMContext)[v pointerValue]); }
    else   { [self mgl_makeCurrentContext]; }
}

- (void)mgl_flushBuffer
{
    NSValue *v = objc_getAssociatedObject(self, kMGLCtxKey);
    if (v) { MGLswapBuffers((GLMContext)[v pointerValue]); }
    else   { [self mgl_flushBuffer]; }
}

- (void)mgl_update
{
    // O MGL acompanha o tamanho pelo layer; nada a fazer aqui, mas mantém a chamada do app viva.
    NSValue *v = objc_getAssociatedObject(self, kMGLCtxKey);
    if (!v) [self mgl_update];
}

@end

#pragma mark - instalação

static void mglshim_swizzle(Class c, SEL orig, SEL repl)
{
    if (!c) return;
    Method m1 = class_getInstanceMethod(c, orig);
    Method m2 = class_getInstanceMethod(c, repl);
    if (m1 && m2) method_exchangeImplementations(m1, m2);
    else mglshim_log("AVISO: não achei método para trocar (%s)", sel_getName(orig));
}

__attribute__((constructor))
static void mglshim_install(void)
{
    @autoreleasepool {
        Class pf  = objc_getClass("NSOpenGLPixelFormat");
        Class ctx = objc_getClass("NSOpenGLContext");
        mglshim_swizzle(pf,  @selector(initWithAttributes:),            @selector(mgl_initWithAttributes:));
        mglshim_swizzle(ctx, @selector(initWithFormat:shareContext:),   @selector(mgl_initWithFormat:shareContext:));
        mglshim_swizzle(ctx, @selector(setView:),                       @selector(mgl_setView:));
        mglshim_swizzle(ctx, @selector(makeCurrentContext),             @selector(mgl_makeCurrentContext));
        mglshim_swizzle(ctx, @selector(flushBuffer),                    @selector(mgl_flushBuffer));
        mglshim_swizzle(ctx, @selector(update),                         @selector(mgl_update));
        mglshim_log("instalado: NSOpenGLContext/NSOpenGLPixelFormat desviados para o MGL");
    }
}
