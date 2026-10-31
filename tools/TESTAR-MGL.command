#!/bin/zsh
# Dois cliques (macOS): testa se o MGL desenha na GPU (passo 2). Precisa ter rodado o COMPILAR-MGL antes.
D=${0:A:h}
S=""
for cand in "$D/mgl-test.sh" "$D/emulador/mgl-test.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o mgl-test.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== Teste do MGL na GPU (headless, rápido)"
zsh "$S" "$D/mgl-test-log.txt"
echo
echo "Pronto. Log: $D/mgl-test-log.txt — me mande esse arquivo."
read -k 1 "?Aperte uma tecla para fechar. "
