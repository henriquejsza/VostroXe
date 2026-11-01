#!/bin/zsh
# Dois cliques (macOS): TESTE das permissões nativas (microfone/câmera/tela) SEM perder a aceleração.
# O que faz, pedindo a senha UMA vez:
#   1. compila o NootedGreen novo (com o patch de library validation, ligado só por ngreenlv=1);
#   2. instala esse kext no EFI do SSD (guarda o antigo em NootedGreen.kext.lvbak);
#   3. liga um config de teste (config-seq-lv) que TIRA amfi_get_out_of_my_way=1 e põe ngreenlv=1.
# SEGURANÇA: o config acelerado de sempre (config-seq-hdmi) e o Linux continuam no menu do OpenCore.
#   Se a tela ficar preta / sem aceleração: reinicie, escolha Linux, e rode REVERTER-LV.command (ou me avise).
D=${0:A:h}
DEST="$HOME/VostroXe-src"
T="$D/vostroxe-src.tar.gz"
LV="$D/config-seq-lv.plist"
{
echo "== $(date '+%d/%m %H:%M:%S')  macOS $(sw_vers -productVersion) ($(sw_vers -buildVersion))"
[[ -f $T ]]  || { echo "não achei vostroxe-src.tar.gz ao lado deste arquivo"; exit 1; }
[[ -f $LV ]] || { echo "não achei config-seq-lv.plist ao lado deste arquivo"; exit 1; }
echo "== senha do macOS (uma vez):"; sudo -v || exit 1

echo "== 1/4 fonte nova -> $DEST"
mkdir -p "$DEST" && tar xzf "$T" -C "$DEST" || { echo "falha ao extrair"; exit 1; }
cd "$DEST" || exit 1
echo "   versão: $(cat .vostroxe-commit 2>/dev/null)"
echo "   internet: $(curl -sI -m 10 https://github.com >/dev/null 2>&1 && echo OK || echo 'SEM ACESSO — ligue o cabo/ancoragem: o build baixa MacKernelSDK + Lilu na 1a vez')"

echo "== 2/4 compilando o NootedGreen.kext (patch de library validation)"
zsh build-nootedgreen.sh > "$D/seq-lv-build.txt" 2>&1 || { echo "BUILD FALHOU (veja seq-lv-build.txt):"; tail -15 "$D/seq-lv-build.txt"; exit 1; }
K="$DEST/build/NootedGreen.kext"
[[ -d $K ]] || { echo "sem $K após o build"; exit 1; }
echo "   ok: build/NootedGreen.kext"

echo "== 3/4 confirmação"
echo "   Isto vai TROCAR o boot para o config de teste (sem amfi, com ngreenlv=1)."
echo -n "   Digite S e Enter para continuar (qualquer outra coisa cancela): "; read resp
[[ ${resp:l} == s ]] || { echo "   cancelado. Nada mudou no boot."; exit 0; }

echo "== 4/4 instalando o kext e ligando o config de teste no EFI do SSD"
M=/tmp/xe-esp; mkdir -p $M; ok=0
for p in $(diskutil list | awk '/ EFI / {print $NF}'); do
  sudo diskutil mount -mountPoint $M $p >/dev/null 2>&1 || continue
  if [[ -f $M/EFI/OC/config-install.plist && -d $M/EFI/Manjaro ]]; then
    sudo rm -rf "$M/EFI/OC/Kexts/NootedGreen.kext.lvbak"
    sudo cp -R "$M/EFI/OC/Kexts/NootedGreen.kext" "$M/EFI/OC/Kexts/NootedGreen.kext.lvbak" 2>/dev/null
    sudo rm -rf "$M/EFI/OC/Kexts/NootedGreen.kext" && sudo cp -R "$K" "$M/EFI/OC/Kexts/NootedGreen.kext" \
      || { echo "falha ao instalar o kext"; sync; sudo diskutil unmount $M >/dev/null 2>&1; exit 1; }
    sudo cp -X "$LV" "$M/EFI/OC/config-seq-lv.plist"
    sudo cp -X "$M/EFI/OC/config.plist" "$M/EFI/OC/config-antes-lv.bak.plist"
    sudo cp -X "$M/EFI/OC/config-seq-lv.plist" "$M/EFI/OC/config.plist"
    ok=1
    echo "   $p: NootedGreen.kext novo + config.plist <- config-seq-lv (backup: config-antes-lv.bak.plist / NootedGreen.kext.lvbak)"
  fi
  sync; sudo diskutil unmount $M >/dev/null 2>&1
  (( ok )) && break
done
(( ok )) || { echo ">>> não achei o EFI do SSD. Nada mudou no boot. Me avise."; exit 1; }
echo
echo ">>> PRONTO. Reinicie e escolha o macOS (verboso)."
echo ">>> Teste: abra um app de terceiros (Discord/OBS) e veja se aparece o PEDIDO de microfone;"
echo ">>>        e confira em Ajustes do Sistema > Privacidade e Segurança > Microfone."
echo ">>> Se ficar preto / sem aceleração: reinicie, escolha Linux, rode REVERTER-LV.command (ou me avise)."
} 2>&1 | tee "$D/seq-lv-log.txt"
read -k 1 "?Aperte uma tecla para fechar. "
