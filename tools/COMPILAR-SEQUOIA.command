#!/bin/zsh
# Dois cliques (macOS): COMPILA (não instala) o stack de aceleração do VostroXe no macOS atual, para ver se
# ele monta no Sequoia. Precisa de internet (cabo de rede ou ancoragem USB do Android).
# NÃO instala nada, NÃO pede senha e NÃO mexe no boot: só baixa dependências e compila em ~/VostroXe-src.
D=${0:A:h}
T="$D/vostroxe-src.tar.gz"
DEST="$HOME/VostroXe-src"
LOG="$D/seq-build-log.txt"
[[ -f $T ]] || { echo "não achei vostroxe-src.tar.gz ao lado deste arquivo ($D)."; read -k 1 "?tecla para fechar "; exit 1; }
echo "== extraindo a fonte do VostroXe para $DEST"
mkdir -p "$DEST" && tar xzf "$T" -C "$DEST" || { echo "falha ao extrair o tarball."; read -k 1 "?tecla "; exit 1; }
cd "$DEST" || { read -k 1 "?tecla "; exit 1; }
echo "== macOS $(sw_vers -productVersion) ($(sw_vers -buildVersion)), fonte commit $(head -c 7 .vostroxe-commit 2>/dev/null)"
echo "== internet: $(curl -sI -m 10 https://github.com >/dev/null 2>&1 && echo OK || echo 'SEM ACESSO — ligue o cabo de rede ou a ancoragem USB e tente de novo')"
echo "== xcode-select: $(xcode-select -p 2>/dev/null || echo 'FALTA — rode xcode-select --install')"
echo
echo "== rodando:  XE_FORCE=1 zsh install.sh --build-only   (sem sudo, sem instalar)"
XE_FORCE=1 zsh install.sh --build-only 2>&1 | tee "$LOG"
echo
cp "$DEST/build/install.log" "$D/seq-install-full-log.txt" 2>/dev/null && echo "copiei o log completo para o pendrive (seq-install-full-log.txt)"
echo "logs no pendrive: seq-build-log.txt (resumo) + seq-install-full-log.txt (completo)"
echo ">>> me mande esses dois arquivos. Isso só compilou; ainda não instalei nem mudei o boot."
read -k 1 "?Aperte uma tecla para fechar. "
