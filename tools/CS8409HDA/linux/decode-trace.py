#!/usr/bin/env python3
"""decode-trace.py: annotate an ftrace capture of Linux HDA verbs (hda:hda_send_cmd / hda_get_response) for the
Dell CS8409/CS42L42 codec. Reconstructs the CS8409 vendor-coefficient accesses (NID 0x47) and the CS42L42 I2C
register accesses that the cs8409 driver tunnels through them.

  decode-trace.py TRACE [--codec 0] [--writes] [--i2c-only] [--cs42l42-h PATH]

  default     every verb: time (ms), NID, verb, payload, response, decoded meaning
  --writes    only state-changing operations (SET verbs, coefficient writes, I2C writes), one per line: the sequence
              a driver has to reproduce
  --i2c-only  only the CS42L42 register accesses
"""
import argparse, re, sys

VERB12 = {
    0xF00: "GET_PARAMETER", 0xF01: "GET_CONNECT_SEL", 0x701: "SET_CONNECT_SEL", 0xF02: "GET_CONNECT_LIST",
    0xF03: "GET_PROC_STATE", 0x703: "SET_PROC_STATE", 0xF04: "GET_SDI_SELECT", 0x704: "SET_SDI_SELECT",
    0xF05: "GET_POWER_STATE", 0x705: "SET_POWER_STATE", 0xF06: "GET_CONV", 0x706: "SET_CHANNEL_STREAMID",
    0xF07: "GET_PIN_WIDGET_CONTROL", 0x707: "SET_PIN_WIDGET_CONTROL", 0xF08: "GET_UNSOLICITED_RESPONSE",
    0x708: "SET_UNSOLICITED_ENABLE", 0xF09: "GET_PIN_SENSE", 0x709: "SET_PIN_SENSE", 0xF0A: "GET_BEEP_CONTROL",
    0x70A: "SET_BEEP_CONTROL", 0xF0C: "GET_EAPD_BTLENABLE", 0x70C: "SET_EAPD_BTLENABLE", 0xF0D: "GET_DIGI_CONVERT_1",
    0x70D: "SET_DIGI_CONVERT_1", 0x70E: "SET_DIGI_CONVERT_2", 0xF0F: "GET_VOLUME_KNOB_CONTROL",
    0x70F: "SET_VOLUME_KNOB_CONTROL", 0xF15: "GET_GPIO_DATA", 0x715: "SET_GPIO_DATA", 0xF16: "GET_GPIO_MASK",
    0x716: "SET_GPIO_MASK", 0xF17: "GET_GPIO_DIRECTION", 0x717: "SET_GPIO_DIRECTION", 0xF18: "GET_GPIO_WAKE_MASK",
    0x718: "SET_GPIO_WAKE_MASK", 0xF19: "GET_GPIO_UNSOLICITED_RSP_MASK", 0x719: "SET_GPIO_UNSOLICITED_RSP_MASK",
    0xF1A: "GET_GPIO_STICKY_MASK", 0x71A: "SET_GPIO_STICKY_MASK", 0xF1C: "GET_CONFIG_DEFAULT",
    0x71C: "SET_CONFIG_DEFAULT_BYTES_0", 0x71D: "SET_CONFIG_DEFAULT_BYTES_1", 0x71E: "SET_CONFIG_DEFAULT_BYTES_2",
    0x71F: "SET_CONFIG_DEFAULT_BYTES_3", 0xF20: "GET_SUBSYSTEM_ID", 0x7FF: "SET_CODEC_RESET",
    0xF2D: "GET_CVT_CHAN_COUNT", 0x72D: "SET_CVT_CHAN_COUNT", 0xF2F: "GET_HDMI_IDT",
}
VERB4 = {0x2: "SET_STREAM_FORMAT", 0xA: "GET_STREAM_FORMAT", 0x3: "SET_AMP_GAIN_MUTE", 0xB: "GET_AMP_GAIN_MUTE",
         0x4: "SET_PROC_COEF", 0xC: "GET_PROC_COEF", 0x5: "SET_COEF_INDEX", 0xD: "GET_COEF_INDEX"}
PARAMS = {0x00: "VENDOR_ID", 0x02: "REV_ID", 0x04: "NODE_COUNT", 0x05: "FUNCTION_TYPE", 0x08: "AUDIO_FG_CAP",
          0x09: "AUDIO_WIDGET_CAP", 0x0A: "PCM", 0x0B: "STREAM", 0x0C: "PIN_CAP", 0x0D: "AMP_IN_CAP",
          0x0E: "CONNLIST_LEN", 0x0F: "POWER_STATE", 0x10: "PROC_CAP", 0x11: "GPIO_CAP", 0x12: "AMP_OUT_CAP",
          0x13: "VOL_KNB_CAP"}

# CS8409 vendor coefficients (enum cs8409_coefficient_index_registers in sound/hda/codecs/cirrus/cs8409.h)
_COEFS = """DEV_CFG1 DEV_CFG2 DEV_CFG3 ASP1_CLK_CTRL1 ASP1_CLK_CTRL2 ASP1_CLK_CTRL3 ASP2_CLK_CTRL1 ASP2_CLK_CTRL2
ASP2_CLK_CTRL3 DMIC_CFG BEEP_CFG ASP1_RX_NULL_INS_RMV ASP1_Rx_RATE1 ASP1_Rx_RATE2 ASP1_Tx_NULL_INS_RMV ASP1_Tx_RATE1
ASP1_Tx_RATE2 ASP2_Rx_NULL_INS_RMV ASP2_Rx_RATE1 ASP2_Rx_RATE2 ASP2_Tx_NULL_INS_RMV ASP2_Tx_RATE1 ASP2_Tx_RATE2
ASP1_SYNC_CTRL ASP2_SYNC_CTRL""".split()
for asp in ("ASP1", "ASP2"):
    for ch in "ABCDEFGH":
        _COEFS += [f"{asp}_{ch}_TX_CTRL1", f"{asp}_{ch}_TX_CTRL2"]
for asp in ("ASP1", "ASP2"):
    for ch in "ABCDEFGH":
        _COEFS += [f"{asp}_{ch}_RX_CTRL1", f"{asp}_{ch}_RX_CTRL2"]
_COEFS += """I2C_ADDR I2C_DATA I2C_CTRL I2C_STS I2C_QWRITE I2C_QREAD SPI_CTRL SPI_TX_DATA SPI_RX_DATA SPI_STS
PFE_COEF_W1 PFE_COEF_W2 PFE_CTRL1 PFE_CTRL2 PRE_SCALE_ATTN1 PRE_SCALE_ATTN2 PFE_COEF_MON1 PFE_COEF_MON2
ASP1_INTRN_STS ASP2_INTRN_STS ASP1_RX_SCLK_COUNT ASP1_TX_SCLK_COUNT ASP2_RX_SCLK_COUNT ASP2_TX_SCLK_COUNT
ASP_UNS_RESP_MASK""".split()
COEF = {i: n for i, n in enumerate(_COEFS)}
COEF.update({0x80: "LOOPBACK_CTRL", 0x82: "PAD_CFG_SLW_RATE_CTRL", 0xC0: "TEST_MODE", 0xC5: "GPIO_HYSTERESIS"})
I2C_ADDR, I2C_STS, I2C_QWRITE, I2C_QREAD = 0x59, 0x5C, 0x5D, 0x5E
VPW = 0x47


def load_cs42l42_names(path):
    names = {}
    try:
        txt = open(path).read()
    except OSError:
        return names
    pages = {m.group(1): int(m.group(2), 16)
             for m in re.finditer(r"#define\s+(CS42L42_PAGE_\w+)\s+(0x[0-9A-Fa-f]+)", txt)}
    for m in re.finditer(r"#define\s+CS42L42_(\w+)\s+\((CS42L42_PAGE_\w+)\s*\+\s*(0x[0-9A-Fa-f]+)\)", txt):
        if m.group(2) in pages:
            names.setdefault(pages[m.group(2)] + int(m.group(3), 16), m.group(1))
    return names


def verb_fields(cmd):
    nid = (cmd >> 20) & 0x7F
    v4 = (cmd >> 16) & 0xF
    if v4 in VERB4 and v4 not in (0x7, 0xF):
        return nid, v4, VERB4[v4], cmd & 0xFFFF, True
    v12 = (cmd >> 8) & 0xFFF
    return nid, v12, VERB12.get(v12, f"VERB_{v12:03X}"), cmd & 0xFF, False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("trace")
    ap.add_argument("--codec", type=int, default=0)
    ap.add_argument("--writes", action="store_true")
    ap.add_argument("--i2c-only", action="store_true")
    ap.add_argument("--cs42l42-h", default="/usr/lib/modules/%s/build/include/sound/cs42l42.h")
    a = ap.parse_args()
    import os
    regname = load_cs42l42_names(a.cs42l42_h % os.uname().release if "%s" in a.cs42l42_h else a.cs42l42_h)

    ev = []   # (t, kind, payload)
    rx = re.compile(r"\s(\d+\.\d+): (\w+): (.*)$")
    for line in open(a.trace):
        if line.startswith("#"):
            continue
        m = rx.search(line)
        if not m:
            continue
        t, name, rest = float(m.group(1)), m.group(2), m.group(3)
        if name in ("hda_send_cmd", "hda_get_response"):
            m2 = re.match(r"\[[^\]]*:(\d+)\] val=0x([0-9a-f]+)", rest)
            if m2 and int(m2.group(1)) == a.codec:
                ev.append((t, name, int(m2.group(2), 16)))
        else:
            ev.append((t, name, rest))

    t0 = ev[0][0] if ev else 0.0
    coef_idx = None
    page = 0           # CS42L42 page register (last value written to I2C register 0x00)
    i2c_addr = None
    pending = None     # (t, cmd) waiting for its response
    i2c_op = None      # ('W'|'R', reg, val)
    out = []

    def emit(t, text, write=False, i2c=False):
        if a.i2c_only and not i2c:
            return
        if a.writes and not write:
            return
        out.append(f"{(t - t0) * 1000:10.3f}  {text}")

    def handle(t, cmd, res):
        nonlocal coef_idx, page, i2c_addr, i2c_op
        nid, verb, vname, pl, is4 = verb_fields(cmd)
        what = f"{nid:02x} {vname:<30s} {pl:#06x}" if is4 else f"{nid:02x} {vname:<30s} {pl:#04x}"
        extra = ""
        write = vname.startswith("SET_")
        if vname == "GET_PARAMETER":
            extra = PARAMS.get(pl, "")
        if nid == VPW and vname == "SET_COEF_INDEX":
            coef_idx = pl
            if not a.writes and not a.i2c_only:
                emit(t, f"{what} -> {res:#010x}   [index {COEF.get(pl, '?')}]")
            return
        if nid == VPW and vname in ("SET_PROC_COEF", "GET_PROC_COEF") and coef_idx is not None:
            cname = COEF.get(coef_idx, f"COEF_{coef_idx:02x}")
            if vname == "SET_PROC_COEF":
                if coef_idx == I2C_ADDR:
                    i2c_addr = pl
                if coef_idx == I2C_QWRITE:
                    reg8, val = pl >> 8, pl & 0xFF
                    if reg8 == 0:
                        i2c_op = ("P", 0, val)
                    else:
                        i2c_op = ("W", (page << 8) | reg8, val)
                elif coef_idx == I2C_QREAD:
                    i2c_op = ("R", (page << 8) | (pl >> 8), None)
                emit(t, f"COEF {cname:<22s}[{coef_idx:#04x}] <- {pl:#06x}", write=True)
            else:
                if coef_idx == I2C_STS:
                    if not a.writes and not a.i2c_only:
                        emit(t, f"COEF {cname:<22s}[{coef_idx:#04x}] -> {res:#06x}")
                    if i2c_op and (res & 0x18):
                        kind, reg, val = i2c_op
                        if kind == "P":
                            page = val
                        elif kind == "W":
                            emit(t, f"I2C {i2c_addr or 0:#04x} W {reg:#06x} {regname.get(reg, ''):<26s} = {val:#04x}",
                                 write=True, i2c=True)
                            i2c_op = None
                        if kind == "P":
                            i2c_op = None
                    return
                if coef_idx == I2C_QREAD and i2c_op and i2c_op[0] == "R":
                    reg = i2c_op[1]
                    emit(t, f"I2C {i2c_addr or 0:#04x} R {reg:#06x} {regname.get(reg, ''):<26s} -> {res & 0xFF:#04x}",
                         i2c=True)
                    i2c_op = None
                    return
                emit(t, f"COEF {cname:<22s}[{coef_idx:#04x}] -> {res:#06x}")
            return
        if vname == "SET_STREAM_FORMAT":
            rate = 44100 if pl & 0x4000 else 48000
            mult, div = ((pl >> 11) & 7) + 1, ((pl >> 8) & 7) + 1
            bits = {0: 8, 1: 16, 2: 20, 3: 24, 4: 32}.get((pl >> 4) & 7, "?")
            extra = f"{rate * mult // div} Hz {bits} bit {(pl & 0xF) + 1} ch"
        elif vname == "SET_CHANNEL_STREAMID":
            extra = f"stream {pl >> 4} channel {pl & 0xF}"
        elif vname in ("SET_POWER_STATE", "GET_POWER_STATE"):
            extra = f"D{pl & 3}" if vname.startswith("SET") else f"set D{res & 3} actual D{(res >> 4) & 3}"
        emit(t, f"{what} -> {res:#010x}   {extra}".rstrip(), write=write)

    for t, kind, p in ev:
        if kind == "hda_send_cmd":
            if pending:
                handle(pending[0], pending[1], 0xFFFFFFFF)
            pending = (t, p)
        elif kind == "hda_get_response":
            if pending:
                handle(pending[0], pending[1], p)
                pending = None
        elif not a.i2c_only:
            emit(t, f"--- {kind}: {p}", write=True)
    if pending:
        handle(pending[0], pending[1], 0xFFFFFFFF)
    print("\n".join(out))


if __name__ == "__main__":
    main()
