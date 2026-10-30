# External HDMI on the Vostro 3520

Status: **not working yet.** macOS detects the monitor and reads its EDID with opt-in boot-args, and lists it as a
second display, but the screen stays black. This page has what is known, the boot-args for the experiments and the
next step. The register capture and the notes of every iteration are in [HDMI-TMDS.md](HDMI-TMDS.md) (Portuguese).

## The hardware path

From Linux (i915, kernel 7.1) with a 1080p monitor in use as an extended desktop:

```
[CRTC:269:pipe B]: mode="1920x1080": 60 148500 ...   port_clock=148500
	[ENCODER:516:DDI B/PHY B]: connectors: [CONNECTOR:517:HDMI-A-1]
```

- Power domains in use: `PW_2`, `PW_A`, `PW_B`, `DDI_IO_A`, `DDI_IO_B` and `AUX_A` (the eDP's). No `AUX_B`.
- VBT (`$VBT ALDERLAKE-P`, BDB 249): HDMI child device type `0x60D2` (HDMI, not DP++), port B, DDC on GMBUS
  pin 2, no AUX channel, no LSPCON, no Type-C or Thunderbolt flag, `hdmi_max_data_rate` 165 MHz.
- Dell's spec for this port: HDMI 1.4, up to 1920×1080 at 60 Hz.

So it is a native HDMI encoder on combo PHY B: no AUX, DDC over GMBUS pin 2, TMDS at 148.5 MHz.

## What macOS does

The spoofed Tiger Lake framebuffer gets its connector table from NootedGreen (`getOSInformation`). con1 used to
be DisplayPort on GMBUS pin 1; it is now HDMI on DDI 1 with GMBUS pin 2. With the default boot-args:

- HPD works: `invokeHotplugHandler` fires for DDI 1 on plug and unplug.
- The framebuffer still runs DP AUX on the port: `runAUXCommand ddi = 1 Time out`, about every 4 ms in bursts.
- No display appears, and framebuffers 1 and 2 have no `connector-type`.

Findings, in the order they were made:

1. **No DDC in the port masks.** displaypolicyd logged `Vendor portmap 0x6 mst 0x4 ddc 0x0 aux 0x6`: the external
   port was advertised as DP with AUX and without DDC, so the EDID was never read over I2C.
   `AppleIntelBaseController::GetGPUCapability` builds these masks from the flags word of each connector (bit 0x1:
   MST and AUX, bit 0x8: AUX, bit 0x2: DDC). `ngreenhdmiflags=0x202` gives `mst 0x0 ddc 0x4 aux 0x2`.
2. **Apple's GMBUS read fails on pin 2.** With DDC advertised, displaypolicyd logged
   `EDID read 2.0 failed: GPU failed the command for block 0` 67 times in one boot, while NootedGreen's own GMBUS
   reader got the EDID from the same pin. `ngreenhdmiddc=1` hooks `hwDoGMBusRequest` and serves the base-block EDID
   read (offset byte 0 written to `0xA0`, 128 bytes read) with that reader; everything else goes to Apple's code.
3. **Detected, but black.** With both (27 Oct), System Information lists the monitor ("LG ULTRAGEAR",
   1920 × 1080 at 60 Hz) next to the internal panel, as an extended display. The screen stays black.
4. **The pipe-B output chain is off.** The read-only snapshot (`ngreenhdmiregs=1`) against the Linux values:

   | Register | macOS | Linux, HDMI on |
   |---|---|---|
   | `0x45404` power well control 2 (PW_2, PW_B) | `0x0c03` | `0x3c0f` |
   | `0x45454` DDI-B power well | `0x3` | `0xf` |
   | `0x164280` DPCLKA_CFGCR0 | `0x01e07801` | `0x01e07004` |
   | `0x46144` TRANS_CLK_SEL_B | `0` | `0x20000000` |
   | `0x64100` DDI_BUF_CTL_B | `0x80` | `0x80000000` |
   | `0x61400` TRANS_DDI_FUNC_CTL_B | `0` | `0x90030000` |
   | `0x71008` TRANSCONF_B | `0` | `0xc0000000` |

5. **Apple's driver never runs its HDMI enable.** Framebuffer 1 always takes the "Partial modeset by updating plane"
   branch, so `LightUpTMDS` is not called. `ngreenhdmimodeset=2` forces the full modeset; the internal panel
   flickers, and whether it then reaches `LightUpTMDS` is not known yet.
6. **The PLLs are swapped compared with Linux.** On macOS `DPCLKA_CFGCR0` has the eDP (PHY A) on DPLL1 and PHY B
   on DPLL0 with its clock gated; Linux uses DPLL0 for the eDP and DPLL1 for HDMI. The HDMI therefore needs DPLL0
   on macOS, and DPLL1 must not be touched while the internal panel is on.

`ngreenhdmilight=1` does the first part of the enable: power wells PW_2, PW_B and DDI-B, and ungates the DDI-B
clock. It does not start the PLL, the DDI buffer or the transcoder.

## Next step

Program the rest of the pipe-B enable in NootedGreen, using the Linux values in [HDMI-TMDS.md](HDMI-TMDS.md) as the
target: DPLL0 for 148.5 MHz and PHY B's clock select, the combo PHY B HDMI swing, `DDI_BUF_CTL_B`,
`TRANS_DDI_FUNC_CTL_B` in HDMI mode, `TRANS_CLK_SEL_B`, then transcoder, pipe and plane B. WhateverXe
([b00t0x/WhateverXe](https://github.com/b00t0x/WhateverXe), BSD 3-clause) implements fixed HDMI on Display 13
combo ports with Apple's driver; its sequence is the reference, not its offsets (it targets another framebuffer
build).

## Boot-args

Defaults, on without boot-args: con1 as HDMI on DDI 1 / GMBUS pin 2 (`ngreenhdmiddi`, `ngreenhdmibus`,
`ngreenhdmisig`; `-ngreennohdmi` restores the old entry), the TMDS kind for the HDMI port (`-ngreennohdmikind`
turns it off) and the framebuffer log bridge (`-ngreennofblog`, `ngreenfblog=MASK`, `-ngreennoquiet`).

Opt-in:

| Boot-arg | Effect |
|---|---|
| `ngreenhdmiflags=N` | con1 flags word, which sets the AGDC port masks (`0x202`: DDC only) |
| `ngreenhdmiddc=1` | serve the EDID base-block read on the HDMI pin |
| `ngreenhdmiedid=1` | NootedGreen's own GMBUS EDID read on hotplug, result in `ngreen-edid` |
| `ngreenhdmiaux=1` / `=2` | answer `runAUXCommand` on the HDMI port at once with a timeout / success |
| `ngreenhdmiregs=1` | read-only pipe-B register snapshot in `ngreen-hdmiregs1/2` |
| `ngreenhdmilight=1` | power wells and DDI-B clock (no PLL, no scanout) |
| `ngreenhdmimodeset=1` / `=2` | log the framebuffer 1 modeset decision / force the full modeset (the panel flickers) |
| `ngreenhdmipw`, `ngreenhdmitrig`, `ngreenhdmisink`, `ngreenhdmilanes`, `ngreenhdmionline`, `ngreenhdmiprobe` | earlier experiments, see [HDMI-TMDS.md](HDMI-TMDS.md) |

## Tools

```sh
zsh tools/hdmi-flags.sh test          # config.plist = config-accel.plist + ngreenhdmiflags=0x202 ngreenhdmiddc=1
zsh tools/hdmi-flags.sh testregs      # ... + ngreenhdmiregs=1
zsh tools/hdmi-flags.sh off           # back to config-accel.plist
zsh tools/diagnostics/hdmi-diag.sh replug   # read-only report: logs, displaypolicyd, AGDC, IORegistry, registers
```

`hdmi-flags.sh` edits `config.plist` on the partition labelled OPENCORE and needs `config-accel.plist` next to it,
which `make-efi.py` writes. Reboot after each change.
