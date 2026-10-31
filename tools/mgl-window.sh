#!/bin/zsh
# Passo 4: janela na tela. Abre uma janela pela GLFW do MGL (o caminho que apps como o PrismLauncher usam) e
# desenha por ~6 s o triângulo RGB com o fundo pulsando, na Iris Xe (MGL -> Metal). O programa usa só GLFW e
# OpenGL padrão, como um app; liga no libglfw.dylib e no libmgl.dylib do VostroXe.
# Precisa ter rodado o COMPILAR-MGL antes.
# Roda no macOS:  zsh /Volumes/MACINSTALL/mgl-window.sh   (ou dois cliques no JANELA-MGL.command)
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-window-log.txt}"
ERRLOG="${LOG:r}-mgl.txt"   # o que o próprio MGL escreve (muitas linhas por quadro), à parte
# MGL compilado pelo mgl-build.sh: src/MGL num checkout do VostroXe, ou ~/VostroXe-MGL (fonte vinda do pendrive)
if [[ -n ${MGL_DIR:-} ]]; then MGLDIR=$MGL_DIR
elif [[ -f $HERE/../src/MGL/Makefile ]]; then MGLDIR=${HERE:h}/src/MGL
else MGLDIR=$HOME/VostroXe-MGL; fi
{
  echo "== $(date '+%d/%m %H:%M')  janela OpenGL na tela (GLFW do MGL)"
  for f in build/libmgl.dylib build/libglfw.dylib external/glfw/include/GLFW/glfw3.h; do
    [[ -f $MGLDIR/$f ]] || { echo "não achei $MGLDIR/$f — rode o COMPILAR-MGL primeiro."; exit 1; }
  done
  SRC="$(mktemp -t mglwin).c"; BIN="$(mktemp -t mglwin)"
  cat > "$SRC" <<'C'
#define GL_GLEXT_PROTOTYPES 1
#include <GL/glcorearb.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <dlfcn.h>
#include <math.h>
#include <stdio.h>

static void on_glfw_error(int code, const char* desc){ printf("GLFW ERRO 0x%x: %s\n", code, desc ? desc : "(sem texto)"); }

/* De qual biblioteca vem uma função: libmgl.dylib (MGL) ou o OpenGL da Apple. */
static const char* origin(const void* p){ Dl_info i; return (p && dladdr(p, &i) && i.dli_fname) ? i.dli_fname : "(não achei)"; }

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
    setvbuf(stdout, NULL, _IOLBF, 0);   /* sai linha a linha, mesmo se o programa cair */
    glfwSetErrorCallback(on_glfw_error);
    printf("GLFW: %s\n", glfwGetVersionString());
    if(!glfwInit()){ printf("glfwInit FALHOU\n"); return 2; }

    /* A GLFW do MGL só cria contexto se o app pedir OpenGL 4.6. */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);   /* fica por cima do Terminal */
    GLFWwindow* win = glfwCreateWindow(480, 360, "VostroXe: OpenGL na Iris Xe (MGL)", NULL, NULL);
    if(!win){ printf("glfwCreateWindow FALHOU (o motivo está na linha GLFW ERRO acima)\n"); glfwTerminate(); return 3; }
    printf("glfwCreateWindow: OK\n");
    glfwMakeContextCurrent(win);

    int ww=0, wh=0, fw=0, fh=0; float sx=0, sy=0;
    glfwGetWindowSize(win, &ww, &wh); glfwGetFramebufferSize(win, &fw, &fh); glfwGetWindowContentScale(win, &sx, &sy);
    printf("janela %dx%d pontos, framebuffer %dx%d pixels, escala %.1f; visível=%d, em foco=%d\n",
           ww, wh, fw, fh, sx, glfwGetWindowAttrib(win, GLFW_VISIBLE), glfwGetWindowAttrib(win, GLFW_FOCUSED));
    printf("GL_RENDERER : %s  |  GL_VERSION : %s\n", (const char*)glGetString(GL_RENDERER), (const char*)glGetString(GL_VERSION));
    printf("glGetString pela GLFW (glfwGetProcAddress) vem de: %s\n", origin((const void*)glfwGetProcAddress("glGetString")));
    printf("glDrawArrays ligado no programa vem de: %s\n", origin((const void*)&glDrawArrays));

    float verts[] = {          /* pos.xyz, cor.rgb (entrelaçado, stride 24) */
         0.0f,  0.7f, 0.0f,   1.0f, 0.0f, 0.0f,   /* topo     = vermelho */
         0.7f, -0.7f, 0.0f,   0.0f, 1.0f, 0.0f,   /* direita  = verde    */
        -0.7f, -0.7f, 0.0f,   0.0f, 0.0f, 1.0f    /* esquerda = azul     */
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

    /* ~6 s: fundo pulsando (azul escuro <-> azul) + triângulo RGB parado. */
    double t0 = glfwGetTime(), t = t0, worst = 0, last = t0;
    long frames = 0; GLenum firsterr = 0;
    while(!glfwWindowShouldClose(win) && t - t0 < 6.0){
        glfwGetFramebufferSize(win, &fw, &fh);
        glViewport(0, 0, fw, fh);
        float k = 0.5f + 0.5f * sinf((float)(t - t0) * 3.0f);
        glClearColor(0.05f, 0.05f + 0.25f * k, 0.10f + 0.60f * k, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(win);
        glfwPollEvents();
        GLenum e = glGetError(); if(e && !firsterr) firsterr = e;
        frames++;
        t = glfwGetTime(); if(t - last > worst) worst = t - last; last = t;
    }
    double secs = t - t0;
    printf("quadros: %ld em %.1f s = %.0f por segundo (quadro mais lento: %.0f ms); primeiro glGetError != 0: 0x%x\n",
           frames, secs, secs > 0 ? frames / secs : 0, worst * 1000, firsterr);
    int ok = frames >= 30 && firsterr == 0 && linked;
    printf(ok ? ">>> JANELA: %ld quadros desenhados e apresentados sem erro de GL. Confira se você viu o triângulo.\n"
              : ">>> JANELA: abriu, mas %ld quadros e/ou erro de GL acima; me mande os logs.\n", frames);
    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}
C
  echo "== compilando contra $MGLDIR/build/{libglfw,libmgl}.dylib (clang, Command Line Tools):"
  clang "$SRC" -o "$BIN" -I"$MGLDIR/MGL/include" -I"$MGLDIR/MGL/include/GL" -I"$MGLDIR/external/glfw/include" \
    "$MGLDIR/build/libglfw.dylib" "$MGLDIR/build/libmgl.dylib" -Wl,-rpath,"$MGLDIR/build" 2>&1 | tail -25
  if [[ ! -x $BIN ]]; then echo "a compilação FALHOU (ver acima)"; exit 1; fi
  echo "== rodando: uma janela abre por ~6 s (triângulo colorido, fundo pulsando). O log do MGL vai para ${ERRLOG:t}."
  DYLD_LIBRARY_PATH="$MGLDIR/build" DYLD_FALLBACK_LIBRARY_PATH="$MGLDIR/build" "$BIN" 2> "$ERRLOG"; rc=$?
  echo "== o programa terminou com código $rc (0 = normal; 134 = abortou num assert)"
  echo "== resumo do log do MGL (${ERRLOG:t}, $(wc -l < "$ERRLOG" | tr -d ' ') linhas):"
  grep -m1 -A1 'Metal device created' "$ERRLOG"
  np=$(grep -c 'Presenting drawable with texture' "$ERRLOG")
  echo "quadros apresentados na tela (Presenting drawable): $np"
  grep -m1 'Presenting drawable with texture' "$ERRLOG" | sed -E 's/^.*MGL INFO: //'
  echo "mensagens de erro/aviso do MGL (contagem, sem a hora):"
  grep -E 'ERROR|CRITICAL|Assertion|EMERGENCY|WARNING|xception|GLFW' "$ERRLOG" \
    | sed -E 's/^[0-9-]+ [0-9:.]+ [^ ]+ //; s/0x[0-9a-f]{6,}/0x…/g' | sort | uniq -c | sort -rn | head -15
  rm -f "$SRC" "$BIN"
} 2>&1 | tee "$LOG"
echo; echo "logs: $LOG  (+ ${ERRLOG:t})"
