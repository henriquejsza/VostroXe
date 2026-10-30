#!/bin/zsh
# hdmi-diag.sh: one-shot, READ-ONLY macOS snapshot for the Dell Vostro 3520 HDMI bring-up (DDI B / pipe B / PHY B).
# Writes nothing to hardware or NVRAM: no `xectl wr`, no `nvram` writes, no kext loading. It only reads and prints.
#
#   zsh tools/diagnostics/hdmi-diag.sh <label>
#     -> writes ./hdmi-diag-<label>-<timestamp>.txt in the current directory and prints its path.
#
# Register values come from XeShim via `xectl rd <off>` when XeShim is loaded; otherwise the script prints the exact
# build/load steps (it never loads anything itself). Every ADL-P offset is named after its i915 macro in a comment.
#
# Iteration 2 (commander findings F6):
#  (a) probe one register first; if the read fails (XeShim not loaded), print instructions instead of a ???? table.
#  (b) build/load steps match the repo (xectl and XeShim); the XeShim *load* line is marked "not in repo docs".
#  (c) the register table is parsed from docs/HDMI-TMDS.md at runtime so EVERY captured register is covered, minus the
#      ones with read side effects (justified inline); named registers not in the capture are appended; values are
#      normalized (lowercase, 8 hex digits) before comparing.
#  (d) the kernel-log query is predicate-filtered and covers the whole current boot (`log show --last boot`, with a
#      time-window fallback), matching XeHDMI / V183.PGE / hdmiargs / hdmitrig lines.
#  (e) the newest kernel panic report (if any) is collected read-only.
#  (f) read-only; `zsh -n` passes.
#
# Iteration 3 (fix pass 2):
#  - reads displaypolicyd's OWN log file /private/var/log/displaypolicy/displaypolicyd.log (+ rotated siblings),
#    directly if readable else via `sudo -n`; the unified-log query is kept.
#  - at start, if not root and stdin is a terminal, `sudo -v` once so the later read-only `sudo -n` work; never
#    writes anything as root.
#  - each `log show` query runs ONCE; the time-window variant is the fallback only on a non-zero exit.
#  - long sections keep the first 60 AND the last 200 lines (hotplug lines are at the END of the boot).
#  - a SUMMARY section near the top, computed after the other sections (body is built in a temp file, then the
#    report is assembled: header + SUMMARY + body).
#  - DP_FILELOG env var overrides the displaypolicyd log path (for the Linux test). Still read-only, one output file.
set -u
LABEL=${1:-run}
TS=$(date +%Y%m%d-%H%M%S)
OUT="$PWD/hdmi-diag-${LABEL}-${TS}.txt"
# PROGRESSIVE WRITE (fix 2026-10-26): the previous version assembled $OUT only at the very END (header+SUMMARY+BODY),
# so a run interrupted before the end left a 0-byte file (three such files on the 2026-10-26 runs). Now the header is
# written to $OUT immediately and every section is appended to $OUT as it is produced; the SUMMARY is computed last
# and appended at the END (and printed on screen). An interrupted run therefore keeps everything produced so far.
: > "$OUT"
{
  print -r -- "# HDMI diagnostic — label=$LABEL  $TS"
  print -r -- "# Vostro 3520: HDMI on DDI B, combo PHY B, pipe B, GMBUS pin 2 (1920x1080@60 max). READ-ONLY."
  print -r -- "# (SUMMARY is at the END of this file; an interrupted run keeps the sections produced so far.)"
  print -r -- ""
} >> "$OUT"
# `out` is this script's report-writer; it appends directly to $OUT (progressive). It used to be named `log`, which
# SHADOWED macOS /usr/bin/log, so every `log show ...` below silently wrote its own arguments into the report instead
# of running. Renamed to `out`; the system tool is always invoked as `command log` so no function can shadow it.
out() { print -r -- "$@" >> "$OUT"; }
sec() { out ""; out "== $1"; }
# BODY kept as an alias of $OUT so the existing `>> "$BODY"` section writers also append progressively.
BODY="$OUT"

# displaypolicyd's own log file (not the unified log). Overridable for the Linux test via DP_FILELOG.
DP_FILELOG=${DP_FILELOG:-/private/var/log/displaypolicy/displaypolicyd.log}

# sudo priming: if not root and we have a terminal, refresh the sudo timestamp ONCE so the later read-only
# `sudo -n` reads (the displaypolicyd file log) do not each prompt. Never writes anything as root. If it fails,
# continue; the sudo-gated sections will say they were skipped.
SUDO_OK=0
if [[ $(id -u) -ne 0 ]]; then
  if [[ -t 0 ]]; then
    if sudo -v 2>/dev/null; then SUDO_OK=1; fi
  fi
else
  SUDO_OK=1
fi

# capN: append at most the FIRST `head` lines and the LAST `tail` lines of stdin to BODY, with the total count.
# Usage:  some_command | capN <head> <tail> "label"
capN() {
  local h=$1 t=$2 label=$3 tmp n
  tmp=$(mktemp 2>/dev/null) || tmp="$OUT.capN.$$"
  cat > "$tmp"
  n=$(wc -l < "$tmp" | tr -d ' ')
  if (( n <= h + t )); then
    cat "$tmp" >> "$BODY"
    out "[$label: $n line(s) total]"
  else
    head -n "$h" "$tmp" >> "$BODY"
    out "[$label: ... $((n - h - t)) line(s) omitted ...]"
    tail -n "$t" "$tmp" >> "$BODY"
    out "[$label: $n line(s) total, showing first $h + last $t]"
  fi
  rm -f "$tmp"
}

REPO=${0:A:h:h:h}                 # .../tools/diagnostics/hdmi-diag.sh -> repo root
TMDS="$REPO/docs/HDMI-TMDS.md"
TB="$REPO/tools/build"

# xectl: built into tools/build/ or on $PATH. Read-only use here (rd only).
X=""
for c in "$TB/xectl" "$(command -v xectl 2>/dev/null)"; do [[ -x $c ]] && { X=$c; break; }; done

# (the report header is written during the final assembly, before the SUMMARY.)

sec "macOS / kernel / boot-args"
sw_vers >> "$BODY" 2>&1
out "kernel: $(uname -r)"
# F7: confirm the boot-args the kernel actually received (vs what NVRAM holds) — the SYSLOG 'ngreen hdmiargs:' line
# (matched in the kernel-log section below) is the second confirmation that each ngreenhdmi* arg survived.
out "kern.bootargs: $(sysctl -n kern.bootargs 2>/dev/null)"
out "nvram boot-args: $(nvram boot-args 2>/dev/null | sed 's/^boot-args[[:space:]]*//')"
out "kern.msgbuf: $(sysctl -n kern.msgbuf 2>/dev/null) bytes"

sec "Kext load state (NootedGreen / XeShim)"
kmutil showloaded 2>/dev/null | grep -iE 'NootedGreen|XeShim|TGL' | sed 's/^ */  /' >> "$BODY"

sec "Displays (system_profiler SPDisplaysDataType)"
system_profiler SPDisplaysDataType >> "$BODY" 2>&1

sec "IORegistry ngreen-* properties (our runtime diagnostics)"
ioreg -lw0 2>/dev/null | grep -iE 'ngreen-' | sed 's/^[ |]*//' >> "$BODY"

sec "Kernel log: NootedGreen (XeHDMI / XeFB / XeAUX / V183.PGE / hdmiargs / hdmitrig / ngreen)"
# F6(d): predicate-filtered query over the WHOLE current boot. `log show --last boot` exists on modern macOS; if it
# is rejected (older build), fall back to a wide time window. The predicate is far faster than piping to grep.
# BUGFIX: the report-writer used to be named log() and SHADOWED the macOS `log` binary, so bare `log show ...` just
# wrote its arguments as literal text to $OUT and the real query never ran (empty kernel-log section). The writer is
# now `out`; the system tool is always invoked as `command log` so no function can shadow it. The probe `if log show`
# also always succeeded via the old function (return 0) and forced the wrong branch; `command log` fixes that too so
# the time-window fallback can trigger on older builds.
# logwin <desc> <predicate>: run the predicate query over the current boot ONCE. The `log show --last boot` output
# is captured to a temp file; only if that command EXITS NON-ZERO (older build without `--last boot`) is the
# `--last 6h` variant run as a fallback. No query is ever run twice on success.
logwin() {
  local desc=$1 pred=$2 save=${3:-} tmp src
  tmp=$(mktemp 2>/dev/null) || tmp="$OUT.logwin.$$"
  if command log show --last boot --predicate "$pred" >"$tmp" 2>/dev/null; then
    src="log show --last boot"
  else
    command log show --last 6h --predicate "$pred" >"$tmp" 2>/dev/null || true
    src="log show --last 6h ('--last boot' failed)"
  fi
  out "--- $desc ($src) ---"
  cut -c1-240 "$tmp" | capN 60 200 "$desc"
  [[ -n $save ]] && cp "$tmp" "$save"    # keep the raw capture for the SUMMARY (no re-query)
  rm -f "$tmp"
}
PRED='eventMessage CONTAINS "XeHDMI" OR eventMessage CONTAINS "XeFB" OR eventMessage CONTAINS "XeAUX" OR eventMessage CONTAINS "V183.PGE" OR eventMessage CONTAINS "hdmiargs" OR eventMessage CONTAINS "hdmitrig" OR eventMessage CONTAINS "ngreen"'
# FIX3: keep the raw NootedGreen capture for the SUMMARY. The framebuffer-side strings ('Path has not been
# assigned', 'invokeHotplugHandler', 'StreamGetEDID') come from Apple's FB log AND from NootedGreen's IOLog bridge
# (the 'XeFB[DEFAULT] ...:1357 FB1: Path has not been assigned' lines), never from displaypolicyd — so we count them
# per source below instead of over the displaypolicyd text (where they are always 0, which falsely reads as success).
NGREEN_TMP=$(mktemp 2>/dev/null) || NGREEN_TMP="$OUT.ngreen.$$"
: > "$NGREEN_TMP"
logwin "NootedGreen (XeHDMI/XeFB/XeAUX/V183.PGE/hdmiargs/hdmitrig/ngreen)" "$PRED" "$NGREEN_TMP"

sec "Kernel buffer: dmesg (NootedGreen XeHDMI / XeFB / ngreen / hdmiargs — read-only)"
# dmesg capture (fix 2026-10-26): the unified-log query above sometimes misses NootedGreen's IOLog lines (they land
# in the kernel message buffer but not always in os_log). `dmesg` needs root on macOS, so we use `sudo -n` (primed by
# the `sudo -v` at the top). READ-ONLY: dmesg only prints the kernel buffer, it never writes. If `sudo -n` is not
# available/denied we say so and move on. Kept for the SUMMARY's 'XeHDMI ddc' line.
DMESG_TMP=$(mktemp 2>/dev/null) || DMESG_TMP="$OUT.dmesg.$$"
: > "$DMESG_TMP"
if [[ $SUDO_OK -eq 1 ]]; then
  if sudo -n dmesg > "$DMESG_TMP.raw" 2>/dev/null && [[ -s $DMESG_TMP.raw ]]; then
    grep -E 'XeHDMI|XeFB|XeAUX|ngreen|hdmiargs|hdmitrig|V183.PGE' "$DMESG_TMP.raw" > "$DMESG_TMP" 2>/dev/null || true
    cut -c1-240 "$DMESG_TMP" | capN 60 200 "dmesg NootedGreen lines"
  else
    out "(dmesg produced no output via 'sudo -n' — either denied, or the buffer has no matching lines)"
  fi
  rm -f "$DMESG_TMP.raw"
else
  out "(dmesg skipped: 'sudo -n' unavailable — run as root or prime sudo with 'sudo -v' first)"
fi

sec "Kernel log: Apple framebuffer (AppleIntelTGLGraphicsFramebuffer)"
# FIX3: keep the raw Apple-framebuffer capture for the per-source SUMMARY counts.
FB_TMP=$(mktemp 2>/dev/null) || FB_TMP="$OUT.fb.$$"
: > "$FB_TMP"
logwin "AppleIntelTGLGraphicsFramebuffer" 'sender == "AppleIntelTGLGraphicsFramebuffer"' "$FB_TMP"

sec "Kernel log: displaypolicyd"
DP_UNIFIED_TMP=$(mktemp 2>/dev/null) || DP_UNIFIED_TMP="$OUT.dpuni.$$"
: > "$DP_UNIFIED_TMP"
logwin "displaypolicyd" 'process == "displaypolicyd"' "$DP_UNIFIED_TMP"

sec "displaypolicyd FILE log (per-GPU /private/var/log/displaypolicy/displaypolicyd.0:2:0.log + siblings)"
# displaypolicyd also writes its OWN log file (format: 'YYYY-MM-DD HH:MM:SS.ffffff-ZZZZ: LEVEL: message'), separate
# from the unified log. It holds the 'Vendor portmap ...' and 'Populated addr ...' lines we key the SUMMARY on.
# Read each file DIRECTLY if readable, else via `sudo -n` (primed by the `sudo -v` at the top); if neither works,
# say so. Read-only: only `cat`, never a write. Rotated siblings are displaypolicyd.log.0, .1, ... and .*.gz.
# read_ro <file>: cat the file read-only (direct, else sudo -n); gz siblings via zcat/gzcat. Sets DP_READ_RC.
read_ro() {
  local f=$1
  if [[ $f == *.gz ]]; then
    if [[ -r $f ]]; then (gzcat "$f" 2>/dev/null || zcat "$f" 2>/dev/null); return $?; fi
    if [[ $SUDO_OK -eq 1 ]]; then sudo -n sh -c "gzcat '$f' 2>/dev/null || zcat '$f' 2>/dev/null"; return $?; fi
    return 1
  fi
  if [[ -r $f ]]; then cat "$f"; return $?; fi
  if [[ $SUDO_OK -eq 1 ]]; then sudo -n cat "$f" 2>/dev/null; return $?; fi
  return 1
}
DP_FILES=()
# Per-GPU preference (fix 2026-10-26): displaypolicyd writes the DETAILED log to a PER-GPU file named by b:d:f, e.g.
# displaypolicyd.0:2:0.log — that is where 'EDID read 2.0 failed', 'Vendor portmap', 'event: Insert' and
# 'DeviceState_IsUnknown' live. The old plain displaypolicyd.log holds only start/exit lines. We therefore:
#   1) honour an explicit DP_FILELOG override first (the Linux test points it at the copied capture);
#   2) otherwise gather ALL displaypolicyd*.log files in the folder and order them so the 0:2:0 (Vostro HDMI GPU)
#      file comes FIRST, then any other per-GPU files, then the bare displaypolicyd.log last.
DP_DIR=${DP_FILELOG:h}
DP_BDF="0:2:0"     # bus:device:function of the Vostro iGPU (8086:46a8) that drives the HDMI port
if [[ $DP_FILELOG != /private/var/log/displaypolicy/displaypolicyd.log ]]; then
  # explicit override (e.g. the Linux test capture): use exactly that file.
  [[ -e $DP_FILELOG ]] && DP_FILES+=("$DP_FILELOG")
else
  # default: prefer the per-GPU 0:2:0 file, then other per-GPU files, then the bare log, then rotated siblings.
  [[ -e "$DP_DIR/displaypolicyd.$DP_BDF.log" ]] && DP_FILES+=("$DP_DIR/displaypolicyd.$DP_BDF.log")
  for s in $DP_DIR/displaypolicyd.*.log(N); do
    [[ $s == "$DP_DIR/displaypolicyd.$DP_BDF.log" ]] && continue
    DP_FILES+=("$s")
  done
  [[ -e $DP_FILELOG ]] && DP_FILES+=("$DP_FILELOG")
  for s in ${DP_FILELOG}.*(N) $DP_DIR/displaypolicyd.log.*(N); do
    [[ $s == $DP_FILELOG ]] && continue
    DP_FILES+=("$s")
  done
fi
# de-dup while keeping order
typeset -A _seen; _dpf=()
for f in $DP_FILES; do [[ -n ${_seen[$f]:-} ]] && continue; _seen[$f]=1; _dpf+=("$f"); done
DP_FILES=($_dpf)
DP_FILELOG_TMP=$(mktemp 2>/dev/null) || DP_FILELOG_TMP="$OUT.dpfile.$$"
: > "$DP_FILELOG_TMP"
if (( ${#DP_FILES} == 0 )); then
  out "(no displaypolicyd file log at $DP_FILELOG — not present)"
else
  for f in $DP_FILES; do
    if read_ro "$f" > "$DP_FILELOG_TMP.one" 2>/dev/null && [[ -s $DP_FILELOG_TMP.one ]]; then
      out "--- $f ---"
      cat "$DP_FILELOG_TMP.one" >> "$DP_FILELOG_TMP"
      cut -c1-240 "$DP_FILELOG_TMP.one" | capN 60 200 "displaypolicyd file: $f"
    else
      out "--- $f --- (unreadable: not readable directly and 'sudo -n' unavailable or denied)"
    fi
    rm -f "$DP_FILELOG_TMP.one"
  done
fi
# DP_FILELOG_TMP now holds the concatenated readable file-log content (for the SUMMARY). Removed at the end.

sec "Kernel log: AppleGraphicsDevicePolicy (AGDC / AGDP)"
logwin "AppleGraphicsDevicePolicy" 'sender == "AppleGraphicsDevicePolicy" OR eventMessage CONTAINS "AGDC" OR eventMessage CONTAINS "AppleGraphicsDevicePolicy"'

sec "IORegistry framebuffer objects (index / online / connector-type / port / AGDC)"
# Reuses the 'Framebuffers (online / conector)' logic of tools/CS8409HDA/macos/video-externo.sh, extended with the
# AGDC-related properties that the AGDP/displaypolicyd path reads (read-only; no edits to that script).
ioreg -lw0 -r -c AppleIntelFramebuffer 2>/dev/null | \
  grep -iE '\+-o AppleIntelFramebuffer|"connector-type"|"IOFBDependentIndex"|"port-number"|"IOFBCurrentPixelCount"|"online"|"display-online"|"AGDCDiagnose"|"agdc-online"|"EDID UUID"|"IOFBUUID"' | \
  sed 's/|//g; s/^ *//' | capN 60 120 "AppleIntelFramebuffer objects"

sec "Newest kernel panic report (if any)"
# F6(e): read-only. macOS 26 writes panics to /Library/Logs/DiagnosticReports as *.panic (and legacy *.ips).
# (N) = NULL_GLOB so an empty match does not error (and is a no-op on Linux where the dir is absent).
PANIC=$(print -rl -- /Library/Logs/DiagnosticReports/*.panic(Nom) /Library/Logs/DiagnosticReports/Kernel*.ips(Nom) 2>/dev/null | head -1)
if [[ -n ${PANIC:-} && -r $PANIC ]]; then
  out "file: $PANIC"
  out "date: $(stat -f '%Sm' "$PANIC" 2>/dev/null)"
  out "--- panicString head ---"
  # .panic/.ips are JSON-ish; show the first panic/caller lines without dumping the whole file.
  grep -aoE '"panicString"[^,]*|panic\(cpu[^"]*|@[A-Za-z0-9_./:+-]+' "$PANIC" 2>/dev/null | head -8 >> "$BODY"
  head -c 600 "$PANIC" 2>/dev/null | tr -d '\0' >> "$BODY"
  out ""
else
  out "(no kernel panic report found in /Library/Logs/DiagnosticReports)"
fi

sec "Register table (macOS value vs Linux on/off from docs/HDMI-TMDS.md)"
# F6(a): probe ONE register first. If it fails, XeShim is not loaded -> print instructions, skip the table.
PROBE_OK=0
if [[ -n $X ]]; then
  pr=$("$X" rd 0x45404 2>/dev/null | awk '{print $3}')
  [[ -n $pr ]] && PROBE_OK=1
fi
if [[ $PROBE_OK -eq 0 ]]; then
  out "No register read (xectl missing or XeShim not loaded — a probe read of 0x45404 failed)."
  out "To enable (one time):"
  out "  1) build xectl:  clang -O2 -o tools/build/xectl tools/xectl.c -framework IOKit   (docs/INSTALL.md §6)"
  out "  2) build XeShim: zsh tools/build-kext.sh XeShim                                   (docs/INSTALL.md §6)"
  out "  3) load XeShim:  sudo kmutil load -p tools/build/XeShim.kext"
  out "       (standard kmutil load — the repo documents building XeShim but NOT a load command; this line is not"
  out "        from the repo docs. SIP/dev-mode may need it to be in a signed bundle or loaded via your boot EFI.)"
  out "  4) re-run:       zsh tools/diagnostics/hdmi-diag.sh $LABEL"
else
  # normalize a hex value to lowercase 8 digits (strip 0x, pad).
  norm() { local v=${1#0x}; v=${(L)v}; printf '%08s' "$v" | tr ' ' '0'; }

  # --- F6(c): registers with READ SIDE EFFECTS, excluded from the auto-parsed table (justified) ---
  #   0xc510c GMBUS3  : I2C data FIFO — reading it ADVANCES the FIFO and corrupts an in-flight EDID transfer.
  #   0xc5110 GMBUS5  : 2-byte index register tied to the same transfer state as GMBUS3; reading mid-transfer
  #                     can perturb the sequencer. Excluded for the same reason (conservative).
  typeset -A SKIP
  SKIP[0x0c510c]=1 SKIP[0xc510c]=1
  SKIP[0x0c5110]=1 SKIP[0xc5110]=1

  # --- Named registers (i915 macro) to ANNOTATE the parsed rows and to APPEND if absent from the capture ---
  # F6(c): fix the misnamed DPLL rows. The capture's 0x164b** block is the DPLL0 DIV0 region (_TGL_DPLL0_DIV0
  # 0x164B00) and 0x164c** is the DPLL1 DIV0 region (_TGL_DPLL1_DIV0 0x164C00) — NOT CFGCR. The real CFGCR/DIV0
  # macros (i915 intel_display_regs.h:3023-3034, used by ADL-P via TGL_DPLL_CFGCR0/1 in intel_dpll_mgr.c:3829):
  #   _TGL_DPLL0_CFGCR0 0x164284  _TGL_DPLL0_CFGCR1 0x164288  _TGL_DPLL0_DIV0 0x164B00
  #   _TGL_DPLL1_CFGCR0 0x16428C  _TGL_DPLL1_CFGCR1 0x164290  _TGL_DPLL1_DIV0 0x164C00
  # CDCLK: 0x46070 BXT_DE_PLL_ENABLE (regs.h:3077), 0x46000 CDCLK_CTL (regs.h:2774). 0x45254 _PIPEDMC_CONTROL_B
  # (intel_dmc_regs.h:281). 0x45008 _DBUF_CTL_S0 (skl_watermark_regs.h). The duplicate 0x46144 TRANS_CLK_SEL_B row
  # from iteration 1 is dropped (it is the same register already named REG_46144 in the capture).
  typeset -A NAME
  NAME[0x045008]=DBUF_CTL_S0           NAME[0x045254]=PIPEDMC_CONTROL_B
  NAME[0x045400]=HSW_PWR_WELL_CTL1     NAME[0x045404]=HSW_PWR_WELL_CTL2_PW_B
  NAME[0x04540c]=HSW_PWR_WELL_CTL4     NAME[0x045450]=ICL_PWR_WELL_CTL_DDI1
  NAME[0x045454]=ICL_PWR_WELL_CTL_DDI2 NAME[0x046000]=CDCLK_CTL
  NAME[0x046010]=LCPLL1_CTL_DPLL0      NAME[0x046014]=LCPLL2_CTL_DPLL1
  NAME[0x046070]=BXT_DE_PLL_ENABLE     NAME[0x046144]=TRANS_CLK_SEL_B
  NAME[0x164284]=TGL_DPLL0_CFGCR0      NAME[0x164288]=TGL_DPLL0_CFGCR1
  NAME[0x16428c]=TGL_DPLL1_CFGCR0      NAME[0x164290]=TGL_DPLL1_CFGCR1
  NAME[0x164280]=DPCLKA_CFGCR0         NAME[0x164e80]=DPCLKA_CFGCR0_MIRROR
  NAME[0x164b00]=TGL_DPLL0_DIV0        NAME[0x164c00]=TGL_DPLL1_DIV0
  NAME[0x164b54]=DPLL0_DIV0_region     NAME[0x164c54]=DPLL1_DIV0_region
  NAME[0x06c00c]=PHY_B_PORT_COMP_DW    NAME[0x064100]=DDI_BUF_CTL_B
  NAME[0x061400]=TRANS_DDI_FUNC_CTL_B  NAME[0x071008]=TRANSCONF_B
  NAME[0x06101c]=PIPEBSRC              NAME[0x0c5100]=GMBUS0_pin
  NAME[0x0c5108]=GMBUS2_status

  # Named registers NOT present in the capture (appended for completeness; F6(c)).
  typeset -A EXTRA_NAME
  EXTRA_NAME[0x042000]=SKL_FUSE_STATUS       # PG dist bits (PW_B fuse)
  EXTRA_NAME[0x045504]=DC_STATE_EN           # DC5/DC6 — PW_B being held blocks DC entry
  EXTRA_NAME[0x164b00]=TGL_DPLL0_DIV0        # DPLL0 ratio/div
  EXTRA_NAME[0x164c00]=TGL_DPLL1_DIV0        # DPLL1 ratio/div
  EXTRA_NAME[0x164284]=TGL_DPLL0_CFGCR0
  EXTRA_NAME[0x16428c]=TGL_DPLL1_CFGCR0
  EXTRA_NAME[0x164288]=TGL_DPLL0_CFGCR1
  EXTRA_NAME[0x164290]=TGL_DPLL1_CFGCR1
  EXTRA_NAME[0x046000]=CDCLK_CTL             # F8: cdclk ratio check (179.2->192 MHz, audio min 2x96 MHz BCLK)
  EXTRA_NAME[0x044fe8]=DBUF_CTL_S1
  EXTRA_NAME[0x044300]=DBUF_CTL_S2
  EXTRA_NAME[0x044304]=DBUF_CTL_S3

  out ""
  printf "%-24s %-9s %-11s %-11s %-11s %s\n" NAME OFF MACOS LINUX_ON LINUX_OFF VERDICT >> "$BODY"

  typeset -A SEEN
  # F6(c): parse EVERY '0x...  off=0x...  on=0x...' line from the capture at runtime.
  if [[ -r $TMDS ]]; then
    while IFS= read -r line; do
      off=$(print -r -- "$line" | sed -nE 's/^[[:space:]]*(0x[0-9a-fA-F]+)[[:space:]]+off=0x[0-9a-fA-F]+[[:space:]]+on=0x[0-9a-fA-F]+.*/\1/p')
      [[ -z $off ]] && continue
      loff=$(print -r -- "$line" | sed -nE 's/.*off=(0x[0-9a-fA-F]+).*/\1/p')
      lon=$(print -r -- "$line"  | sed -nE 's/.*on=(0x[0-9a-fA-F]+).*/\1/p')
      offl=${(L)off}
      SEEN[$offl]=1
      if [[ -n ${SKIP[$offl]:-} ]]; then
        printf "%-24s %-9s %-11s %-11s %-11s %s\n" "${NAME[$offl]:-REG}" "$off" "(skip:RD-sidefx)" "$(norm $lon)" "$(norm $loff)" "excluded" >> "$BODY"
        continue
      fi
      raw=$("$X" rd "$off" 2>/dev/null | awk '{print $3}')
      [[ -z $raw ]] && raw="????????"
      mv=$(norm "0x$raw"); lonn=$(norm "$lon"); loffn=$(norm "$loff")
      if [[ $mv == "00??????" || $raw == "????????" ]]; then verdict="noread"
      elif [[ $mv == $lonn ]]; then verdict="=on"
      elif [[ $mv == $loffn ]]; then verdict="=off"
      else verdict="other"; fi
      printf "%-24s %-9s 0x%-9s 0x%-9s 0x%-9s %s\n" "${NAME[$offl]:-REG}" "$off" "$mv" "$lonn" "$loffn" "$verdict" >> "$BODY"
    done < "$TMDS"
  else
    out "(docs/HDMI-TMDS.md not readable at $TMDS — capture rows skipped)"
  fi

  # Append named registers absent from the capture.
  out ""
  out "# named registers not in the capture (read-only snapshot, no Linux on/off reference):"
  for off name in ${(kv)EXTRA_NAME}; do
    [[ -n ${SEEN[${(L)off}]:-} ]] && continue
    raw=$("$X" rd "$off" 2>/dev/null | awk '{print $3}')
    [[ -z $raw ]] && raw="????????"
    printf "%-24s %-9s 0x%-9s %-11s %-11s %s\n" "$name" "$off" "$(norm 0x$raw)" "-" "-" "-" >> "$BODY"
  done
fi

# ===================== SUMMARY (computed AFTER all sections, placed near the TOP) =====================
# Sources (FIX3):
#   * framebuffer-side strings ('Path has not been assigned', 'invokeHotplugHandler', 'StreamGetEDID') are counted
#     PER SOURCE — the Apple FB capture (FB_TMP) and the NootedGreen IOLog bridge capture (NGREEN_TMP) — because
#     those lines never appear in displaypolicyd. Counting them over the displaypolicyd text (as before) always gave
#     0, which falsely looked like success.
#   * displaypolicyd-side strings ('DeviceState_IsUnknown', 'To errorQ', 'Populated addr', 'Vendor portmap') and the
#     Insert/Remove LinkUpdate events are counted over the CURRENT-BOOT displaypolicyd text only: the unified-log
#     capture (always current boot) plus the file log sliced from its LAST 'PolicyEngine started' line to the end
#     (the file can hold earlier boots). If no marker is found the whole file is used (and the summary says so).
#   * XeHDMI edid/trig last lines come from the NootedGreen capture.
# No new `log show` is run here. All read-only.
SUMMARY=$(mktemp 2>/dev/null) || SUMMARY="$OUT.summary.$$"
: > "$SUMMARY"
sm() { print -r -- "$@" >> "$SUMMARY"; }

# Current-boot slice of the displaypolicyd FILE log: from the LAST 'PolicyEngine started' line to EOF. The file may
# concatenate several boots; only the newest one is relevant to the SUMMARY. If the marker is absent, use it whole.
DP_FILE_CUR=$(mktemp 2>/dev/null) || DP_FILE_CUR="$OUT.dpcur.$$"
: > "$DP_FILE_CUR"
DP_BOOT_NOTE=""
if [[ -s $DP_FILELOG_TMP ]]; then
  LASTMARK=$(grep -n 'PolicyEngine started' "$DP_FILELOG_TMP" 2>/dev/null | tail -1 | cut -d: -f1)
  if [[ -n $LASTMARK ]]; then
    tail -n "+$LASTMARK" "$DP_FILELOG_TMP" > "$DP_FILE_CUR"
    DP_BOOT_NOTE="from the last 'PolicyEngine started' line (line $LASTMARK) to end of file"
  else
    cat "$DP_FILELOG_TMP" > "$DP_FILE_CUR"
    DP_BOOT_NOTE="no 'PolicyEngine started' marker found — whole file log used"
  fi
else
  DP_BOOT_NOTE="no readable displaypolicyd file log"
fi

# current-boot displaypolicyd text = current-boot file slice + unified-log capture (unified is already current boot).
DP_CUR=$(mktemp 2>/dev/null) || DP_CUR="$OUT.dpcurall.$$"
: > "$DP_CUR"
[[ -s $DP_FILE_CUR ]]    && cat "$DP_FILE_CUR"    >> "$DP_CUR"
[[ -s $DP_UNIFIED_TMP ]] && cat "$DP_UNIFIED_TMP" >> "$DP_CUR"

# number of displays in system_profiler: count the 'Resolution:' lines (one per display) in the body.
NDISP=$(grep -c 'Resolution:' "$BODY" 2>/dev/null); NDISP=${NDISP:-0}
# the ngreen-hdmi-con1 IORegistry string (now includes flags=0x...).
CON1=$(grep -i 'ngreen-hdmi-con1' "$BODY" 2>/dev/null | head -1 | sed 's/^[ |]*//')
# last 'Vendor portmap' line from the CURRENT-BOOT file slice and from the UNIFIED log.
PM_FILE=$(grep 'Vendor portmap' "$DP_FILE_CUR" 2>/dev/null | tail -1)
PM_UNI=$(grep 'Vendor portmap' "$DP_UNIFIED_TMP" 2>/dev/null | tail -1)
# the hdmiargs line (SYSLOG 'ngreen hdmiargs: ...' / IORegistry). Exclude our own section headers (== / ---).
HDMIARGS=$(grep -i 'hdmiargs' "$BODY" 2>/dev/null | grep -vE '^(==|---|\[)' | grep -vi 'Kernel log:' | head -1 | sed 's/^[ |]*//')
# last XeHDMI edid / XeHDMI trig lines from the NootedGreen bridge capture.
XE_EDID=$(grep 'XeHDMI edid' "$NGREEN_TMP" 2>/dev/null | tail -1 | sed 's/^[ |]*//')
XE_TRIG=$(grep 'XeHDMI trig' "$NGREEN_TMP" 2>/dev/null | tail -1 | sed 's/^[ |]*//')
# ngreenhdmiddc: last 'XeHDMI ddc' line (served/pass) from the NootedGreen capture or the dmesg capture, plus the
# ngreen-hdmiddc IORegistry property (calls/served/pass/last result published by the wrapper's IOService site).
XE_DDC=$(grep 'XeHDMI ddc' "$NGREEN_TMP" "$DMESG_TMP" 2>/dev/null | tail -1 | sed 's/^[^ ]*: //; s/^[ |]*//')
DDCPROP=$(grep -i 'ngreen-hdmiddc' "$BODY" 2>/dev/null | head -1 | sed 's/^[ |]*//')
# ngreenhdmiregs: the read-only pipe-B register snapshot. Two IORegistry properties (ngreen-hdmiregs1/2), each
# `name@off=live<verdict>` (= on, . off, ? other) vs the Linux capture in docs/HDMI-TMDS.md. Printed verbatim.
REGS1=$(grep -i 'ngreen-hdmiregs1' "$BODY" 2>/dev/null | head -1 | sed 's/^[ |]*//')
REGS2=$(grep -i 'ngreen-hdmiregs2' "$BODY" 2>/dev/null | head -1 | sed 's/^[ |]*//')
# ngreenhdmilight (Phase 1: power wells + DDI-B clock ungate, NO scanout): last 'XeHDMI light' IOLog line and the
# ngreen-hdmilight IORegistry property (pg2/pwb/ddi/dpclka ok + before->after of 0x45404/0x45454/0x164280; P2 DPLL
# deferred because DPLL1 feeds the internal eDP on macOS). 0x46014 DPLL1_ENABLE is in the read-only snapshot above.
XE_LIGHT=$(grep 'XeHDMI light' "$NGREEN_TMP" "$DMESG_TMP" 2>/dev/null | tail -1 | sed 's/^[^ ]*: //; s/^[ |]*//')
LIGHTPROP=$(grep -i 'ngreen-hdmilight' "$BODY" 2>/dev/null | head -1 | sed 's/^[ |]*//')

# cntf <file> <pattern>: matching-line count in <file>. `grep -c` always prints a count; swallow its non-zero exit.
cntf() { local n; n=$(grep -c -- "$2" "$1" 2>/dev/null); print -r -- "${n:-0}"; }
# LinkUpdate Insert/Remove events in the current-boot displaypolicyd text (the 'LinkUpdate: X.Y event: Insert/Remove'
# lines; the plain 'Insert'/'Remove' tokens also appear on 'Addr:' NOTICE lines, so filter to LinkUpdate first).
cnt_lu() { local n; n=$(grep 'LinkUpdate' "$DP_CUR" 2>/dev/null | grep -c -- "$1" 2>/dev/null); print -r -- "${n:-0}"; }

sm "# SUMMARY (computed from the sections below)"
sm "displays (system_profiler 'Resolution:' lines): $NDISP"
sm "ngreen-hdmi-con1: ${CON1:-(not found)}"
sm "last 'Vendor portmap' (displaypolicyd file log, current boot): ${PM_FILE:-(none)}"
sm "last 'Vendor portmap' (unified log):                           ${PM_UNI:-(none)}"
sm "# framebuffer-side counts, per source (FB log = AppleIntelTGLGraphicsFramebuffer, NootedGreen bridge = XeFB IOLog):"
sm "count 'Path has not been assigned': FB log $(cntf "$FB_TMP" 'Path has not been assigned'), NootedGreen bridge $(cntf "$NGREEN_TMP" 'Path has not been assigned')"
sm "count 'invokeHotplugHandler':       FB log $(cntf "$FB_TMP" 'invokeHotplugHandler'), NootedGreen bridge $(cntf "$NGREEN_TMP" 'invokeHotplugHandler')"
sm "count 'StreamGetEDID':              FB log $(cntf "$FB_TMP" 'StreamGetEDID'), NootedGreen bridge $(cntf "$NGREEN_TMP" 'StreamGetEDID')"
sm "# displaypolicyd-side counts for the EXTERNAL display (addr 2.0), current boot: $DP_BOOT_NOTE:"
sm "count 'EDID read 2.0 failed':       $(cntf "$DP_CUR" 'EDID read 2.0 failed')"
sm "count 'DeviceState_IsUnknown':      $(cntf "$DP_CUR" 'DeviceState_IsUnknown')"
sm "count 'To errorQ addr 2.0':         $(cntf "$DP_CUR" 'To errorQ addr 2.0')"
sm "count 'event: Insert':              $(cntf "$DP_CUR" 'event: Insert')"
sm "count 'Populated addr 2.0':         $(cntf "$DP_CUR" 'Populated addr 2.0')"
sm "LinkUpdate events 'Insert':         $(cnt_lu 'Insert')"
sm "LinkUpdate events 'Remove':         $(cnt_lu 'Remove')"
sm "last 'XeHDMI edid' (NootedGreen):   ${XE_EDID:-(none)}"
sm "last 'XeHDMI trig' (NootedGreen):   ${XE_TRIG:-(none)}"
sm "last 'XeHDMI ddc' (NootedGreen):    ${XE_DDC:-(none)}"
sm "ngreen-hdmiddc (ioreg): ${DDCPROP:-(not found)}"
sm "ngreen-hdmiregs1 (ioreg): ${REGS1:-(not found)}"
sm "ngreen-hdmiregs2 (ioreg): ${REGS2:-(not found)}"
sm "last 'XeHDMI light' (NootedGreen): ${XE_LIGHT:-(none)}"
sm "ngreen-hdmilight (ioreg): ${LIGHTPROP:-(not found)}"
sm "hdmiargs: ${HDMIARGS:-(not found)}"

# ===================== append the SUMMARY at the END and print it on screen =====================
# The header and every section are already in $OUT (progressive write). Here we only APPEND the computed SUMMARY,
# so an interrupted run still has a non-empty, useful file. BODY is an alias of $OUT, so it is NOT removed here.
{
  print -r -- ""
  print -r -- "# ============================== SUMMARY =============================="
  cat "$SUMMARY"
} >> "$OUT"

# echo the SUMMARY to the screen too (handy when the run is interrupted or piped).
print -r -- ""
cat "$SUMMARY"

rm -f "$SUMMARY" "$DP_FILE_CUR" "$DP_CUR" "$DP_UNIFIED_TMP" "$DP_FILELOG_TMP" "$NGREEN_TMP" "$FB_TMP" "$DMESG_TMP"

print "wrote $OUT"


