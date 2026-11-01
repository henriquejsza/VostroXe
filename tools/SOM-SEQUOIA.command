#!/bin/zsh
# Dois cliques (macOS Sequoia): som interno e microfone (CS8409HDA + XeSpeakers). Pede a SENHA uma vez.
#  1. confere que só o CS8409HDA está no controlador de áudio (o AppleHDAController da Apple não pode estar junto)
#  2. compila o cs8409ctl e o XeSpeakers (sem internet; o kext é o do EFI)
#  3. autoteste: VAI TOCAR BIPES nos alto-falantes, gravados pelo microfone interno
#  4. instala o dispositivo de som do macOS: "Alto-falantes internos" e "Microfone interno"
#  5. opcional: libera o microfone para o Google Chrome
# Tudo vai para som-seq-log.txt no pendrive, com os relatórios do autoteste.
D=${0:A:h}
DEST="$HOME/VostroXe-src"
T="$D/vostroxe-som.tar.gz"
{
echo "== $(date '+%d/%m %H:%M:%S')  macOS $(sw_vers -productVersion) ($(sw_vers -buildVersion))"
[[ -f $T ]] || { echo "não achei $T"; exit 1; }
echo "== senha do macOS (uma vez):"; sudo -v || exit 1
mkdir -p "$DEST" && tar xzf "$T" -C "$DEST" || { echo "falha ao extrair"; exit 1; }
cd "$DEST" || exit 1
echo "   versão: $(cat .vostroxe-som-commit 2>/dev/null)"

echo; echo "== 1/5 drivers no controlador de áudio (8086:51C8)"
kmutil showloaded 2>/dev/null | awk '/CS8409|AppleHDA|IOHDAFamily/ {print "   carregado: "$6" "$7}'
ioreg -p IOService -w0 2>/dev/null | grep -E -B2 -A1 'class (CS8409HDA|AppleHDAController)[,>]' | sed 's/^/   /'
I=$(ioreg -r -c CS8409HDA -d 1 2>/dev/null | awk -F'= ' '/"AudShimInterface"/ {print $2}')
if ioreg -r -c AppleHDAController -d 1 2>/dev/null | grep -q AppleHDAController; then
  echo "   ✗ o AppleHDAController (Apple) está ligado no controlador:"
  ioreg -r -c AppleHDAController -d 1 -w0 2>/dev/null | head -5 | sed 's/^/     /'
  echo ">>> parei antes de tocar no hardware. Volte pro Linux e me avise."
  exit 1
fi
[[ -n $I ]] || { echo "   ✗ o CS8409HDA não está ligado no controlador. Volte pro Linux e me avise."; exit 1; }
echo "   ✓ só o CS8409HDA (interface v$I; v9 = alto-falantes + microfone)"

echo; echo "== 2/5 compilando o cs8409ctl e o XeSpeakers"
B=$DEST/tools/build; mkdir -p "$B"
clang -O2 -Wall -o "$B/cs8409ctl" tools/CS8409HDA/cs8409ctl.c -framework IOKit -framework CoreFoundation || { echo "   ✗ falha no cs8409ctl"; exit 1; }
zsh tools/XeSpeakers/build.sh >/dev/null || { echo "   ✗ falha no XeSpeakers"; exit 1; }
codesign -v "$B/XeSpeakers.driver" || { echo "   ✗ assinatura do XeSpeakers"; exit 1; }
echo "   ✓ ok"

echo; echo "== 3-4/5 autoteste (bipes) e dispositivo de som"
zsh tools/CS8409HDA/macos/audio.sh test; RC=$?
R=$(ls -t "$HOME"/Library/Logs/CS8409HDA/report-*.txt 2>/dev/null | grep -vE -- '-(log|hal)\.txt$' | head -1)
[[ -n $R ]] && cp -X "${R%.txt}"*.txt "$D/" 2>/dev/null && echo "   relatórios no pendrive: ${R:t:r}*.txt"
(( RC == 0 )) || { echo ">>> o autoteste ou a instalação falhou (detalhes acima). Volte pro Linux e me avise."; exit 1; }
echo; echo "== dispositivos de som:"
system_profiler SPAudioDataType 2>/dev/null | grep -E '^ {8}[^ ].*:$|Default (Output|Input) Device|Input Channels|Output Channels' | sed 's/^ */   /'

echo; echo "== 5/5 microfone para o Google Chrome (o macOS não mostra o pedido de permissão para apps de terceiros)"
if [[ -d "/Applications/Google Chrome.app" ]]; then
  read -k 1 "r?   liberar o microfone para o Google Chrome? (s/n) "; echo
  if [[ $r == [sS] ]]; then
    sudo zsh tools/tcc-permitir.sh microfone "Google Chrome" ||
      echo "   ✗ não deu para gravar a permissão: ligue o Terminal em Ajustes do Sistema › Privacidade e Segurança › Acesso Total ao Disco e rode este arquivo de novo"
  fi
else
  echo "   (Google Chrome não instalado)"
fi
echo
echo "== assinatura do CS8409HDA.kext com o Info.plist novo (para o repositório; não muda o código)"
S=/tmp/cs8409-assinar; rm -rf "$S"; mkdir -p "$S"
if ditto EFI/OC/Kexts/CS8409HDA.kext "$S/CS8409HDA.kext" && codesign -f -s - "$S/CS8409HDA.kext" 2>/dev/null &&
   codesign -v "$S/CS8409HDA.kext"; then
  rm -rf "$D/CS8409HDA-assinado.kext"
  ditto --norsrc --noextattr --noqtn "$S/CS8409HDA.kext" "$D/CS8409HDA-assinado.kext" && echo "   ✓ CS8409HDA-assinado.kext no pendrive"
else
  echo "   (não deu para assinar; não afeta o som)"
fi
echo
echo ">>> PRONTO. Volume começa em 30%. Em Ajustes do Sistema › Som: saída \"Alto-falantes internos\", entrada \"Microfone interno\"."
} 2>&1 | tee "$D/som-seq-log.txt"
read -k 1 "?Aperte uma tecla para fechar. "
