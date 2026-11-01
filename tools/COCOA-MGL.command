#!/bin/zsh
# Dois cliques no Finder (macOS): abre uma janela Cocoa nativa (sem GLFW) e desenha o triângulo pela Iris Xe (MGL).
# É o teste do caminho dos apps nativos do Mac. Precisa ter rodado o COMPILAR-MGL antes.
D=${0:A:h}
S=""
for cand in "$D/mgl-cocoa.sh" "$D/emulador/mgl-cocoa.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o mgl-cocoa.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== Janela Cocoa nativa pelo MGL (sem GLFW)"
echo "Uma janela abre por ~6 s com o triângulo vermelho/verde/azul e o fundo pulsando entre azul escuro e azul."
echo "É o mesmo triângulo da JANELA-MGL, mas numa NSWindow nativa, como um app do Mac faz."
echo
zsh "$S" "$D/mgl-cocoa-log.txt"
echo
echo "Pronto. Me diga o que você viu na janela e me mande o mgl-cocoa-log.txt (e o mgl-cocoa-log-mgl.txt)."
read -k 1 "?Aperte uma tecla para fechar. "
