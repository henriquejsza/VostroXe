#!/bin/zsh
# Dois cliques (macOS): liga/desliga a permissão de MICROFONE, CÂMERA ou GRAVAÇÃO DE TELA por app.
#
# Por que isto existe: a aceleração da GPU exige o boot-arg amfi_get_out_of_my_way=1 (o driver é ad-hoc assinado).
# Com ele, o macOS trata todo app de terceiros como "platform binary" e NÃO mostra o pedido automático de permissão
# (o tccd registra "Policy disallows prompt ... is Platform Binary"). O microfone/câmera existem e funcionam como
# dispositivos; só o aviso de primeira vez não aparece. Aqui a gente grava a MESMA autorização que o botão de Ajustes
# gravaria — presa à assinatura do app, e reversível. Depois de liberar, o app também aparece em
# Ajustes do Sistema > Privacidade e Segurança, onde dá para ligar/desligar.
#
# Pede a senha uma vez (grava no banco do TCC).
D=${0:A:h}
TCC=""
for c in "$HOME/VostroXe-src/tools/tcc-permitir.sh" "$D/tcc-permitir.sh"; do [[ -f $c ]] && { TCC=$c; break; }; done
if [[ -z $TCC && -f $D/vostroxe-som.tar.gz ]]; then
  mkdir -p /tmp/xe-perm && tar xzf "$D/vostroxe-som.tar.gz" -C /tmp/xe-perm ./tools/tcc-permitir.sh 2>/dev/null
  [[ -f /tmp/xe-perm/tools/tcc-permitir.sh ]] && TCC=/tmp/xe-perm/tools/tcc-permitir.sh
fi
[[ -n $TCC ]] || { echo "não achei o tcc-permitir.sh (rode o SOM-SEQUOIA antes, ou deixe o vostroxe-som.tar.gz ao lado)"; read -k 1 "?tecla "; exit 1; }

print -P "%BPermissões por app (Vostro 3520 / Sequoia)%b"
echo "Serviço:  1) microfone   2) câmera   3) gravação de tela"
read "svcn?Escolha [1/2/3]: "
case $svcn in
  1) SVC=microfone;; 2) SVC=camera;; 3) SVC=tela;;
  *) echo "opção inválida"; read -k 1 "?tecla "; exit 1;;
esac
echo "Digite o nome do app como aparece em /Aplicativos (ex: Discord, OBS, Google Chrome, zoom.us)."
read "app?App: "
[[ -n $app ]] || { echo "sem app"; read -k 1 "?tecla "; exit 1; }
read "acao?(L)iberar ou (R)evogar para \"$app\"? [L/R]: "
echo
if [[ ${acao:l} == r ]]; then
  sudo zsh "$TCC" --remover "$SVC" "$app"
else
  sudo zsh "$TCC" "$SVC" "$app"
fi
echo
echo ">>> Pronto. Feche e abra o \"$app\". Ele também aparece em Ajustes do Sistema > Privacidade e Segurança > ${SVC},"
echo ">>> onde você pode ligar/desligar quando quiser."
echo ">>> Para ver tudo que está liberado:  sudo zsh \"$TCC\" --listar"
read -k 1 "?Aperte uma tecla para fechar. "
