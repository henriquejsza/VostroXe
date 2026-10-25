#!/bin/bash
# Build the Linux helper modules (development only) against the running kernel, out of tree:
#   bash tools/CS8409HDA/linux/build-modules.sh   ->  /tmp/cs8409-kbuild/<name>/<name>.ko
#   hdaregs     one-shot read-only register snapshot while snd_hda_intel owns the controller
#   cs8409test  harness that runs tools/CS8409HDA/core (the macOS kext's code) on the controller
set -euo pipefail
SRC=$(cd "$(dirname "$0")" && pwd)
CORE=$SRC/../core
KB=/usr/lib/modules/$(uname -r)/build
OUT=/tmp/cs8409-kbuild
for m in hdaregs cs8409test; do
    rm -rf "$OUT/$m" && mkdir -p "$OUT/$m"
    cp "$SRC/$m/$m.c" "$OUT/$m/"
    [[ $m == cs8409test ]] && cp "$CORE"/*.c "$CORE"/*.h "$OUT/$m/"
    printf 'obj-m := %s.o\nccflags-y := -Wall -Wno-unused-function\n' "$m" > "$OUT/$m/Makefile"
    make -s -C "$KB" M="$OUT/$m" modules
    echo "built $OUT/$m/$m.ko"
done
