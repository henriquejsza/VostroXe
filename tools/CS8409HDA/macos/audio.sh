#!/bin/zsh
# Som interno do Dell Vostro 3520 no macOS Tahoe (alto-falantes + microfone interno), com o driver próprio
# CS8409HDA (controlador Intel HDA 8086:51C8 + Cirrus CS8409) e o plug-in de som XeSpeakers.
#
#   zsh /Volumes/MACINSTALL/audio.sh           1) compila e coloca o CS8409HDA.kext no pendrive. Depois REINICIE.
#   zsh /Volumes/MACINSTALL/audio.sh testar    2) depois do reboot: bipes + autoteste (alto-falante ouvido pelo
#                                                 microfone); se passar, instala o dispositivo de som do macOS
#   zsh /Volumes/MACINSTALL/audio.sh status    mostra o estado
#   zsh /Volumes/MACINSTALL/audio.sh off       tira o dispositivo de som e desliga o kext no pendrive
#
# Relatórios (para ler no Linux): /Volumes/MACINSTALL/CS8409HDA/relatorios/
# Se o macOS não iniciar depois do passo 1: entre no Linux; lá o kext pode ser desligado no pendrive.
# Boot-arg de emergência: -cs8409off (o kext não se conecta ao hardware).
set -e

KIT=${0:A:h}/CS8409HDA
WORK=$HOME/cs8409hda
B=$WORK/tools/build
REP=$KIT/relatorios
HAL=/Library/Audio/Plug-Ins/HAL/XeSpeakers.driver

ok()   { print -P "  %F{green}✓%f $1"; }
step() { print; print -P "%F{cyan}%B$1%b%f"; }
fail() { print; print -P "%F{red}✗%f $1"; exit 1; }

oc_dev() { diskutil list | awk '/OPENCORE/ {print $NF; exit}'; }

mount_oc() {
  local dev
  dev=$(oc_dev)
  [[ -n $dev ]] || fail "não achei o pendrive (partição OPENCORE). Conecte o pendrive e rode de novo."
  sudo diskutil mount $dev >/dev/null 2>&1 || true
  OC=$(diskutil info -plist $dev | plutil -extract MountPoint raw -o - - 2>/dev/null || true)
  [[ -n $OC ]] || OC=/Volumes/OPENCORE
  [[ -f $OC/EFI/OC/config.plist ]] || fail "não achei EFI/OC/config.plist na partição OPENCORE ($dev)."
}

umount_oc() {
  sudo dot_clean -m "$OC" 2>/dev/null || true
  sudo diskutil unmount "$OC" >/dev/null 2>&1 || true
}

# Kernel>Add: liga ($2 = YES) ou desliga (NO) a entrada do CS8409HDA.kext; cria no fim se não existir.
# Edita uma cópia temporária, valida com plutil -lint e só então troca o arquivo do pendrive (nunca fica pela metade).
kext_entry() {
  local f=$1 en=${2:-YES} n i bp t
  t=$(mktemp /tmp/cs8409-config.XXXXXX)
  cp "$f" "$t"
  n=$(plutil -extract Kernel.Add raw -o - "$t" 2>/dev/null || true)
  [[ $n == <-> ]] || { rm -f "$t"; fail "não consegui ler Kernel>Add de $f (nada foi alterado)"; }
  for ((i = 0; i < n; i++)); do
    bp=$(plutil -extract Kernel.Add.$i.BundlePath raw -o - "$t" 2>/dev/null || true)
    if [[ $bp == CS8409HDA.kext ]]; then
      plutil -replace Kernel.Add.$i.Enabled -bool $en "$t" && plutil -lint "$t" >/dev/null ||
        { rm -f "$t"; fail "não consegui editar $f (nada foi alterado)"; }
      sudo cp "$t" "$f.novo" && sudo mv "$f.novo" "$f"
      rm -f "$t"
      return 0
    fi
  done
  if [[ $en != YES ]]; then rm -f "$t"; return 0; fi
  if ! { plutil -insert Kernel.Add.$n -dictionary "$t" &&
         plutil -insert Kernel.Add.$n.Arch -string x86_64 "$t" &&
         plutil -insert Kernel.Add.$n.BundlePath -string CS8409HDA.kext "$t" &&
         plutil -insert Kernel.Add.$n.Comment -string "som interno Vostro 3520 (HDA + Cirrus CS8409)" "$t" &&
         plutil -insert Kernel.Add.$n.Enabled -bool YES "$t" &&
         plutil -insert Kernel.Add.$n.ExecutablePath -string Contents/MacOS/CS8409HDA "$t" &&
         plutil -insert Kernel.Add.$n.MaxKernel -string "" "$t" &&
         plutil -insert Kernel.Add.$n.MinKernel -string "" "$t" &&
         plutil -insert Kernel.Add.$n.PlistPath -string Contents/Info.plist "$t" &&
         plutil -lint "$t" >/dev/null; }; then
    rm -f "$t"
    fail "não consegui editar $f (nada foi alterado)"
  fi
  [[ -f $f.antes-cs8409 ]] || sudo cp "$f" "$f.antes-cs8409"
  sudo cp "$t" "$f.novo" && sudo mv "$f.novo" "$f"
  rm -f "$t"
}

build() {
  step "1/2 Compilação"
  [[ $(uname -m) == x86_64 ]] || fail "isto só funciona em Mac Intel."
  [[ -d $KIT/src/tools/CS8409HDA ]] || fail "não achei os fontes em $KIT/src (o pendrive foi preparado no Linux?)"
  xcode-select -p >/dev/null 2>&1 || fail "faltam as Command Line Tools: rode  xcode-select --install  e depois este script de novo."
  rm -rf "$WORK"
  mkdir -p "$WORK"
  ditto --norsrc --noextattr "$KIT/src" "$WORK"
  zsh "$WORK/tools/build-kext.sh" CS8409HDA
  clang -O2 -Wall -o "$B/cs8409ctl" "$WORK/tools/CS8409HDA/cs8409ctl.c" -framework IOKit -framework CoreFoundation
  zsh "$WORK/tools/XeSpeakers/build.sh"
  codesign -v "$B/CS8409HDA.kext" && codesign -v "$B/XeSpeakers.driver" || fail "assinatura dos binários falhou"
  ok "CS8409HDA.kext, cs8409ctl e XeSpeakers.driver em $B"
}

install_kext() {
  step "2/2 Kext no pendrive (pede a sua senha)"
  mount_oc
  local K=$OC/EFI/OC/Kexts c
  sudo rm -rf "$K/CS8409HDA.kext"
  sudo ditto --norsrc --noextattr --noqtn --noacl "$B/CS8409HDA.kext" "$K/CS8409HDA.kext"
  for c in config.plist config-accel.plist config-install.plist; do
    [[ -f $OC/EFI/OC/$c ]] && kext_entry "$OC/EFI/OC/$c" YES && ok "entrada no $c"
  done
  umount_oc
  ok "CS8409HDA.kext no pendrive"
}

hal_install() {
  local I
  I=$(ioreg -r -c CS8409HDA -d 1 2>/dev/null | awk -F'= ' '/"AudShimInterface"/ {print $2}')
  [[ $I == 8 || $I == 9 ]] || fail "o CS8409HDA não está carregado (interface '${I:-nenhuma}')"
  sudo rm -rf "$HAL"
  sudo ditto "$B/XeSpeakers.driver" "$HAL"
  sudo chown -R root:wheel "$HAL"
  # O coreaudiod roda como _coreaudiod (uid 202), não root. O fonte vindo do pendrive exFAT fica 0700, então o
  # Info.plist nasce ilegível para o coreaudiod e o plug-in é ignorado em silêncio (sem dispositivo, sem log).
  # Deixa tudo legível/atravessável por todos (gravável só pelo dono), como os outros plug-ins HAL.
  sudo chmod -R u=rwX,go=rX "$HAL"
  sudo killall coreaudiod 2>/dev/null || true
  sleep 5
}

case ${1:-} in
"")
  build
  install_kext
  print
  print -P "%BPronto.%b Reinicie com o pendrive conectado e depois rode:"
  print "  zsh /Volumes/MACINSTALL/audio.sh testar"
  ;;
testar)
  step "1/3 Kext"
  kmutil showloaded 2>/dev/null | grep -q local.xe.CS8409HDA ||
    fail "o CS8409HDA não está carregado. Rodou  zsh /Volumes/MACINSTALL/audio.sh  e reiniciou com o pendrive?"
  [[ -x $B/cs8409ctl ]] || build
  ok "CS8409HDA carregado"
  if [[ -d $HAL ]]; then
    print "  o dispositivo de som (XeSpeakers) já está instalado e ocupa o hardware: tirando para o teste"
    sudo rm -rf "$HAL"
    sudo killall coreaudiod 2>/dev/null || true
    sleep 3
  fi
  step "2/3 Autoteste: você vai ouvir bipes nos alto-falantes"
  mkdir -p "$REP"
  R=$REP/relatorio-$(date +%Y%m%d-%H%M%S).txt
  set +e
  "$B/cs8409ctl" report "$R" | grep -E 'RESULT|summary|rises|DMA rate|OPEN|FAILED|!!'
  RC=$pipestatus[1]
  set -e
  log show --last 5m --style compact --predicate 'senderImagePath CONTAINS "CS8409HDA" OR eventMessage CONTAINS "CS8409HDA"' \
    > "${R%.txt}-log.txt" 2>/dev/null || true
  print "  relatório: $R"
  if (( RC != 0 )); then
    fail "o autoteste falhou. Volte ao Linux e me diga: eu leio o relatório no pendrive."
  fi
  ok "alto-falantes e microfone funcionando no teste"
  step "3/3 Dispositivo de som do macOS (pede a sua senha)"
  hal_install
  if system_profiler SPAudioDataType 2>/dev/null | grep -q "Alto-falantes internos"; then
    ok "\"Alto-falantes internos\" e \"Microfone interno\" disponíveis"
  else
    print "  o macOS ainda não listou o dispositivo; espere alguns segundos e confira em Ajustes > Som"
  fi
  log show --last 2m --style compact --predicate 'subsystem == "local.xe.XeSpeakers" OR eventMessage CONTAINS "CS8409HDA"' \
    > "${R%.txt}-hal.txt" 2>/dev/null || true
  print
  print -P "%BPronto.%b Em Ajustes do Sistema > Som, escolha \"Alto-falantes internos\" (Saída) e"
  print "  \"Microfone interno\" (Entrada). O volume começa em 30%."
  ;;
status)
  kmutil showloaded 2>/dev/null | grep -q local.xe.CS8409HDA && ok "CS8409HDA carregado" || print "  CS8409HDA não carregado"
  [[ -x $B/cs8409ctl ]] && "$B/cs8409ctl" info || true
  [[ -d $HAL ]] && ok "XeSpeakers instalado" || print "  XeSpeakers não instalado"
  system_profiler SPAudioDataType 2>/dev/null | grep -E '^ {8}[^ ].*:$|Default (Output|Input) Device: Yes' || true
  ;;
off)
  sudo rm -rf "$HAL"
  sudo killall coreaudiod 2>/dev/null || true
  mount_oc
  for c in config.plist config-accel.plist config-install.plist; do
    [[ -f $OC/EFI/OC/$c ]] && kext_entry "$OC/EFI/OC/$c" NO
  done
  umount_oc
  ok "dispositivo de som removido e kext desligado no pendrive. Reinicie."
  ;;
*)
  print "uso: zsh audio.sh [testar|status|off]"
  exit 1
  ;;
esac
