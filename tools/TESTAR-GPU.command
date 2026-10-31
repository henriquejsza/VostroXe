#!/bin/zsh
# Dois cliques no Finder (macOS): testa o emulador pela GPU (Vulkan por MoltenVK -> Metal) em vez do SwiftShader (CPU).
# Não altera nada permanente: só lança este teste com a variável ANDROID_EMU_VK_ICD=moltenvk e -gpu host.
# Funciona do pendrive (ao lado da pasta emulador/) ou de ~/xe-tools (ao lado do emulador-android.sh).
D=${0:A:h}
S=""
for cand in "$D/emulador-android.sh" "$D/emulador/emulador-android.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o emulador-android.sh (nem ao lado, nem em emulador/). Pasta: $D"
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
LOG="$D/emulador-gpu.txt"
echo "== $(date '+%d/%m %H:%M') teste de GPU (MoltenVK)   (script: $S)" | tee "$LOG"
echo "Feche a janela do emulador se estiver aberta. Vou abrir um boot a frio pela GPU." | tee -a "$LOG"
zsh "$S" testar-gpu 2>&1 | tee -a "$LOG"
klog=( "$HOME/Library/Logs/xe-emulador/"*gpu*.txt(.Nom) )
[[ -n ${klog[1]} ]] && cp "${klog[1]}" "$D/emulador-gpu-boot.txt"
echo
echo "Pronto. Resumo: $LOG"
[[ -n ${klog[1]} ]] && echo "Log completo: $D/emulador-gpu-boot.txt"
echo "Me diga se a tela ficou mais rápida/fluida; e mande o emulador-gpu-boot.txt."
read -k 1 "?Aperte uma tecla para fechar. "
