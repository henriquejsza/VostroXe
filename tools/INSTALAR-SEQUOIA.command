#!/bin/zsh
# Dois cliques (macOS): INSTALA o stack de aceleração do VostroXe no Sequoia. Pede sua SENHA uma vez.
# O EFI do SSD já está numa config SEGURA (sem aceleração), então, se depois algo travar, é só reiniciar
# e escolher o disco interno: o Sequoia liga normal (sem aceleração). O teste acelerado é pelo pendrive (F12),
# que eu preparo depois com os logs.  Precisa de internet (cabo de rede ou ancoragem USB do Android).
D=${0:A:h}
DEST="$HOME/VostroXe-src"
LOG="$D/seq-install-log.txt"
if [[ ! -f $DEST/install.sh ]]; then
  T="$D/vostroxe-src.tar.gz"
  [[ -f $T ]] || { echo "não achei a fonte ($DEST/install.sh nem $T)."; read -k 1 "?tecla "; exit 1; }
  echo "== extraindo a fonte para $DEST"; mkdir -p "$DEST" && tar xzf "$T" -C "$DEST" || { echo "falha ao extrair"; read -k 1 "?tecla "; exit 1; }
fi
cd "$DEST" || { read -k 1 "?tecla "; exit 1; }
echo "== macOS $(sw_vers -productVersion) ($(sw_vers -buildVersion))"
echo "== internet: $(curl -sI -m 10 https://github.com >/dev/null 2>&1 && echo OK || echo 'SEM ACESSO — ligue o cabo de rede ou a ancoragem USB e tente de novo')"
echo
echo "== instalação completa (XE_FORCE=1). Vai pedir a SENHA do macOS para copiar os drivers."
XE_FORCE=1 zsh install.sh 2>&1 | tee "$LOG"
echo
if [[ -d $DEST/build/NootedGreen.kext ]]; then
  rm -rf "$D/NootedGreen-sequoia.kext"
  cp -R "$DEST/build/NootedGreen.kext" "$D/NootedGreen-sequoia.kext" && echo "copiei o NootedGreen.kext (compilado no Sequoia) para o pendrive"
fi
cp "$DEST/build/install.log" "$D/seq-install-full2-log.txt" 2>/dev/null
echo
echo ">>> IMPORTANTE: NÃO reinicie no modo acelerado ainda."
echo ">>> Me mande o seq-install-log.txt (e o NootedGreen-sequoia.kext já está no pendrive)."
echo ">>> Eu preparo o boot de teste no pendrive e te digo quando reiniciar pelo F12."
read -k 1 "?Aperte uma tecla para fechar. "
