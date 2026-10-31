#!/bin/zsh
# Passo 3 (prova visual): desenha o triângulo RGB clássico (vertex+fragment shader, VBO/VAO, glDrawArrays)
# num FBO offscreen na Iris Xe (MGL->Metal), lê de volta e salva uma imagem BMP que você abre no Preview.
# Precisa ter rodado o COMPILAR-MGL antes (usa ~/MGL/build/libmgl.dylib, já com os 5 patches).
# Roda no macOS:  zsh /Volumes/MACINSTALL/mgl-triangle.sh   (ou dois cliques no TRIANGULO-MGL.command)
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-triangle-log.txt}"
BMP="${2:-$HERE/mgl-triangulo.bmp}"
MGLDIR="$HOME/MGL"
{
  echo "== $(date '+%d/%m %H:%M')  triângulo MGL na GPU (offscreen -> BMP)"
  if [[ ! -f $MGLDIR/build/libmgl.dylib ]]; then
    echo "não achei $MGLDIR/build/libmgl.dylib — rode o COMPILAR-MGL primeiro."; exit 1
  fi
  SRC="$(mktemp -t mgltri).c"; BIN="$(mktemp -t mgltri)"
  cat > "$SRC" <<'C'
#define GL_GLEXT_PROTOTYPES 1
#include <GL/glcorearb.h>
#include "MGLContext.h"
#include "MGLRenderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void writeBMP(const char* path, const unsigned char* rgba, int w, int h){
    int rowbytes = w*3; int pad = (4-(rowbytes%4))%4;
    int datasize = (rowbytes+pad)*h; int filesize = 54 + datasize;
    FILE* f = fopen(path,"wb"); if(!f){ printf("nao abriu %s\n", path); return; }
    unsigned char hdr[54]; memset(hdr,0,54);
    hdr[0]='B'; hdr[1]='M';
    hdr[2]=filesize&0xff; hdr[3]=(filesize>>8)&0xff; hdr[4]=(filesize>>16)&0xff; hdr[5]=(filesize>>24)&0xff;
    hdr[10]=54; hdr[14]=40;
    hdr[18]=w&0xff; hdr[19]=(w>>8)&0xff; hdr[20]=(w>>16)&0xff; hdr[21]=(w>>24)&0xff;
    hdr[22]=h&0xff; hdr[23]=(h>>8)&0xff; hdr[24]=(h>>16)&0xff; hdr[25]=(h>>24)&0xff;
    hdr[26]=1; hdr[28]=24;
    fwrite(hdr,1,54,f);
    unsigned char* row=(unsigned char*)malloc(rowbytes+pad); for(int i=0;i<pad;i++) row[rowbytes+i]=0;
    for(int y=0;y<h;y++){                     /* glReadPixels e BMP sao ambos bottom-up: sem flip */
        const unsigned char* s = rgba + (size_t)y*w*4;
        for(int x=0;x<w;x++){ row[x*3+0]=s[x*4+2]; row[x*3+1]=s[x*4+1]; row[x*3+2]=s[x*4+0]; }
        fwrite(row,1,rowbytes+pad,f);
    }
    free(row); fclose(f);
}

static GLuint mkshader(GLenum type, const char* src){
    GLuint s=glCreateShader(type); glShaderSource(s,1,&src,NULL); glCompileShader(s);
    GLint ok=0; glGetShaderiv(s,GL_COMPILE_STATUS,&ok);
    char log[2048]; GLsizei n=0; glGetShaderInfoLog(s,2048,&n,log);
    printf("shader %s: %s%s%.*s\n", type==GL_VERTEX_SHADER?"vertex":"fragment",
           ok?"compilou":"FALHOU", n?" — ":"", (int)n, n?log:"");
    return s;
}

int main(int argc, char** argv){
    const char* out = (argc>1)? argv[1] : "mgl-triangulo.bmp";
    GLMContext ctx = createGLMContext(GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, GL_DEPTH_COMPONENT, GL_FLOAT, 0, 0);
    if(!ctx){ printf("createGLMContext FALHOU\n"); return 2; }
    if(!CppCreateMGLRendererHeadless(ctx)){ printf("CppCreateMGLRendererHeadless FALHOU\n"); return 3; }
    MGLsetCurrentContext(ctx);
    printf("GL_RENDERER : %s  |  GL_VERSION : %s\n", (const char*)glGetString(GL_RENDERER), (const char*)glGetString(GL_VERSION));

    const int W=256,H=256; GLuint tex=0,fbo=0;
    glGenTextures(1,&tex); glBindTexture(GL_TEXTURE_2D,tex);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,W,H,0,GL_RGBA,GL_UNSIGNED_BYTE,0);
    glGenFramebuffers(1,&fbo); glBindFramebuffer(GL_FRAMEBUFFER,fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,tex,0);
    printf("framebuffer status = 0x%x (0x%x=completo)\n", glCheckFramebufferStatus(GL_FRAMEBUFFER), GL_FRAMEBUFFER_COMPLETE);

    float verts[] = {          /* pos.xyz, cor.rgb (entrelaçado, stride 24) */
         0.0f,  0.7f, 0.0f,   1.0f,0.0f,0.0f,   /* topo    = vermelho */
         0.7f, -0.7f, 0.0f,   0.0f,1.0f,0.0f,   /* dir.    = verde    */
        -0.7f, -0.7f, 0.0f,   0.0f,0.0f,1.0f    /* esq.    = azul     */
    };
    GLuint vbo=0,vao=0;
    glGenBuffers(1,&vbo); glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
    glGenVertexArrays(1,&vao); glBindVertexArray(vao);
    glEnableVertexAttribArray(0); glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,24,(void*)0);
    glEnableVertexAttribArray(1); glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,24,(void*)(3*sizeof(float)));

    GLuint prog=glCreateProgram();
    GLuint vs=mkshader(GL_VERTEX_SHADER,VS), fs=mkshader(GL_FRAGMENT_SHADER,FS);
    glAttachShader(prog,vs); glAttachShader(prog,fs); glLinkProgram(prog);
    GLint linked=0; glGetProgramiv(prog,GL_LINK_STATUS,&linked);
    char plog[2048]; GLsizei pn=0; glGetProgramInfoLog(prog,2048,&pn,plog);
    printf("programa: %s%s%.*s\n", linked?"linkou":"LINK FALHOU", pn?" — ":"", (int)pn, pn?plog:"");
    glUseProgram(prog);

    glViewport(0,0,W,H);
    glClearColor(0.10f,0.10f,0.12f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES,0,3);
    glFinish();
    printf("glGetError pos-draw = 0x%x\n", glGetError());

    unsigned char* px=(unsigned char*)malloc((size_t)W*H*4);
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,px);

    long bg=0,tri=0,red=0,grn=0,blu=0;
    for(int i=0;i<W*H;i++){
        unsigned char R=px[i*4],G=px[i*4+1],B=px[i*4+2];
        if(R<60 && G<60 && B<75) bg++;
        else { tri++;
            if(R>120 && R>G+40 && R>B+40) red++;
            else if(G>120 && G>R+40 && G>B+40) grn++;
            else if(B>120 && B>R+40 && B>G+40) blu++;
        }
    }
    printf("pixels: fundo=%ld triangulo=%ld  (vermelho=%ld verde=%ld azul=%ld)\n", bg,tri,red,grn,blu);
    writeBMP(out,px,W,H);
    printf("imagem salva: %s (%dx%d)\n", out, W, H);
    int ok = (tri > W*H/12) && red>50 && grn>50 && blu>50 && bg>50;
    printf(ok ? ">>> TRIANGULO OK NA GPU: vertex+fragment shader + VBO/VAO + glDrawArrays na Iris Xe. Abra a imagem acima.\n"
             : ">>> nao bateu o esperado; abra a imagem e me mande ela + este log.\n");
    free(px);
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
  DYLD_LIBRARY_PATH="$MGLDIR/build" DYLD_FALLBACK_LIBRARY_PATH="$MGLDIR/build" "$BIN" "$BMP" 2>&1
  rm -f "$SRC" "$BIN"
} 2>&1 | tee "$LOG"
echo; echo "log: $LOG"
echo "imagem: $BMP  (abra no Preview — deve ser o triângulo R/G/B num fundo escuro)"
