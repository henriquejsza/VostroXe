# VostroXe on the Dell Vostro 3520

What this fork changes for the Vostro 3520, and why. The rest of `docs/` describes the base project,
[Hackintosh-XPS13Plus-IrisXe-Tahoe](https://github.com/JulioNectar/Hackintosh-XPS13Plus-IrisXe-Tahoe), on the
Dell XPS 13 Plus: the GPU work (kernel patches, Metal driver, shader compiler) is the same here.

## Hardware

One machine so far: Vostro 3520 with BIOS 1.43.0, macOS Tahoe 26.7.1 (25G241). The macOS column names the driver
or method; [README.md](../README.md#what-works) says which parts are confirmed.

| Part | ID | macOS |
|---|---|---|
| CPU | Intel Core i5-1235U (Alder Lake-U, 2P + 8E, 12 threads) | E-cores can stay on (OpenCore `Cpuid1Data` fix) |
| GPU | Iris Xe `8086:46A8` rev 0c, subsystem `1028:0B94`, display version 13, 80 EU (5 DSS × 16, 6 L3 banks) | presented as Tiger Lake `9A49`, Apple's TGL driver through NootedGreen |
| Panel | 1920×1080, 120 Hz, eDP on DDI A / PHY A | works |
| HDMI | native HDMI 1.4 on DDI B / combo PHY B (VBT child `0x60D2`, DDC on GMBUS pin 2, no AUX, 165 MHz max) | picture at 1920×1080, 60 Hz with opt-in boot-args (DVI mode, no audio), see [HDMI.md](HDMI.md) |
| Audio | Intel HDA `8086:51C8` + Cirrus CS8409 bridge (subsystem `1028:0B94`, "Warlock MLK"), CS42L42 headset codec | speakers and microphones through CS8409HDA; headset jack not supported |
| Ethernet | Realtek RTL8111 | RealtekRTL8111 3.0.0 |
| Wi-Fi, Bluetooth | Realtek RTL8821CE / `0BDA:C829` | no macOS driver |
| USB | XHCI `8086:51ED`: 2× USB 3 Type-A, 1× USB 2 Type-A | UTBMap (USBToolBox) |
| Keyboard, touchpad | PS/2 keyboard, I2C touchpad | VoodooPS2, VoodooI2C in polling mode |
| Webcam, fingerprint | `0BDA:5522` (USB), Goodix `27C6:639C` | not checked |

Other Vostro 3520 configurations may need changes: an i7-1255U has 96 EU, so it must not use
`ngreen-eu=80 ngreen-l3=6`, and models with a USB-C port have more USB ports than the map lists.

## EFI

`EFI/` is the tested EFI of this laptop with the serials blanked. `make-efi.py` fills in the SMBIOS from
`smbios.local`, adds `HfsPlus.efi` and writes three configs to `dist/EFI/OC`.

Compared with the XPS 13 Plus EFI:

- **ACPI:** no `SSDT-GPI0`, no `SSDT-XPS-I2C` and none of the XPS renames. On this laptop `PNLF` is a field in
  the DSDT, so the XPS `PNLF` to `XNLF` rename would corrupt it. The Dell `xh_Dell_` SSDT is kept
  (`SSDT-USB-Reset` already hides `RHUB`).
- **Kexts:** UTBMap instead of UTBDefault, RealtekRTL8111, HoRNDIS (Android USB tethering) and CS8409HDA. No Intel
  Wi-Fi or Bluetooth kexts. CpuTopologyRebuild is off.
- **Boot-args**, accelerated config:

  ```
  -ngreentglwithgfx -allow3d -disablegfxfirmware ngreen-dmc=adlp -ngreenv189 -ngreenkeepefi -ngreenxefix
  -ngreenfixbootmode amfi_get_out_of_my_way=1 ngreenSched=4 ngreenV142=3 ngreen-eu=80 ngreen-l3=6
  -vi2c-force-polling gfxrst=1 ngreenpm=20
  ```

  Against the XPS: `ngreen-eu=80 ngreen-l3=6` for the 80 EU GPU, `-vi2c-force-polling` for the touchpad,
  `ngreenpm=20` (XE-PM with a 20 W sustained power limit instead of 22 W), no `ngreenblmax` (that is the XPS
  panel's brightness range) and no `IGLogLevel`.
- **Safe config** (`config-install.plist`): no GPU spoof, NootedGreen off, `keepsyms=1 -vi2c-force-polling -v`.
- Both configs show the auxiliary entries and wait 5 s (accelerated) or 8 s (safe), so the recovery and the
  other config can be picked at boot.

## NootedGreen changes

All in `src/NootedGreen/kern_gen11.cpp`; each can be turned off by boot-arg.

### Boot divide-by-zero (`-ngreenfixbootmode`)

`AppleIntelBaseController::hwCRTCToIODetailedTimingInformation` divides by the live transcoder register
`0x60044 + (plane << 12)`, which still reads 0 early in boot. The fixbootmode worker now reads the same divisor
source and waits until it is non-zero. Off: `-ngreennofixbootmode`.

### `__cxa_pure_virtual` in `probePortState` (upstream issue #8)

`AppleIntelPort::probePortState()` calls vtable slot `0x190` of the port when HPD reads high. On this laptop that
panicked WindowServer during accelerated boots on 24 Oct (`__cxa_pure_virtual`, `probePortState() + 0x207`).

The cause is in how the driver is linked. The 16.0.32 framebuffer does not define
`AppleIntelPortHAL::probePortMode()`: it imports it (`llvm-nm -m` lists it as undefined), and HookCase provides it.
When kmutil builds the Auxiliary Kernel Collection it patches vtables the way kxld did
([`kxld_vtable_patch`](https://github.com/apple-oss-distributions/xnu/blob/main/libkern/kxld/kxld_vtable.c)): an
entry bound to a symbol of another kext, that is not pure virtual and not the superclass's own entry, is replaced
by the superclass's entry. The superclass is `AppleIntelPort`, whose slot `0x190` is `___cxa_pure_virtual`.

The AuxKC on this machine shows it. Slot `0x190` of `AppleIntelPortHAL` and `AppleIntelPortHALDiags` holds the
same chained fixup as the pure slots of `AppleIntelPort` (`0x0040000000ab59c0`, kernel `___cxa_pure_virtual`), while
the neighbouring slots point at the right functions (`runAUXCommand`, `setDklDPMode`). No fixup points at HookCase's
`probePortMode`.

So every live port has a pure slot `0x190`. NootedGreen writes that slot of both vtables to a stub that returns
PortMode 0, the value the HPD-low branch passes to `setPortMode()`. For the HDMI port it switches the port's kind
from DP to TMDS and returns PortMode 1 instead (`ngreenhdmimode`). Off: `-ngreennoportmode`; other value for the
other ports: `ngreenportmode=N`.

### External HDMI

The connector table describes con1 as HDMI on DDI 1 with GMBUS pin 2, and a set of opt-in boot-args drives the
HDMI bring-up. With `ngreenhdmilight=2` (XE-HDMI13) and the detection boot-args (`zsh tools/hdmi-flags.sh light`),
the external monitor shows a picture at 1920×1080, 60 Hz (tested 30 Oct). See [HDMI.md](HDMI.md).

## Audio

`tools/CS8409HDA` is a driver written for this laptop: Tahoe has no AppleHDA, so AppleALC cannot help. A small
OS-independent core (`core/`) runs the Intel HDA controller and programs the CS8409 the way the Linux `cs8409`
driver does on this machine (traces in `ref/`). The same core runs in a Linux test module (`linux/`), where it was
checked on the hardware before macOS. The kext exposes AudShim's driver interface, so the `XeSpeakers` HAL plug-in
drives it; volume and mute are done in software because the speaker path has no hardware gain.

Self-test on this laptop (`cs8409ctl selftest`): a tone through the speakers recorded by the internal microphone
62 dB above silence, playback DMA at the expected 384 kB/s.

```sh
zsh tools/CS8409HDA/macos/audio.sh test     # beeps + self-test, then installs XeSpeakers
```

Boot-args: `-cs8409off` (do not touch the hardware), `cs8409lingerms`, `cs8409capdb`, `-cs8409nomic`,
`-cs8409anyssid`, `-cs8409hp`.

## Known issues

- **`powermetrics` panics the kernel.** `IntelFBClientControl::doAttribute` → `pmtGetMiscCntr` →
  `CamelliaBase::ReadDpbResidency` dereferences the TCON object, which this panel does not have (three panics on
  25 Oct, one on 27 Oct). Don't run `powermetrics`.
- **A WindowServer hang** ended in a watchdog panic on 27 Oct (`no successful checkins from WindowServer in
  120 seconds`). The GPU had been reporting channel errors for 5 minutes before it, and the forced HDMI mode set of
  that boot never ran ([HDMI.md](HDMI.md), finding 5).
- **Privacy prompts never appear** for third-party apps, because of `amfi_get_out_of_my_way=1`: microphone, camera
  and screen recording are denied silently. Grant them with
  `sudo zsh tools/tcc-permitir.sh microfone|camera|tela|... <app>`.
- **With an HDMI monitor connected** the framebuffer logs a `runAUXCommand ddi = 1 Time out` about every 4 ms in
  bursts: 8,439 in 73 s, starting 15 s after boot. `ngreenhdmiaux=1` (in `hdmi-flags.sh light`) answers these at
  once: the 30 Oct test boot logged none.
- Updating macOS past 26.7.1 (25G241) breaks the acceleration, as in the base project.
- **Android emulator** (Android Studio, x86_64 AVDs): black window. The guest kernel panics 0.4 s into its boot on
  TPAUSE, which the emulator's QEMU lets the guest see on this CPU. Fix, not tested yet:
  `zsh tools/emulador-android.sh corrigir`. See [EMULATOR.md](EMULATOR.md).
- **Minecraft Launcher** 2.6.12 crashes at start (4 crash reports, 29–30 Oct): `EXC_BAD_ACCESS` in `strlen()`
  called from `mojang::platform::getOpenGLVersion()`, so the OpenGL version string it read was null. OpenGL here has
  no hardware renderer, only the Apple Software Renderer ([EMULATOR.md](EMULATOR.md#fix), limits).

## Keeping up with the base project

The base project is the `upstream` remote:

```sh
git remote add upstream https://github.com/JulioNectar/Hackintosh-XPS13Plus-IrisXe-Tahoe.git
git fetch upstream && git merge upstream/main
```

Expect conflicts in `README.md`, `README.pt-BR.md`, `NOTICE.md`, `EFI/` and `src/NootedGreen/kern_gen11.cpp`. Keep
this repository's README, NOTICE and EFI configs, take upstream's new kexts only after checking them on the Vostro,
and merge `kern_gen11.cpp` by hand. Then rebuild with `zsh install.sh` and check the NootedGreen sources with
`clang -fsyntax-only` before booting.

## Changes

| Date | Change |
|---|---|
| 2026-10-30 | `tools/emulador-android.sh`: `clearcpuid=waitpkg,rdpid` for the Android emulator's guest kernel (black window, guest panic on TPAUSE) and the renderer back to automatic, not tested yet |
| 2026-10-30 | NootedGreen XE-HDMI13 (`ngreenhdmilight=2`): external HDMI works, 1920×1080 at 60 Hz through Apple's `LightUpTMDS` (opt-in) |
| 2026-10-30 | VostroXe: the Vostro work in its own repository, on top of the base project at 6f03560 |
| 2026-10-27 | NootedGreen HDMI work on DDI-B (detection and EDID with opt-in boot-args, no picture yet); XE-PM and the rest of upstream 99631db |
| 2026-10-25 | CS8409HDA: internal speakers and microphones |
| 2026-10-24 | Boot fixes: divide-by-zero in the fixbootmode worker, `__cxa_pure_virtual` in `probePortState` |
| 2026-10-24 | First Vostro EFI, 80 EU topology (`ngreen-eu=80 ngreen-l3=6`) |
