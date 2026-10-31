#!/bin/zsh
# Dois cliques (macOS): abre uma janela OpenGL na tela pela GLFW do MGL, desenhando na GPU (Iris Xe).
# Precisa ter rodado o COMPILAR-MGL antes.
D=${0:A:h}
S=""
for cand in "$D/mgl-window.sh" "$D/emulador/mgl-window.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o mgl-window.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== Janela OpenGL na tela (GLFW do MGL)"
echo "Vai abrir uma janela por uns 6 segundos. Olhe para ela: deve mostrar um triângulo"
echo "vermelho/verde/azul e o fundo pulsando entre azul escuro e azul."
echo
zsh "$S" "$D/mgl-window-log.txt"
echo
echo "Pronto. Me diga o que você viu na janela e me mande o mgl-window-log.txt (e o mgl-window-log-mgl.txt)."
read -k 1 "?Aperte uma tecla para fechar. "
