#!/bin/zsh
# Roda um app qualquer sob o shim do MGL: desvia o OpenGL do app (NSOpenGLContext + gl*) para a Iris Xe (Metal).
# Compila o shim (mglshim.m + mgl_gl_interpose.c) uma vez em build/libmglshim.dylib e lança o app com
# DYLD_INSERT_LIBRARIES. Precisa: COMPILAR-MGL feito, e a validação de biblioteca desligada no boot
# (amfi_get_out_of_my_way=1 no Tahoe, ou ngreenlv=1 no Sequoia) — senão o macOS ignora o DYLD_INSERT.
#
# Uso (no Terminal do macOS):
#   zsh /Volumes/MACINSTALL/mgl-run.sh /Applications/OBS.app
#   zsh /Volumes/MACINSTALL/mgl-run.sh /caminho/para/o/binario
set -u
SELF=${0:A}; HERE=${SELF:h}
APP="${1:-}"
LOG="$HERE/mgl-run-log.txt"; ERRLOG="${LOG:r}-mgl.txt"
if [[ -z $APP ]]; then
  echo "uso: zsh mgl-run.sh <AppOuBinario>   (ex.: zsh mgl-run.sh /Applications/OBS.app)"; exit 1
fi
if [[ -n ${MGL_DIR:-} ]]; then MGLDIR=$MGL_DIR
elif [[ -f $HERE/../src/MGL/Makefile ]]; then MGLDIR=${HERE:h}/src/MGL
else MGLDIR=$HOME/VostroXe-MGL; fi
if   [[ -f $HERE/../src/MGLShim/mglshim.m ]]; then SHIMSRC=${HERE:h}/src/MGLShim/mglshim.m; GENSRC=${HERE:h}/src/MGLShim/mgl_gl_interpose.c
elif [[ -f $HERE/mglshim.m ]];              then SHIMSRC=$HERE/mglshim.m; GENSRC=$HERE/mgl_gl_interpose.c
else SHIMSRC=""; GENSRC=""; fi

# Resolve o binário dentro de um .app
BIN="$APP"
if [[ -d $APP ]]; then
  name=${${APP:t}:r}
  for cand in "$APP/Contents/MacOS/$name" "$APP"/Contents/MacOS/*(.N); do
    [[ -x $cand ]] && { BIN=$cand; break; }
  done
fi
{
  echo "== $(date '+%d/%m %H:%M')  rodar app sob o shim do MGL"
  echo "macOS $(sw_vers -productVersion 2>/dev/null) ($(sw_vers -buildVersion 2>/dev/null))"
  [[ -f $MGLDIR/build/libmgl.dylib ]] || { echo "não achei $MGLDIR/build/libmgl.dylib — rode o COMPILAR-MGL primeiro."; exit 1; }
  [[ -n $SHIMSRC && -n $GENSRC ]] || { echo "não achei mglshim.m / mgl_gl_interpose.c."; exit 1; }
  [[ -x $BIN ]] || { echo "não achei um binário executável em: $APP"; exit 1; }
  echo "== app: $BIN"

  SHIM="$MGLDIR/build/libmglshim.dylib"
  echo "== compilando o shim em $SHIM"
  clang -dynamiclib -ObjC "$SHIMSRC" "$GENSRC" -o "$SHIM" \
    -I"$MGLDIR/MGL/include" -I"$MGLDIR/MGL/include/GL" \
    -framework Cocoa -framework QuartzCore -framework Metal -framework OpenGL \
    -install_name @rpath/libmglshim.dylib 2>&1 | tail -20
  [[ -f $SHIM ]] || { echo "o shim NÃO compilou (ver acima)"; exit 1; }

  echo "== lançando o app sob o shim. Feche o app quando terminar de olhar; o log do MGL vai para ${ERRLOG:t}."
  echo "   (se o app não abrir nada diferente, pode ser que ele não use NSOpenGLContext, ou a validação de"
  echo "    biblioteca esteja ligada — aí o DYLD_INSERT é ignorado.)"
  DYLD_INSERT_LIBRARIES="$SHIM" MGLSHIM_LIB="$MGLDIR/build/libmgl.dylib" \
    DYLD_LIBRARY_PATH="$MGLDIR/build" DYLD_FALLBACK_LIBRARY_PATH="$MGLDIR/build" "$BIN" 2> "$ERRLOG"
  rc=$?
  echo "== o app terminou com código $rc (0 = normal, 139 = segfault, 134 = assert)"
  echo "== resumo do log do MGL (${ERRLOG:t}, $(wc -l < "$ERRLOG" | tr -d ' ') linhas):"
  grep 'MGLSHIM:' "$ERRLOG" | sed -E 's/^.*MGLSHIM: /   /' | sort -u | head -20
  nd=$(grep -c 'Metal device created' "$ERRLOG")
  np=$(grep -c 'Presenting drawable with texture' "$ERRLOG")
  echo "   renderers do MGL (Metal device created): $nd  | quadros apresentados (Presenting drawable): $np"
  echo "   erros/avisos do MGL (sem a hora, 15 mais comuns):"
  grep -E 'ERROR|CRITICAL|Assertion|EMERGENCY|WARNING|xception|not implemented|Unimplemented' "$ERRLOG" \
    | sed -E 's/^[0-9-]+ [0-9:.]+ [^ ]+ //; s/0x[0-9a-f]{6,}/0x…/g; s/[0-9]+/N/g' | sort | uniq -c | sort -rn | head -15
} 2>&1 | tee "$LOG"
echo; echo "logs: $LOG  (+ ${ERRLOG:t})"
