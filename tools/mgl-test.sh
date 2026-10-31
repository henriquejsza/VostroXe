#!/bin/zsh
# Passo 2: confirma que o MGL desenha na GPU (Iris Xe via Metal) — caminho WINDOWED (o que o MGL testa).
# Abre uma janela GLFW do MGL, limpa de azul por ~2s, lê o pixel central de volta e loga.
# Roda no macOS:  zsh /Volumes/MACINSTALL/mgl-test.sh   (ou dois cliques no TESTAR-MGL.command)
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-test-log.txt}"
MGLDIR="$HOME/MGL"
{
  echo "== $(date '+%d/%m %H:%M')  teste do MGL na GPU (windowed)"
  if [[ ! -f $MGLDIR/build/libmgl.dylib || ! -f $MGLDIR/build/libglfw.dylib ]]; then
    echo "não achei build/libmgl.dylib e/ou build/libglfw.dylib — rode o COMPILAR-MGL primeiro."; exit 1
  fi
  SRC="$(mktemp -t mglprobe).c"; BIN="$(mktemp -t mglprobe)"
  cat > "$SRC" <<'C'
#define GL_GLEXT_PROTOTYPES 1
#include <GL/glcorearb.h>
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3native.h>
#include "MGLContext.h"
#include "MGLRenderer.h"
#include <stdio.h>
#include <unistd.h>
int main(void){
    if(!glfwInit()){ printf("glfwInit FALHOU\n"); return 2; }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
    glfwWindowHint(GLFW_DEPTH_BITS, 32);
    GLFWwindow* window = glfwCreateWindow(256, 256, "MGL VostroXe - teste GPU", NULL, NULL);
    if(!window){ printf("glfwCreateWindow FALHOU\n"); glfwTerminate(); return 3; }
    GLMContext glm_ctx = createGLMContext(GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, GL_DEPTH_COMPONENT, GL_FLOAT, 0, 0);
    if(!glm_ctx){ printf("createGLMContext FALHOU\n"); glfwTerminate(); return 4; }
    void* renderer = CppCreateMGLRendererFromContextAndBindToWindow(glm_ctx, glfwGetCocoaWindow(window));
    if(!renderer){ printf("CppCreateMGLRendererFromContextAndBindToWindow FALHOU\n"); glfwTerminate(); return 5; }
    MGLsetCurrentContext(glm_ctx);

    printf("GL_VENDOR   : %s\n", (const char*)glGetString(GL_VENDOR));
    printf("GL_RENDERER : %s\n", (const char*)glGetString(GL_RENDERER));
    printf("GL_VERSION  : %s\n", (const char*)glGetString(GL_VERSION));
    printf("GL_SHADING  : %s\n", (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));

    int fbw=256, fbh=256; glfwGetFramebufferSize(window, &fbw, &fbh);
    if(fbw<=0||fbh<=0){ fbw=256; fbh=256; }
    printf("framebuffer: %dx%d\n", fbw, fbh);

    unsigned char px[4] = {0,0,0,0};
    int read_done=0, ok=0; GLenum glerr=0;
    for(int frame=0; frame<120; frame++){            /* ~2s a ~60fps */
        glViewport(0,0,fbw,fbh);
        glClearColor(0.0f, 0.5f, 1.0f, 1.0f);        /* azul */
        glClear(GL_COLOR_BUFFER_BIT);
        glFinish();
        if(frame==3){                                 /* lê depois de estabilizar o drawable */
            glReadPixels(fbw/2, fbh/2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
            glerr = glGetError();
            ok = (px[1]>=90 && px[1]<=170) && ((px[0]<80 && px[2]>190) || (px[0]>190 && px[2]<80));
            read_done=1;
        }
        MGLswapBuffers(glm_ctx);
        glfwPollEvents();
        usleep(16000);
    }
    if(read_done){
        printf("pixel central RGBA = %u %u %u %u  (azul: ~0 128 255 255, ou 255 128 0 255 se BGRA)\n", px[0],px[1],px[2],px[3]);
        printf("glGetError = 0x%x\n", glerr);
    } else printf("nao consegui ler o pixel\n");
    printf(ok ? ">>> RENDER OK NA GPU: janela azul desenhada pelo Metal (Iris Xe) e lida de volta.\n"
             : ">>> a janela abriu, mas o pixel lido nao bateu; me mande o log.\n");
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
C
  echo "== compilando o probe + gl_core.c (clang, Command Line Tools):"
  clang "$SRC" "$MGLDIR/MGL/src/gl_core.c" -o "$BIN" -DMGL_GL_CORE \
    -I"$MGLDIR/MGL/include" -I"$MGLDIR/MGL/include/GL" -I"$MGLDIR/external/glfw/include" \
    -I"$MGLDIR/external/SPIRV-Cross" -I"$MGLDIR/external/SPIRV-Tools/include" \
    -I"$MGLDIR/external/glslang/glslang/Include" -I"$MGLDIR/MGL/SPIRV/SPIRV-Cross" \
    -DENABLE_OPT=0 -DSPIRV_CROSS_C_API_MSL=1 -DSPIRV_CROSS_C_API_GLSL=1 -DSPIRV_CROSS_C_API_CPP=1 -DSPIRV_CROSS_C_API_REFLECT=1 \
    "$MGLDIR/build/libmgl.dylib" "$MGLDIR/build/libglfw.dylib" \
    -framework Metal -framework Foundation -framework QuartzCore -framework Cocoa -framework CoreFoundation -framework CoreGraphics -framework IOKit -framework OpenGL 2>&1 | tail -25
  if [[ ! -x $BIN ]]; then echo "a compilacao do probe FALHOU (ver acima)"; exit 1; fi
  echo "== rodando — vai abrir uma JANELA AZUL por ~2s (as linhas 'MGL INFO: Metal device created: ...' mostram a GPU):"
  DYLD_LIBRARY_PATH="$MGLDIR/build" DYLD_FALLBACK_LIBRARY_PATH="$MGLDIR/build" "$BIN" 2>&1
  rm -f "$SRC" "$BIN"
} 2>&1 | tee "$LOG"
echo; echo "log: $LOG — me mande este arquivo."
