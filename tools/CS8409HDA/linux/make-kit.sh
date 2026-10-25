#!/bin/bash
# make-kit.sh: copy the macOS audio kit to the pendrive's MACINSTALL (exFAT) partition, from Linux.
#   bash tools/CS8409HDA/linux/make-kit.sh [MOUNTPOINT]      (default: where /dev/disk/by-label/MACINSTALL is mounted)
# Result: MOUNTPOINT/audio.sh (run it on macOS) and MOUNTPOINT/CS8409HDA/src/tools/... (sources it builds).
set -euo pipefail
REPO=$(cd "$(dirname "$0")/../../.." && pwd)
MI=${1:-$(findmnt -n -o TARGET /dev/disk/by-label/MACINSTALL 2>/dev/null || true)}
[[ -n $MI && -d $MI ]] || { echo "MACINSTALL not mounted (udisksctl mount -b /dev/disk/by-label/MACINSTALL)"; exit 1; }
K=$MI/CS8409HDA
S=$K/src/tools
rm -rf "$K/src"
mkdir -p "$S/CS8409HDA/core" "$S/AudShim" "$S/XeSpeakers" "$K/relatorios"
cp "$REPO/tools/build-kext.sh" "$S/"
cp "$REPO/tools/AudShim/AudShimDrv.h" "$S/AudShim/"
cp "$REPO/tools/CS8409HDA/CS8409HDA.cpp" "$REPO/tools/CS8409HDA/Info.plist" "$REPO/tools/CS8409HDA/cs8409ctl.c" "$S/CS8409HDA/"
cp "$REPO"/tools/CS8409HDA/core/*.[ch] "$S/CS8409HDA/core/"
cp "$REPO/tools/XeSpeakers/XeSpeakers.c" "$REPO/tools/XeSpeakers/Info.plist" "$REPO/tools/XeSpeakers/build.sh" "$S/XeSpeakers/"
cp "$REPO/tools/CS8409HDA/macos/audio.sh" "$MI/audio.sh"
cp "$REPO/tools/CS8409HDA/macos/tudo.sh" "$MI/tudo.sh"
# NootedGreen já com as correções dos panics de boot (o tudo.sh sobrepõe isto sobre o clone antes de compilar)
mkdir -p "$K/nootedgreen/src"
ditto --norsrc --noextattr "$REPO/src/NootedGreen" "$K/nootedgreen/src/NootedGreen" 2>/dev/null || \
  cp -R "$REPO/src/NootedGreen" "$K/nootedgreen/src/NootedGreen"
{
    echo "kit made $(date -Iseconds) on $(hostname) from $(git -C "$REPO" rev-parse --short HEAD) + working tree"
    (cd "$K/src" && find . -type f | sort | xargs sha256sum)
    (cd "$K/nootedgreen/src" && find . -type f | sort | xargs sha256sum)
} > "$K/kit-info.txt"
sync
echo "kit in $K ($(find "$K/src" "$K/nootedgreen/src" -type f | wc -l) files), scripts $MI/tudo.sh and $MI/audio.sh"
