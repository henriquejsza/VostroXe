// cs8409ctl: command-line tool for the CS8409HDA kext (Dell Vostro 3520 internal audio).
//
//   cs8409ctl info                 kext version, state, controller and codec ids
//   cs8409ctl log [FILE]           the kext's own log (bring-up, errors, register dumps)
//   cs8409ctl dump                 controller + codec registers into the kext log (hardware must be up)
//   sudo cs8409ctl verb HEX        one raw HDA verb (cmd = addr << 28 | nid << 20 | verb), hardware up
//   cs8409ctl test [SECONDS]       speakers: 1 kHz tone at -24 dBFS, checks the DMA rate, twice (restart path)
//   cs8409ctl rec FILE.wav [S]     internal microphone to a WAV file (S32_LE stereo 48 kHz)
//   cs8409ctl selftest             tone through the speakers recorded by the internal microphone, with and without
//                                  the tone: proves speakers + microphone + both DMA paths without anyone listening
//   cs8409ctl report [FILE]        info + test + selftest + dump + log into one text file (default
//                                  ~/cs8409-report.txt), the thing to send back when something fails
//
// The playback/record commands open a driver connection like the XeSpeakers HAL plug-in does; while coreaudiod owns
// the device (plug-in installed) they get "busy": remove the plug-in first or use System Settings.
// Build (Command Line Tools): clang -O2 -Wall -o cs8409ctl cs8409ctl.c -framework IOKit -framework CoreFoundation
#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CoreFoundation.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../AudShim/AudShimDrv.h"

#define CTL_VERSION "0.1.0"
static const uint32_t kRing = AUDSHIM_RING_BYTES, kFrames = AUDSHIM_RING_FRAMES;
static const double kRate = 48000.0, kToneHz = 171.0 * 48000.0 / 8192.0;   // 1001.95 Hz, seamless in the ring

static FILE *gOut;          // stdout, or the report file (everything printed is also captured there)
static void say(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
static void say(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    if (gOut && gOut != stdout) {
        va_start(ap, fmt);
        vfprintf(gOut, fmt, ap);
        va_end(ap);
    }
    fflush(stdout);
}

static double ticksToSec(uint64_t t) {
    static mach_timebase_info_data_t tb;
    if (!tb.denom) mach_timebase_info(&tb);
    return (double)t * tb.numer / tb.denom / 1e9;
}

static io_service_t findKext(void) {
    return IOServiceGetMatchingService(MACH_PORT_NULL, IOServiceMatching("CS8409HDA"));
}

static io_connect_t openConn(uint32_t type) {
    io_service_t s = findKext();
    io_connect_t c = IO_OBJECT_NULL;
    if (!s) { say("CS8409HDA kext not loaded (check: kmutil showloaded | grep CS8409)\n"); return IO_OBJECT_NULL; }
    kern_return_t kr = IOServiceOpen(s, mach_task_self(), type, &c);
    IOObjectRelease(s);
    if (kr) { say("IOServiceOpen(type 0x%x): 0x%x\n", type, kr); return IO_OBJECT_NULL; }
    return c;
}

static const char *stName(uint64_t s) {
    static const char *n[] = {"IDLE", "BUSY", "READY", "RUNNING", "FAILED"};
    return s < 5 ? n[s] : "?";
}

static int drv(io_connect_t c, uint64_t op, uint64_t a0, uint64_t o[16]) {
    uint64_t in[2] = {op, a0};
    uint32_t n = 16;
    memset(o, 0, 16 * sizeof o[0]);
    kern_return_t kr = IOConnectCallScalarMethod(c, AUDSHIM_METHOD_DRV, in, 2, o, &n);
    if (kr) { say("  DRV op %llu: IOKit error 0x%x\n", (unsigned long long)op, kr); return -1; }
    return 0;
}

static void printState(const uint64_t o[16]) {
    say("  state %s, fail step %llu code %lld, starts %llu, bring-ups %llu (last %llu ms), DMA errors %llu, "
        "linger %llu, cap -%llu dB\n", stName(o[1]), (unsigned long long)o[2], (long long)(int32_t)o[3],
        (unsigned long long)o[7], (unsigned long long)o[11], (unsigned long long)o[12], (unsigned long long)o[10],
        (unsigned long long)((o[14] >> 1) & 1), (unsigned long long)o[6]);
}

// ---------------------------------------------------------------- info / log / dump / verb
static int cmdInfo(void) {
    io_service_t s = findKext();
    if (!s) { say("CS8409HDA kext not loaded\n"); return 1; }
    CFStringRef ver = (CFStringRef)IORegistryEntryCreateCFProperty(s, CFSTR("CS8409HDAVersion"), NULL, 0);
    char vb[32] = "?";
    if (ver && CFGetTypeID(ver) == CFStringGetTypeID()) CFStringGetCString(ver, vb, sizeof vb, kCFStringEncodingUTF8);
    if (ver) CFRelease(ver);
    IOObjectRelease(s);
    io_connect_t c = openConn(0);
    if (!c) return 1;
    uint64_t o[16] = {0};
    uint32_t n = 16;
    kern_return_t kr = IOConnectCallScalarMethod(c, 0, NULL, 0, o, &n);
    IOServiceClose(c);
    if (kr) { say("info: 0x%x\n", kr); return 1; }
    say("CS8409HDA %s (cs8409ctl %s), interface v%llu\n", vb, CTL_VERSION, (unsigned long long)o[15]);
    say("  playback %s, capture %s, bring-ups %llu, verbs %llu (timeouts %llu), last failure step %llu code %lld\n",
        stName(o[1]), o[2] == 1 ? "running" : o[2] == 2 ? "FAILED" : "off", (unsigned long long)o[8],
        (unsigned long long)o[9], (unsigned long long)o[10], (unsigned long long)(o[11] & 0xffffffff),
        (long long)(int32_t)(o[11] >> 32));
    say("  controller GCAP %04llx GCTL %08llx, PCI cmd/sts %08llx PMCSR %04llx\n", (unsigned long long)o[3],
        (unsigned long long)o[14], (unsigned long long)o[12], (unsigned long long)o[13]);
    if (o[5])
        say("  codec mask %04llx, CS8409 vendor %08llx subsystem %08llx revision %08llx\n", (unsigned long long)o[4],
            (unsigned long long)o[5], (unsigned long long)o[6], (unsigned long long)o[7]);
    else
        say("  codec not probed yet (the hardware is brought up when a client opens it)\n");
    return 0;
}

static int cmdLog(const char *path) {
    io_connect_t c = openConn(0);
    if (!c) return 1;
    FILE *f = path ? fopen(path, "w") : NULL;
    if (path && !f) { say("cannot write %s\n", path); IOServiceClose(c); return 1; }
    uint64_t off = 0;
    char buf[4096];
    for (;;) {
        uint64_t o[2] = {0, 0};
        uint32_t no = 2;
        size_t sz = sizeof buf;
        kern_return_t kr = IOConnectCallMethod(c, 2, &off, 1, NULL, 0, o, &no, buf, &sz);
        if (kr) { say("log: 0x%x\n", kr); break; }
        if (!o[1]) break;
        if (f) fwrite(buf, 1, (size_t)o[1], f);
        else { fwrite(buf, 1, (size_t)o[1], stdout); if (gOut && gOut != stdout) fwrite(buf, 1, (size_t)o[1], gOut); }
        off += o[1];
        if (off >= o[0]) break;
    }
    if (f) { fclose(f); say("kext log (%llu bytes) written to %s\n", (unsigned long long)off, path); }
    IOServiceClose(c);
    return 0;
}

static int cmdDump(void) {
    io_connect_t c = openConn(0);
    if (!c) return 1;
    uint64_t o[1] = {0};
    uint32_t n = 1;
    kern_return_t kr = IOConnectCallScalarMethod(c, 3, NULL, 0, o, &n);
    IOServiceClose(c);
    say("dump %s (see: cs8409ctl log)\n", kr ? "failed" : o[0] ? "written to the kext log" : "partial: hardware is not up");
    return kr ? 1 : 0;
}

static int cmdVerb(const char *hex) {
    uint64_t in = strtoull(hex, NULL, 16), o[2] = {0, 0};
    uint32_t n = 2;
    io_connect_t c = openConn(0);
    if (!c) return 1;
    kern_return_t kr = IOConnectCallScalarMethod(c, 1, &in, 1, o, &n);
    IOServiceClose(c);
    if (kr) { say("verb: 0x%x (root needed: sudo)\n", kr); return 1; }
    say("verb %08llx -> %08llx (status %lld)\n", (unsigned long long)in, (unsigned long long)o[0], (long long)o[1]);
    return o[1] ? 1 : 0;
}

// ---------------------------------------------------------------- driver-mode helpers
struct dconn {
    io_connect_t c;
    mach_vm_address_t ring, cring;
    mach_vm_size_t ringSz, cringSz;
};

static int dOpen(struct dconn *d) {
    memset(d, 0, sizeof *d);
    d->c = openConn(AUDSHIM_DRV_CONN_TYPE);
    if (!d->c) return -1;
    uint64_t o[16];
    if (drv(d->c, kDrvOpOpen, 0, o)) return -1;
    if (o[0]) {
        say("  OPEN refused: %s (result %llu)\n", o[0] == kDrvErrBusy ? "busy, coreaudiod owns the device" :
            o[0] == kDrvErrRetryLater ? "failed recently, retry in 3 s" : "bring-up failed", (unsigned long long)o[0]);
        printState(o);
        return -1;
    }
    say("  OPEN: hardware %s in %llu ms (bring-up #%llu)\n", stName(o[1]), (unsigned long long)o[12],
        (unsigned long long)o[11]);
    return 0;
}

static void dClose(struct dconn *d) {
    uint64_t o[16];
    if (!d->c) return;
    if (d->ring) IOConnectUnmapMemory64(d->c, AUDSHIM_MEM_RING, mach_task_self(), d->ring);
    if (d->cring) IOConnectUnmapMemory64(d->c, AUDSHIM_MEM_CRING, mach_task_self(), d->cring);
    drv(d->c, kDrvOpClose, 0, o);
    IOServiceClose(d->c);
    d->c = IO_OBJECT_NULL;
}

static int mapRing(struct dconn *d, int capture) {
    mach_vm_address_t *a = capture ? &d->cring : &d->ring;
    mach_vm_size_t *s = capture ? &d->cringSz : &d->ringSz;
    if (*a) return 0;
    kern_return_t kr = IOConnectMapMemory64(d->c, capture ? AUDSHIM_MEM_CRING : AUDSHIM_MEM_RING, mach_task_self(), a, s,
                                            kIOMapAnywhere | (capture ? kIOMapReadOnly : 0));
    if (kr || *s < kRing) { say("  ring map (%s) failed: 0x%x size %llu\n", capture ? "capture" : "playback", kr,
                                (unsigned long long)*s); *a = 0; return -1; }
    return 0;
}

static void fillTone(int32_t *ring, double dbfs) {
    double a = pow(10.0, dbfs / 20.0) * 2147483647.0;
    for (uint32_t i = 0; i < kFrames; i++) {
        int32_t v = (int32_t)lrint(a * sin(2.0 * M_PI * 171.0 * i / kFrames));
        ring[2 * i] = v;
        ring[2 * i + 1] = v;
    }
}

// follow the playback DMA for `secs`: returns the measured rate in bytes/s (0 on error)
static double watchPlayback(struct dconn *d, double secs) {
    uint64_t p[8], t0 = 0, tl = 0;
    uint32_t prev = 0, n;
    double moved = 0, el = 0;
    while (el < secs) {
        usleep(20000);
        n = 8;
        if (IOConnectCallScalarMethod(d->c, AUDSHIM_METHOD_POS, NULL, 0, p, &n)) { say("  POS failed\n"); return 0; }
        if (p[0] != kDrvStRunning) { say("  !! playback state %s\n", stName(p[0])); return 0; }
        if (!t0) { t0 = tl = p[2]; prev = (uint32_t)p[1]; continue; }
        moved += (double)(((uint32_t)p[1] - prev) & (kRing - 1));
        prev = (uint32_t)p[1];
        el = ticksToSec(p[2] - t0);
        if (ticksToSec(p[2] - tl) >= 0.5) {
            say("    t=%4.2f s  DPIB 0x%05x  LPIB 0x%05llx  SD %08llx  %.0f B/s\n", el, prev, (unsigned long long)p[5],
                (unsigned long long)p[4], moved / el);
            tl = p[2];
        }
    }
    return el > 0 ? moved / el : 0;
}

// ---------------------------------------------------------------- test (speakers)
static int cmdTest(double secs) {
    struct dconn d;
    uint64_t o[16];
    int rc = 0;
    say("speaker test: %.1f s of a %.1f Hz tone at -24 dBFS, two rounds\n", secs, kToneHz);
    if (dOpen(&d)) { dClose(&d); say("DRV TEST RESULT: FAIL (open)\n"); return 1; }
    if (mapRing(&d, 0)) rc = 1;
    for (int round = 1; round <= 2 && !rc; round++) {
        fillTone((int32_t *)(uintptr_t)d.ring, -24.0);
        if (drv(d.c, kDrvOpStart, 0, o) || o[0] || o[1] != kDrvStRunning) {
            say("  START round %d failed (result %llu)\n", round, (unsigned long long)o[0]);
            printState(o);
            rc = 1;
            break;
        }
        double rate = watchPlayback(&d, secs);
        if (rate < 0.8 * 384000 || rate > 1.2 * 384000) {
            say("  !! round %d: DMA rate %.0f B/s, expected 384000\n", round, rate);
            rc = 1;
        } else {
            say("  round %d: DMA rate %.0f B/s (expected 384000)\n", round, rate);
        }
        drv(d.c, kDrvOpStop, 0, o);
        usleep(400000);
    }
    drv(d.c, kDrvOpState, 0, o);
    printState(o);
    dClose(&d);
    say("DRV TEST RESULT: %s\n", rc ? "FAIL" : "SUCCESS (you should have heard two short beeps)");
    return rc;
}

// ---------------------------------------------------------------- capture
// Record `secs` from the capture ring into buf (frames S32 stereo); returns frames recorded.
static size_t capture(struct dconn *d, int32_t *buf, size_t maxFrames, double secs, double *rate) {
    uint64_t p[8], t0 = 0;
    uint32_t n, rd = 0;
    size_t got = 0;
    double el = 0;
    const uint8_t *ring = (const uint8_t *)(uintptr_t)d->cring;
    *rate = 0;
    while (el < secs && got < maxFrames) {
        usleep(10000);
        n = 8;
        if (IOConnectCallScalarMethod(d->c, AUDSHIM_METHOD_CPOS, NULL, 0, p, &n) || p[0] != 1) {
            say("  capture stopped unexpectedly\n");
            break;
        }
        uint32_t wp = (uint32_t)p[1] & (kRing - 1) & ~7u;
        if (!t0) { t0 = p[2]; rd = wp; continue; }
        while (rd != wp && got < maxFrames) {
            memcpy(&buf[2 * got], ring + rd, 8);
            got++;
            rd = (rd + 8) & (kRing - 1);
        }
        el = ticksToSec(p[2] - t0);
    }
    if (el > 0) *rate = got * 8.0 / el;
    return got;
}

// level of the tone frequency and of the band around it (Goertzel), dBFS
static void toneLevel(const int32_t *buf, size_t frames, double *tone, double *noise, double *rms) {
    double best = 0, band = 0, sum = 0;
    int nb = 0;
    if (frames > 48000) { buf += 2 * (frames - 48000); frames = 48000; }   // last second
    for (size_t i = 0; i < frames; i++) { double x = buf[2 * i] / 2147483648.0; sum += x * x; }
    *rms = 10 * log10(sum / (frames ? frames : 1) + 1e-20);
    for (int k = -6; k <= 6; k++) {
        double f = kToneHz + k * 40.0, w = 2 * M_PI * f / kRate, cw = 2 * cos(w), s1 = 0, s2 = 0;
        for (size_t i = 0; i < frames; i++) {
            double win = 0.5 - 0.5 * cos(2 * M_PI * i / (frames - 1));
            double s0 = buf[2 * i] / 2147483648.0 * win + cw * s1 - s2;
            s2 = s1; s1 = s0;
        }
        double mag = sqrt(s1 * s1 + s2 * s2 - cw * s1 * s2) / (frames / 4.0);
        if (k == 0) best = mag;
        else if (abs(k) >= 2) { band += mag; nb++; }
    }
    *tone = 20 * log10(best + 1e-12);
    *noise = 20 * log10(band / (nb ? nb : 1) + 1e-12);
}

static int writeWav(const char *path, const int32_t *buf, size_t frames) {
    FILE *f = fopen(path, "wb");
    if (!f) return -1;
    uint32_t data = (uint32_t)(frames * 8), v;
    uint16_t s;
    fwrite("RIFF", 1, 4, f); v = 36 + data; fwrite(&v, 4, 1, f); fwrite("WAVEfmt ", 1, 8, f);
    v = 16; fwrite(&v, 4, 1, f); s = 1; fwrite(&s, 2, 1, f); s = 2; fwrite(&s, 2, 1, f);
    v = 48000; fwrite(&v, 4, 1, f); v = 48000 * 8; fwrite(&v, 4, 1, f); s = 8; fwrite(&s, 2, 1, f);
    s = 32; fwrite(&s, 2, 1, f); fwrite("data", 1, 4, f); fwrite(&data, 4, 1, f);
    fwrite(buf, 8, frames, f);
    fclose(f);
    return 0;
}

static int cmdRec(const char *path, double secs) {
    struct dconn d;
    uint64_t o[16];
    double rate, tone, noise, rms;
    size_t maxf = (size_t)(secs * kRate) + 4800;
    int32_t *buf = calloc(maxf, 8);
    int rc = 1;
    if (!buf) return 1;
    if (dOpen(&d) == 0 && drv(d.c, kDrvOpCapStart, 0, o) == 0 && !o[0] && o[2] == kCapStRunning && !mapRing(&d, 1)) {
        size_t n = capture(&d, buf, maxf, secs, &rate);
        drv(d.c, kDrvOpCapStop, 0, o);
        toneLevel(buf, n, &tone, &noise, &rms);
        say("  recorded %zu frames (%.1f s), capture DMA %.0f B/s, RMS %.1f dBFS\n", n, n / kRate, rate, rms);
        if (path && n && !writeWav(path, buf, n)) say("  written to %s\n", path);
        rc = (n > 0 && rate > 0.8 * 384000 && rate < 1.2 * 384000) ? 0 : 1;
    } else {
        say("  capture start failed (result %llu, capture state %llu, step %llu code %lld)\n",
            (unsigned long long)o[0], (unsigned long long)o[2], (unsigned long long)o[3], (long long)(int32_t)o[4]);
    }
    dClose(&d);
    free(buf);
    say("REC RESULT: %s\n", rc ? "FAIL" : "OK");
    return rc;
}

// ---------------------------------------------------------------- selftest: speaker tone heard by the microphone
static int cmdSelftest(void) {
    struct dconn d;
    uint64_t o[16];
    double rate[2] = {0, 0}, prate = 0, tone[2] = {0, 0}, noise[2] = {0, 0}, rms[2] = {0, 0};
    size_t maxf = 2 * 48000 + 4800, n;
    int32_t *buf = calloc(maxf, 8);
    int rc = 1;
    if (!buf) return 1;
    say("selftest: %.1f Hz tone at -30 dBFS through the speakers, recorded by the internal microphone\n", kToneHz);
    if (dOpen(&d) || mapRing(&d, 0)) goto out;
    if (drv(d.c, kDrvOpCapStart, 0, o) || o[0] || o[2] != kCapStRunning || mapRing(&d, 1)) {
        say("  capture start failed (result %llu, step %llu code %lld)\n", (unsigned long long)o[0],
            (unsigned long long)o[3], (long long)(int32_t)o[4]);
        goto out;
    }
    for (int pass = 0; pass < 2; pass++) {      // pass 0: silence, pass 1: tone
        if (pass) fillTone((int32_t *)(uintptr_t)d.ring, -30.0);
        else memset((void *)(uintptr_t)d.ring, 0, kRing);
        if (drv(d.c, kDrvOpStart, 0, o) || o[0] || o[1] != kDrvStRunning) { say("  START failed\n"); printState(o); goto out; }
        usleep(300000);
        n = capture(&d, buf, maxf, 1.5, &rate[pass]);
        if (pass) {
            uint64_t p[8];
            uint32_t pn = 8;
            if (!IOConnectCallScalarMethod(d.c, AUDSHIM_METHOD_POS, NULL, 0, p, &pn))
                say("  playback DPIB 0x%05llx LPIB 0x%05llx SD %08llx\n", (unsigned long long)p[1],
                    (unsigned long long)p[5], (unsigned long long)p[4]);
            prate = watchPlayback(&d, 0.5);
        }
        drv(d.c, kDrvOpStop, 0, o);
        toneLevel(buf, n, &tone[pass], &noise[pass], &rms[pass]);
        say("  %s: %zu frames, capture DMA %.0f B/s, %.0f Hz at %.1f dBFS (band %.1f dBFS), RMS %.1f dBFS\n",
            pass ? "tone   " : "silence", n, rate[pass], kToneHz, tone[pass], noise[pass], rms[pass]);
        usleep(200000);
    }
    drv(d.c, kDrvOpCapStop, 0, o);
    {
        double gain = tone[1] - tone[0], snr = tone[1] - noise[1];
        int dmaOk = rate[0] > 0.8 * 384000 && rate[0] < 1.2 * 384000 && rate[1] > 0.8 * 384000 &&
                    rate[1] < 1.2 * 384000 && prate > 0.8 * 384000 && prate < 1.2 * 384000;
        say("  tone rises %.1f dB above the silent recording, %.1f dB above the nearby noise; playback DMA %.0f B/s\n",
            gain, snr, prate);
        rc = (gain > 15 && snr > 15 && dmaOk) ? 0 : 1;
        if (!dmaOk) say("  !! a DMA path did not run at 48 kHz\n");
        else if (rc) say("  !! the microphone did not hear the tone: speakers silent (or the microphone path broken)\n");
    }
out:
    dClose(&d);
    free(buf);
    say("SELFTEST RESULT: %s\n", rc ? "FAIL" : "PASS (speakers and microphone work)");
    return rc;
}

static int cmdReport(const char *path) {
    char def[1024];
    if (!path) { snprintf(def, sizeof def, "%s/cs8409-report.txt", getenv("HOME") ? getenv("HOME") : "/tmp"); path = def; }
    gOut = fopen(path, "w");
    if (!gOut) { printf("cannot write %s\n", path); return 1; }
    time_t now = time(NULL);
    say("cs8409ctl %s report, %s", CTL_VERSION, ctime(&now));
    say("\n== info\n");      cmdInfo();
    say("\n== speaker test\n"); int t = cmdTest(1.0);
    say("\n== selftest\n");  int s = cmdSelftest();
    say("\n== registers (hardware up for the dump)\n");
    {
        struct dconn d;
        if (dOpen(&d) == 0) cmdDump();
        dClose(&d);
    }
    say("\n== kext log\n");  cmdLog(NULL);
    say("\n== summary: speaker test %s, selftest %s\n", t ? "FAIL" : "SUCCESS", s ? "FAIL" : "PASS");
    fclose(gOut);
    gOut = stdout;
    printf("report written to %s\n", path);
    return t || s;
}

int main(int argc, char **argv) {
    gOut = stdout;
    const char *cmd = argc > 1 ? argv[1] : "info";
    if (!strcmp(cmd, "info")) return cmdInfo();
    if (!strcmp(cmd, "log")) return cmdLog(argc > 2 ? argv[2] : NULL);
    if (!strcmp(cmd, "dump")) return cmdDump();
    if (!strcmp(cmd, "verb") && argc > 2) return cmdVerb(argv[2]);
    if (!strcmp(cmd, "test")) return cmdTest(argc > 2 ? atof(argv[2]) : 1.5);
    if (!strcmp(cmd, "rec") && argc > 2) return cmdRec(argv[2], argc > 3 ? atof(argv[3]) : 5.0);
    if (!strcmp(cmd, "selftest")) return cmdSelftest();
    if (!strcmp(cmd, "report")) return cmdReport(argc > 2 ? argv[2] : NULL);
    fprintf(stderr, "usage: cs8409ctl info | log [FILE] | dump | verb HEX | test [S] | rec FILE.wav [S] | selftest | report [FILE]\n");
    return 2;
}
