#!/bin/zsh
# Emulador do Android Studio (AVDs x86_64) no Vostro 3520: corrige a tela preta.
#
# Por quê: o kernel do Android (6.12) faz o udelay() com a instrução TPAUSE quando a CPU anuncia WAITPKG
# (CPUID.7.0:ECX bit 5). O i5-1235U (Alder Lake) anuncia, e o QEMU do emulador repassa o bit ao guest no
# Hypervisor.framework. Lá a TPAUSE dá "invalid opcode": o kernel do guest entra em panic com 0,4 s de boot, ao
# ligar as outras CPUs, e a janela do emulador fica preta. Nenhum Mac Intel de verdade tem WAITPKG.
# A correção é o parâmetro clearcpuid=waitpkg no kernel do guest, pela propriedade kernel.parameters do config.ini
# de cada AVD, que o emulador acrescenta à linha de comando do kernel. O snapshot de boot rápido salvo antes guarda
# um guest que já entrou em panic: ele vai para o backup, e o próximo início é um boot a frio.
#
# Uso:   zsh tools/emulador-android.sh [status]           (não muda os AVDs; o "adb devices" pode iniciar o adb)
#        zsh tools/emulador-android.sh corrigir [AVD ...]  (sem nomes: todos os AVDs)
#        zsh tools/emulador-android.sh desfazer [AVD ...]
# Feche o emulador antes de corrigir ou desfazer. Rode o corrigir de novo para cada AVD novo.
# Backups: ~/Library/Application Support/xe-emulador/<data-hora>/<AVD>/ (config.ini e o snapshot default_boot).
set -euo pipefail
setopt null_glob
zmodload -F zsh/stat b:zstat
[[ $EUID -ne 0 ]] || { echo "rode sem sudo, na sua conta"; exit 1; }

AVDROOT=${ANDROID_AVD_HOME:-${ANDROID_USER_HOME:-$HOME/.android}/avd}
SDK=${ANDROID_HOME:-${ANDROID_SDK_ROOT:-$HOME/Library/Android/sdk}}
BKROOT="$HOME/Library/Application Support/xe-emulador"
FIX=waitpkg

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
with_fix() {      # parâmetros $1 com waitpkg no clearcpuid
  local -a out; local t found=0
  for t in ${=1}; do
    if [[ $t == clearcpuid=* ]]; then
      found=1
      [[ ,${t#clearcpuid=}, == *,$FIX,* ]] || t="$t,$FIX"
    fi
    out+=$t
  done
  (( found )) || out+="clearcpuid=$FIX"
  print -r -- "${(j: :)out}"
}
without_fix() {   # parâmetros $1 sem o waitpkg (e sem o clearcpuid, se ficar vazio)
  local -a out ids; local t
  for t in ${=1}; do
    if [[ $t == clearcpuid=* ]]; then
      ids=(${(s:,:)${t#clearcpuid=}}); ids=(${ids:#$FIX})
      (( ${#ids} )) && out+="clearcpuid=${(j:,:)ids}"
    else
      out+=$t
    fi
  done
  print -r -- "${(j: :)out}"
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
  local stamp n d cfg cur new bk changed=0
  stamp=$(date +%Y%m%d-%H%M%S)
  for n in $names; do
    d=$(avd_dir "$n") || { echo "$n: AVD não encontrado em $AVDROOT"; continue; }
    cfg="$d/config.ini"
    [[ -f $cfg ]] || { echo "$n: sem config.ini em $d"; continue; }
    cur=$(cfg_get "$cfg" kernel.parameters)
    if [[ $mode == corrigir ]]; then new=$(with_fix "$cur"); else new=$(without_fix "$cur"); fi
    if [[ $new == "$cur" ]]; then
      [[ $mode == corrigir ]] && echo "$n: já corrigido (kernel.parameters=$cur)" || echo "$n: não tem a correção"
      continue
    fi
    bk="$BKROOT/$stamp/$n"
    mkdir -p "$bk"
    cp -p "$cfg" "$bk/config.ini"
    cfg_set "$cfg" kernel.parameters "$new"
    echo "$n: kernel.parameters=${new:-(removido)}"
    if [[ $mode == corrigir && -d $d/snapshots/default_boot ]]; then
      mv "$d/snapshots/default_boot" "$bk/snapshot-default_boot"
      echo "$n: snapshot default_boot movido para o backup (o próximo início é um boot a frio)"
    fi
    changed=1
  done
  (( changed )) && echo "backup: $BKROOT/$stamp"
  return 0
}

status() {
  local l7 emu adb n d cfg kp hq
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
    echo "$n: $([[ $(with_fix "$kp") == "$kp" ]] && echo corrigido || echo 'SEM a correção')" \
         "| imagem $(cfg_get "$cfg" image.sysdir.1) | gpu $(cfg_get "$cfg" hw.gpu.mode)" \
         "| kernel.parameters=${kp:-(vazio)}"
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
}

case ${1:-status} in
  status) status;;
  corrigir|desfazer) change "$@";;
  *) sed -n '/^# Uso:/,/^# Backups:/p' "$0" | sed 's/^# \{0,1\}//'; exit 1;;
esac
