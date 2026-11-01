#!/bin/zsh
# Dois cliques (macOS, no boot normal, que está SEGURO): corrige o libxedrv para o Sequoia.
#  1. guarda os logs do boot acelerado que deu tela preta;  2. recompila o driver Metal com a fonte nova (sem internet);
#  3. testa a correção no Metal deste macOS;  4. SÓ se o teste passar: instala o driver Metal corrigido e liga a config
#     acelerada no EFI do SSD.  Pede a SENHA uma vez.  Se o boot acelerado travar: reinicie e escolha Linux no menu.
D=${0:A:h}
DEST="$HOME/VostroXe-src"
T="$D/vostroxe-src.tar.gz"
{
echo "== $(date '+%d/%m %H:%M:%S')  macOS $(sw_vers -productVersion) ($(sw_vers -buildVersion))"
[[ -f $T ]] || { echo "não achei $T"; exit 1; }
[[ -f $DEST/install.sh ]] || { echo "não achei $DEST (rode antes o INSTALAR-SEQUOIA)"; exit 1; }
echo "== senha do macOS (uma vez):"; sudo -v || exit 1

echo "== 1/4 logs do boot acelerado de 31/10 (kernel + WindowServer) -> accel-boot1-log.txt"
sudo log show --start "2026-10-31 23:45:00" --end "2026-11-01 00:05:00" --style compact \
  --predicate '(process == "kernel" AND (eventMessage CONTAINS[c] "ngreen" OR eventMessage CONTAINS "XeNG" OR eventMessage CONTAINS "DYLD" OR eventMessage CONTAINS "Lilu" OR eventMessage CONTAINS "AppleIntel" OR eventMessage CONTAINS "IGFB")) OR eventMessage CONTAINS "xedrv"' \
  > "$D/accel-boot1-log.txt" 2>&1
echo "   $(wc -l < "$D/accel-boot1-log.txt" | tr -d ' ') linhas"

echo "== 2/4 fonte nova e build do driver Metal"
tar xzf "$T" -C "$DEST" || { echo "falha ao extrair"; exit 1; }
cd "$DEST" || exit 1
echo "   versão: $(cat .vostroxe-commit 2>/dev/null)"
SLE=$DEST/build/deps/NootedGreen/sle_Internal/sle
zsh macos/build-all.sh "$SLE" > "$D/seq-atualizar-build.txt" 2>&1 || { echo "BUILD FALHOU (seq-atualizar-build.txt):"; tail -15 "$D/seq-atualizar-build.txt"; exit 1; }
B=$DEST/macos/out/AppleIntelTGLGraphicsMTLDriver.bundle
L=$B/Contents/MacOS/libxedrv.dylib
[[ -f $L ]] || { echo "sem $L"; exit 1; }
echo "   ok"

echo "== 3/4 teste do layout do Metal deste macOS"
clang -fobjc-arc -framework Foundation -framework Metal macos/src/xe-preflight.m -o /tmp/xe-preflight || { echo "falha ao compilar o teste"; exit 1; }
rm -f /tmp/xedrv-xe-preflight.log
/tmp/xe-preflight "$L"; sleep 1
cp /tmp/xedrv-xe-preflight.log "$D/seq-preflight-log.txt" 2>/dev/null
grep -E 'layout' /tmp/xedrv-xe-preflight.log 2>/dev/null | sed -E 's/^[0-9]+ /   /'
if ! grep -q 'layout: Sequoia -> conversão ligada' /tmp/xedrv-xe-preflight.log 2>/dev/null; then
  echo ">>> o teste NÃO passou: nada foi instalado e o boot continua seguro. Volte pro Linux e me avise."
  exit 1
fi

echo "== 4/4 instalando o driver Metal corrigido em /Library/GPUBundles"
G=/Library/GPUBundles/AppleIntelTGLGraphicsMTLDriver.bundle
sudo rm -rf "$G" && sudo ditto "$B" "$G" && sudo chown -R root:wheel "$G" || { echo "falha ao instalar"; exit 1; }
echo "   libxedrv md5 $(md5 -q "$G/Contents/MacOS/libxedrv.dylib")"
echo "== ligando a config acelerada no EFI do SSD"
M=/tmp/xe-esp; mkdir -p $M; ok=0
for p in $(diskutil list | awk '/ EFI / {print $NF}'); do
  sudo diskutil mount -mountPoint $M $p >/dev/null 2>&1 || continue
  if [[ -f $M/EFI/OC/config-seq.plist && -f $M/EFI/OC/config-install.plist && -d $M/EFI/Manjaro ]]; then
    sudo cp -X $M/EFI/OC/config.plist $M/EFI/OC/config-antes-acel.bak.plist &&
    sudo cp -X $M/EFI/OC/config-seq.plist $M/EFI/OC/config.plist && ok=1
    (( ok )) && echo "   $p: config.plist <- config-seq.plist (cópia da anterior: config-antes-acel.bak.plist)"
  fi
  sync; sudo diskutil unmount $M >/dev/null 2>&1
  (( ok )) && break
done
(( ok )) || { echo ">>> não achei o EFI do SSD: o driver foi instalado, mas o boot continua SEGURO. Me avise."; exit 1; }
echo
echo ">>> PRONTO. Reinicie e escolha o macOS no menu do OpenCore (modo verboso)."
echo ">>> Se ficar preto ou travar: reinicie, escolha Linux no menu e me avise."
} 2>&1 | tee "$D/seq-atualizar-log.txt"
read -k 1 "?Aperte uma tecla para fechar. "
