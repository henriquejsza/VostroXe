#!/bin/zsh
# Passo 5 (caminho dos apps nativos): uma janela Cocoa de verdade (NSApplication + NSWindow), SEM GLFW, desenha
# o triângulo RGB pela Iris Xe (MGL -> Metal). É o que um app nativo do Mac faz: cria a própria janela e amarra
# o MGL nela com CppCreateMGLRendererFromContextAndBindToWindow. Prova o alicerce para rotear apps quaisquer ao MGL.
# Liga só no libmgl.dylib (não precisa do libglfw.dylib). Precisa ter rodado o COMPILAR-MGL antes.
# Roda no macOS:  zsh /Volumes/MACINSTALL/mgl-cocoa.sh   (ou dois cliques no COCOA-MGL.command)
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-cocoa-log.txt}"
ERRLOG="${LOG:r}-mgl.txt"   # o que o próprio MGL escreve (muitas linhas por quadro), à parte
# MGL compilado pelo mgl-build.sh: src/MGL num checkout do VostroXe, ou ~/VostroXe-MGL (fonte vinda do pendrive)
if [[ -n ${MGL_DIR:-} ]]; then MGLDIR=$MGL_DIR
elif [[ -f $HERE/../src/MGL/Makefile ]]; then MGLDIR=${HERE:h}/src/MGL
else MGLDIR=$HOME/VostroXe-MGL; fi
{
  echo "== $(date '+%d/%m %H:%M')  janela Cocoa nativa (sem GLFW) pelo MGL"
  for f in build/libmgl.dylib MGL/include/MGLContext.h MGL/include/MGLRenderer.h; do
    [[ -f $MGLDIR/$f ]] || { echo "não achei $MGLDIR/$f — rode o COMPILAR-MGL primeiro."; exit 1; }
  done
  SRC="$(mktemp -t mglcocoa).m"; BIN="$(mktemp -t mglcocoa)"
  cat > "$SRC" <<'OBJC'
#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/Metal.h>
#define GL_GLEXT_PROTOTYPES 1
#include <GL/glcorearb.h>
#include "MGLContext.h"
#include "MGLRenderer.h"
#include <dlfcn.h>
#include <math.h>
#include <stdio.h>

/* De qual biblioteca vem uma função: libmgl.dylib (MGL) ou o OpenGL da Apple. */
static const char* origin(const void* p){ Dl_info i; return (p && dladdr(p, &i) && i.dli_fname) ? i.dli_fname : "(nao achei)"; }

static const char* VS =
"#version 460\n"
"layout(location=0) in vec3 position;\n"
"layout(location=1) in vec3 color;\n"
"layout(location=0) out vec3 vcolor;\n"
"void main(){ vcolor = color; gl_Position = vec4(position, 1.0); }\n";

static const char* FS =
"#version 460\n"
"layout(location=0) in vec3 vcolor;\n"
"layout(location=0) out vec4 frag_colour;\n"
"void main(){ frag_colour = vec4(vcolor, 1.0); }\n";

static GLuint mkshader(GLenum type, const char* src){
    GLuint s = glCreateShader(type); glShaderSource(s, 1, &src, NULL); glCompileShader(s);
    GLint ok = 0; glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    printf("shader %s: %s\n", type == GL_VERTEX_SHADER ? "vertex" : "fragment", ok ? "compilou" : "FALHOU");
    return s;
}

int main(void){
    setvbuf(stdout, NULL, _IOLBF, 0);   /* sai linha a linha, mesmo se cair */
    @autoreleasepool {
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

        /* Uma janela Cocoa comum, como a de qualquer app. Tamanho fixo 480x360. */
        NSRect frame = NSMakeRect(0, 0, 480, 360);
        NSWindow* win = [[NSWindow alloc] initWithContentRect:frame
                            styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
                              backing:NSBackingStoreBuffered defer:NO];
        [win setTitle:@"VostroXe: OpenGL na Iris Xe (Cocoa nativo, sem GLFW)"];
        [win center];
        [win setLevel:NSFloatingWindowLevel];   /* fica por cima do Terminal */

        /* Contexto do MGL e amarra o MGL nesta janela (ele troca a contentView pela dele, com CAMetalLayer). */
        GLMContext ctx = createGLMContext(GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, GL_DEPTH_COMPONENT, GL_FLOAT, 0, 0);
        if(!ctx){ printf("createGLMContext FALHOU\n"); return 2; }
        void* renderer = CppCreateMGLRendererFromContextAndBindToWindow(ctx, (__bridge void*)win);
        if(!renderer){ printf("CppCreateMGLRendererFromContextAndBindToWindow FALHOU\n"); return 3; }
        printf("amarrou o MGL na NSWindow: OK\n");
        MGLsetCurrentContext(ctx);

        [win makeKeyAndOrderFront:nil];
        [NSApp activateIgnoringOtherApps:YES];

        printf("GL_RENDERER : %s  |  GL_VERSION : %s\n", (const char*)glGetString(GL_RENDERER), (const char*)glGetString(GL_VERSION));
        printf("glDrawArrays ligado no programa vem de: %s\n", origin((const void*)&glDrawArrays));

        float verts[] = {          /* pos.xyz, cor.rgb (entrelacado, stride 24) */
             0.0f,  0.7f, 0.0f,   1.0f, 0.0f, 0.0f,   /* topo    = vermelho */
             0.7f, -0.7f, 0.0f,   0.0f, 1.0f, 0.0f,   /* direita = verde    */
            -0.7f, -0.7f, 0.0f,   0.0f, 0.0f, 1.0f    /* esquerda= azul     */
        };
        GLuint vbo = 0, vao = 0;
        glGenBuffers(1, &vbo); glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
        glGenVertexArrays(1, &vao); glBindVertexArray(vao);
        glEnableVertexAttribArray(0); glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
        glEnableVertexAttribArray(1); glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)(3*sizeof(float)));
        GLuint prog = glCreateProgram();
        glAttachShader(prog, mkshader(GL_VERTEX_SHADER, VS)); glAttachShader(prog, mkshader(GL_FRAGMENT_SHADER, FS));
        glLinkProgram(prog);
        GLint linked = 0; glGetProgramiv(prog, GL_LINK_STATUS, &linked);
        printf("programa: %s\n", linked ? "linkou" : "LINK FALHOU");
        glUseProgram(prog);
        printf("glGetError depois do setup = 0x%x\n", glGetError());

        /* ~6 s: fundo pulsando (azul escuro <-> azul) + triangulo RGB parado. Roda o loop de eventos do Cocoa. */
        double t0 = CACurrentMediaTime(), t = t0, worst = 0, last = t0;
        long frames = 0; GLenum firsterr = 0;
        while(t - t0 < 6.0){
            @autoreleasepool {
                NSEvent* e;
                while((e = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast]
                                                 inMode:NSDefaultRunLoopMode dequeue:YES]))
                    [NSApp sendEvent:e];
                NSRect b = win.contentView.bounds; CGFloat s = win.backingScaleFactor;
                int fw = (int)(b.size.width * s), fh = (int)(b.size.height * s);
                glViewport(0, 0, fw, fh);
                float k = 0.5f + 0.5f * sinf((float)(t - t0) * 3.0f);
                glClearColor(0.05f, 0.05f + 0.25f * k, 0.10f + 0.60f * k, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                glDrawArrays(GL_TRIANGLES, 0, 3);
                MGLswapBuffers(ctx);
                GLenum er = glGetError(); if(er && !firsterr) firsterr = er;
                frames++;
                t = CACurrentMediaTime(); if(t - last > worst) worst = t - last; last = t;
            }
        }
        double secs = t - t0;
        printf("quadros: %ld em %.1f s = %.0f por segundo (quadro mais lento: %.0f ms); primeiro glGetError != 0: 0x%x\n",
               frames, secs, secs > 0 ? frames / secs : 0, worst * 1000, firsterr);
        int ok = frames >= 30 && firsterr == 0 && linked;
        printf(ok ? ">>> COCOA: %ld quadros desenhados e apresentados sem erro de GL numa NSWindow nativa. Confira se viu o triangulo.\n"
                  : ">>> COCOA: abriu, mas %ld quadros e/ou erro de GL acima; me mande os logs.\n", frames);
    }
    return 0;
}
OBJC
  echo "== compilando contra $MGLDIR/build/libmgl.dylib (clang -ObjC, Command Line Tools):"
  clang -ObjC -fobjc-arc "$SRC" -o "$BIN" \
    -I"$MGLDIR/MGL/include" -I"$MGLDIR/MGL/include/GL" \
    "$MGLDIR/build/libmgl.dylib" \
    -framework Cocoa -framework QuartzCore -framework Metal \
    -Wl,-rpath,"$MGLDIR/build" 2>&1 | tail -25
  if [[ ! -x $BIN ]]; then echo "a compilacao FALHOU (ver acima)"; exit 1; fi
  echo "== rodando: uma janela abre por ~6 s (triangulo colorido, fundo pulsando). O log do MGL vai para ${ERRLOG:t}."
  DYLD_LIBRARY_PATH="$MGLDIR/build" DYLD_FALLBACK_LIBRARY_PATH="$MGLDIR/build" "$BIN" 2> "$ERRLOG"; rc=$?
  echo "== o programa terminou com codigo $rc (0 = normal; 134 = abortou num assert)"
  echo "== resumo do log do MGL (${ERRLOG:t}, $(wc -l < "$ERRLOG" | tr -d ' ') linhas):"
  # A libmgl cria um renderer headless ao carregar (construtor em glm_context.c), em todo programa, antes do main();
  # o contexto da janela cria um segundo renderer.
  nd=$(grep -c 'Metal device created' "$ERRLOG")
  echo "renderers do MGL criados (linhas 'Metal device created'): $nd  (1 = so o headless da carga da libmgl; 2 = tambem o da janela)"
  grep -m1 'Metal device created' "$ERRLOG" | sed -E 's/^.*MGL INFO: //'
  np=$(grep -c 'Presenting drawable with texture' "$ERRLOG")
  echo "quadros apresentados na tela (Presenting drawable): $np"
  grep -m1 'Presenting drawable with texture' "$ERRLOG" | sed -E 's/^.*MGL INFO: //'
  echo "mensagens de erro/aviso do MGL (contagem, sem a hora):"
  grep -E 'ERROR|CRITICAL|Assertion|EMERGENCY|WARNING|xception' "$ERRLOG" \
    | sed -E 's/^[0-9-]+ [0-9:.]+ [^ ]+ //; s/0x[0-9a-f]{6,}/0x…/g' | sort | uniq -c | sort -rn | head -15
  rm -f "$SRC" "$BIN"
} 2>&1 | tee "$LOG"
echo; echo "logs: $LOG  (+ ${ERRLOG:t})"
