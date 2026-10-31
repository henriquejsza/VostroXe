#!/bin/zsh
# Emulador do Android Studio (AVDs x86_64) no Vostro 3520: corrige a tela preta.
#
# Por quê: o kernel do Android (6.12) faz o udelay() com a instrução TPAUSE quando a CPU anuncia WAITPKG
# (CPUID.7.0:ECX bit 5). O i5-1235U (Alder Lake) anuncia, e o QEMU do emulador repassa o bit ao guest no
# Hypervisor.framework. Lá a TPAUSE dá "invalid opcode": o kernel do guest entra em panic com 0,4 s de boot, ao
# ligar as outras CPUs, e a janela do emulador fica preta. Nenhum Mac Intel de verdade tem WAITPKG.
# A RDPID (CPUID.7.0:ECX bit 22) também passa para o guest, e o QEMU do emulador não liga o controle da VMX de que
# ela depende ("enable RDTSCP"); o vDSO do Linux usa a RDPID no getcpu(). Por precaução ela sai junto.
# A correção é o parâmetro clearcpuid=waitpkg,rdpid no kernel do guest, pela propriedade kernel.parameters do
# config.ini de cada AVD, que o emulador acrescenta à linha de comando do kernel. O snapshot de boot rápido salvo
# antes guarda um guest que já entrou em panic: ele vai para o backup, e o próximo início é um boot a frio.
# O corrigir também volta ao automático o renderizador escolhido nas configurações do emulador (AVD.conf). O OpenGL
# do Mac aqui é só o renderizador por software da Apple (OpenGL ES 2.0 para o guest), e o Android 37 precisa de
# GLES 3.1; no automático o emulador usa o SwiftShader.
#
# Uso:   zsh tools/emulador-android.sh [status]           (não muda os AVDs; o "adb devices" pode iniciar o adb)
#        zsh tools/emulador-android.sh corrigir [AVD ...]  (sem nomes: todos os AVDs)
#        zsh tools/emulador-android.sh desfazer [AVD ...]
# Feche o emulador antes de corrigir ou desfazer. Rode o corrigir de novo para cada AVD novo.
# Backups: ~/Library/Application Support/xe-emulador/<data-hora>/<AVD>/ (config.ini, AVD.conf, snapshot).
set -euo pipefail
setopt null_glob
zmodload -F zsh/stat b:zstat
SELF=${0:A}
[[ $EUID -ne 0 ]] || { echo "rode sem sudo, na sua conta"; exit 1; }

AVDROOT=${ANDROID_AVD_HOME:-${ANDROID_USER_HOME:-$HOME/.android}/avd}
SDK=${ANDROID_HOME:-${ANDROID_SDK_ROOT:-$HOME/Library/Android/sdk}}
BKROOT="$HOME/Library/Application Support/xe-emulador"
FIX=(waitpkg rdpid)
GLKEYS=(glesBackendPreference glesApiLevelPreference guestGlesDriverPreference)

avd_names() { local f; for f in "$AVDROOT"/*.ini; do print -r -- "${${f:t}%.ini}"; done; }
avd_dir() {   # pasta do AVD $1, pelo path= (ou path.rel=) do $AVDROOT/$1.ini
  local ini="$AVDROOT/$1.ini" p
  [[ -f $ini ]] || return 1
  p=$(cfg_get "$ini" path)
  [[ -n $p && -d $p ]] && { print -r -- "$p"; return 0; }
  p=$(cfg_get "$ini" path.rel)
  [[ -n $p && -d ${AVDROOT:h}/$p ]] && { print -r -- "${AVDROOT:h}/$p"; return 0; }
  [[ -d $AVDROOT/$1.avd ]] && { print -r -- "$AVDROOT/$1.avd"; return 0; }
  return 1
}
cfg_get() {   # valor da chave $2 no arquivo $1 (vazio se não existir)
  awk -v k="$2" 'index($0, k) == 1 { r = substr($0, length(k) + 1)
    if (r ~ /^[ \t]*=/) { sub(/^[ \t]*=[ \t]*/, "", r); v = r } } END { print v }' "$1"
}
cfg_set() {   # grava $2=$3 no arquivo $1 no lugar da chave (ou no fim); valor vazio apaga a chave
  local tmp="$1.xe-tmp"
  awk -v k="$2" -v v="$3" '
    index($0, k) == 1 && substr($0, length(k) + 1) ~ /^[ \t]*=/ { if (!done && v != "") print k "=" v; done = 1; next }
    { print }
    END { if (!done && v != "") print k "=" v }' "$1" > "$tmp"
  mv "$tmp" "$1"
}
with_fix() {      # parâmetros $1 com todos os ids de $FIX no clearcpuid
  local -a out ids; local t id found=0
  for t in ${=1}; do
    if [[ $t == clearcpuid=* ]]; then
      found=1
      ids=(${(s:,:)${t#clearcpuid=}})
      for id in $FIX; do (( ${ids[(Ie)$id]} )) || ids+=$id; done
      t="clearcpuid=${(j:,:)ids}"
    fi
    out+=$t
  done
  (( found )) || out+="clearcpuid=${(j:,:)FIX}"
  print -r -- "${(j: :)out}"
}
without_fix() {   # parâmetros $1 sem os ids de $FIX (e sem o clearcpuid, se ficar vazio)
  local -a out ids; local t id
  for t in ${=1}; do
    if [[ $t == clearcpuid=* ]]; then
      ids=(${(s:,:)${t#clearcpuid=}})
      for id in $FIX; do ids=(${ids:#$id}); done
      (( ${#ids} )) && out+="clearcpuid=${(j:,:)ids}"
    else
      out+=$t
    fi
  done
  print -r -- "${(j: :)out}"
}
gl_prefs() {      # escolhas de renderização salvas no AVD.conf $1 ("chave=valor ..."; vazio se não houver)
  [[ -f $1 ]] || return 0
  awk -v keys="${(j: :)GLKEYS}" 'BEGIN { n = split(keys, k, " "); for (i = 1; i <= n; i++) want[k[i]] = 1 }
    { split($0, a, "="); if (a[1] in want) s = s (s == "" ? "" : " ") $0 } END { print s }' "$1"
}
gl_reset() {      # tira essas escolhas do AVD.conf $1: o emulador volta ao automático
  local tmp="$1.xe-tmp"
  awk -v keys="${(j: :)GLKEYS}" 'BEGIN { n = split(keys, k, " "); for (i = 1; i <= n; i++) want[k[i]] = 1 }
    { split($0, a, "="); if (!(a[1] in want)) print }' "$1" > "$tmp"
  mv "$tmp" "$1"
}
mtime() { zstat -F '%d/%m %H:%M' +mtime -- "$1" 2>/dev/null || echo '?'; }
emu_running() { pgrep -f '/emulator/qemu/[^/ ]+/qemu-system-' >/dev/null 2>&1; }
pick() {          # nomes dados, ou todos
  if (( $# )); then print -rl -- "$@"; else avd_names; fi
}

change() {        # $1 = corrigir | desfazer; resto = AVDs
  local mode=$1; shift
  if emu_running; then echo "o emulador está aberto: feche a janela dele e rode de novo"; exit 1; fi
  local -a names; names=(${(f)"$(pick "$@")"})
  (( ${#names} )) || { echo "nenhum AVD em $AVDROOT"; exit 1; }
  local stamp n d cfg conf cur new gl bk changed=0
  stamp=$(date +%Y%m%d-%H%M%S)
  for n in $names; do
    d=$(avd_dir "$n") || { echo "$n: AVD não encontrado em $AVDROOT"; continue; }
    cfg="$d/config.ini"
    conf="$d/AVD.conf"
    [[ -f $cfg ]] || { echo "$n: sem config.ini em $d"; continue; }
    cur=$(cfg_get "$cfg" kernel.parameters)
    gl=""
    if [[ $mode == corrigir ]]; then
      new=$(with_fix "$cur")
      gl=$(gl_prefs "$conf")
    else
      new=$(without_fix "$cur")
    fi
    if [[ $new == "$cur" && -z $gl ]]; then
      [[ $mode == corrigir ]] && echo "$n: já corrigido (kernel.parameters=$cur)" || echo "$n: não tem a correção"
      continue
    fi
    bk="$BKROOT/$stamp/$n"
    mkdir -p "$bk"
    cp -p "$cfg" "$bk/config.ini"
    [[ -f $conf ]] && cp -p "$conf" "$bk/AVD.conf"
    if [[ $new != "$cur" ]]; then
      cfg_set "$cfg" kernel.parameters "$new"
      echo "$n: kernel.parameters=${new:-(removido)}"
      if [[ $mode == corrigir && -d $d/snapshots/default_boot ]]; then
        mv "$d/snapshots/default_boot" "$bk/snapshot-default_boot"
        echo "$n: snapshot default_boot movido para o backup (o próximo início é um boot a frio)"
      fi
    fi
    if [[ -n $gl ]]; then
      gl_reset "$conf"
      echo "$n: renderização de volta ao automático (tirado do AVD.conf: $gl)"
    fi
    changed=1
  done
  (( changed )) && echo "backup: $BKROOT/$stamp"
  return 0
}

status() {
  local l7 emu adb n d cfg kp gl hq ok missing=0
  echo "== macOS"
  echo "Hypervisor.framework (kern.hv_support): $(sysctl -n kern.hv_support 2>/dev/null || echo '?')"
  l7=$(sysctl -n machdep.cpu.leaf7_features 2>/dev/null || true)
  echo "WAITPKG na CPU (machdep.cpu.leaf7_features): $([[ " $l7 " == *" WAITPKG "* ]] && echo sim || echo 'não listado')"
  emu="$SDK/emulator/emulator"
  echo "== emulador ($emu)"
  if [[ -x $emu ]]; then
    "$emu" -version 2>/dev/null | head -1 || true
    "$emu" -accel-check 2>&1 | head -6 || true
  else
    echo "não encontrado"
  fi
  emu_running && echo "(o emulador está aberto agora)"
  echo "== AVDs ($AVDROOT)"
  for n in ${(f)"$(avd_names)"}; do
    d=$(avd_dir "$n") || { echo "$n: pasta não encontrada"; continue; }
    cfg="$d/config.ini"
    kp=$(cfg_get "$cfg" kernel.parameters)
    gl=$(gl_prefs "$d/AVD.conf")
    ok=1
    [[ $(with_fix "$kp") == "$kp" && -z $gl ]] || { ok=0; missing=1; }
    echo "$n: $( (( ok )) && echo corrigido || echo 'SEM a correção')" \
         "| imagem $(cfg_get "$cfg" image.sysdir.1) | gpu $(cfg_get "$cfg" hw.gpu.mode)" \
         "| kernel.parameters=${kp:-(vazio)}"
    [[ -n $gl ]] && echo "   renderização escolhida no emulador (AVD.conf): $gl"
    hq="$d/hardware-qemu.ini"
    [[ -f $hq ]] && echo "   último início ($(mtime "$hq")): kernel.parameters = ${$(cfg_get "$hq" kernel.parameters):-(vazio)}"
    [[ -d $d/snapshots/default_boot ]] && echo "   snapshot default_boot de $(mtime "$d/snapshots/default_boot")"
  done
  adb="$SDK/platform-tools/adb"
  echo "== adb ($adb)"
  if [[ -x $adb ]]; then
    perl -e 'alarm 20; exec @ARGV' "$adb" devices 2>&1 | head -8 || echo "adb devices falhou ou passou de 20 s"
  else
    echo "não encontrado"
  fi
  if (( missing )); then
    echo
    echo ">>> Falta aplicar a correção. Feche o emulador e rode:  zsh ${(q)SELF} corrigir"
  fi
  return 0
}

case ${1:-status} in
  status) status;;
  corrigir|desfazer) change "$@";;
  *) sed -n '/^# Uso:/,/^# Backups:/p' "$0" | sed 's/^# \{0,1\}//'; exit 1;;
esac
