#!/bin/bash
# capture-trace.sh: ground truth for the macOS CS8409HDA driver, recorded from the Linux snd_hda_intel + cs8409 drivers
# on the Dell Vostro 3520 (CS8409/CS42L42, SSID 1028:0B94 = "Warlock MLK"). Linux only, needs sudo. Runs ~1.5 min.
#
#   bash tools/CS8409HDA/linux/capture-trace.sh [OUTDIR]      (default: tools/CS8409HDA/ref)
#
# It never re-probes the codec driver (sysfs "reconfig" or unbind/bind of hdaudioC0D0 makes the Linux cs8409 driver
# loop forever in cs8409_cs42l42_exec_verb). It only uses the normal runtime-PM path: with PipeWire stopped the codec
# suspends after power_save seconds, and the next open resumes it with the full CS8409 + CS42L42 init.
#
# Output in OUTDIR:
#   trace-play.txt     resume + init, 2 s tone, 1 s gap, 1 s tone (warm restart), cleanup, runtime suspend
#   hdaregs-play.txt   controller registers + DMA position samples while the first tone plays
#   trace-rec.txt      resume, tone + simultaneous internal-mic recording, suspend
#   rec-analysis.txt   1 kHz level in the internal-mic recording, with and without the tone (acoustic check)
set -uo pipefail
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=$(realpath -m "${1:-$HERE/../ref}")
T=/sys/kernel/tracing
CODEC=/sys/bus/hdaudio/devices/hdaudioC0D0
PCIDEV=/sys/bus/pci/devices/0000:00:1f.3
W=/tmp/cs8409-capture
mkdir -p "$OUT" "$W"

log() { echo "[$(date +%T)] $*"; }
die() { log "ERROR: $*"; exit 1; }

[[ $(cat /sys/class/sound/hwC0D0/vendor_id) == 0x10138409 ]] || die "codec 0 is not a CS8409"
OLD_BUF=$(sudo cat $T/buffer_size_kb | sed 's/ .*//')

restore() {
    sudo sh -c "echo 0 > $T/tracing_on; echo > $T/set_event; echo $OLD_BUF > $T/buffer_size_kb" 2>/dev/null
    [[ -f $W/asound.state ]] && sudo alsactl restore -f $W/asound.state 0 2>/dev/null
    systemctl --user start pipewire.socket pipewire-pulse.socket pipewire wireplumber pipewire-pulse 2>/dev/null
    log "tracing off, PipeWire restarted"
}
trap restore EXIT

# test signals: S32_LE stereo 48 kHz, 1 kHz sine with 50 ms fades
python3 - "$W" <<'EOF'
import math, struct, sys, wave
def tone(path, secs, dbfs, freq=1000.0, rate=48000):
    amp = 10 ** (dbfs / 20); n = int(rate * secs); fr = bytearray()
    for i in range(n):
        g = amp * min(1.0, i / 2400, (n - i) / 2400)
        s = int(g * math.sin(2 * math.pi * freq * i / rate) * 0x7fffffff)
        fr += struct.pack("<ii", s, s)
    w = wave.open(path, "wb"); w.setnchannels(2); w.setsampwidth(4); w.setframerate(rate); w.writeframes(bytes(fr)); w.close()
tone(sys.argv[1] + "/toneA.wav", 2.0, -24)
tone(sys.argv[1] + "/toneB.wav", 1.0, -24)
tone(sys.argv[1] + "/toneR.wav", 3.0, -20)
EOF

bash "$HERE/build-modules.sh" >/dev/null || die "module build failed"

wait_rpm() {   # wait_rpm STATE SECONDS: wait until the codec's runtime PM status is STATE
    local i
    for ((i = 0; i < $2 * 2; i++)); do
        [[ $(cat $CODEC/power/runtime_status) == "$1" ]] && return 0
        sleep 0.5
    done
    return 1
}
run_bg() {     # run_bg SECONDS CMD...: run CMD in the background, give up (without waiting) after SECONDS
    local secs=$1; shift
    "$@" & local pid=$! i
    for ((i = 0; i < secs * 10; i++)); do
        kill -0 $pid 2>/dev/null || { wait $pid; return $?; }
        sleep 0.1
    done
    log "WARNING: '$*' still running after ${secs}s (pid $pid), not waiting for it"
    return 124
}
wait_pid() {   # wait_pid PID SECONDS: wait for a background child, give up (without blocking) after SECONDS
    local i
    for ((i = 0; i < $2 * 10; i++)); do
        kill -0 $1 2>/dev/null || { wait $1; return $?; }
        sleep 0.1
    done
    log "WARNING: pid $1 still running after $2 s, not waiting for it"
    return 124
}
hdaregs_snapshot() {  # hdaregs_snapshot FILE: one-shot register dump (the module never stays loaded)
    sudo insmod /tmp/cs8409-kbuild/hdaregs/hdaregs.ko 2>/dev/null
    sudo dmesg | awk '/hdaregs: .* cfg TCSEL/ {buf = ""} /hdaregs:/ {buf = buf $0 "\n"} END {printf "%s", buf}' > "$1"
}
trace_start() { sudo sh -c "echo 0 > $T/tracing_on; echo > $T/trace; echo 1 > $T/tracing_on"; }
trace_save() {  # trace_save NAME
    sudo sh -c "echo 0 > $T/tracing_on"
    sudo cat $T/trace > "$OUT/trace-$1.txt"
    log "trace-$1.txt: $(grep -c hda_send_cmd "$OUT/trace-$1.txt") verbs, lost: $(sudo grep -m1 entries-in-buffer $T/trace)"
}

log "stopping PipeWire"
systemctl --user stop pipewire.socket pipewire-pulse.socket pipewire-pulse wireplumber pipewire
sleep 1
if sudo fuser /dev/snd/pcmC0D0p /dev/snd/pcmC0D0c /dev/snd/controlC0 >/dev/null 2>&1; then
    sudo fuser -v /dev/snd/* ; die "the HDA card is still in use"
fi
sudo alsactl store -f $W/asound.state 0 || true
log "controller runtime PM control=$(cat $PCIDEV/power/control) status=$(cat $PCIDEV/power/runtime_status), power_save=$(cat /sys/module/snd_hda_intel/parameters/power_save)"

sudo sh -c "
echo 0 > $T/tracing_on
echo 8192 > $T/buffer_size_kb
echo > $T/set_event
for e in hda:hda_send_cmd hda:hda_get_response hda:hda_unsol_event hda:snd_hdac_stream_start hda:snd_hdac_stream_stop \
         hda_controller:azx_pcm_open hda_controller:azx_pcm_close hda_controller:azx_pcm_hw_params \
         hda_controller:azx_pcm_prepare hda_controller:azx_pcm_trigger; do echo \$e >> $T/set_event; done
" || die "tracefs setup failed"

# ---- phase play
log "waiting for codec runtime suspend"
wait_rpm suspended 40 || die "codec did not suspend (status $(cat $CODEC/power/runtime_status))"
amixer -q -c0 cset name='Speaker Playback Switch' on || true
trace_start
log "tone A (2 s, -24 dBFS) on hw:0,0"
aplay -q -D hw:0,0 $W/toneA.wav & APID=$!
sleep 1
hdaregs_snapshot "$OUT/hdaregs-play.txt"
wait_pid $APID 15 || die "tone A playback did not finish"
sleep 1
log "tone B (1 s) right after (warm restart)"
run_bg 15 aplay -q -D hw:0,0 $W/toneB.wav || die "tone B playback did not finish"
log "waiting for runtime suspend after playback"
wait_rpm suspended 40 || log "WARNING: codec did not suspend after playback"
sleep 1
trace_save play

# ---- phase rec: acoustic check through the internal microphone (DMIC on the CS8409)
log "recording 3 s of room noise from the internal mic (no tone)"
wait_rpm suspended 40 || true
run_bg 15 arecord -q -D hw:0,0 -f S32_LE -r 48000 -c 2 -d 3 $W/rec-silence.wav || log "WARNING: silent recording failed"
wait_rpm suspended 40 || die "codec did not suspend before the recording test"
trace_start
log "tone R (3 s, -20 dBFS) + simultaneous internal-mic recording (4 s)"
arecord -q -D hw:0,0 -f S32_LE -r 48000 -c 2 -d 4 $W/rec-tone.wav & RPID=$!
sleep 0.5
run_bg 15 aplay -q -D hw:0,0 $W/toneR.wav || log "WARNING: tone R playback failed"
wait_pid $RPID 15 || log "WARNING: recording did not finish"
wait_rpm suspended 40 || log "WARNING: codec did not suspend after the recording test"
sleep 1
trace_save rec

python3 - "$W/rec-silence.wav" "$W/rec-tone.wav" > "$OUT/rec-analysis.txt" <<'EOF'
import sys, wave
import numpy as np
def level(path, f0=1000.0):
    w = wave.open(path); rate = w.getframerate(); ch = w.getnchannels()
    x = np.frombuffer(w.readframes(w.getnframes()), dtype="<i4").astype(np.float64).reshape(-1, ch) / 2**31
    x = x[int(0.6 * rate):]                       # skip the first 0.6 s (mic settling, tone fade-in)
    out = []
    for c in range(ch):
        s = x[:, c] - x[:, c].mean()
        win = np.hanning(len(s)); spec = np.abs(np.fft.rfft(s * win)) / (win.sum() / 2)
        f = np.fft.rfftfreq(len(s), 1 / rate)
        k = np.argmin(np.abs(f - f0)); peak = spec[k - 2:k + 3].max()
        band = (np.abs(f - f0) < 200) & (np.abs(f - f0) > 20)
        noise = np.median(spec[band])
        rms = np.sqrt(np.mean(s ** 2))
        out.append((20 * np.log10(peak + 1e-12), 20 * np.log10(peak / (noise + 1e-15)), 20 * np.log10(rms + 1e-12)))
    return out
for name, path in (("no tone", sys.argv[1]), ("tone", sys.argv[2])):
    try:
        for c, (lv, snr, rms) in enumerate(level(path)):
            print(f"{name:8s} ch{c}: 1 kHz {lv:7.1f} dBFS, {snr:5.1f} dB above the nearby noise floor, total RMS {rms:6.1f} dBFS")
    except Exception as e:
        print(f"{name}: analysis failed: {e}")
EOF
cat "$OUT/rec-analysis.txt"
cp /sys/class/sound/hwC0D0/init_pin_configs "$OUT/init_pin_configs.txt"
cp /sys/class/sound/hwC0D0/driver_pin_configs "$OUT/driver_pin_configs.txt"
cp $W/rec-tone.wav $W/rec-silence.wav "$OUT/" 2>/dev/null
log "done: $OUT"
