#!/bin/bash
# run-harness.sh: test the CS8409HDA core (the code of the macOS kext) on Linux, on the real controller.
# Development only, needs sudo, takes ~30 s, Linux audio is unavailable meanwhile (PipeWire is stopped).
#
#   bash tools/CS8409HDA/linux/run-harness.sh [OUTDIR]          (default /tmp/cs8409-harness)
#
# 1. waits until the Linux codec is runtime-suspended, unbinds snd_hda_intel from 0000:00:1f.3 and binds the
#    cs8409test module instead (driver_override); 2. through /sys/kernel/debug/cs8409test: controller + codec
#    bring-up, a 1 kHz tone (-30 dBFS) through the speakers while recording the internal microphone, the same with
#    silence, DMA rate and position checks, register dumps, teardown, then a bring-up with the CS42L42 headset codec;
#    3. gives the controller back to snd_hda_intel, restarts PipeWire; 4. prints the tone level seen by the mic.
set -uo pipefail
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=${1:-/tmp/cs8409-harness}
DEV=0000:00:1f.3
D=/sys/kernel/debug/cs8409test
CODEC=/sys/bus/hdaudio/devices/hdaudioC0D0
mkdir -p "$OUT"
log() { echo "[$(date +%T)] $*"; }
die() { log "ERROR: $*"; exit 1; }
ctl() { sudo sh -c "echo '$1' > $D/ctl" || log "WARNING: command '$1' failed"; }

restore() {
    if [[ -e /sys/bus/pci/drivers/cs8409test/$DEV ]]; then
        ctl down
        sudo cat $D/log > "$OUT/harness-log.txt" 2>/dev/null
        sudo sh -c "echo $DEV > /sys/bus/pci/drivers/cs8409test/unbind"
    fi
    [[ -f /sys/bus/pci/devices/$DEV/driver_override ]] && sudo sh -c "echo > /sys/bus/pci/devices/$DEV/driver_override"
    if [[ ! -e /sys/bus/pci/drivers/snd_hda_intel/$DEV ]]; then
        sudo sh -c "echo $DEV > /sys/bus/pci/drivers/snd_hda_intel/bind" && log "controller back on snd_hda_intel" \
            || log "WARNING: snd_hda_intel did not take the controller back (reboot to restore Linux audio)"
    fi
    grep -q '^cs8409test ' /proc/modules && sudo rmmod cs8409test
    systemctl --user start pipewire.socket pipewire-pulse.socket pipewire wireplumber pipewire-pulse 2>/dev/null
    log "PipeWire restarted"
}

[[ $(cat /sys/bus/pci/devices/$DEV/device) == 0x51c8 ]] || die "$DEV is not the 8086:51C8 HDA controller"
bash "$HERE/build-modules.sh" >/dev/null || die "module build failed"
python3 - "$OUT" <<'EOF' || exit 1
import math, struct, sys
# 8192 frames = the whole 64 KiB ring, 171 cycles -> seamless loop at 1001.95 Hz (same tone as audctl drv test)
a = 10 ** (-30 / 20) * 2147483647
b = bytearray()
for i in range(8192):
    s = int(round(a * math.sin(2 * math.pi * 171 * i / 8192)))
    b += struct.pack("<ii", s, s)
open(sys.argv[1] + "/tone.raw", "wb").write(bytes(b))
open(sys.argv[1] + "/zero.raw", "wb").write(bytes(65536))
EOF

log "stopping PipeWire"
systemctl --user stop pipewire.socket pipewire-pulse.socket pipewire-pulse wireplumber pipewire
sleep 1
if sudo fuser /dev/snd/controlC0 /dev/snd/pcmC0D* /dev/snd/hwC0D* >/dev/null 2>&1; then
    sudo fuser -v /dev/snd/*
    systemctl --user start pipewire.socket pipewire-pulse.socket pipewire wireplumber pipewire-pulse
    die "the HDA card is still in use"
fi
for i in $(seq 1 80); do [[ $(cat $CODEC/power/runtime_status) == suspended ]] && break; sleep 0.5; done
log "Linux codec runtime status: $(cat $CODEC/power/runtime_status)"
trap restore EXIT

grep -q '^cs8409test ' /proc/modules && { sudo rmmod cs8409test || die "a previous cs8409test is still loaded"; }
sudo insmod /tmp/cs8409-kbuild/cs8409test/cs8409test.ko || die "insmod failed"
sudo sh -c "echo $DEV > /sys/bus/pci/drivers/snd_hda_intel/unbind" || die "unbind from snd_hda_intel failed"
sudo sh -c "echo cs8409test > /sys/bus/pci/devices/$DEV/driver_override"
sudo sh -c "echo $DEV > /sys/bus/pci/drivers/cs8409test/bind" || die "bind to cs8409test failed"
log "controller bound to cs8409test"

ctl up
ctl dump
sudo cat $D/log | grep -E 'up: |codec [0-9]|controller up|failed' | tail -5
sudo grep -q 'up: 0 ' $D/log || die "bring-up failed (see $OUT/harness-log.txt)"

log "tone through the speakers + internal mic recording"
sudo dd status=none if="$OUT/tone.raw" of=$D/oring bs=65536 count=1
ctl rec
ctl play
sleep 0.3
ctl rate
ctl pos
sleep 0.4
ctl recstop
sudo dd status=none if=$D/iring of="$OUT/rec-tone.raw" bs=65536 count=1
ctl dump
ctl stop

log "silence (noise floor)"
sudo dd status=none if="$OUT/zero.raw" of=$D/oring bs=65536 count=1
ctl rec
ctl play
sleep 1.2
ctl recstop
sudo dd status=none if=$D/iring of="$OUT/rec-silence.raw" bs=65536 count=1
ctl stop
ctl trace
ctl down

log "bring-up with the CS42L42 (headset codec) and its shutdown"
ctl "up hp"
ctl dump
ctl down

sudo cat $D/log > "$OUT/harness-log.txt"
grep -E 'up: |play: |rec: |rate |recstop|stop: |CS42L42|bring-up failed|no response|mismatch|stays|LOSIDV|PPCTL' \
    "$OUT/harness-log.txt" | cut -c 1-180

python3 - "$OUT" <<'EOF' | tee "$OUT/analysis.txt"
import sys
import numpy as np
d = sys.argv[1]
f0 = 171 * 48000 / 8192
for name in ("rec-silence", "rec-tone"):
    x = np.frombuffer(open(f"{d}/{name}.raw", "rb").read(), dtype="<i4").astype(np.float64).reshape(-1, 2) / 2**31
    for c in range(2):
        s = x[:, c] - x[:, c].mean()
        w = np.hanning(len(s)); sp = np.abs(np.fft.rfft(s * w)) / (w.sum() / 2)
        f = np.fft.rfftfreq(len(s), 1 / 48000)
        k = np.argmin(np.abs(f - f0)); peak = sp[k - 2:k + 3].max()
        noise = np.median(sp[(np.abs(f - f0) < 300) & (np.abs(f - f0) > 30)])
        print(f"{name:12s} ch{c}: {f0:.1f} Hz at {20*np.log10(peak+1e-12):6.1f} dBFS, "
              f"{20*np.log10(peak/(noise+1e-15)):5.1f} dB above the noise, RMS {20*np.log10(np.sqrt(np.mean(s**2))+1e-12):6.1f} dBFS, "
              f"nonzero samples {np.count_nonzero(x[:, c])}/{len(s)}")
EOF
log "done: $OUT"
