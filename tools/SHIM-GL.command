#!/bin/zsh
# Dois cliques no Finder (macOS): prova o shim que desvia o OpenGL de apps nativos para o MGL.
# Roda a mesma sonda NSOpenGLView duas vezes (sem e com o shim) e mostra o GL_RENDERER virar de
# "Apple Software Renderer" para "MGL". Precisa ter rodado o COMPILAR-MGL antes.
D=${0:A:h}
S=""
for cand in "$D/mgl-shim.sh" "$D/emulador/mgl-shim.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o mgl-shim.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== Shim do MGL: desviar o OpenGL de apps nativos (NSOpenGLContext) para o MGL"
echo "Roda uma sonda NSOpenGLView duas vezes: sem o shim (OpenGL da Apple) e com o shim (MGL)."
echo "Na segunda, uma janela deve abrir com o triângulo desenhado pela Iris Xe."
echo
zsh "$S" "$D/mgl-shim-log.txt"
echo
echo "Pronto. Me diga o que viu na tela e me mande o mgl-shim-log.txt (e o mgl-shim-log-mgl.txt)."
read -k 1 "?Aperte uma tecla para fechar. "
