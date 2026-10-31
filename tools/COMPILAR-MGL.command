#!/bin/zsh
# Dois cliques no Finder (macOS): compila o MGL do VostroXe (OpenGL 4.6 -> Metal) e salva o log ao lado.
# Precisa só das Command Line Tools (xcode-select --install), não do Xcode.
D=${0:A:h}
S=""
for cand in "$D/mgl-build.sh" "$D/emulador/mgl-build.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o mgl-build.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== Compilar o MGL do VostroXe (OpenGL -> Metal)"
echo "Reaproveita as dependências já compiladas em ~/MGL. Sem elas, precisa de internet (cabo) e demora vários minutos."
echo
zsh "$S" "$D/mgl-build-log.txt"
echo
echo "Pronto. Log salvo em: $D/mgl-build-log.txt  — me mande esse arquivo."
read -k 1 "?Aperte uma tecla para fechar. "
