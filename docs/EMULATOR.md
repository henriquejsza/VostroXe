# Android emulator on the Vostro 3520

Status: **fix ready, not tested on the laptop yet.** The Android Studio emulator showed a black window: the
guest's Linux kernel panics 0.4 s into its boot on an instruction the hypervisor does not allow.
`zsh tools/emulador-android.sh corrigir` makes the guest kernel stop using it.

Versions on this laptop: Android Studio 2026.2, emulator 37.2.12 (build 16428233), one AVD "Medium Phone API 37.0"
(x86_64, Google Play image revision 7, Android 17, guest kernel 6.12.81-android16).

## What happened

From the macOS disk, read from Linux: Android Studio's `idea.log` and the AVD folder.

- The emulator ran twice, on 25 Oct (2 min) and 29 Oct (3 min). Each time it created the VM (`pc_memory_init`),
  picked software rendering (`API level 37 requires GLES 3.1, forcing software rendering for GLES`: SwiftShader for
  Vulkan, ANGLE on SwiftShader for GLES) and opened its window. At exit it logged
  `Could not take screenshot, error: -1`: the guest never posted a frame.
- The quickboot snapshot saved at the 29 Oct exit (`snapshots/default_boot/ram.bin`, the guest RAM, uncompressed)
  still holds the guest kernel log:

  ```
  [    0.408246] Kernel panic - not syncing: Fatal exception in interrupt
  Oops: invalid opcode: 0000 [#19] PREEMPT SMP PTI
  CPU: 0 UID: 0 PID: 1 Comm: swapper/0 Tainted: G      D            6.12.81-android16-6-g4f69fc7b210c-ab16167562 #1
  RIP: 0010:delay_halt_tpause+0x15/0x20
  Code: ... 48 c1 ea 20 31 c9 <66> 0f ae f1 5d c3 ...
   __udelay+0x14/0x30
   native_kick_ap+0x434/0x640
   ...
   smp_init+0x29/0x90
  ```

  `66 0f ae f1` is `tpause ecx`. The first fault comes while the kernel starts the other 5 vCPUs
  (`native_kick_ap` → `udelay`). The panic path calls `udelay` again and faults again: the snapshot holds 83
  records with that RIP. The guest never reached `/init`.

## Why

- Linux 6.12 implements `udelay()` with TPAUSE when the CPU reports WAITPKG (`x86_late_time_init()` →
  `use_tpause_delay()` in `arch/x86/kernel/time.c`). The i5-1235U reports it (`waitpkg` in `/proc/cpuinfo` on
  Linux). Intel Macs never had a CPU with WAITPKG.
- The emulator's own QEMU fork passes CPUID leaf 7 ECX from the host to the guest and removes only AVX512VBMI
  (`target/i386/hvf-utils/x86_cpuid.c`). Upstream QEMU's HVF code keeps an allow-list of three ECX bits
  (AVX512_VBMI, AVX512_VPOPCNTDQ, RDPID), so it never shows WAITPKG to a guest.
- In VMX non-root mode TPAUSE raises #UD unless the hypervisor sets the "enable user wait and pause" control. KVM
  shows WAITPKG to a guest only when it can set that control (`cpu_has_vmx_waitpkg()`). The emulator's VM runs
  without it under Hypervisor.framework, hence the invalid opcode above.

Virtualization as such works: the emulator's VM ran the guest kernel, and Docker Desktop's Linux VM (Apple's
Virtualization.framework, Linux 7.0.14) booted to its login prompt on 30 Oct.

## Fix

The kernel parameter `clearcpuid=waitpkg` makes the guest kernel ignore WAITPKG, so `udelay()` uses the TSC loop.
The emulator appends an AVD's `kernel.parameters` property to the guest command line
(`android/android-emu/android/main-kernel-parameters.cpp`). On Linux under KVM, the same `kernel-ranchu` printed
`Clearing CPUID bits: waitpkg` with this parameter and brought up 6 CPUs.

```sh
zsh tools/emulador-android.sh            # status: kern.hv_support, emulator -accel-check, AVDs, adb devices
zsh tools/emulador-android.sh corrigir   # all AVDs, or the ones named; close the emulator first
zsh tools/emulador-android.sh desfazer   # removes clearcpuid=waitpkg again
```

`corrigir` adds `clearcpuid=waitpkg` to `kernel.parameters` in each AVD's `config.ini` and moves the quickboot
snapshot `default_boot`, a guest that already panicked, into the backup, so the next start is a cold boot. Backups
go to `~/Library/Application Support/xe-emulador/<date-time>/<AVD>/`. Run it again for each new AVD and after editing
an AVD in Device Manager; the status shows which AVDs have the fix and what the last start used (`hardware-qemu.ini`).

Limits:

- `clearcpuid` only changes what the kernel uses. A guest program that reads CPUID itself still sees WAITPKG and
  would get SIGILL on TPAUSE or UMWAIT.
- The guest GPU stays in software (SwiftShader): for API 37 the emulator needs GLES 3.1 from the host, and OpenGL on
  this machine is software-only.

## adb

Android Studio could not start the adb server: `idea.log` (25–29 Oct) has 97 `adb start-server` exits with code 255
(`ADB server didn't ACK`). The server log it quotes shows an Android device on USB failing with
`Could not open interface: e00002c5` (`kIOReturnExclusiveAccess`). Without adb, Studio cannot install an app on the
emulator even after it boots. Not investigated yet; the status runs `adb devices`.

## Test

1. Close Android Studio's emulator, then run `zsh tools/emulador-android.sh corrigir` and
   `zsh tools/emulador-android.sh`.
2. Start the AVD from Device Manager. The first start is a cold boot with software rendering: the Android logo
   should appear within a few minutes.
3. Run `zsh tools/emulador-android.sh` again and keep the output (it shows `kernel.parameters` of the last start and
   `adb devices`).
