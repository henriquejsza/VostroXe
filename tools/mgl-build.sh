#!/bin/zsh
# GL geral via MGL (OpenGL 4.6 / ES 3.x -> Metal) no Vostro 3520 — BUILD COMPLETO (precisa de internet).
# Compila as dependências (SPIRV-Tools, SPIRV-Cross, SPIRV-Headers, glslang, glfw) e depois o MGL.
# Roda no macOS:  zsh /Volumes/MACINSTALL/mgl-build.sh   (ou dois cliques no COMPILAR-MGL.command)
# Não precisa de Xcode (só as Command Line Tools). Logs ficam no pendrive.
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-build-log.txt}"
DEPLOG="$HERE/mgl-deps-log.txt"; MAKELOG="$HERE/mgl-make-log.txt"
MGLDIR="$HOME/MGL"; TOOLS="$HOME/mgl-tools"; CMVER="3.31.6"
err=0
{
  echo "== $(date '+%d/%m %H:%M')  MGL build completo"
  echo "macOS $(sw_vers -productVersion 2>/dev/null) ($(sw_vers -buildVersion 2>/dev/null)), arch $(uname -m)"
  for t in git make clang curl python3; do command -v $t >/dev/null && echo "  $t: ok" || echo "  $t: FALTA (rode: xcode-select --install)"; done
  echo "internet: $(curl -sI -m 10 https://github.com >/dev/null 2>&1 && echo OK || echo 'SEM ACESSO — ligue o cabo de rede e tente de novo')"

  # ---- cmake (do sistema, ou baixa um standalone) ----
  if command -v cmake >/dev/null; then CMAKE=cmake; echo "cmake: $(cmake --version | head -1) (sistema)"
  else
    echo "== baixando cmake $CMVER (uma vez)"; mkdir -p "$TOOLS/cmake"
    if [[ ! -x $TOOLS/cmake/CMake.app/Contents/bin/cmake ]]; then
      curl -fL -o "$TOOLS/cmake.tgz" "https://github.com/Kitware/CMake/releases/download/v$CMVER/cmake-$CMVER-macos-universal.tar.gz" && \
      tar xzf "$TOOLS/cmake.tgz" -C "$TOOLS/cmake" --strip-components=1
    fi
    CMAKE="$TOOLS/cmake/CMake.app/Contents/bin/cmake"
    [[ -x $CMAKE ]] && echo "cmake: $($CMAKE --version | head -1) (baixado)" || { echo "FALHA ao obter o cmake"; exit 1; }
  fi
  export PATH="${CMAKE:h}:$PATH"

  # ---- fonte do MGL ----
  if [[ -d $MGLDIR/.git ]]; then echo "== MGL já em $MGLDIR (git pull)"; ( cd "$MGLDIR" && git checkout -- MGL/src/glm_params.c MGL/src/MGLRenderer.m Makefile 2>/dev/null; git pull --ff-only 2>&1 | tail -2 )
  else echo "== clonando MGL em $MGLDIR"; git clone https://github.com/openglonmetal/MGL.git "$MGLDIR" 2>&1 | tail -4 || { echo "clone MGL FALHOU"; exit 1; }; fi
  cd "$MGLDIR" || { echo "sem $MGLDIR"; exit 1; }

  # ---- dependências: clonar + compilar ----
  cd external || { echo "sem external/"; exit 1; }
  if [[ ! -d SPIRV-Tools || ! -d glslang || ! -d SPIRV-Cross ]]; then
    echo "== clonando dependências (clone_external.sh)"; bash clone_external.sh 2>&1 | tail -12
  else echo "== dependências já clonadas"; fi
  if [[ -f SPIRV-Cross/build/libspirv-cross-core.a && -f glslang/build/glslang/libglslang.a && -f SPIRV-Tools/build/source/lint/libSPIRV-Tools-lint.a ]]; then
    echo "== dependências já compiladas (pulando build_external.sh)"
  else
    echo "== compilando dependências (build_external.sh) — vários minutos; log em mgl-deps-log.txt"
    bash build_external.sh > "$DEPLOG" 2>&1; echo "   build_external rc=$? ; últimas linhas:"; tail -20 "$DEPLOG"
  fi
  cd "$MGLDIR"

  # ---- patch VostroXe: getMacOSDefaults pede um pixel format CGL ACELERADO (kCGLPFAAccelerated),
  #      que falha nesta GPU (issue #21: 0 formats acelerados). Esse contexto CGL só serve pra ler
  #      os defaults do estado GL; sem "accelerated" ele cai pro renderer por software (GL 4.1),
  #      lê os MESMOS defaults da spec, e o MGL segue renderizando no Metal/GPU. Idempotente.
  PF="MGL/src/glm_params.c"
  if grep -q 'kCGLPFAAccelerated' "$PF"; then
    echo "== patch VostroXe: removendo kCGLPFAAccelerated de getMacOSDefaults ($PF)"
    perl -0pi -e 's/attributes\[4\] = \{\n\s*kCGLPFAAccelerated,[^\n]*\n/attributes[3] = {\n/' "$PF"
    if grep -q 'kCGLPFAAccelerated' "$PF"; then echo "   AVISO: patch NAO aplicou (confira $PF)"; err=1; else echo "   patch aplicado (attributes[3], sem acelerado)"; fi
  else
    echo "== patch VostroXe getMacOSDefaults: já aplicado"
  fi

  # ---- patch VostroXe B: o Makefile do MGL tem um typo ($(mgl_gl_obj), vazio) no alvo da lib core,
  #      então o libmgl.dylib sai SEM os pontos de entrada glXxx (gl_core.o). Isso quebra a GLFW do MGL
  #      (getProcAddress via dlsym) e o uso por apps. O certo é $(mgl_core_obj) (como a lib ES já faz).
  MF="Makefile"
  if grep -q 'mgl_gl_obj' "$MF"; then
    echo "== patch VostroXe: Makefile libmgl core (mgl_gl_obj -> mgl_core_obj, inclui gl_core.o)"
    perl -pi -e 's/\$\(mgl_gl_obj\)/\$(mgl_core_obj)/g' "$MF"
    grep -q 'mgl_gl_obj' "$MF" && { echo "   AVISO: nao aplicou"; err=1; } || echo "   patch Makefile aplicado"
  else
    echo "== patch VostroXe Makefile: já aplicado"
  fi

  # ---- patch VostroXe C: no render para um FBO com textura de cor, o MGL não "realiza" o Metal texture
  #      do anexo (mtl_data fica nulo -> assert em newRenderEncoder). Marca como render target e realiza.
  RF="MGL/src/MGLRenderer.m"
  if ! grep -q 'VostroXe: realize FBO color attachment' "$RF"; then
    echo "== patch VostroXe: realizar mtl_data do anexo de cor do FBO ($RF)"
    perl -0pi -e 's/\Qassert(tex->mtl_data);\E/\/* VostroXe: realize FBO color attachment *\/ tex->is_render_target = true; if (tex->mtl_data == NULL) [self bindMTLTexture: tex]; assert(tex->mtl_data);/' "$RF"
    grep -q 'VostroXe: realize FBO color attachment' "$RF" && echo "   patch MGLRenderer aplicado" || { echo "   AVISO: nao aplicou"; err=1; }
  else
    echo "== patch VostroXe MGLRenderer: já aplicado"
  fi

  # ---- MGL ----
  echo "== compilando o MGL (make) — log em mgl-make-log.txt"
  make > "$MAKELOG" 2>&1; echo "   make rc=$? ; últimas linhas:"; tail -25 "$MAKELOG"

  echo "== resultado (dylibs geradas):"; ls -la "$MGLDIR"/build/*.dylib "$MGLDIR"/*.dylib 2>/dev/null | awk '{print $5,$NF}'
  for f in build/libmgl.dylib build/libmgl_es.dylib build/libglfw.dylib; do
    [[ -f $MGLDIR/$f ]] && echo "OK  $f" || { echo "FALTOU  $f"; err=1; }
  done
  [[ -f $MGLDIR/build/libmgl.dylib ]] && { echo "== otool libmgl.dylib:"; otool -L "$MGLDIR/build/libmgl.dylib" 2>/dev/null | grep -iE 'Metal|OpenGL|Foundation|spirv|glslang' | head; }
  echo
  (( err )) && echo ">>> algo não compilou. Me mande: mgl-build-log.txt, mgl-deps-log.txt e mgl-make-log.txt" \
            || echo ">>> MGL COMPILOU! Me mande o mgl-build-log.txt pro passo 2 (testar na GPU)."
} 2>&1 | tee "$LOG"
echo; echo "logs no pendrive: $LOG  (+ mgl-deps-log.txt, mgl-make-log.txt)"
