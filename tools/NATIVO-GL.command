#!/bin/zsh
# Dois cliques no Finder (macOS): mostra o OpenGL que um app nativo tem HOJE, sem o MGL (linha de base).
# Abre um NSOpenGLView comum por ~4 s e imprime o GL_RENDERER/GL_VERSION da Apple. NÃO precisa do MGL.
D=${0:A:h}
S=""
for cand in "$D/gl-nativo.sh" "$D/emulador/gl-nativo.sh"; do
  [[ -f $cand ]] && { S=$cand; break; }
done
if [[ -z $S ]]; then
  echo "não achei o gl-nativo.sh ao lado deste arquivo ($D)."
  read -k 1 "?Aperte uma tecla para fechar. "; exit 1
fi
echo "== OpenGL nativo da Apple (linha de base, sem MGL)"
echo "Abre uma janela por ~4 s. Serve para ver o renderizador que um app comum usa hoje (por software)."
echo "Depois o shim vai desviar esse mesmo caminho para o MGL (na GPU)."
echo
zsh "$S" "$D/gl-nativo-log.txt"
echo
echo "Pronto. Me mande o gl-nativo-log.txt (principalmente as linhas GL_RENDERER e GL_VERSION)."
read -k 1 "?Aperte uma tecla para fechar. "
