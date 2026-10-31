#!/bin/zsh
# GL geral: compila o MGL do VostroXe (src/MGL: OpenGL 4.6 -> Metal, com as correções do Vostro) no macOS.
# A fonte é o src/MGL deste repositório. Quando o script roda do pendrive, ela vem do mgl-src.tar.gz ao
# lado dele e é copiada para ~/VostroXe-MGL (só os arquivos que mudaram, para o make recompilar só eles).
# As dependências (SPIRV-Cross, SPIRV-Tools, glslang, a GLFW do MGL) são reaproveitadas de ~/MGL/external
# quando já foram compiladas lá; senão são baixadas e compiladas (precisa de internet, vários minutos).
# Roda no macOS:  zsh /Volumes/MACINSTALL/mgl-build.sh   (ou dois cliques no COMPILAR-MGL.command)
# Não precisa de Xcode (só as Command Line Tools). Logs ficam ao lado do script.
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-build-log.txt}"
DEPLOG="${LOG:h}/mgl-deps-log.txt"; MAKELOG="${LOG:h}/mgl-make-log.txt"
TARBALL="$HERE/mgl-src.tar.gz"
COPY="$HOME/VostroXe-MGL"   # cópia de trabalho quando a fonte vem do pendrive
OLD="$HOME/MGL"             # checkout antigo do MGL: as dependências já compiladas nele são reaproveitadas
TOOLS="$HOME/mgl-tools"; CMVER="3.31.6"
DEPS=(OpenGL-Registry SPIRV-Cross SPIRV-Headers SPIRV-Tools ezxml glslang)   # o que clone_external.sh baixa
err=0

online() { curl -sI -m 10 https://github.com >/dev/null 2>&1; }

# As bibliotecas que o Makefile do MGL linka (o build_external.sh gera todas).
deps_built() {
  [[ -f SPIRV-Cross/build/libspirv-cross-core.a && -f SPIRV-Tools/build/source/libSPIRV-Tools.a &&
     -f glslang/build/glslang/libglslang.a && -f glfw/build/src/libglfw3.a ]]
}

# Copia a árvore $1 para $2 trocando só os arquivos de conteúdo diferente (eles ganham mtime novo, então o make
# recompila só esses) e apaga os que saíram da fonte (o Makefile compila MGL/src/* por curinga). Não mexe no
# build/, nas dependências baixadas nem nos links que o Makefile cria. Deixa as contagens em NCHG e NDEL.
sync_tree() {
  local src=$1 dst=$2 f
  NCHG=0; NDEL=0
  mkdir -p "$dst" || return 1
  while IFS= read -r f; do
    if ! cmp -s "$src/$f" "$dst/$f"; then
      mkdir -p "$dst/${f:h}" && cp "$src/$f" "$dst/$f" || return 1
      NCHG=$((NCHG + 1))
    fi
  done < <(cd "$src" && find . -type f | sed 's|^\./||')
  while IFS= read -r f; do
    if [[ ! -e $src/$f ]]; then rm -f "$dst/$f" && NDEL=$((NDEL + 1)); fi
  done < <(cd "$dst" && find . \( -path ./build -o -path './lib*.dylib' -o -path ./external/glfw/build \
             -o -path ./external/OpenGL-Registry -o -path ./external/SPIRV-Cross -o -path ./external/SPIRV-Headers \
             -o -path ./external/SPIRV-Tools -o -path ./external/ezxml -o -path ./external/glslang \) -prune \
             -o -type f -print | sed 's|^\./||')
}

# cmake do sistema, ou um standalone baixado uma vez (só é preciso para compilar as dependências).
ensure_cmake() {
  if command -v cmake >/dev/null; then echo "cmake: $(cmake --version | head -1) (sistema)"; return 0; fi
  local cm="$TOOLS/cmake/CMake.app/Contents/bin/cmake"
  if [[ ! -x $cm ]]; then
    echo "== baixando cmake $CMVER (uma vez)"; mkdir -p "$TOOLS/cmake"
    curl -fL -o "$TOOLS/cmake.tgz" "https://github.com/Kitware/CMake/releases/download/v$CMVER/cmake-$CMVER-macos-universal.tar.gz" &&
      tar xzf "$TOOLS/cmake.tgz" -C "$TOOLS/cmake" --strip-components=1
  fi
  [[ -x $cm ]] || { echo "FALHA ao obter o cmake"; return 1; }
  export PATH="${cm:h}:$PATH"; echo "cmake: $($cm --version | head -1) (baixado)"
}

{
  echo "== $(date '+%d/%m %H:%M')  MGL do VostroXe (src/MGL)"
  [[ $(uname) == Darwin ]] || { echo "rode no macOS"; exit 1; }
  echo "macOS $(sw_vers -productVersion 2>/dev/null) ($(sw_vers -buildVersion 2>/dev/null)), arch $(uname -m)"
  for t in make clang git curl python3; do command -v $t >/dev/null && echo "  $t: ok" || echo "  $t: FALTA (rode: xcode-select --install)"; done

  # ---- fonte: o checkout do VostroXe, ou o mgl-src.tar.gz do pendrive ----
  if [[ -f $HERE/../src/MGL/Makefile ]]; then
    MGLSRC=${HERE:h}/src/MGL
    echo "== fonte: $MGLSRC (checkout do VostroXe, commit $(git -C "$MGLSRC" rev-parse --short HEAD 2>/dev/null || echo '?'))"
  elif [[ -f $TARBALL ]]; then
    echo "== fonte: $TARBALL -> $COPY"
    STAGE=$(mktemp -d -t mglsrc) || exit 1
    if ! tar -xzf "$TARBALL" -C "$STAGE"; then echo "não consegui extrair $TARBALL"; rm -rf "$STAGE"; exit 1; fi
    if ! sync_tree "$STAGE" "$COPY"; then echo "falha ao copiar a fonte para $COPY"; rm -rf "$STAGE"; exit 1; fi
    rm -rf "$STAGE"
    MGLSRC=$COPY
    echo "   commit $(head -c 12 "$COPY/.vostroxe-commit" 2>/dev/null || echo '?'): $NCHG arquivo(s) novo(s) ou mudado(s), $NDEL removido(s)"
  elif [[ -f $COPY/Makefile ]]; then
    MGLSRC=$COPY
    echo "== fonte: $COPY (cópia anterior; não achei $TARBALL)"
  else
    echo "não achei a fonte do MGL: nem src/MGL (checkout do VostroXe) nem $TARBALL"; exit 1
  fi

  # ---- dependências: reaproveitar as de ~/MGL, ou baixar e compilar ----
  cd "$MGLSRC/external" || { echo "sem $MGLSRC/external"; exit 1; }
  for d in $DEPS; do
    if [[ ! -e $d && -d $OLD/external/$d ]]; then ln -s "$OLD/external/$d" "$d" && echo "== reaproveitando $OLD/external/$d"; fi
  done
  if [[ ! -e glfw/build && -f $OLD/external/glfw/build/src/libglfw3.a ]]; then
    ln -s "$OLD/external/glfw/build" glfw/build && echo "== reaproveitando $OLD/external/glfw/build (libglfw3.a)"
  fi
  if deps_built; then
    echo "== dependências já compiladas (pulando clone_external.sh e build_external.sh)"
  else
    online || { echo "as dependências não estão compiladas e não há internet: ligue o cabo de rede e rode de novo"; exit 1; }
    missing=(); for d in $DEPS; do [[ -e $d ]] || missing+=($d); done
    if (( ${#missing} )); then echo "== baixando dependências (clone_external.sh): ${missing[*]}"; bash clone_external.sh 2>&1 | tail -12; fi
    ensure_cmake || exit 1
    echo "== compilando dependências (build_external.sh) — vários minutos; log em ${DEPLOG:t}"
    bash build_external.sh > "$DEPLOG" 2>&1; echo "   build_external rc=$? ; últimas linhas:"; tail -20 "$DEPLOG"
    # build_external.sh copia MGL/include/MGL{Context,Renderer}.h por cima das cópias versionadas em glfw/src
    git -C "$MGLSRC" checkout -- external/glfw/src/MGLContext.h external/glfw/src/MGLRenderer.h 2>/dev/null
    deps_built || { echo "as dependências não compilaram: me mande o ${DEPLOG:t}"; exit 1; }
  fi

  # ---- MGL ----
  cd "$MGLSRC" || exit 1
  echo "== compilando o MGL (make) — log em ${MAKELOG:t}"
  make -j4 > "$MAKELOG" 2>&1; rc=$?
  echo "   make rc=$rc ; últimas linhas:"; tail -25 "$MAKELOG" | cut -c1-300
  (( rc )) && err=1

  echo "== resultado ($MGLSRC/build):"
  for f in build/libmgl.dylib build/libmgl_es.dylib build/libglfw.dylib; do
    [[ -f $f ]] && echo "OK  $f ($(( $(stat -f %z "$f") / 1048576 )) MB)" || { echo "FALTOU  $f"; err=1; }
  done
  if [[ -f build/libmgl.dylib ]]; then
    ngl=$(nm -gU build/libmgl.dylib 2>/dev/null | grep -cE ' _gl[A-Z]')
    echo "funções gl* exportadas pelo libmgl.dylib: $ngl"
    (( ngl > 0 )) || { echo "   0 = o gl_core.o ficou fora da lib"; err=1; }
    echo "== otool libmgl.dylib:"; otool -L build/libmgl.dylib 2>/dev/null | grep -iE 'Metal|OpenGL|Foundation' | head
  fi
  echo
  (( err )) && echo ">>> algo não compilou. Me mande: mgl-build-log.txt, mgl-deps-log.txt e mgl-make-log.txt" \
            || echo ">>> MGL do VostroXe COMPILOU. Agora rode o TESTAR-MGL e o TRIANGULO-MGL."
} 2>&1 | tee "$LOG"
echo; echo "logs: $LOG  (+ ${DEPLOG:t}, ${MAKELOG:t})"
