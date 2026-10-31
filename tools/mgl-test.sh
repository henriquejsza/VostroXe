#!/bin/zsh
# Passo 2: confirma que o MGL desenha na GPU (Iris Xe via Metal). Headless, offscreen (sem janela).
# Compila um probe contra ~/MGL/build/libmgl.dylib, desenha um clear azul num FBO e lê o pixel de volta.
# Roda no macOS:  zsh /Volumes/MACINSTALL/mgl-test.sh   (ou dois cliques no TESTAR-MGL.command)
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-test-log.txt}"
MGLDIR="$HOME/MGL"
{
  echo "== $(date '+%d/%m %H:%M')  teste do MGL na GPU (headless/offscreen)"
  if [[ ! -f $MGLDIR/build/libmgl.dylib ]]; then
    echo "não achei $MGLDIR/build/libmgl.dylib — rode o COMPILAR-MGL primeiro."; exit 1
  fi
  SRC="$(mktemp -t mglprobe).c"; BIN="$(mktemp -t mglprobe)"
  cat > "$SRC" <<'C'
#define GL_GLEXT_PROTOTYPES 1
#include <GL/glcorearb.h>
#include "MGLContext.h"
#include "MGLRenderer.h"
#include <stdio.h>
int main(void){
    GLMContext ctx = createGLMContext(GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, GL_DEPTH_COMPONENT, GL_FLOAT, 0, 0);
    if(!ctx){ printf("createGLMContext FALHOU\n"); return 2; }
    if(!CppCreateMGLRendererHeadless(ctx)){ printf("CppCreateMGLRendererHeadless FALHOU\n"); return 3; }
    MGLsetCurrentContext(ctx);
    printf("GL_VENDOR   : %s\n", (const char*)glGetString(GL_VENDOR));
    printf("GL_RENDERER : %s\n", (const char*)glGetString(GL_RENDERER));
    printf("GL_VERSION  : %s\n", (const char*)glGetString(GL_VERSION));
    printf("GL_SHADING  : %s\n", (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
    const int w=64,h=64; GLuint tex=0,fbo=0;
    glGenTextures(1,&tex); glBindTexture(GL_TEXTURE_2D,tex);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,0);
    glGenFramebuffers(1,&fbo); glBindFramebuffer(GL_FRAMEBUFFER,fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,tex,0);
    printf("framebuffer status = 0x%x  (0x%x = completo)\n", glCheckFramebufferStatus(GL_FRAMEBUFFER), GL_FRAMEBUFFER_COMPLETE);
    glViewport(0,0,w,h);
    glClearColor(0.0f,0.5f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();
    unsigned char px[64*64*4]; for(int i=0;i<w*h*4;i++) px[i]=123;
    glReadPixels(0,0,w,h,GL_RGBA,GL_UNSIGNED_BYTE,px);
    GLenum e=glGetError(); int c=((h/2)*w+(w/2))*4;
    printf("pixel central RGBA = %u %u %u %u  (clear azul: espero ~0 128 255 255, ou 255 128 0 255 se BGRA)\n", px[c],px[c+1],px[c+2],px[c+3]);
    printf("glGetError = 0x%x\n", e);
    int ok = (px[c+1]>=90 && px[c+1]<=170) && ((px[c]<80 && px[c+2]>190) || (px[c]>190 && px[c+2]<80));
    printf(ok ? ">>> RENDER OK NA GPU: o clear foi desenhado num FBO e lido de volta pelo Metal (Iris Xe).\n"
             : ">>> o pixel nao bateu; me mande o log (pode ser detalhe de cobertura do MGL).\n");
    return 0;
}
C
  echo "== compilando o probe + gl_core.c (clang, Command Line Tools):"
  clang "$SRC" "$MGLDIR/MGL/src/gl_core.c" -o "$BIN" -DMGL_GL_CORE \
    -I"$MGLDIR/MGL/include" -I"$MGLDIR/MGL/include/GL" \
    -I"$MGLDIR/external/SPIRV-Cross" -I"$MGLDIR/external/SPIRV-Tools/include" \
    -I"$MGLDIR/external/glslang/glslang/Include" -I"$MGLDIR/MGL/SPIRV/SPIRV-Cross" \
    -DENABLE_OPT=0 -DSPIRV_CROSS_C_API_MSL=1 -DSPIRV_CROSS_C_API_GLSL=1 -DSPIRV_CROSS_C_API_CPP=1 -DSPIRV_CROSS_C_API_REFLECT=1 \
    "$MGLDIR/build/libmgl.dylib" \
    -framework Metal -framework Foundation -framework QuartzCore -framework Cocoa -framework CoreGraphics -framework IOKit 2>&1 | tail -25
  if [[ ! -x $BIN ]]; then echo "a compilacao do probe FALHOU (ver acima)"; exit 1; fi
  echo "== rodando (as linhas 'MGL INFO: Metal device created: ...' mostram a GPU de verdade):"
  DYLD_LIBRARY_PATH="$MGLDIR/build" DYLD_FALLBACK_LIBRARY_PATH="$MGLDIR/build" "$BIN" 2>&1
  rm -f "$SRC" "$BIN"
} 2>&1 | tee "$LOG"
echo; echo "log: $LOG — me mande este arquivo."
