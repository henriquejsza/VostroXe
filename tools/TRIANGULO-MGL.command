#!/bin/zsh
# Dois cliques (macOS): desenha o triângulo RGB na GPU (Iris Xe) via MGL e salva uma imagem BMP.
# Precisa ter rodado o COMPILAR-MGL antes.
D=${0:A:h}
S=""
for cand in "$D/mgl-triangle.sh" "$D/emulador/mgl-triangle.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o mgl-triangle.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== Triângulo RGB na GPU (MGL, offscreen -> imagem)"
zsh "$S" "$D/mgl-triangle-log.txt" "$D/mgl-triangulo.bmp"
echo
echo "Pronto. Abra a imagem: $D/mgl-triangulo.bmp"
echo "Log: $D/mgl-triangle-log.txt — me mande a imagem e o log."
read -k 1 "?Aperte uma tecla para fechar. "
