#!/bin/zsh
# Marco 2b: prova o shim que desvia o OpenGL de apps nativos (NSOpenGLContext) para o MGL, sem recompilar o app.
# Compila o shim (src/MGLShim/mglshim.m) e roda a MESMA sonda NSOpenGLView duas vezes:
#   1) normal           -> OpenGL da Apple (esperado: "Apple Software Renderer")
#   2) com o shim        -> deve virar "MGL" e desenhar na Iris Xe (Metal)
# Precisa ter rodado o COMPILAR-MGL antes. Roda no macOS:
#   zsh /Volumes/MACINSTALL/mgl-shim.sh   (ou dois cliques no SHIM-GL.command)
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-shim-log.txt}"
ERRLOG="${LOG:r}-mgl.txt"   # o que o MGL e o shim escrevem (stderr), à parte
if [[ -n ${MGL_DIR:-} ]]; then MGLDIR=$MGL_DIR
elif [[ -f $HERE/../src/MGL/Makefile ]]; then MGLDIR=${HERE:h}/src/MGL
else MGLDIR=$HOME/VostroXe-MGL; fi
# A fonte do shim: no checkout vem de src/MGLShim; no pendrive vem ao lado deste script.
if   [[ -f $HERE/../src/MGLShim/mglshim.m ]]; then SHIMSRC=${HERE:h}/src/MGLShim/mglshim.m
elif [[ -f $HERE/mglshim.m ]];              then SHIMSRC=$HERE/mglshim.m
else SHIMSRC=""; fi
if   [[ -f $HERE/../src/MGLShim/mgl_gl_interpose.c ]]; then GENSRC=${HERE:h}/src/MGLShim/mgl_gl_interpose.c
elif [[ -f $HERE/mgl_gl_interpose.c ]];              then GENSRC=$HERE/mgl_gl_interpose.c
else GENSRC=""; fi
{
  echo "== $(date '+%d/%m %H:%M')  shim do MGL: desviar o OpenGL nativo (NSOpenGLContext) para o MGL"
  [[ $(uname) == Darwin ]] || { echo "rode no macOS"; exit 1; }
  echo "macOS $(sw_vers -productVersion 2>/dev/null) ($(sw_vers -buildVersion 2>/dev/null)), arch $(uname -m)"
  [[ -f $MGLDIR/build/libmgl.dylib ]] || { echo "não achei $MGLDIR/build/libmgl.dylib — rode o COMPILAR-MGL primeiro."; exit 1; }
  [[ -n $SHIMSRC ]] || { echo "não achei o mglshim.m (nem em src/MGLShim nem ao lado deste script)."; exit 1; }
  [[ -n $GENSRC ]] || { echo "não achei o mgl_gl_interpose.c (gerado por gen-interpose.py)."; exit 1; }
  echo "== fonte do shim: $SHIMSRC + ${GENSRC:t}"

  SHIM="$(mktemp -t libmglshim).dylib"
  echo "== compilando o shim (clang -dynamiclib, mglshim.m + interpose gerado de $(grep -c 'INTERPOSE(' "$GENSRC") gl*):"
  clang -dynamiclib -ObjC "$SHIMSRC" "$GENSRC" -o "$SHIM" \
    -I"$MGLDIR/MGL/include" -I"$MGLDIR/MGL/include/GL" \
    -framework Cocoa -framework QuartzCore -framework Metal -framework OpenGL \
    -Wl,-undefined,dynamic_lookup \
    -install_name @rpath/libmglshim.dylib 2>&1 | tail -25
  [[ -f $SHIM ]] || { echo "o shim NÃO compilou (ver acima)"; exit 1; }
  echo "shim compilado: $SHIM"

  # ---- a "sonda-app": um NSOpenGLView comum, como um app nativo (ligado só no OpenGL da Apple) ----
  PSRC="$(mktemp -t glprobe).m"; BIN="$(mktemp -t glprobe)"
  cat > "$PSRC" <<'OBJC'
#define GL_SILENCE_DEPRECATION 1
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <OpenGL/OpenGL.h>
#include <math.h>
#include <stdio.h>
static const char* VS =
"#version 410 core\n""layout(location=0) in vec3 position;\n""layout(location=1) in vec3 color;\n""layout(location=0) out vec3 vcolor;\n"
"void main(){ vcolor = color; gl_Position = vec4(position, 1.0); }\n";
static const char* FS =
"#version 410 core\n""layout(location=0) in vec3 vcolor;\n""layout(location=0) out vec4 frag_colour;\n"
"void main(){ frag_colour = vec4(vcolor, 1.0); }\n";
static GLuint mkshader(GLenum type, const char* src){
    GLuint s = glCreateShader(type); glShaderSource(s, 1, &src, NULL); glCompileShader(s);
    GLint ok=0; glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    printf("shader %s: %s\n", type==GL_VERTEX_SHADER?"vertex":"fragment", ok?"compilou":"FALHOU"); return s;
}
int main(void){
    setvbuf(stdout, NULL, _IOLBF, 0);
    @autoreleasepool {
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        NSRect fr = NSMakeRect(0,0,480,360);
        NSWindow* win = [[NSWindow alloc] initWithContentRect:fr
            styleMask:(NSWindowStyleMaskTitled|NSWindowStyleMaskClosable) backing:NSBackingStoreBuffered defer:NO];
        [win setTitle:@"VostroXe: sonda NSOpenGLView"]; [win center]; [win setLevel:NSFloatingWindowLevel];
        NSView* view = [[NSView alloc] initWithFrame:fr]; [win setContentView:view];
        [win makeKeyAndOrderFront:nil]; [NSApp activateIgnoringOtherApps:YES];
        NSOpenGLPixelFormatAttribute attrs[] = {
            NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
            NSOpenGLPFAColorSize, 24, NSOpenGLPFADoubleBuffer, 0 };
        NSOpenGLPixelFormat* pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
        if(!pf){ printf("NSOpenGLPixelFormat: NULO\n"); return 2; }
        NSOpenGLContext* glc = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
        if(!glc){ printf("NSOpenGLContext: NULO\n"); return 3; }
        [glc setView:view]; [glc makeCurrentContext];
        printf("GL_RENDERER : %s\n", (const char*)glGetString(GL_RENDERER));
        printf("GL_VERSION  : %s\n", (const char*)glGetString(GL_VERSION));
        float v[]={ 0.0f,0.7f,0.0f, 1,0,0,  0.7f,-0.7f,0.0f, 0,1,0,  -0.7f,-0.7f,0.0f, 0,0,1 };
        GLuint vbo=0,vao=0; glGenVertexArrays(1,&vao); glBindVertexArray(vao);
        glGenBuffers(1,&vbo); glBindBuffer(GL_ARRAY_BUFFER,vbo);
        glBufferData(GL_ARRAY_BUFFER,sizeof(v),v,GL_STATIC_DRAW);
        GLuint p=glCreateProgram();
        glAttachShader(p,mkshader(GL_VERTEX_SHADER,VS)); glAttachShader(p,mkshader(GL_FRAGMENT_SHADER,FS));
        glLinkProgram(p);  /* locations via layout() no shader: o MGL não implementa glBindAttribLocation */
        GLint linked=0; glGetProgramiv(p,GL_LINK_STATUS,&linked);
        printf("programa: %s\n", linked?"linkou":"LINK FALHOU"); glUseProgram(p);
        glEnableVertexAttribArray(0); glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,24,(void*)0);
        glEnableVertexAttribArray(1); glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,24,(void*)(3*sizeof(float)));
        printf("glGetError depois do setup = 0x%x\n", glGetError());
        double t0=CACurrentMediaTime(), t=t0; long frames=0; GLenum firsterr=0;
        while(t-t0 < 4.0){ @autoreleasepool {
            NSEvent* e; while((e=[NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast]
                                                       inMode:NSDefaultRunLoopMode dequeue:YES])) [NSApp sendEvent:e];
            GLint fw=(GLint)(view.bounds.size.width*win.backingScaleFactor), fh=(GLint)(view.bounds.size.height*win.backingScaleFactor);
            glViewport(0,0,fw,fh);
            float k=0.5f+0.5f*sinf((float)(t-t0)*3.0f);
            glClearColor(0.05f,0.05f+0.25f*k,0.10f+0.60f*k,1.0f); glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_TRIANGLES,0,3); [glc flushBuffer];
            GLenum er=glGetError(); if(er&&!firsterr) firsterr=er; frames++; t=CACurrentMediaTime();
        } }
        printf("quadros: %ld em %.1f s = %.0f por segundo; primeiro glGetError != 0: 0x%x\n",
               frames, t-t0, (t-t0)>0?frames/(t-t0):0, firsterr);
    }
    return 0;
}
OBJC
  echo "== compilando a sonda NSOpenGLView (clang -ObjC, só OpenGL da Apple):"
  clang -ObjC -fobjc-arc "$PSRC" -o "$BIN" -framework Cocoa -framework OpenGL -framework QuartzCore 2>&1 | tail -15
  [[ -x $BIN ]] || { echo "a sonda NÃO compilou (ver acima)"; exit 1; }

  echo
  echo "== 1) LINHA DE BASE (sem shim): OpenGL da Apple"
  BASEOUT=$("$BIN" 2>/dev/null)
  echo "$BASEOUT" | grep -E 'GL_RENDERER|GL_VERSION|shader|programa|quadros|glGetError'
  echo
  echo "== 2) COM O SHIM: deve virar MGL e desenhar na Iris Xe"
  SHIMOUT=$(DYLD_INSERT_LIBRARIES="$SHIM" MGLSHIM_LIB="$MGLDIR/build/libmgl.dylib" \
    DYLD_LIBRARY_PATH="$MGLDIR/build" DYLD_FALLBACK_LIBRARY_PATH="$MGLDIR/build" "$BIN" 2> "$ERRLOG")
  rc=$?
  echo "$SHIMOUT" | grep -E 'GL_RENDERER|GL_VERSION|shader|programa|quadros|glGetError'
  echo "   (a sonda com o shim terminou com código $rc; 0 = normal, 139 = segfault, 134 = assert)"
  echo
  echo "== veredito:"
  base=$(echo "$BASEOUT" | awk -F': ' '/GL_RENDERER/{print $2; exit}')
  shimr=$(echo "$SHIMOUT" | awk -F': ' '/GL_RENDERER/{print $2; exit}')
  echo "   GL_RENDERER sem shim : ${base:-?}"
  echo "   GL_RENDERER com shim : ${shimr:-? (vazio = a sonda caiu antes de imprimir)}"
  echo "   linhas do shim no log (${ERRLOG:t}):"
  grep 'MGLSHIM:' "$ERRLOG" | sed -E 's/^.*MGLSHIM: /     /' | head
  nd=$(grep -c 'Metal device created' "$ERRLOG")
  np=$(grep -c 'Presenting drawable with texture' "$ERRLOG")
  echo "   renderers do MGL criados (Metal device created): $nd  | quadros apresentados (Presenting drawable): $np"
  echo "   erros/avisos do MGL (sem a hora):"
  grep -E 'ERROR|CRITICAL|Assertion|EMERGENCY|WARNING|xception' "$ERRLOG" \
    | sed -E 's/^[0-9-]+ [0-9:.]+ [^ ]+ //; s/0x[0-9a-f]{6,}/0x…/g' | sort | uniq -c | sort -rn | head -10
  if (( np > 0 )); then
    echo "   >>> SHIM OK: o NSOpenGLContext do app foi parar no MGL e apresentou quadros na GPU."
  else
    echo "   >>> o shim carregou mas não apresentou quadros pelo MGL; o ${ERRLOG:t} diz onde travou."
  fi
  rm -f "$PSRC" "$BIN" "$SHIM"
} 2>&1 | tee "$LOG"
echo; echo "logs: $LOG  (+ ${ERRLOG:t})"
