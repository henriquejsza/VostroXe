#!/bin/zsh
# Dois cliques (macOS): GAMBIARRA pra testar GPU — faz o "ICD do swiftshader" do emulador apontar pro MoltenVK
# (Vulkan -> Metal) SÓ durante este teste, e restaura no fim. Experimental: pode travar/dar tela preta.
# Funciona do pendrive (ao lado da pasta emulador/) ou de ~/xe-tools.
D=${0:A:h}
S=""
for cand in "$D/emulador-android.sh" "$D/emulador/emulador-android.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o emulador-android.sh (nem ao lado, nem em emulador/). Pasta: $D"
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
LOG="$D/emulador-gpuhack.txt"
echo "== $(date '+%d/%m %H:%M') teste GPU GAMBIARRA (MoltenVK)   (script: $S)" | tee "$LOG"
echo "Feche a janela do emulador se estiver aberta. Isto é experimental." | tee -a "$LOG"
zsh "$S" testar-gpu-hack 2>&1 | tee -a "$LOG"
# rede de segurança: garante que o ICD voltou ao normal
zsh "$S" restaurar-icd 2>&1 | tee -a "$LOG"
klog=( "$HOME/Library/Logs/xe-emulador/"*gpuhack*.txt(.Nom) )
[[ -n ${klog[1]} ]] && cp "${klog[1]}" "$D/emulador-gpuhack-boot.txt"
echo
echo "Pronto. Resumo: $LOG"
[[ -n ${klog[1]} ]] && echo "Log completo: $D/emulador-gpuhack-boot.txt"
echo "Me diga se abriu e se ficou fluido; e mande o emulador-gpuhack-boot.txt."
read -k 1 "?Aperte uma tecla para fechar. "
