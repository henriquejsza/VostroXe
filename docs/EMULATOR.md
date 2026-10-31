# Android emulator on the Vostro 3520

Status: **fix ready, not tested on the laptop yet.** The Android Studio emulator showed a black window: the
guest's Linux kernel panics 0.4 s into its boot on an instruction the hypervisor does not allow.
`zsh tools/emulador-android.sh corrigir` makes the guest kernel stop using it. On 31 Oct this got the guest kernel
past the TPAUSE panic and through Android init (confirmed in the guest kernel log), but it then hung on a second
CPUID mismatch (PKU); `corrigir` now clears that too. Still not booted to the UI on the laptop
([the tries](#first-try-30-oct)).

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
- The emulator's HVF code sets only "virtualize APIC accesses" among the secondary VMX controls
  (`target/i386/hvf-all.c`), so "enable RDTSCP" is off as well. It hides RDTSCP from the guest (CPUID 0x80000001
  EDX keeps only LM, SYSCALL and NX), but RDPID (leaf 7 ECX bit 22) passes through, and RDPID needs the same control:
  KVM hides RDPID when it cannot set "enable RDTSCP" (`vmx_set_cpu_caps()`). Linux uses RDPID in the vDSO's
  `getcpu()` (`vdso_read_cpunode()`), so Android programs would hit it after the kernel boots.
- PKU (memory protection keys, leaf 7 ECX bit 3) is the third case, found in the fourth try (below). The emulator
  advertises PKU, so the guest sets `CR4.PKE` and uses the PKRU register, but the guest's XSAVE (CPUID leaf 0xD)
  does not carry the PKRU component: `x86/fpu: Enabled xstate features 0x7` (x87, SSE, AVX only). No real CPU is
  inconsistent like that. When the kernel saves a process's FPU state into a signal frame it looks up the PKRU
  component (feature 9) and warns (`get_xsave_addr_user`, `xstate.c`), and `init` (PID 1) wedges in signal
  delivery, which hangs the whole VM.

Virtualization as such works: the emulator's VM ran the guest kernel, and Docker Desktop's Linux VM (Apple's
Virtualization.framework, Linux 7.0.14) booted to its login prompt on 30 Oct.

## Fix

The kernel parameter `clearcpuid=waitpkg,rdpid,pku` makes the guest kernel ignore all three features: `udelay()` uses the
TSC loop, `getcpu()` uses LSL, and no process enables protection keys (no PKRU in the signal frame). The emulator
appends an AVD's `kernel.parameters` property to the guest command line
(`android/android-emu/android/main-kernel-parameters.cpp`). On Linux under KVM, the same `kernel-ranchu` printed
`Clearing CPUID bits: waitpkg rdpid pku` with this parameter and brought up 6 CPUs.

```sh
zsh tools/emulador-android.sh            # status: kern.hv_support, emulator -accel-check, AVDs, snapshots, adb devices
zsh tools/emulador-android.sh corrigir   # all AVDs, or the ones named; close the emulator first
zsh tools/emulador-android.sh desfazer   # removes the fix and sets forceColdBoot=no again
zsh tools/emulador-android.sh boot-frio  # only removes the quickboot snapshot
zsh tools/emulador-android.sh testar     # cold boot of the first AVD with the guest kernel log in a file
```

`corrigir` makes three changes to each AVD, with a backup first:

1. Adds `clearcpuid=waitpkg,rdpid,pku` to `kernel.parameters` in the AVD's `config.ini`.
2. Sets `fastboot.forceColdBoot=yes`, so the emulator never loads a quickboot snapshot and always does a clean cold
   boot, including launches from Device Manager. Quickboot has never loaded on this machine: every attempt since
   25 Oct failed (`error while loading state ... 'goldfish_pipe'`, or `Error -5 while loading VM state`), and a
   half-applied load leaves the VM dirty and the fallback cold boot stuck in the BIOS (second and third tries). This
   trades fast boot (which never worked here) for a reliable boot.
3. Removes the quickboot snapshot `default_boot`, a guest that already panicked. It has two parts and both go: the
   guest RAM in `snapshots/default_boot`, moved into the backup, and the CPU and device state, an internal qcow2
   snapshot named `default_boot` in the AVD's `.qcow2` disks, deleted with the SDK's `emulator/qemu-img snapshot -d`
   after a copy of each disk into the backup (an APFS clone when possible). If the SDK's `qemu-img` does not run,
   nothing is removed, but `forceColdBoot=yes` already keeps the snapshot from being loaded.

It also removes the renderer choices the emulator's settings save in the AVD's `AVD.conf` (`glesBackendPreference`,
`glesApiLevelPreference`, `guestGlesDriverPreference`), so the emulator picks the renderer itself again (SwiftShader
for API 37). Backups go to `~/Library/Application Support/xe-emulador/<date-time>/<AVD>/`. Run it again for each new
AVD and after editing an AVD in Device Manager. `corrigir` acts even when `kernel.parameters` is already set, because
the snapshot can come back (the emulator saves it on exit). `desfazer` undoes 1 and 2. The status shows which AVDs
have the fix, the cold-boot setting, the renderer choices, what the last start used (`hardware-qemu.ini`), the
quickboot snapshot, and the next command to run.

`testar` removes the quickboot snapshot and starts the emulator with `-no-snapshot-load -no-snapshot-save
-show-kernel`, so the guest kernel's console goes to a log file (`~/Library/Logs/xe-emulador/` by default). It
leaves no snapshot behind.

Limits:

- `clearcpuid` only changes what the kernel uses. A guest program that reads CPUID itself still sees WAITPKG and
  RDPID and would get SIGILL on TPAUSE, UMWAIT or RDPID.
- The guest GPU stays in software (SwiftShader): for API 37 the emulator needs GLES 3.1 from the host, and OpenGL on
  this machine is software-only. With the host renderer the emulator got `Apple Software Renderer` and
  `OpenGL ES 2.0 (2.1 APPLE-23.1.1)` (30 Oct).

## adb

Android Studio could not start the adb server: `idea.log` (25–29 Oct) has 97 `adb start-server` exits with code 255
(`ADB server didn't ACK`). The server log it quotes shows an Android device on USB failing with
`Could not open interface: e00002c5` (`kIOReturnExclusiveAccess`). Without adb, Studio cannot install an app on the
emulator even after it boots. Not investigated yet; the status runs `adb devices`. On 30 Oct Studio connected to
adb, with no `start-server` failure.

In the 22:37 run of 30 Oct adb failed again (`ADB server didn't ACK`), and the emulator's crash handler (which adb
inherits as its child) wrote 13 minidumps in 3 minutes (`/tmp/android-<user>/emu-crash-37.2.12.db/completed/`). Each
one is the adb server killed by the system: `EXC_CRASH` with code `0x09c0....`, that is `SIGKILL` after a guard
exception (`EXC_GUARD`), on its `RunLoop` thread inside `IOUSBLib`, while it scans USB devices.

## First try, 30 Oct

The status ran (`zsh emulador-android.sh`, without `corrigir`), so the AVD did not change: `config.ini` still dated
from 25 Oct, without `kernel.parameters`, and there was no backup folder. The emulator then ran twice:

- 21:53, cold boot (the old snapshot failed to load: `error while loading state ... 'goldfish_pipe'`), SwiftShader.
- 21:55, after renderer choices were saved in `AVD.conf` (`glesBackendPreference=6`, `glesApiLevelPreference=2`,
  `guestGlesDriverPreference=2`): `gles_mode_selected:host`, `Apple Software Renderer`, OpenGL ES 2.0, and the
  warning `API level '37' requires GLES 3.1`.

The snapshot saved at 21:56 holds the same panic, now at 0.355561 s, with 83 records of `delay_halt_tpause` and no
`clearcpuid` on the guest command line. Both windows stayed black.

## Second try, 30 Oct

`corrigir` ran at 22:37 (report on the USB: `kernel.parameters=clearcpuid=waitpkg,rdpid`, renderer choices removed,
`snapshot default_boot` moved), and the start at 22:37:57 used it (`hardware-qemu.ini`:
`kernel.parameters = clearcpuid=waitpkg,rdpid`, SwiftShader). The window stayed black for the 2 min 50 s it ran. The
state saved at exit, read from the AVD's `cache.img.qcow2` (VM state) and `ram.bin` on Linux:

- The guest never left the BIOS. Its RAM had 71 non-zero pages: the interrupt table, SeaBIOS, ACPI tables, no kernel.
- vCPU0 was in real mode at `f000:ff53`, the `iret` of SeaBIOS's default interrupt handler, with `0000:0003` as the
  return address on its stack. It had jumped to `0000:0000` and was running the interrupt table as code: the bytes at
  `0000:0003` are `f0 53` (`lock push bx`), an invalid opcode, and the #UD handler (`f000:ff53`) returns to the same
  instruction.
- vCPU4 was in SeaBIOS's CPU scan (`smp_scan`), waiting with `CountCPUs = 5` for 6 (`RBX = 6`). vCPUs 1, 2, 3 and 5
  had reported in and halted; vCPU0 never did.

Why: `corrigir` had moved only the RAM part of the old quickboot snapshot (`snapshots/default_boot`). The rest is an
internal snapshot `default_boot` in the AVD's `.qcow2` disks (the CPU and device state is in `cache.img.qcow2`), and it
stayed. The emulator
started loading it, failed (`Error -1 from the snapshot callback`), and the boot that followed did not start from a
clean machine. The most likely path to `0000:0000`: the old state is a guest that panicked inside `native_kick_ap`,
after Linux had set the CMOS shutdown code to 0x0A and the warm-reset vector at 40:67 to its trampoline (the 21:56
RAM has 40:67 = `9900:0000`). SeaBIOS's reset path (`handle_resume`) reads that code, clears it (CMOS 0x0F was 0 at
exit) and for 0x0A jumps through 40:67. Without the old RAM the vector is `0000:0000`, which it was at exit.

So the fix was not tested in this run. The tool then removed both parts of the snapshot.

## Third try, 30 Oct

`CORRIGIR-EMULADOR.command` ran `corrigir` at 23:46, but the AVD already had `kernel.parameters=clearcpuid=waitpkg,rdpid`
from 22:37, and that version of `corrigir` only removed the snapshot when it changed `kernel.parameters`. So it printed
`já corrigido` and left the snapshot that the 22:40 exit had saved whole. `testar` did not run (no `-no-snapshot-load`
in `idea.log`); the emulator was launched from Device Manager at 23:47 and 23:58, both loaded the snapshot, both failed
(`error while loading state ... 'goldfish_pipe'`, `Error -5`), both black.

Two fixes followed: `corrigir` now acts even when `kernel.parameters` is already set (it removes the snapshot and sets
cold boot), and it sets `fastboot.forceColdBoot=yes` so a Device Manager launch can never load the snapshot. Quickboot
has never loaded on this machine, so forcing cold boot costs nothing here.

## Fourth try, 31 Oct (TPAUSE fixed, PKU hang)

`corrigir` + `testar` ran at 00:25 with `clearcpuid=waitpkg,rdpid`, cold boot, no snapshot. The guest kernel log
(`-show-kernel`, 1984 lines) shows the TPAUSE fix worked: `Clearing CPUID bits: waitpkg rdpid`, `Run /init as init
process` at 1.66 s, no panic, Android init reached its second stage and started 40+ services (logd, servicemanager,
vold, keystore2, surfaceflinger, apexd, zygote's parents). Then it hung: at 15.6 s the kernel logged
`WARNING ... get_xsave_addr_user+0x30 ... copy_fpstate_to_sigframe ... x64_setup_rt_frame` for `init` (PID 1,
`RSI = 9`, the PKRU xsave component), and from ~17 s on the guest made almost no progress (log time jumps 17 → 205 →
490 → 574 s, `rcu_preempt detected stalls`, `sched: DL replenish lagged too much`). At 574 s `init` was still in the
same signal-delivery path. The window stayed black.

Why: the guest has `CR4.PKE = 1` (PKU enabled) but `Enabled xstate features 0x7` (no PKRU in XSAVE), the leaf-7 /
leaf-0xD mismatch above. Saving a signal frame for `init` looks up the missing PKRU component, warns, and wedges
`init`, which stalls the VM. Fix: add `pku` to `clearcpuid`. The KVM test accepts `clearcpuid=waitpkg,rdpid,pku`
(`Clearing CPUID bits: waitpkg rdpid pku`). Not tested on the laptop yet.

## Test

1. Close Android Studio's emulator, then run `zsh tools/emulador-android.sh corrigir` and
   `zsh tools/emulador-android.sh`. The status must say `corrigido`, `cold boot yes`, `snapshot: nenhum`, and
   `kernel.parameters=clearcpuid=waitpkg,rdpid,pku`.
2. Start the AVD from Device Manager, or run `zsh tools/emulador-android.sh testar`. Either way it cold-boots with
   software rendering: the Android logo should appear within a few minutes. `testar` also keeps the guest kernel log.
3. If it is still black, keep the log `testar` names (`~/Library/Logs/xe-emulador/<AVD>-<date-time>.txt`): it holds
   the guest kernel's console (look past 15 s, where the PKU hang used to be).
