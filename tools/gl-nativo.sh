#!/bin/zsh
# Marco 2a (linha de base): como um app nativo do Mac entra no OpenGL HOJE, SEM MGL. Abre um NSOpenGLView comum
# (NSOpenGLPixelFormat + NSOpenGLContext), liga só no OpenGL.framework da Apple e desenha um triângulo por ~4 s.
# Mostra o GL_RENDERER/GL_VERSION que o caminho padrão negocia nesta máquina (esperado: Apple Software Renderer),
# e qual versão/perfil de GL um app consegue. Isso define o shim (marco 2b) que vai desviar esse caminho ao MGL.
# NÃO usa o MGL. Roda no macOS:  zsh /Volumes/MACINSTALL/gl-nativo.sh   (ou dois cliques no NATIVO-GL.command)
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/gl-nativo-log.txt}"
{
  echo "== $(date '+%d/%m %H:%M')  OpenGL nativo da Apple num NSOpenGLView (linha de base, sem MGL)"
  [[ $(uname) == Darwin ]] || { echo "rode no macOS"; exit 1; }
  echo "macOS $(sw_vers -productVersion 2>/dev/null) ($(sw_vers -buildVersion 2>/dev/null)), arch $(uname -m)"
  SRC="$(mktemp -t glnativo).m"; BIN="$(mktemp -t glnativo)"
  cat > "$SRC" <<'OBJC'
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <OpenGL/OpenGL.h>
#include <math.h>
#include <stdio.h>

static const char* VS =
"#version 150\n"
"in vec3 position;\n"
"in vec3 color;\n"
"out vec3 vcolor;\n"
"void main(){ vcolor = color; gl_Position = vec4(position, 1.0); }\n";

static const char* FS =
"#version 150\n"
"in vec3 vcolor;\n"
"out vec4 frag_colour;\n"
"void main(){ frag_colour = vec4(vcolor, 1.0); }\n";

static GLuint mkshader(GLenum type, const char* src){
    GLuint s = glCreateShader(type); glShaderSource(s, 1, &src, NULL); glCompileShader(s);
    GLint ok = 0; glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    printf("shader %s: %s\n", type == GL_VERTEX_SHADER ? "vertex" : "fragment", ok ? "compilou" : "FALHOU");
    return s;
}

int main(void){
    setvbuf(stdout, NULL, _IOLBF, 0);
    @autoreleasepool {
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

        NSRect frame = NSMakeRect(0, 0, 480, 360);
        NSWindow* win = [[NSWindow alloc] initWithContentRect:frame
                            styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
                              backing:NSBackingStoreBuffered defer:NO];
        [win setTitle:@"VostroXe: OpenGL nativo da Apple (linha de base, sem MGL)"];
        [win center];
        [win setLevel:NSFloatingWindowLevel];
        NSView* view = [[NSView alloc] initWithFrame:frame];
        [win setContentView:view];
        [win makeKeyAndOrderFront:nil];
        [NSApp activateIgnoringOtherApps:YES];

        /* Pedimos 3.2 core SEM exigir aceleração: nesta GPU o formato acelerado falha (issue #21),
           então o normal é cair no renderizador por software da Apple. */
        NSOpenGLPixelFormatAttribute attrs[] = {
            NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
            NSOpenGLPFAColorSize, 24,
            NSOpenGLPFADoubleBuffer,
            0
        };
        NSOpenGLPixelFormat* pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
        if(!pf){ printf("NSOpenGLPixelFormat 3.2 core: NULO (sem formato)\n"); return 2; }
        printf("NSOpenGLPixelFormat 3.2 core: OK\n");
        NSOpenGLContext* glctx = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
        if(!glctx){ printf("NSOpenGLContext: NULO\n"); return 3; }
        [glctx setView:view];
        [glctx makeCurrentContext];
        printf("NSOpenGLContext criado e corrente: OK\n");

        printf("GL_VENDOR   : %s\n", (const char*)glGetString(GL_VENDOR));
        printf("GL_RENDERER : %s\n", (const char*)glGetString(GL_RENDERER));
        printf("GL_VERSION  : %s\n", (const char*)glGetString(GL_VERSION));
        printf("GLSL_VERSION: %s\n", (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));

        float verts[] = {
             0.0f,  0.7f, 0.0f,   1.0f, 0.0f, 0.0f,
             0.7f, -0.7f, 0.0f,   0.0f, 1.0f, 0.0f,
            -0.7f, -0.7f, 0.0f,   0.0f, 0.0f, 1.0f
        };
        GLuint vbo = 0, vao = 0;
        glGenVertexArrays(1, &vao); glBindVertexArray(vao);
        glGenBuffers(1, &vbo); glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
        GLuint prog = glCreateProgram();
        glAttachShader(prog, mkshader(GL_VERTEX_SHADER, VS));
        glAttachShader(prog, mkshader(GL_FRAGMENT_SHADER, FS));
        glBindAttribLocation(prog, 0, "position");
        glBindAttribLocation(prog, 1, "color");
        glBindFragDataLocation(prog, 0, "frag_colour");
        glLinkProgram(prog);
        GLint linked = 0; glGetProgramiv(prog, GL_LINK_STATUS, &linked);
        printf("programa: %s\n", linked ? "linkou" : "LINK FALHOU");
        glUseProgram(prog);
        glEnableVertexAttribArray(0); glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
        glEnableVertexAttribArray(1); glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)(3*sizeof(float)));
        printf("glGetError depois do setup = 0x%x\n", glGetError());

        double t0 = CACurrentMediaTime(), t = t0; long frames = 0; GLenum firsterr = 0;
        while(t - t0 < 4.0){
            @autoreleasepool {
                NSEvent* e;
                while((e = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast]
                                                 inMode:NSDefaultRunLoopMode dequeue:YES]))
                    [NSApp sendEvent:e];
                GLint fw = (GLint)(view.bounds.size.width * win.backingScaleFactor);
                GLint fh = (GLint)(view.bounds.size.height * win.backingScaleFactor);
                glViewport(0, 0, fw, fh);
                float k = 0.5f + 0.5f * sinf((float)(t - t0) * 3.0f);
                glClearColor(0.05f, 0.05f + 0.25f * k, 0.10f + 0.60f * k, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                glDrawArrays(GL_TRIANGLES, 0, 3);
                [glctx flushBuffer];
                GLenum er = glGetError(); if(er && !firsterr) firsterr = er;
                frames++;
                t = CACurrentMediaTime();
            }
        }
        double secs = t - t0;
        printf("quadros: %ld em %.1f s = %.0f por segundo; primeiro glGetError != 0: 0x%x\n",
               frames, secs, secs > 0 ? frames / secs : 0, firsterr);
        printf(">>> LINHA DE BASE: este e o OpenGL que um app nativo tem HOJE (renderizador acima). O shim (2b) vai desviar este caminho ao MGL.\n");
    }
    return 0;
}
OBJC
  echo "== compilando (clang -ObjC, so OpenGL da Apple, sem MGL):"
  clang -ObjC -fobjc-arc "$SRC" -o "$BIN" \
    -framework Cocoa -framework OpenGL -framework QuartzCore 2>&1 | tail -25
  if [[ ! -x $BIN ]]; then echo "a compilacao FALHOU (ver acima)"; exit 1; fi
  echo "== rodando: uma janela abre por ~4 s. OpenGL da Apple (provavelmente por software)."
  "$BIN"; rc=$?
  echo "== o programa terminou com codigo $rc"
} 2>&1 | tee "$LOG"
echo; echo "log: $LOG"
