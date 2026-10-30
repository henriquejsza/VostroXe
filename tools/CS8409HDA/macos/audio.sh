#!/bin/zsh
# Internal audio of the Dell Vostro 3520 on macOS Tahoe (speakers + internal microphone): the CS8409HDA kext (Intel HDA
# controller 8086:51C8 + Cirrus CS8409) and the XeSpeakers HAL plug-in. Run it on macOS, from a clone of this
# repository on an APFS disk:
#
#   zsh tools/CS8409HDA/macos/audio.sh           build CS8409HDA.kext, cs8409ctl and XeSpeakers.driver (no install)
#   zsh tools/CS8409HDA/macos/audio.sh efi       also put the new CS8409HDA.kext on the OpenCore partition. Reboot.
#   zsh tools/CS8409HDA/macos/audio.sh test      after the reboot: beeps + self-test (the speakers recorded by the
#                                                internal mic); if it passes, installs the macOS sound device
#   zsh tools/CS8409HDA/macos/audio.sh status    show the state
#   zsh tools/CS8409HDA/macos/audio.sh off       remove the sound device and disable the kext in the configs
#
# The repository's EFI already ships CS8409HDA.kext, enabled in both configs; "efi" is for a kext you changed.
# The OpenCore partition is found by its label (OPENCORE, the install USB) or picked with OC_DEV=diskXsY.
# Reports go to ~/Library/Logs/CS8409HDA/. Emergency boot-arg: -cs8409off (the kext does not touch the hardware).
set -e

REPO=${0:A:h:h:h:h}
B=$REPO/tools/build
REP=$HOME/Library/Logs/CS8409HDA
HAL=/Library/Audio/Plug-Ins/HAL/XeSpeakers.driver
CONFIGS=(config.plist config-accel.plist config-install.plist)

ok()   { print -P "  %F{green}✓%f $1"; }
step() { print; print -P "%F{cyan}%B$1%b%f"; }
fail() { print; print -P "%F{red}✗%f $1"; exit 1; }

oc_dev() { [[ -n ${OC_DEV:-} ]] && { print -r -- $OC_DEV; return; }; diskutil list | awk '/OPENCORE/ {print $NF; exit}'; }

mount_oc() {
  local dev
  dev=$(oc_dev)
  [[ -n $dev ]] || fail "no OPENCORE partition found. Connect the USB drive, or set OC_DEV=diskXsY (see diskutil list)."
  sudo diskutil mount $dev >/dev/null 2>&1 || true
  OC=$(diskutil info -plist $dev | plutil -extract MountPoint raw -o - - 2>/dev/null || true)
  [[ -n $OC && -f $OC/EFI/OC/config.plist ]] || fail "no EFI/OC/config.plist on $dev."
}

umount_oc() {
  sudo dot_clean -m "$OC" 2>/dev/null || true
  sudo diskutil unmount "$OC" >/dev/null 2>&1 || true
}

# Kernel>Add: enable ($2 = YES) or disable (NO) the CS8409HDA.kext entry; append it if missing. Edits a temporary
# copy, checks it with plutil -lint and only then replaces the config (never left half-written).
kext_entry() {
  local f=$1 en=${2:-YES} n i bp t
  t=$(mktemp /tmp/cs8409-config.XXXXXX)
  cp "$f" "$t"
  n=$(plutil -extract Kernel.Add raw -o - "$t" 2>/dev/null || true)
  [[ $n == <-> ]] || { rm -f "$t"; fail "could not read Kernel>Add in $f (nothing changed)"; }
  for ((i = 0; i < n; i++)); do
    bp=$(plutil -extract Kernel.Add.$i.BundlePath raw -o - "$t" 2>/dev/null || true)
    if [[ $bp == CS8409HDA.kext ]]; then
      plutil -replace Kernel.Add.$i.Enabled -bool $en "$t" && plutil -lint "$t" >/dev/null ||
        { rm -f "$t"; fail "could not edit $f (nothing changed)"; }
      sudo cp "$t" "$f.new" && sudo mv "$f.new" "$f"
      rm -f "$t"
      return 0
    fi
  done
  if [[ $en != YES ]]; then rm -f "$t"; return 0; fi
  if ! { plutil -insert Kernel.Add.$n -dictionary "$t" &&
         plutil -insert Kernel.Add.$n.Arch -string x86_64 "$t" &&
         plutil -insert Kernel.Add.$n.BundlePath -string CS8409HDA.kext "$t" &&
         plutil -insert Kernel.Add.$n.Comment -string "Vostro 3520 internal audio (HDA + Cirrus CS8409)" "$t" &&
         plutil -insert Kernel.Add.$n.Enabled -bool YES "$t" &&
         plutil -insert Kernel.Add.$n.ExecutablePath -string Contents/MacOS/CS8409HDA "$t" &&
         plutil -insert Kernel.Add.$n.MaxKernel -string "" "$t" &&
         plutil -insert Kernel.Add.$n.MinKernel -string "" "$t" &&
         plutil -insert Kernel.Add.$n.PlistPath -string Contents/Info.plist "$t" &&
         plutil -lint "$t" >/dev/null; }; then
    rm -f "$t"
    fail "could not edit $f (nothing changed)"
  fi
  [[ -f $f.before-cs8409 ]] || sudo cp "$f" "$f.before-cs8409"
  sudo cp "$t" "$f.new" && sudo mv "$f.new" "$f"
  rm -f "$t"
}

build() {
  step "Build"
  [[ $(uname -m) == x86_64 ]] || fail "this only works on an Intel Mac."
  xcode-select -p >/dev/null 2>&1 || fail "the Command Line Tools are missing: run  xcode-select --install  and then this script again."
  zsh "$REPO/tools/build-kext.sh" CS8409HDA
  clang -O2 -Wall -o "$B/cs8409ctl" "$REPO/tools/CS8409HDA/cs8409ctl.c" -framework IOKit -framework CoreFoundation
  zsh "$REPO/tools/XeSpeakers/build.sh"
  codesign -v "$B/CS8409HDA.kext" && codesign -v "$B/XeSpeakers.driver" || fail "signing the binaries failed"
  ok "CS8409HDA.kext, cs8409ctl and XeSpeakers.driver in $B"
}

install_kext() {
  step "Kext on the OpenCore partition (asks for your password)"
  mount_oc
  local K=$OC/EFI/OC/Kexts c
  sudo rm -rf "$K/CS8409HDA.kext"
  sudo ditto --norsrc --noextattr --noqtn --noacl "$B/CS8409HDA.kext" "$K/CS8409HDA.kext"
  for c in $CONFIGS; do
    [[ -f $OC/EFI/OC/$c ]] && kext_entry "$OC/EFI/OC/$c" YES && ok "entry in $c"
  done
  umount_oc
  ok "CS8409HDA.kext on $OC"
}

hal_install() {
  local I
  I=$(ioreg -r -c CS8409HDA -d 1 2>/dev/null | awk -F'= ' '/"AudShimInterface"/ {print $2}')
  [[ $I == 8 || $I == 9 ]] || fail "CS8409HDA is not loaded (interface '${I:-none}')"
  sudo rm -rf "$HAL"
  sudo ditto "$B/XeSpeakers.driver" "$HAL"
  sudo chown -R root:wheel "$HAL"
  # coreaudiod runs as _coreaudiod (uid 202), not root: a bundle copied from an exFAT drive keeps mode 0700, its
  # Info.plist is then unreadable for coreaudiod and the plug-in is silently ignored. Make it world-readable.
  sudo chmod -R u=rwX,go=rX "$HAL"
  sudo killall coreaudiod 2>/dev/null || true
  sleep 5
}

case ${1:-} in
"")
  build
  print
  print "  Built, nothing installed. The repository's EFI already has CS8409HDA.kext; to put this build there:"
  print "    zsh ${0:A} efi"
  ;;
efi)
  build
  install_kext
  print
  print -P "%BDone.%b Reboot, then run:  zsh ${0:A} test"
  ;;
test)
  step "1/3 Kext"
  kmutil showloaded 2>/dev/null | grep -q local.xe.CS8409HDA ||
    fail "CS8409HDA is not loaded. Is CS8409HDA.kext enabled in the config.plist you boot?"
  [[ -x $B/cs8409ctl && -d $B/XeSpeakers.driver ]] || build
  ok "CS8409HDA loaded"
  if [[ -d $HAL ]]; then
    print "  the sound device (XeSpeakers) is installed and holds the hardware: removing it for the test"
    sudo rm -rf "$HAL"
    sudo killall coreaudiod 2>/dev/null || true
    sleep 3
  fi
  step "2/3 Self-test: you will hear beeps from the speakers"
  mkdir -p "$REP"
  R=$REP/report-$(date +%Y%m%d-%H%M%S).txt
  set +e
  "$B/cs8409ctl" report "$R" | grep -E 'RESULT|summary|rises|DMA rate|OPEN|FAILED|!!'
  RC=$pipestatus[1]
  set -e
  command log show --last 5m --style compact --predicate 'senderImagePath CONTAINS "CS8409HDA" OR eventMessage CONTAINS "CS8409HDA"' \
    > "${R%.txt}-log.txt" 2>/dev/null || true
  print "  report: $R"
  (( RC == 0 )) || fail "the self-test failed; the report above has the details."
  ok "speakers and microphone work in the test"
  step "3/3 macOS sound device (asks for your password)"
  hal_install
  if system_profiler SPAudioDataType 2>/dev/null | grep -q "Alto-falantes internos"; then
    ok "\"Alto-falantes internos\" and \"Microfone interno\" available"
  else
    print "  macOS does not list the device yet; wait a few seconds and check System Settings > Sound"
  fi
  command log show --last 2m --style compact --predicate 'subsystem == "local.xe.XeSpeakers" OR eventMessage CONTAINS "CS8409HDA"' \
    > "${R%.txt}-hal.txt" 2>/dev/null || true
  print
  print -P "%BDone.%b In System Settings > Sound pick \"Alto-falantes internos\" (output) and \"Microfone interno\" (input)."
  print "  Volume starts at 30%."
  ;;
status)
  kmutil showloaded 2>/dev/null | grep -q local.xe.CS8409HDA && ok "CS8409HDA loaded" || print "  CS8409HDA not loaded"
  [[ -x $B/cs8409ctl ]] && "$B/cs8409ctl" info || true
  [[ -d $HAL ]] && ok "XeSpeakers installed" || print "  XeSpeakers not installed"
  system_profiler SPAudioDataType 2>/dev/null | grep -E '^ {8}[^ ].*:$|Default (Output|Input) Device: Yes' || true
  ;;
off)
  sudo rm -rf "$HAL"
  sudo killall coreaudiod 2>/dev/null || true
  mount_oc
  for c in $CONFIGS; do
    [[ -f $OC/EFI/OC/$c ]] && kext_entry "$OC/EFI/OC/$c" NO
  done
  umount_oc
  ok "sound device removed and the kext disabled in the configs. Reboot."
  ;;
*)
  print "usage: zsh audio.sh [efi|test|status|off]"
  exit 1
  ;;
esac
