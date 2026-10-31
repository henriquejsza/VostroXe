# VostroXe

Iris Xe graphics acceleration on macOS Tahoe for the **Dell Vostro 3520** (Core i5-1235U, Iris Xe `8086:46A8`,
80 EU), in an OpenCore hackintosh.

> 🇧🇷 Leia em português: [README.pt-BR.md](README.pt-BR.md)

There is no Apple driver for Alder Lake graphics. VostroXe is a fork of
[Hackintosh-XPS13Plus-IrisXe-Tahoe](https://github.com/JulioNectar/Hackintosh-XPS13Plus-IrisXe-Tahoe), which runs
Apple's driver for Tiger Lake Iris Xe (GPUDriversIntel 16.0.32) on newer Iris Xe GPUs: a modified
[NootedGreen](https://github.com/sgiammori/NootedGreen) patches the kernel side, and patched user-space pieces adapt
the 2020 driver to Tahoe's Metal stack. VostroXe adds what this laptop needs (its OpenCore EFI, two boot-panic
fixes, a driver for its audio, and the work in progress on its HDMI port) and follows the base project for the GPU
work.

> ⚠️ **Experimental.** Expect GPU hangs and occasional kernel panics. Keep a second way to boot, such as the
> install USB with the safe config.

## What works

Tested on one Vostro 3520 (i5-1235U, BIOS 1.43.0) with macOS Tahoe 26.7.1 (25G241).

| Area | Status |
|---|---|
| Graphics | ✅ Metal on the Iris Xe (System Information: Metal 2, 1536 MB), internal panel at 1920×1080, 120 Hz |
| Speakers, microphones | ✅ internal speakers and microphones (CS8409HDA + XeSpeakers; self-test: the tone 62 dB above silence) · ❌ headset jack |
| Boot | ✅ accelerated boot, with the fixes for the `probePortState` and divide-by-zero panics (24 Oct) |
| Keyboard, USB, NVMe | ✅ |
| Network | ✅ a USB CDC-ECM network device (Apple's driver) · ❌ Wi-Fi and Bluetooth: the Realtek RTL8821CE has no macOS driver |
| External HDMI | ✅ picture at 1920×1080, 60 Hz on a 1080p monitor, with opt-in boot-args (`zsh tools/hdmi-flags.sh light`, [docs/HDMI.md](docs/HDMI.md)) · ❌ HDMI audio (the port runs in DVI mode) · replug and sleep not checked yet |
| In the EFI, not confirmed yet | Ethernet (RealtekRTL8111), Android RNDIS tethering (HoRNDIS), touchpad (VoodooI2C in polling mode), battery status, all 12 CPU threads (`Cpuid1Data` fix), XE-PM turbo and idle profile (`ngreenpm=20`) |
| Not checked yet | brightness keys, sleep, webcam, fingerprint reader |

Known issues: `powermetrics` panics the kernel, a WindowServer hang once ended in a watchdog panic, and third-party
apps never get the microphone, camera or screen-recording prompt (fix: `tools/tcc-permitir.sh`). The Android
emulator shows a black window (fix not tested yet: `tools/emulador-android.sh`, [docs/EMULATOR.md](docs/EMULATOR.md)).
Details in [docs/VOSTRO.md](docs/VOSTRO.md#known-issues).

## Install

You need macOS Tahoe **26.7.1 (25G241)**: the patches are made for that build. In the BIOS (F2), set storage to AHCI
(not RAID/Intel RST) and turn Secure Boot off.

**1. EFI and install USB**, on Linux or macOS (needs git, python3 and curl):

```sh
git clone https://github.com/henriquejsza/VostroXe.git && cd VostroXe
python3 make-efi.py --installer --recovery
```

Copy `dist/EFI` and `dist/com.apple.recovery.boot` to the root of a FAT32 partition on a USB drive.
`smbios.local` now holds this Mac's serial numbers: keep it, and don't publish it or `dist/`.

**2. Install macOS.** Boot the USB (F12), pick "macOS Base System", erase only the volume macOS goes to (APFS), and
reinstall. The installer downloads macOS, and Wi-Fi does not work: connect a cable or a USB network device first. Update to 26.7.1 (25G241) if needed, and no further.

**3. Accelerated config.** On the USB, copy `EFI/OC/config-accel.plist` over `EFI/OC/config.plist` and reboot. The
GPU now shows as Tiger Lake (`9A49`), still without acceleration.

**4. On macOS**, from a clone on an APFS disk (your home folder):

```sh
xcode-select --install
git clone https://github.com/henriquejsza/VostroXe.git ~/VostroXe && cd ~/VostroXe
zsh install.sh
```

`install.sh` gets Apple's 16.0.32 driver bundles through the NootedGreen project, builds NootedGreen, HookCase, the
patched Metal driver, libxedrv and the shader compiler, and installs them. Approve the system extension if macOS
asks, then reboot. The EFI already carries a `NootedGreen.kext` built from `src/NootedGreen`.

**5. Sound:** `zsh tools/CS8409HDA/macos/audio.sh test` (beeps, a self-test, then the sound device).

**6. Privacy permissions** for apps that need them, for example:
`sudo zsh tools/tcc-permitir.sh microfone "Google Chrome"`.

If a boot fails, copy `config-install.plist` over `config.plist` from another system (on Linux, mount the USB's
EFI partition) to get back to the safe config.

## Update

```sh
cd ~/VostroXe && git pull && zsh install.sh
```

Then copy `build/NootedGreen.kext` to `EFI/OC/Kexts/` on the EFI you boot from (keep the old one), and run
`zsh tools/CS8409HDA/macos/audio.sh efi` if `tools/CS8409HDA` changed. Keep your EFI and its serial numbers. If you
rebuild the EFI with `make-efi.py`, run it where your `smbios.local` is.

## Repository layout

```
EFI/                     OpenCore EFI of the Vostro 3520, serials blanked (make-efi.py fills them in)
make-efi.py              builds dist/EFI on Linux or macOS: SMBIOS, HfsPlus.efi, ocvalidate, recovery
src/NootedGreen/         the kernel plugin, with the Vostro changes (boot fixes, HDMI work)
src/HookCase/            HookCase as modified for NootedGreen (MIT)
src/MGL/                 MGL (OpenGL 4.6 on Metal, Apache-2.0) with the fixes that run it on the Iris Xe
macos/                   user-space stack: Metal driver patcher, libxedrv, shader compiler, installer
tools/CS8409HDA/         audio driver for the Vostro's Cirrus CS8409, with a Linux test harness
tools/XeSpeakers/        the macOS sound device (AudioServerPlugIn)
tools/hdmi-flags.sh      switches the HDMI experiment boot-args
tools/diagnostics/       hdmi-diag.sh, i915-regdump.py (Linux) and the base project's GPU test programs
tools/tcc-permitir.sh    privacy permissions that amfi_get_out_of_my_way=1 blocks
tools/emulador-android.sh  Android emulator fix for x86_64 AVDs (guest kernel parameter)
tools/mgl-build.sh       builds src/MGL; mgl-test.sh and mgl-triangle.sh check OpenGL on the GPU
docs/VOSTRO.md           this laptop: hardware, EFI, patches, known issues, changes
docs/HDMI.md             the HDMI work
docs/EMULATOR.md         the Android emulator
docs/OPENGL.md           hardware OpenGL through MGL
```

The other tools (AudShim, touchscreen, fingerprint, haptics and more) and the other documents in `docs/` come from
the base project and describe the Dell XPS 13 Plus. Its [CHANGELOG](CHANGELOG.md) is kept as it is upstream.

## Credits

- **JulioNectar**, author of [Hackintosh-XPS13Plus-IrisXe-Tahoe](https://github.com/JulioNectar/Hackintosh-XPS13Plus-IrisXe-Tahoe):
  the work that runs Apple's Tiger Lake driver on Alder and Raptor Lake (kernel patches, Metal driver, shader
  compiler, XE-PM), which VostroXe is built on. Its README credits the projects it draws from.
- **StezzaPilot**, [NootedGreen](https://github.com/sgiammori/NootedGreen): the base of the kernel plugin and the
  source of the 16.0.32 driver bundles.
- **acidanthera** (OpenCore, Lilu, WhateverGreen, VirtualSMC, NVMeFix, RestrictEvents, BrightnessKeys), **VoodooI2C**,
  **VoodooPS2**, **USBToolBox** (dhinakg), **Mieze** (RealtekRTL8111), **jwise** (HoRNDIS).
- The Linux `cs8409` and `cs42l42` drivers (Cirrus Logic): the reference for CS8409HDA's codec programming.
- **b00t0x**, [WhateverXe](https://github.com/b00t0x/WhateverXe): the reference for Display 13 HDMI.
- **Michael Larson** and contributors, [MGL](https://github.com/openglonmetal/MGL): OpenGL 4.6 on Metal, the base of
  `src/MGL`.

## License

The [Thou Shalt Not Profit License 1.0](LICENSE), the license of NootedGreen and of the base project.
Third-party kexts in `EFI/` keep their own licenses, and no Apple software is included: see [NOTICE.md](NOTICE.md).

VostroXe is a not-for-profit project: its author gets no revenue from distributing it or from support or services
related to it. It is not affiliated with or endorsed by Apple, Intel or Dell, nor by the authors of the projects it
is based on.
