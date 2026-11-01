#!/bin/zsh
# Dois cliques (macOS): DESFAZ o teste de permissões — volta o boot para o config acelerado de sempre
# (config-seq-hdmi, com amfi_get_out_of_my_way=1) e restaura o NootedGreen.kext anterior. Pede a senha uma vez.
D=${0:A:h}
{
echo "== $(date '+%d/%m %H:%M:%S') revertendo o teste de library validation"
echo "== senha do macOS (uma vez):"; sudo -v || exit 1
M=/tmp/xe-esp; mkdir -p $M; ok=0
for p in $(diskutil list | awk '/ EFI / {print $NF}'); do
  sudo diskutil mount -mountPoint $M $p >/dev/null 2>&1 || continue
  if [[ -f $M/EFI/OC/config-install.plist && -d $M/EFI/Manjaro ]]; then
    if [[ -f $M/EFI/OC/config-seq-hdmi.plist ]]; then
      sudo cp -X "$M/EFI/OC/config-seq-hdmi.plist" "$M/EFI/OC/config.plist" && ok=1 \
        && echo "   config.plist <- config-seq-hdmi.plist (acelerado + HDMI, amfi de volta)"
    elif [[ -f $M/EFI/OC/config-antes-lv.bak.plist ]]; then
      sudo cp -X "$M/EFI/OC/config-antes-lv.bak.plist" "$M/EFI/OC/config.plist" && ok=1 \
        && echo "   config.plist <- config-antes-lv.bak.plist"
    fi
    if [[ -d $M/EFI/OC/Kexts/NootedGreen.kext.lvbak ]]; then
      sudo rm -rf "$M/EFI/OC/Kexts/NootedGreen.kext" \
        && sudo cp -R "$M/EFI/OC/Kexts/NootedGreen.kext.lvbak" "$M/EFI/OC/Kexts/NootedGreen.kext" \
        && echo "   NootedGreen.kext restaurado do backup (.lvbak)"
    fi
  fi
  sync; sudo diskutil unmount $M >/dev/null 2>&1
  (( ok )) && break
done
(( ok )) || { echo ">>> não achei o EFI/config para reverter. Me avise."; exit 1; }
echo ">>> PRONTO. Reinicie e escolha o macOS: voltou para o acelerado de sempre."
} 2>&1 | tee "$D/seq-lv-reverter-log.txt"
read -k 1 "?Aperte uma tecla para fechar. "
