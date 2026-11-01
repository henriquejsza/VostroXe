# macOS Sequoia (port in progress)

VostroXe was built for Tahoe 26.7.1 (25G241). This page tracks the port to Sequoia 15.8.2 (24H232, Darwin 24.6) on
the same Vostro 3520.

Status (1 Nov): the accelerated desktop and the external HDMI picture work (below). Internal sound and microphone are
being tested. Sleep and the other areas have not been checked on Sequoia.

## What carries over

- **Build.** `XE_FORCE=1 zsh install.sh --build-only` on 24H232 builds NootedGreen, HookCase, the patched Metal driver
  with libxedrv, and the shader compiler, with Command Line Tools only. `GPUCompiler.framework` is `Versions/32023`,
  the same as on Tahoe, so the shader-compiler bridge is unchanged.
- **Kernel plugin.** NootedGreen accepts Ventura to Tahoe (Darwin 22 to 25). The EFI entry needs `MinKernel` 24.0.0.
- **IOSurface.** On 24H232, `IOSurface::getPlaneCount()` reads `[rdi+0x98]` and `getPixelFormat()` reads
  `[rdi+0x80]` (boot kernel collection), as on Tahoe. PLANES2 and XE-FMT read the right offsets.

## First accelerated boot (31 Oct): black screen

The kernel side and Metal came up: WindowServer got an `MTLDevice` from the TGL driver, and CoreDisplay's shaders
compiled. WindowServer then aborted in `CoreDisplay::CreateMetalDevice` → `GetGPUPassRenderPipelineState`:
`-[_MTLFunctionInternal layouts]: unrecognized selector`, thrown in `-[MTLIGRenderPipelineState generate3DStateVF:posh:]`.
libxedrv's preflight did not know the 24H232 descriptor encoding (it checked for Tahoe's), turned the conversion off,
and the 16.0.32 driver read `vertexFunction` where its layout has `vertexDescriptor`. Evidence, read from Linux:
`/Library/Logs/DiagnosticReports/WindowServer-2026-10-31-235421.ips` and `/private/tmp/xedrv-WindowServer.log`.

## Pipeline descriptor on 24H232

Source: the named type encoding of `_private` in `MTLRenderPipelineDescriptorInternal`, from the 24H232 dyld shared
cache (OS cryptex on the Preboot volume). The struct is 0x278 bytes (class size 0x2a8, ivar at 0x30).

| Part | Sequoia | Old driver (16.0.32) | Conversion |
|---|---|---|---|
| attachments … `shaderValidation` | 0x00–0xa8 | 0x00–0xa8 | copied |
| `sampleCount` … `vertexDescriptor` | 0xb8–0x118 | 0xa8–0x108 | copied (skips `shaderValidationState`, `textureWriteRoundingMode`) |
| `vertexBuffers` … `gpuCompilerSPIOptions` | 0x198 | 0x108 | copied |
| `pad0` … `maxVertexAmplificationCount` | 0x1c0 | 0x128 | copied |
| old tail (`Q@Q`) | 0x1e0 holds `binaryArchives`, `compilerTimeoutInSeconds`, `vertexLinkedFunctions` (`@Q@`) | 0x148–0x160 | zeroed: no pipeline method of the driver reads it |
| misc bitfield | old 21 fields and widths, plus 3 fields at bits 34–36 | bits 0–33 | masked to bits 0–33 |
| color attachment bits | blend@0 … writeMask@27, logicOp@31–35, pixelFormat@36 | same | none |

The byte offsets are Tahoe's; the bitfields are the old driver's. Tahoe widened `alphaToCoverage`, `alphaToOne`,
`blendingEnabled` and `writeMask`, which is why its conversion remaps bits and Sequoia's does not.

## libxedrv v21

- Recognizes Tahoe or Sequoia by the encoding, probes a descriptor with known values (`rasterSampleCount`, `label`,
  `vertexDescriptor`, misc bits, `maxVertexAmplificationCount`, attachment bits) and runs the conversion on it. On
  Sequoia every check must pass.
- If no layout is recognized, `initWithAcceleratorPort:` refuses the device in every process: the desktop runs on the
  software renderer instead of crashing. `XE_FORCE_DEVICE=1` overrides.
- `macos/src/xe-preflight.m` loads a libxedrv in a normal process, so the preflight runs without the GPU driver and
  without a reboot; the verdict is in `/tmp/xedrv-xe-preflight.log`.

## Second accelerated boot (1 Nov): accelerated desktop

- `ATUALIZAR-SEQUOIA.command` rebuilt the Metal driver from d586e33 and the preflight passed in the safe boot:
  `sampleCount@0xb8=4 vertexDescriptor@0x110 ok label@0xf8 ok misc@0xe0=0x7f801b ampl@0x1dc=2
  attachment=0x50051401089 (esperado 0x50051401089) … auto-teste da conversão ok`, then
  `layout: Sequoia -> conversão ligada`.
- In the accelerated boot, WindowServer loaded libxedrv with `layout=Sequoia` and converted the descriptors. Its
  pipeline log reached 128 pipelines created and 0 failures, CoreDisplay's shaders and `UberCompositeVertex` /
  `UberCompositeFragment` included. 31 processes loaded libxedrv (Finder, Dock, Safari, Chrome, Terminal, System
  Settings and others), and none logged a crash or a failure. The desktop worked.
- No crash or panic report.
- The full accelerated boot-args (253 characters) are in use; the first test had run with a trimmed set.

## External HDMI (1 Nov)

With `config-seq-hdmi.plist` (the boot-args of `hdmi-flags.sh light`, unchanged from the Tahoe test) the external
monitor shows a picture next to the internal panel; reported by the user. `VER-HDMI.command` was not run, so the mode,
the refresh rate and the XE-HDMI13 log lines of this boot are not recorded. The HDMI code patches the 16.0.32 Tiger
Lake framebuffer, the same binary as on Tahoe.

## Audio

`CS8409HDA.kext` is in the EFI and OpenCore injects it on Sequoia (`OC: Prelinked injection CS8409HDA.kext v0.1.0 -
Success`). Unlike Tahoe, Sequoia still ships AppleHDA, and AppleHDAController's `BuiltInHDA` personality matches every
HDA controller by PCI class (`0x04010000&0xFFFD0000`, which takes the controller's `0x0403`). CS8409HDA used its own
`IOMatchCategory`, so both drivers could attach to `8086:51C8`. In the HDMI boot AppleHDAController and IOHDAFamily
logged: their log-format files appeared in `/private/var/db/uuidtext` at 01:20. CS8409HDA's personality is now in the
default match category with `IOProbeScore` 1000. The kext loads from the boot kext collection, before AppleHDA's system
collection, so IOKit should give the controller no second driver. Only the Info.plist changed (commit 45cba64).

`tools/SOM-SEQUOIA.command` checks the IORegistry first and stops if AppleHDAController is attached. Then it builds
`cs8409ctl` and XeSpeakers on the Mac, runs `audio.sh test` (beeps recorded by the internal microphone, then the
sound device) and can grant the microphone to Google Chrome with `tcc-permitir.sh`. Test pending.

Every boot of 1 Nov left a `shutdown_stall` report, in spindump's binary format (`spindump -i` decodes it on macOS);
not looked into yet.

## Stability fix verified + audio and privacy (1 Nov, later)

Logs of the boots after `ATUALIZAR-SEQUOIA` (decoded from Linux):

- **Shader fix works.** The installed `xe.bundle` carries the `XE_LOG` gate (`libLLVMbridge.dylib`,
  `libMTLIGCCompilerPlugin.dylib`); 976 compiles in the session with **zero contained failures** and no 250 ms
  sleeps (the ~70 `xe-dump` lines left are the once-per-process `hwinfo` dump, harmless). The user confirmed the
  hitches are gone. The ~260 ms per compile remains — it is the 2020 IGC itself — and the per-app shader cache warms
  it down on repeat launches.
- **Audio works; the controller race is resolved.** Apple still ships AppleHDA on Sequoia, and on the 1 Nov 01:20
  boot (before the match-category fix) AppleHDAController did attach to the 51C8 controller. Since the fix
  (`IOProbeScore` 1000, default category) only CS8409HDA attaches: both post-fix boots logged
  `XeSpeakers: hardware READY (bring-up 7 ms)`, "Alto-falantes internos"/"Microfone interno" activated as the
  defaults, and OBS opened the internal mic. Any sound loss during the update was transient; a reboot or re-picking
  the output in Settings restores it.
- **Privacy prompts: native auto-prompt can't appear while acceleration is on.** `amfi_get_out_of_my_way=1` is
  required to load the ad-hoc-signed driver, and it makes tccd treat third-party apps as platform binaries:
  the log shows `Policy disallows prompt … is Platform Binary` (OBS, Discord, Chrome microphone requests).
  The mic/camera are real system devices and work; only the first-time permission prompt is suppressed. Grant or
  revoke per app with `tools/tcc-permitir.sh` (or the `tools/PERMISSOES.command` launcher); after a grant the app is
  listed in Settings › Privacy & Security to toggle. This is the known trade-off (EXPERIMENTS.md #9).

## Native TCC prompts without losing acceleration — library-validation exemption (in test)

The privacy trade-off above is not fundamental. `amfi_get_out_of_my_way=1` disables *all* of AMFI; the only
thing the ad-hoc GPU bundle actually needs is for **library validation** not to reject it (EXPERIMENTS.md #9:
the failure was `Library Validation failed … mapping process is a platform binary`). Disabling only library
validation — leaving the rest of AMFI (platform-binary labelling, entitlement checks) in place — lets the
bundle load *and* lets tccd keep prompting third-party apps. OpenCore Legacy Patcher dropped the same
boot-arg this way (dortania/OpenCore-Legacy-Patcher #380 is the identical symptom, #497 the fix).

Evidence from the 24H232 x86_64 kernel (read-only, from Linux): AMFI's LV hook
(`AppleSystemPolicy::fileCheckLibraryValidation` → `library_validation(...)`) imports and calls
`cs_require_lv` and `cs_system_require_lv`. `cs_require_lv` returns 1 when `cs_library_val_enable != 0` **or**
the process has `CS_REQUIRE_LV` (0x2000) — which hardened third-party apps (Chrome/Discord) carry — so
patching the global alone is not enough; the function must be routed.

Patch (NootedGreen, commit 7b5c45e): opt-in boot-arg `ngreenlv=1`. `DYLDPatches::processPatcher` routes
`_cs_require_lv` and `_cs_system_require_lv` (KernelID, `routeMultipleLong`) to return 0, so library
validation is never required. Per-page cdhash validation (`cs_validate_page`) is untouched, so the bundle's
own ad-hoc signature is still checked. Off by default; the daily `config-seq-hdmi` is unchanged. The source
change compiles clean against MacKernelSDK + Lilu 1.7.2 (`clang -fsyntax-only`, Darwin target, from Linux).

Test (USB, reversible): `TESTAR-LV.command` builds the patched NootedGreen, installs it on the SSD EFI
(backup `NootedGreen.kext.lvbak`) and switches to `config-seq-lv.plist` — identical to `config-seq-hdmi` but
with `amfi_get_out_of_my_way=1` replaced by `ngreenlv=1` (ocvalidate clean). `REVERTER-LV.command` restores
`config-seq-hdmi` and the old kext; Linux stays in the OpenCore picker as the safe path. To confirm:
acceleration still loads in WindowServer **and** in a third-party Metal app, and a native microphone prompt
appears for a third-party app (no `tools/tcc-permitir.sh`). **Not yet confirmed on hardware.**

## Stability (1 Nov): stutters and one freeze

A ~57-minute session (Discord, Spotify, Chrome, Geekbench) stuttered. The unified log of that boot, decoded from
Linux with the mandiant parser (`macos-UnifiedLogs`, log-archive mode over the copied `Persist/Special/uuidtext`),
shows two separate causes.

**Everyday hitches — the shader compiler.** `MTLCompilerService` ran ~2000 compiles, each a median 260 ms in the
2020 IGC (the Apple front-end is ~5 ms; the time is the old compiler building the ISA). Apps that build pipelines at
runtime paid tens of seconds total: Chrome 87 s, Discord 65 s, Spotify 54 s, Code 36 s, Spotlight 40 s. Worse,
`compiler-adapter` was dumping every bitcode and reply as base64 (~15 MB of syslog) and **sleeping 250 ms per compile
for the first 40 of every process** — about 10 s of pure stall at each Electron app's launch. That debug logging and
sleep are now off unless `XE_LOG=1` (commit 9ef6b10). The per-compile 260 ms remains (it is the compiler); the Metal
shader cache is working (Discord 5.4 MB, Chrome 8.7 MB written), so repeat launches compile less.

**The freeze — a GPU hang that does not recover.** At 02:58, under Geekbench, a WindowServer GPU submission timed out
(RCS render ring busy and "Appears hung", BCS blitter stuck); `Kernel_…-025816.gpuRestart` has the hang dump.
`IOAccelEventMachine2` then looped every ~5.2 s until the user rebooted 8 minutes later: `checkGPUProgress →
Signaling hardware error on channel 26 → GPURestartSkipped: "no channel associated with stamp_idx 26"`. The restart
for the guilty channel is skipped, the ring stays hung, and WindowServer's CoreAnimation `synchronize timed out`
fired 143 times (the frozen UI). This is the class of bug NootedGreen's XE-GPUREC addresses on Tahoe, but on Sequoia
the restart cannot map the stamp back to a channel and never clears the hang. It only happened once, under a GPU
benchmark; it is the next thing to fix (kernel side, in `IOAccelEventMachine2`/XE-GPUREC) and needs test boots.
Avoid GPU stress benchmarks until then.

## DYLD patches on 24H232

The CoreDisplay patterns in `DYLDPatches.cpp` come from Sonoma 14.7.1. None of the active ones (isRemovable guard,
V187, V189) occurs in the 24H232 shared cache, so they don't apply and CoreDisplay runs unpatched. The disabled
GetMTLTexture pattern matches 20 unrelated functions there (WebCore, CoreNLP, HealthKit and others) and must stay
disabled: the patcher rewrites every matching shared-cache page.

## Testing

- `tools/ATUALIZAR-SEQUOIA.command`, run in the safe boot: saves the kernel and WindowServer logs of the previous
  accelerated boot, rebuilds the Metal driver from the source tarball, runs `xe-preflight`, and only if it passes
  installs the bundle in `/Library/GPUBundles` and copies `config-seq.plist` over `config.plist` on the SSD's EFI.
- EFI configs on the SSD: `config-install.plist` (safe: no 9A49 spoof, NootedGreen off), `config-seq.plist`
  (accelerated: NootedGreen from Darwin 24, the full accelerated boot-args plus `-v keepsyms=1`),
  `config-seq-hdmi.plist` (`config-seq.plist` plus the boot-args of `hdmi-flags.sh light`, the set of the 30 Oct
  HDMI test on Tahoe; 391 characters), backups `config-tahoe-accel.bak.plist` and `config-antes-acel.bak.plist`.
- To get back to the safe boot, copy `config-install.plist` over `config.plist` (the OpenCore picker always offers
  Linux). `install.sh --uninstall` removes the stack.
