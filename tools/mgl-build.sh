#!/bin/zsh
# GL geral via MGL (OpenGL 4.6 / ES 3.x -> Metal) no Vostro 3520.
# Passo 1: clonar e compilar o MGL, e listar o que foi gerado. Roda no macOS, no Terminal:
#     zsh /Volumes/MACINSTALL/mgl-build.sh
# Grava um log ao lado (no pendrive) pra eu ler do Linux. Não mexe no sistema; só compila na sua pasta.
set -u
SELF=${0:A}; HERE=${SELF:h}
LOG="${1:-$HERE/mgl-build-log.txt}"
MGLDIR="$HOME/MGL"
{
  echo "== $(date '+%d/%m %H:%M')  MGL build"
  echo "macOS: $(sw_vers -productName 2>/dev/null) $(sw_vers -productVersion 2>/dev/null) ($(sw_vers -buildVersion 2>/dev/null))"
  echo "arch: $(uname -m)"
  if ! command -v git >/dev/null; then echo "FALTA git -> rode: xcode-select --install"; exit 1; fi
  echo "xcodebuild: $(xcodebuild -version 2>&1 | tr '\n' ' ')"
  echo "clang: $(clang --version 2>/dev/null | head -1)"
  echo "== GPU (Metal):"; system_profiler SPDisplaysDataType 2>/dev/null | grep -iE 'Chipset|Vendor|Metal|Device ID|VRAM' | head
  echo
  if [[ -d $MGLDIR/.git ]]; then
    echo "== MGL já clonado em $MGLDIR; atualizando"; ( cd "$MGLDIR" && git pull --ff-only 2>&1 | tail -3 )
  else
    echo "== clonando MGL em $MGLDIR (com submódulos)"; git clone --recurse-submodules https://github.com/openglonmetal/MGL.git "$MGLDIR" 2>&1 | tail -8 || { echo "CLONE FALHOU"; exit 1; }
  fi
  cd "$MGLDIR" || { echo "sem $MGLDIR"; exit 1; }
  echo "== conteúdo do repo:"; ls -1 | tr '\n' ' '; echo
  echo "== tem Makefile?"; [[ -f Makefile ]] && echo "sim" || echo "não"
  echo "== schemes/targets do Xcode:"; xcodebuild -list -project MGL.xcodeproj 2>&1 | head -40
  echo
  echo "== TENTATIVA 1: make (se houver Makefile):"
  if [[ -f Makefile ]]; then make 2>&1 | tail -30; else echo "(sem Makefile, pulando)"; fi
  echo
  echo "== TENTATIVA 2: xcodebuild do scheme MGL (Release):"
  xcodebuild -project MGL.xcodeproj -scheme MGL -configuration Release -derivedDataPath "$MGLDIR/DerivedData" build 2>&1 | tail -35
  echo
  echo "== o que foi gerado (dylib/framework/binários de teste):"
  find "$MGLDIR" "$HOME/Library/Developer/Xcode/DerivedData" -maxdepth 6 \( -name 'libMGL*.dylib' -o -name 'MGL.framework' -o -name 'libmgl*' -o -name 'test_mgl' -o -name '*MGL*.app' \) 2>/dev/null | sed "s#$HOME#~#" | head -20
  echo
  echo "== FIM. Me mande este arquivo:  $LOG"
} 2>&1 | tee "$LOG"
echo
echo "pronto; log salvo em: $LOG"
