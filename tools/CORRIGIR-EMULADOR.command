#!/bin/zsh
# Dois cliques no Finder (no macOS): aplica a correção do emulador do Android e o abre num boot a frio.
# Fica ao lado do emulador-android.sh (ex.: ~/xe-tools/). Não precisa de pendrive nem de senha.
D=${0:A:h}
S="$D/emulador-android.sh"
LOG="$D/emulador-status.txt"
if [[ ! -x $S ]]; then
  echo "não achei o emulador-android.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
{
  echo "== $(date '+%d/%m %H:%M') corrigir"
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
