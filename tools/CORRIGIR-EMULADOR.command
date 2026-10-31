#!/bin/zsh
# Dois cliques no Finder (macOS): aplica a correção do emulador do Android e o abre num boot a frio.
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
LOG="$D/emulador-status.txt"
{
  echo "== $(date '+%d/%m %H:%M') corrigir   (script: $S)"
  zsh "$S" corrigir
  echo
  zsh "$S" status
} 2>&1 | tee "$LOG"
echo
echo "Vou abrir o emulador num boot a frio. Espere ATÉ 5 min pelo logo do Android; depois FECHE a janela dele."
zsh "$S" testar 2>&1 | tee -a "$LOG"
klog=( "$HOME/Library/Logs/xe-emulador/"*.txt(.Nom) )
[[ -n ${klog[1]} ]] && cp "${klog[1]}" "$D/emulador-boot.txt"
echo
echo "Pronto. Relatório: $LOG"
[[ -n ${klog[1]} ]] && echo "Log do kernel do Android: $D/emulador-boot.txt"
read -k 1 "?Aperte uma tecla para fechar. "
