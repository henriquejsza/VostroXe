#!/bin/zsh
# Emulador do Android Studio (AVDs x86_64) no Vostro 3520: corrige a tela preta.
#
# Por quê: o kernel do Android (6.12) faz o udelay() com a instrução TPAUSE quando a CPU anuncia WAITPKG
# (CPUID.7.0:ECX bit 5). O i5-1235U (Alder Lake) anuncia, e o QEMU do emulador repassa o bit ao guest no
# Hypervisor.framework. Lá a TPAUSE dá "invalid opcode": o kernel do guest entra em panic com 0,4 s de boot, ao
# ligar as outras CPUs, e a janela do emulador fica preta. Nenhum Mac Intel de verdade tem WAITPKG.
# A RDPID (CPUID.7.0:ECX bit 22) também passa para o guest, e o QEMU do emulador não liga o controle da VMX de que
# ela depende ("enable RDTSCP"); o vDSO do Linux usa a RDPID no getcpu(). Por precaução ela sai junto.
# A PKU (chaves de proteção de memória, CPUID.7.0:ECX bit 3) é o terceiro caso: o emulador anuncia PKU no leaf 7,
# o guest liga CR4.PKE, mas o XSAVE do guest (leaf 0xD) não traz o componente PKRU (fica só x87/SSE/AVX = 0x7).
# Ao montar o quadro de sinal, o kernel procura o PKRU no XSAVE, não acha, dá WARNING em xstate.c e o init (PID 1)
# trava no meio da entrega do sinal, pendurando a VM inteira (RCU stalls). Por isso a pku também é limpa.
# A correção é o parâmetro clearcpuid=waitpkg,rdpid,pku no kernel do guest, pela propriedade kernel.parameters do
# config.ini de cada AVD, que o emulador acrescenta à linha de comando do kernel.
# O corrigir também volta ao automático o renderizador escolhido nas configurações do emulador (AVD.conf). O OpenGL
# do Mac aqui é só o renderizador por software da Apple (OpenGL ES 2.0 para o guest), e o Android 37 precisa de
# GLES 3.1; no automático o emulador usa o SwiftShader.
# O snapshot de boot rápido salvo antes guarda um guest que já entrou em panic, e sai inteiro: a pasta
# snapshots/default_boot (a RAM) e o snapshot interno "default_boot" de cada disco .qcow2 do AVD (CPUs e
# dispositivos), este com o qemu-img do SDK.
# O boot rápido (quickboot) nunca carregou nesta máquina (sempre "error while loading state ... goldfish_pipe",
# desde 25/10): meio estado carregado deixa a VM suja e o boot a frio seguinte trava no BIOS (testes de 30/10). Por
# isso o corrigir também liga fastboot.forceColdBoot=yes no config.ini, para o emulador nunca tentar carregar o
# snapshot (nem pelo Device Manager) e sempre fazer um boot a frio limpo. O desfazer volta forceColdBoot=no.
#
# Uso:   zsh tools/emulador-android.sh [status]            (não muda os AVDs; o "adb devices" pode iniciar o adb)
#        zsh tools/emulador-android.sh corrigir [AVD ...]   (sem nomes: todos os AVDs)
#        zsh tools/emulador-android.sh desfazer [AVD ...]
#        zsh tools/emulador-android.sh boot-frio [AVD ...]  (só tira o snapshot de boot rápido)
#        zsh tools/emulador-android.sh testar [AVD] [log]   (boot a frio, com o log do kernel do Android em log)
# Feche o emulador antes. Rode o corrigir de novo para cada AVD novo.
# Backups: ~/Library/Application Support/xe-emulador/<data-hora>/<AVD>/ (config.ini, AVD.conf, snapshot, discos).
set -euo pipefail
setopt null_glob
zmodload -F zsh/stat b:zstat
SELF=${0:A}
[[ $EUID -ne 0 ]] || { echo "rode sem sudo, na sua conta"; exit 1; }

AVDROOT=${ANDROID_AVD_HOME:-${ANDROID_USER_HOME:-$HOME/.android}/avd}
SDK=${ANDROID_HOME:-${ANDROID_SDK_ROOT:-$HOME/Library/Android/sdk}}
BKROOT="$HOME/Library/Application Support/xe-emulador"
LOGROOT="$HOME/Library/Logs/xe-emulador"
EMU="$SDK/emulator/emulator"
QEMU_IMG="$SDK/emulator/qemu-img"
FIX=(waitpkg rdpid pku)
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
need_closed() {
  if emu_running; then echo "o emulador está aberto: feche a janela dele e rode de novo"; exit 1; fi
}

qimg_ok() { [[ -x $QEMU_IMG ]] && "$QEMU_IMG" --version >/dev/null 2>&1; }
qcow_qb() {       # discos .qcow2 da pasta $1 que têm o snapshot interno default_boot (um por linha)
  local f
  for f in "$1"/*.qcow2; do
    if "$QEMU_IMG" snapshot -l "$f" 2>/dev/null | awk '$2 == "default_boot" { f = 1 } END { exit !f }'; then
      print -r -- "$f"
    fi
  done
  return 0
}
has_quickboot() { # 0 se o AVD $1 tem snapshot de boot rápido (a RAM ou um qcow2 interno)
  [[ -d $1/snapshots/default_boot ]] && return 0
  qimg_ok || return 1
  local -a q; q=(${(f)"$(qcow_qb "$1")"}); (( ${#q} ))
}
clone_copy() { cp -cp "$1" "$2" 2>/dev/null || cp -p "$1" "$2"; }   # no APFS o -c clona, sem gastar espaço
drop_quickboot() {   # tira o snapshot de boot rápido do AVD $1 inteiro, com backup em $2
  local d=$1 bk=$2 f   # volta 0: tirou; 1: não deu (sem qemu-img); 2: não havia snapshot
  local -a imgs
  if ! qimg_ok; then
    echo "   não consegui rodar $QEMU_IMG, o snapshot de boot rápido ficou como estava;" \
         "use o testar, ou no Device Manager o Cold Boot Now"
    return 1
  fi
  imgs=(${(f)"$(qcow_qb "$d")"})
  if [[ ! -d $d/snapshots/default_boot ]] && (( ${#imgs} == 0 )); then
    return 2
  fi
  mkdir -p "$bk"
  local what=""
  if [[ -d $d/snapshots/default_boot ]]; then
    mv "$d/snapshots/default_boot" "$bk/snapshot-default_boot"
    what="a RAM (snapshots/default_boot)"
  fi
  for f in $imgs; do
    clone_copy "$f" "$bk/${f:t}"
    "$QEMU_IMG" snapshot -d default_boot "$f"
  done
  (( ${#imgs} )) && what="$what${what:+ e }o estado de ${#imgs} disco(s) .qcow2"
  echo "   snapshot de boot rápido tirado ($what): o próximo início é um boot a frio"
  return 0
}

change() {        # $1 = corrigir | desfazer; resto = AVDs
  local mode=$1; shift
  need_closed
  local -a names; names=(${(f)"$(pick "$@")"})
  (( ${#names} )) || { echo "nenhum AVD em $AVDROOT"; exit 1; }
  local stamp n d cfg conf cur new cb wantcb gl bk changed=0 kpch cbch snap
  stamp=$(date +%Y%m%d-%H%M%S)
  for n in $names; do
    d=$(avd_dir "$n") || { echo "$n: AVD não encontrado em $AVDROOT"; continue; }
    cfg="$d/config.ini"
    conf="$d/AVD.conf"
    [[ -f $cfg ]] || { echo "$n: sem config.ini em $d"; continue; }
    cur=$(cfg_get "$cfg" kernel.parameters)
    cb=$(cfg_get "$cfg" fastboot.forceColdBoot)
    gl=""; snap=0; kpch=0; cbch=0
    if [[ $mode == corrigir ]]; then
      new=$(with_fix "$cur"); wantcb=yes
      gl=$(gl_prefs "$conf")
      has_quickboot "$d" && snap=1
      [[ $cb != yes ]] && cbch=1
    else
      new=$(without_fix "$cur"); wantcb=no
      [[ $cb == yes ]] && cbch=1
    fi
    [[ $new != "$cur" ]] && kpch=1
    if (( !kpch && !cbch && !snap )) && [[ -z $gl ]]; then
      [[ $mode == corrigir ]] && echo "$n: já corrigido (kernel.parameters=${cur:-vazio}, cold boot ${cb:-no}, sem snapshot)" \
                               || echo "$n: não tem a correção"
      continue
    fi
    bk="$BKROOT/$stamp/$n"; mkdir -p "$bk"
    cp -p "$cfg" "$bk/config.ini"
    [[ -f $conf ]] && cp -p "$conf" "$bk/AVD.conf"
    (( kpch )) && { cfg_set "$cfg" kernel.parameters "$new"; echo "$n: kernel.parameters=${new:-(removido)}"; }
    (( cbch )) && { cfg_set "$cfg" fastboot.forceColdBoot "$wantcb"; echo "$n: fastboot.forceColdBoot=$wantcb ($([[ $wantcb == yes ]] && echo 'boot a frio sempre' || echo 'volta ao boot rápido'))"; }
    [[ $mode == corrigir ]] && { drop_quickboot "$d" "$bk" || true; }
    [[ -n $gl ]] && { gl_reset "$conf"; echo "$n: renderização de volta ao automático (tirado do AVD.conf: $gl)"; }
    changed=1
  done
  (( changed )) && echo "backup: $BKROOT/$stamp"
  return 0
}

cold() {          # boot-frio: só tira o snapshot de boot rápido
  need_closed
  local -a names; names=(${(f)"$(pick "$@")"})
  (( ${#names} )) || { echo "nenhum AVD em $AVDROOT"; exit 1; }
  local stamp n d rc
  stamp=$(date +%Y%m%d-%H%M%S)
  for n in $names; do
    d=$(avd_dir "$n") || { echo "$n: AVD não encontrado em $AVDROOT"; continue; }
    echo "$n:"
    drop_quickboot "$d" "$BKROOT/$stamp/$n" && rc=0 || rc=$?
    (( rc != 2 )) || echo "   sem snapshot de boot rápido"
  done
  return 0
}

test_boot() {     # testar: boot a frio sem carregar nem salvar snapshot, com o log do kernel do guest
  need_closed
  [[ -x $EMU ]] || { echo "emulador não encontrado: $EMU"; exit 1; }
  local -a names; names=(${(f)"$(avd_names)"})
  (( ${#names} )) || { echo "nenhum AVD em $AVDROOT"; exit 1; }
  local n=${1:-${names[1]}} d kp log
  d=$(avd_dir "$n") || { echo "$n: AVD não encontrado. AVDs: ${(j:, :)names}"; exit 1; }
  kp=$(cfg_get "$d/config.ini" kernel.parameters)
  if [[ $(with_fix "$kp") != "$kp" ]]; then
    echo "$n: falta a correção; rode antes:  zsh ${(q)SELF} corrigir"
    exit 1
  fi
  echo "$n:"
  drop_quickboot "$d" "$BKROOT/$(date +%Y%m%d-%H%M%S)/$n" || true
  mkdir -p "$LOGROOT"
  log="$LOGROOT/$n-$(date +%Y%m%d-%H%M%S).txt"
  echo "abrindo o emulador: boot a frio, sem snapshot, log do kernel do Android em:"
  echo "   $log"
  echo "espere até 5 minutos pelo logo do Android; depois feche a janela do emulador"
  "$EMU" -avd "$n" -no-snapshot-load -no-snapshot-save -show-kernel > "$log" 2>&1 || true
  echo "emulador fechado; log: $log ($(wc -l < "$log" | tr -d ' ') linhas)"
  grep -a -m8 -E "Command line:|Clearing CPUID|Kernel panic|invalid opcode|Run /init|init: init (first|second) stage|bootanim" \
    "$log" | cut -c1-160 || true
  return 0
}

status() {
  local l7 adb n d cfg kp gl hq ok sn missing=0 half=0
  local -a q
  echo "== macOS"
  echo "Hypervisor.framework (kern.hv_support): $(sysctl -n kern.hv_support 2>/dev/null || echo '?')"
  l7=$(sysctl -n machdep.cpu.leaf7_features 2>/dev/null || true)
  echo "WAITPKG na CPU (machdep.cpu.leaf7_features): $([[ " $l7 " == *" WAITPKG "* ]] && echo sim || echo 'não listado')"
  echo "== emulador ($EMU)"
  if [[ -x $EMU ]]; then
    "$EMU" -version 2>/dev/null | head -1 || true
    "$EMU" -accel-check 2>&1 | head -6 || true
  else
    echo "não encontrado"
  fi
  emu_running && echo "(o emulador está aberto agora)"
  echo "== AVDs ($AVDROOT)"
  for n in ${(f)"$(avd_names)"}; do
    d=$(avd_dir "$n") || { echo "$n: pasta não encontrada"; continue; }
    cfg="$d/config.ini"
    kp=$(cfg_get "$cfg" kernel.parameters)
    local cb=$(cfg_get "$cfg" fastboot.forceColdBoot)
    gl=$(gl_prefs "$d/AVD.conf")
    ok=1
    [[ $(with_fix "$kp") == "$kp" && $cb == yes && -z $gl ]] || { ok=0; missing=1; }
    echo "$n: $( (( ok )) && echo corrigido || echo 'SEM a correção')" \
         "| imagem $(cfg_get "$cfg" image.sysdir.1) | gpu $(cfg_get "$cfg" hw.gpu.mode) | cold boot ${cb:-no}" \
         "| kernel.parameters=${kp:-(vazio)}"
    [[ -n $gl ]] && echo "   renderização escolhida no emulador (AVD.conf): $gl"
    hq="$d/hardware-qemu.ini"
    [[ -f $hq ]] && echo "   último início ($(mtime "$hq")): kernel.parameters = ${$(cfg_get "$hq" kernel.parameters):-(vazio)}"
    sn=""
    [[ -d $d/snapshots/default_boot ]] && sn="RAM de $(mtime "$d/snapshots/default_boot")"
    if ! emu_running && qimg_ok; then
      q=(${(f)"$(qcow_qb "$d")"})
      (( ${#q} )) && sn="$sn${sn:+; }discos: ${(j:, :)${(@)q:t}}"
      if [[ -d $d/snapshots/default_boot ]]; then
        (( ${#q} )) || { sn="$sn (PELA METADE)"; half=1; }
      else
        (( ${#q} == 0 )) || { sn="$sn (PELA METADE)"; half=1; }
      fi
    fi
    echo "   snapshot de boot rápido: ${sn:-nenhum}"
  done
  adb="$SDK/platform-tools/adb"
  echo "== adb ($adb)"
  if [[ -x $adb ]]; then
    perl -e 'alarm 10; exec @ARGV' "$adb" devices 2>&1 | head -8 || echo "adb devices falhou ou passou de 10 s"
  else
    echo "não encontrado"
  fi
  echo
  if (( missing )); then
    echo ">>> Falta aplicar a correção. Feche o emulador e rode:  zsh ${(q)SELF} corrigir"
  elif (( half )); then
    echo ">>> Snapshot de boot rápido pela metade. Feche o emulador e rode:  zsh ${(q)SELF} boot-frio"
  else
    echo ">>> Para um boot a frio com o log do kernel do Android:  zsh ${(q)SELF} testar"
  fi
  return 0
}

case ${1:-status} in
  status) status;;
  corrigir|desfazer) change "$@";;
  boot-frio) shift; cold "$@";;
  testar) shift; test_boot "$@";;
  *) sed -n '/^# Uso:/,/^# Backups:/p' "$0" | sed 's/^# \{0,1\}//'; exit 1;;
esac
