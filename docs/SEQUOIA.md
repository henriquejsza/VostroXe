# macOS Sequoia (port in progress)

VostroXe was built for Tahoe 26.7.1 (25G241). This page tracks the port to Sequoia 15.8.2 (24H232, Darwin 24.6) on
the same Vostro 3520.

Status (1 Nov): the accelerated desktop works (second accelerated boot, below). HDMI is being tested. Sound, sleep
and the other areas have not been checked on Sequoia.

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
- No crash or panic report. Both boots of that session, the safe one and the accelerated one, left a
  `shutdown_stall` report; not looked into yet.
- The full accelerated boot-args (253 characters) are in use; the first test had run with a trimmed set.

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
