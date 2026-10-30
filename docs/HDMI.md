# External HDMI on the Vostro 3520

Status: **works with opt-in boot-args** (tested 30 Oct). With `ngreenhdmilight=2` (XE-HDMI13) and the detection
boot-args, the test monitor (LG ULTRAGEAR, 1080p) shows a picture at 1920×1080, 60 Hz, and the internal panel keeps
working. The port runs in DVI mode, so there is no HDMI audio, and replug and sleep have not been checked.
The register captures and the notes of every iteration are in [HDMI-TMDS.md](HDMI-TMDS.md) (Portuguese).

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
- Clocks: the eDP runs from DPLL0 and the HDMI from DPLL1 (`DPCLKA_CFGCR0 = 0x01e07004`). Pipe B's display buffer
  is DBUF slices S2 and S3, with MBUS not joined.

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

5. **Apple's driver never runs its HDMI enable.** Every mode set of framebuffer 1 ends in "Partial modeset by
   updating plane", so `LightUpTMDS` is never called. The cause is NootedGreen's patch `f10`: it turns the `je`
   after the `hwRegsNeedUpdate` call in `hwSetMode` into a `jmp`, so every mode set is partial whatever
   `hwRegsNeedUpdate` returns. The internal panel depends on this, because Apple's driver cannot train its eDP link.
   For the same reason `ngreenhdmimodeset=2` never had an effect: in the 27 Oct test the hook returned 1 four times
   and each mode set was still partial.
6. **Apple's clock code would take the internal panel's PLL.** `enableClocks` for a port uses DPLL number = DDI
   number, so DDI B gets DPLL1, and it writes the dividers at the Ice Lake addresses (`0x164080`, `0x164084`)
   instead of `TGL_DPLL_CFGCR0/1` (`0x16428C`, `0x164290`). The firmware leaves the eDP on DPLL1
   (`DPCLKA_CFGCR0 = 0x01e07801`), so a real HDMI mode set would retune the internal panel's PLL and route it to the
   HDMI port, and `disableClocks` would switch it off.
7. **Pipe B has no power and no display buffer.** It needs PW_2 and PW_B (`0x45404` bits 3/2 and 13/12) and DBUF
   slices S2/S3 (`0x44300`, `0x44304`). The Tiger Lake driver knows neither, and NootedGreen's DC-state exit wrote
   `0x0c03` to `0x45404`, clearing both requests.

## ngreenhdmilight=2 (XE-HDMI13)

With `ngreenhdmilight=2` NootedGreen lets Apple's own HDMI enable run (`hwSetMode` → `LightUpTMDS` →
`enablePipe`, `enablePort`) and fixes what it gets wrong on this hardware:

- **Mode set.** `f10` is undone. The `hwRegsNeedUpdate` hook keeps the internal panel on the partial path, as `f10`
  did, and gives the HDMI path a complete mode set while its transcoder and DDI buffer are off (at most 6 times per
  plug). Once the HDMI pipe is lit, Apple's own decision applies again.
- **Clocks.** `enableClocks` and `disableClocks` are replaced for the HDMI port: a combo PLL the eDP is not using
  (DPLL0 here), dividers computed the way i915 does (148.5 MHz gives the values Linux programs, `0x001001d0` and
  `0x00000e84`), and `DPCLKA_CFGCR0` in two writes (PLL select, then ungate). The eDP's PLL is never touched.
- **Power and display buffer.** At HPD-high and before each HDMI mode set: PW_2, PW_B and DBUF S2/S3, with MBUS
  un-joined if the firmware left it joined. The DC-state exit keeps these bits, and DC5/DC6 stay off while the
  HDMI pipe is held. After the first plug they stay on until the next boot.
- **Pipe.** The ADL-P settings i915 uses for pipe B (`PIPE_ARB_CTL`, `PIPE_CHICKEN`, `PIPE_MBUS_DBOX_CTL`), gamma in
  bypass as on pipe A, and the eDP fixes V97P/V97C on pipe A only.
- **Diagnostics.** IORegistry properties `ngreen-hdmi13` (summary), `-pwr`, `-rnu`, `-clk`, `-pre`, `-post` and
  `-late` (register dumps before and after `LightUpTMDS`, and 2 s later with pipe B's frame count over 100 ms), and
  `XeHDMI13` lines in the kernel log.

Without `ngreenhdmilight=2` the kext behaves as before.

## Test, 30 Oct

macOS 26.7.1 booted from the USB with the boot-args of `zsh tools/hdmi-flags.sh light` and the monitor connected,
and ran for 20 minutes. The kernel log of that boot, read afterwards from Linux:

1. `hdmi13: f10 desfeito=1`. At HPD-high, PW_2 and PW_B came on (`0x45404`: `0x0c03` → `0x3c0f`), and so did DBUF
   S2 and S3.
2. The hook returned `decision=1` for framebuffer 1, which logged `FB1: Complete modeset`; `LightUpTMDS` returned 0.
3. The mode is 1920×1080 with a 159.84 MHz pixel clock (60 Hz). Registers right after `LightUpTMDS`:

   | Register | macOS, 30 Oct | Linux, HDMI on |
   |---|---|---|
   | DPLL0 / DPLL1 enable (`0x46010`, `0x46014`) | `0xcc000000` / `0xcc000000` | `0xcc000000` / `0xcc000000` |
   | HDMI PLL CFGCR0 / CFGCR1 | DPLL0: `0x008001f3` / `0x00000e84` (159.84 MHz) | DPLL1: `0x001001d0` / `0x00000e84` (148.5 MHz) |
   | `0x164280` DPCLKA_CFGCR0 | `0x01e07001` (eDP on DPLL1, HDMI on DPLL0) | `0x01e07004` (eDP on DPLL0, HDMI on DPLL1) |
   | `0x46144` TRANS_CLK_SEL_B | `0x20000000` | `0x20000000` |
   | `0x64100` DDI_BUF_CTL_B | `0x80000000` | `0x80000000` |
   | `0x61400` TRANS_DDI_FUNC_CTL_B | `0x91000000` (DVI) | `0x90030000` (HDMI) |
   | `0x71008` TRANSCONF_B | `0xc0000000` | `0xc0000000` |

   The eDP's PLL kept its dividers (`0x00e001a5` / `0x00000088`).
4. 2 s later pipe B counted 6 frames in 100 ms, with no underrun. The later mode sets of framebuffer 1 were partial,
   with the pipe lit.
5. No AUX timeouts and no GPU errors after the light-up; no panic or GPU restart report that day.

Not checked yet: unplug and replug, sleep, other monitors and modes. Open points:

- **Divide-by-zero warning.** Apple's DP timing code also runs in the mode sets of framebuffer 1 and logged
  `FB1: fActiveNumberOfLanes = 0, linkSymbolClock = 0 ... will lead to DivideByZero panic` 7 times. No panic followed
  in this boot.
- **DVI mode.** Apple's `SetupParams` picks DVI for this sink (`TRANS_DDI_FUNC_CTL` mode 1), so there are no
  infoframes and no audio. Probably macOS only gets the EDID base block: `ngreenhdmiddc=1` serves block 0, and the
  CTA extension, which declares HDMI, is left to Apple's GMBUS code, which fails on this pin.
- **Boot-args.** The test used the whole `light` set, which includes diagnostics (`msgbuf`, `ngreenhdmiregs`,
  `ngreenhdmiedid`). Which ones are needed has not been tested, so none of them is in the default config yet.

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
| `ngreenhdmilight=1` | power wells and DDI-B clock only (no PLL, no scanout) |
| `ngreenhdmilight=2` | XE-HDMI13: the full enable through Apple's `LightUpTMDS` (above) |
| `ngreenhdmimodeset=1` / `=2` | log the framebuffer 1 mode-set decision / try to force the complete mode set (no effect, see finding 5) |
| `ngreenhdmipw`, `ngreenhdmitrig`, `ngreenhdmisink`, `ngreenhdmilanes`, `ngreenhdmionline`, `ngreenhdmiprobe` | earlier experiments, see [HDMI-TMDS.md](HDMI-TMDS.md) |

## Tools

```sh
zsh tools/hdmi-flags.sh light         # config.plist = config-accel.plist + the boot-args of the 30 Oct test (picture)
zsh tools/hdmi-flags.sh test          # config.plist = config-accel.plist + ngreenhdmiflags=0x202 ngreenhdmiddc=1
zsh tools/hdmi-flags.sh testregs      # ... + ngreenhdmiregs=1
zsh tools/hdmi-flags.sh off           # back to config-accel.plist
zsh tools/diagnostics/hdmi-diag.sh replug   # read-only report: logs, displaypolicyd, AGDC, IORegistry, registers
sudo python3 tools/diagnostics/i915-regdump.py   # on Linux, read-only: the display registers i915 programs
```

`hdmi-flags.sh` edits `config.plist` on the partition labelled OPENCORE and needs `config-accel.plist` next to it,
which `make-efi.py` writes. Reboot after each change.
