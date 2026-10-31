#!/bin/zsh
# Dois cliques no Finder (macOS): compila o MGL (OpenGL 4.6 -> Metal) e salva o log ao lado.
# Precisa do Xcode instalado (não só as Command Line Tools), pois o MGL é um projeto .xcodeproj.
D=${0:A:h}
S=""
for cand in "$D/mgl-build.sh" "$D/emulador/mgl-build.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o mgl-build.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== Compilar MGL (OpenGL -> Metal)"
echo "Pode demorar alguns minutos na 1a vez (clona e compila). Precisa do Xcode instalado."
echo
zsh "$S" "$D/mgl-build-log.txt"
echo
echo "Pronto. Log salvo em: $D/mgl-build-log.txt  — me mande esse arquivo."
read -k 1 "?Aperte uma tecla para fechar. "
