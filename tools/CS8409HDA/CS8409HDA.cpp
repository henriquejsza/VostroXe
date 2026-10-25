// CS8409HDA: internal speakers and microphone of the Dell Vostro 3520 on macOS (no AppleHDA in Tahoe).
//
// Hardware: Intel Alder Lake-P HD Audio controller 8086:51C8 in legacy HDA mode, Cirrus Logic CS8409 bridge at
// codec address 0 (subsystem 1028:0B94, "Warlock MLK" in Linux): speakers on its ASP2 behind a TI amplifier
// (enable = CS8409 GPIO1), digital microphones on DMIC1, headset through a CS42L42 (not used yet).
//
// All controller and codec programming lives in core/ (hdx_core.c, cs8409_codec.c, cs8409_dev.c), shared with the
// Linux test module linux/cs8409test that validated it on this machine (speakers + microphone, DMA rate, teardown).
// This file is only the IOKit side: PCI and DMA memory, locking, the user client, power and shutdown.
//
// User-space interface: the AudShim "driver mode" interface (tools/AudShim/AudShimDrv.h, v9), so the XeSpeakers HAL
// plug-in drives it like AudShim: connection type 'XEDR', method 5 DRV (ops 0-8), 6 POS, 7 CPOS, memory 0 = 64 KiB
// playback ring (S32_LE stereo 48 kHz), 1 = 64 KiB capture ring (read-only). There is no hardware volume on the
// speaker path: the HAL applies volume and mute in software (kDrvOpVolume is accepted and only recorded).
// Diagnostics (connection type 0, tools/CS8409HDA/cs8409ctl.c): 0 info, 1 verb (root), 2 log, 3 dump.
//
// Boot-args: -cs8409off (do not attach), cs8409lingerms=N (deferred stop, default 5000), cs8409capdb=N (volume
// ceiling below 0 dB reported to the HAL, 0-20, default 0), -cs8409nomic (interface v8: no microphone device),
// -cs8409anyssid (accept another CS8409 subsystem id), -cs8409hp (also initialise the CS42L42, experimental).

#include <IOKit/IOService.h>
#include <IOKit/IOLib.h>
#include <IOKit/IOUserClient.h>
#include <IOKit/IOMemoryDescriptor.h>
#include <IOKit/IOBufferMemoryDescriptor.h>
#include <IOKit/IODMACommand.h>
#include <IOKit/IOSubMemoryDescriptor.h>
#include <IOKit/IOWorkLoop.h>
#include <IOKit/IOTimerEventSource.h>
#include <IOKit/IOMessage.h>
#include <IOKit/pci/IOPCIDevice.h>
#include <pexpert/pexpert.h>
#include <kern/clock.h>
#include <sys/kauth.h>
#include <libkern/libkern.h>
#include <string.h>
#include <stdarg.h>

#include "../AudShim/AudShimDrv.h"

#define HDX_API static __attribute__((unused))
#include "core/hdx_core.c"
#include "core/cs8409_codec.c"
#include "core/cs8409_dev.c"

#define CS_VERSION "0.1.0"
#define CS_VERSION_NUM 0x000100u
static const uint32_t kPciId = 0x51C88086u;         // device << 16 | vendor (config dword 0)
static const uint32_t kRing = CS8409_RING_BYTES;     // == AUDSHIM_RING_BYTES
static const uint32_t kStreamBytes = CS8409_RING_BYTES + CS8409_BDL_BYTES;   // ring, then its BDL
static const uint32_t kLogBytes = 65536;
static_assert(CS8409_RING_BYTES == AUDSHIM_RING_BYTES, "ring geometry must match AudShimDrv.h");
static_assert(HDX_FMT_48K_32_2CH == 0x0041, "S32_LE stereo 48 kHz");

static char gLogBuf[kLogBytes];
static const uint32_t kCapQ16[21] = { 65536, 58409, 52057, 46396, 41350, 36854, 32846, 29274, 26090, 23253, 20724,
                                      18471, 16462, 14672, 13076, 11654, 10387, 9257, 8250, 7353, 6554 };
static IOPMPowerState gPowerStates[2] = {
    {kIOPMPowerStateVersion1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {kIOPMPowerStateVersion1, kIOPMPowerOn | kIOPMDeviceUsable, kIOPMPowerOn, kIOPMPowerOn, 0, 0, 0, 0, 0, 0, 0, 0},
};

static uint64_t nowUs() {
    uint64_t t = 0, ns = 0;
    clock_get_uptime(&t);
    absolutetime_to_nanoseconds(t, &ns);
    return ns / 1000;
}

static bool bootFlag(const char *name) {
    char dummy[8];
    return PE_parse_boot_argn(name, dummy, sizeof dummy);
}

class CS8409HDAUserClient;

class CS8409HDA : public IOService {
    OSDeclareDefaultStructors(CS8409HDA);
public:
    IOPCIDevice *pci = nullptr;
    IOMemoryMap *map0 = nullptr;
    volatile uint8_t *bar = nullptr;
    uint8_t pmCap = 0;
    uint64_t t0Us = 0;
    IOLock *logLock = nullptr;
    uint32_t logLen = 0;

    // DMA: command buffers (CORB, position buffer, RIRB), playback ring + BDL, capture ring + BDL
    IOBufferMemoryDescriptor *mdCmd = nullptr, *mdOut = nullptr, *mdIn = nullptr;
    IODMACommand *dcCmd = nullptr, *dcOut = nullptr, *dcIn = nullptr;
    uint8_t *vaCmd = nullptr, *vaOut = nullptr, *vaIn = nullptr;
    uint64_t busCmd = 0, busOut = 0, busIn = 0;

    // the device (controller + codec), touched only with drvLock held
    struct cs8409_dev dev;

    // driver mode (drvLock; drvState/capState/gens/hosts/indexes are also read lock-free by POS/CPOS)
    IOLock *drvLock = nullptr;
    CS8409HDAUserClient *drvClient = nullptr, *capClient = nullptr;   // not retained
    volatile uint32_t drvState = kDrvStIdle, capState = kCapStOff;
    volatile uint32_t drvGen = 0, capGen = 0, drvXruns = 0, outIdx = 0, inIdx = 0;
    volatile uint64_t drvRunHost = 0, capRunHost = 0;
    uint32_t drvFailStep = 0, drvFailCode = 0, capFailStep = 0, capFailCode = 0;
    uint64_t drvFailUs = 0, drvLingerUntil = 0;
    uint32_t drvGainReq = 0x10000, drvCapDb = 0, drvLingerMs = 5000;
    uint32_t drvStarts = 0, drvBringUps = 0, drvDmaErr = 0, drvLastUpMs = 0, capStarts = 0, capDmaErr = 0;
    uint32_t capRingGen = 0;
    bool drvMuted = false, drvSuspended = false, drvLinger = false, pmJoined = false;
    bool micEnabled = true, anySsid = false, headset = false;
    IOWorkLoop *wl = nullptr;
    IOTimerEventSource *timer = nullptr;

    IOService *probe(IOService *provider, SInt32 *score) override;
    bool start(IOService *provider) override;
    void stop(IOService *provider) override;
    IOReturn newUserClient(task_t owningTask, void *securityID, UInt32 type, OSDictionary *properties,
                           IOUserClient **handler) override;
    IOReturn setPowerState(unsigned long state, IOService *dev) override;
    void systemWillShutdown(IOOptionBits spec) override;

    void logLine(const char *line);
    void logMsg(const char *fmt, ...) __attribute__((format(printf, 2, 3)));
    bool dmaAlloc(IOBufferMemoryDescriptor **md, IODMACommand **dc, uint8_t **va, uint64_t *bus, uint32_t size,
                  const char *what);
    void dmaFree(IOBufferMemoryDescriptor **md, IODMACommand **dc, uint8_t **va);
    bool otherAudioDriver(char *name, size_t len);
    void logTrace(uint32_t n);

    bool drvBringUp();
    bool drvStartSeq();
    void drvStopSeq(const char *why);
    void drvTeardown(const char *why);
    void drvFail(uint32_t step, uint32_t code, const char *what);
    void drvFillState(uint64_t *o);
    void drvOp(CS8409HDAUserClient *c, uint64_t op, uint64_t a0, uint64_t *o);
    void drvPos(uint64_t *o);
    void capOp(CS8409HDAUserClient *c, uint64_t op, uint64_t *o);
    void capFillState(CS8409HDAUserClient *c, uint64_t *o);
    void capPos(uint64_t *o);
    void drvClientGone(CS8409HDAUserClient *c);
    IOMemoryDescriptor *ringMemory(CS8409HDAUserClient *c, bool capture);
    static void timerFired(OSObject *owner, IOTimerEventSource *sender);
    uint32_t r32(uint32_t off) { return bar ? *(volatile uint32_t *)(bar + off) : 0xffffffffu; }
};

class CS8409HDAUserClient : public IOUserClient {
    OSDeclareDefaultStructors(CS8409HDAUserClient);
public:
    CS8409HDA *drv = nullptr;
    uint32_t connType = 0;      // 0 = diagnostics (cs8409ctl), AUDSHIM_DRV_CONN_TYPE = driver (HAL plug-in, tests)
    bool root = false;
    bool isDriver() const { return connType == AUDSHIM_DRV_CONN_TYPE; }
    static const IOExternalMethodDispatch sMethods[8];
    static IOReturn sInfo(OSObject *t, void *, IOExternalMethodArguments *a);
    static IOReturn sVerb(OSObject *t, void *, IOExternalMethodArguments *a);
    static IOReturn sLog(OSObject *t, void *, IOExternalMethodArguments *a);
    static IOReturn sDump(OSObject *t, void *, IOExternalMethodArguments *a);
    static IOReturn sNone(OSObject *t, void *, IOExternalMethodArguments *a);
    static IOReturn sDrv(OSObject *t, void *, IOExternalMethodArguments *a);
    static IOReturn sPos(OSObject *t, void *, IOExternalMethodArguments *a);
    static IOReturn sCPos(OSObject *t, void *, IOExternalMethodArguments *a);
    bool start(IOService *provider) override;
    IOReturn clientClose() override;
    IOReturn clientMemoryForType(UInt32 type, IOOptionBits *options, IOMemoryDescriptor **memory) override;
    IOReturn externalMethod(uint32_t selector, IOExternalMethodArguments *args, IOExternalMethodDispatch *dispatch,
                            OSObject *target, void *reference) override;
};

OSDefineMetaClassAndStructors(CS8409HDA, IOService);
OSDefineMetaClassAndStructors(CS8409HDAUserClient, IOUserClient);

// ---- host callbacks for core/
static void csDelay(void *ctx, uint32_t us) {
    (void)ctx;
    if (us >= 1000) IOSleep((us + 999) / 1000);
    else if (us) IODelay(us);
}
static void csLog(void *ctx, const char *line) { ((CS8409HDA *)ctx)->logLine(line); }
static uint32_t csCfgRead(void *ctx, uint32_t off, unsigned bytes) {
    IOPCIDevice *p = ((CS8409HDA *)ctx)->pci;
    if (bytes == 1) return p->configRead8((IOByteCount)off);
    if (bytes == 2) return p->configRead16((IOByteCount)off);
    return p->configRead32((IOByteCount)off);
}
static void csCfgWrite(void *ctx, uint32_t off, uint32_t v, unsigned bytes) {
    IOPCIDevice *p = ((CS8409HDA *)ctx)->pci;
    if (bytes == 1) p->configWrite8((IOByteCount)off, (UInt8)v);
    else if (bytes == 2) p->configWrite16((IOByteCount)off, (UInt16)v);
    else p->configWrite32((IOByteCount)off, v);
}

// ---------------------------------------------------------------- logging (IOLog + a text ring for cs8409ctl log)
void CS8409HDA::logLine(const char *line) {
    IOLog("CS8409HDA: %s\n", line);
    if (!logLock) return;
    uint64_t ms = (nowUs() - t0Us) / 1000;
    char pre[32];
    int pn = snprintf(pre, sizeof pre, "%6llu.%03llu  ", (unsigned long long)(ms / 1000), (unsigned long long)(ms % 1000));
    size_t n = strlen(line);
    if (pn < 0) pn = 0;
    if (n > 1024) n = 1024;
    IOLockLock(logLock);
    if (logLen + (uint32_t)pn + n + 1 > kLogBytes) {   // drop the oldest half, at a line boundary
        uint32_t cut = logLen / 2;
        while (cut < logLen && gLogBuf[cut] != '\n') cut++;
        if (cut < logLen) cut++;
        memmove(gLogBuf, gLogBuf + cut, logLen - cut);
        logLen -= cut;
    }
    if (logLen + (uint32_t)pn + n + 1 <= kLogBytes) {
        memcpy(gLogBuf + logLen, pre, (size_t)pn);
        logLen += (uint32_t)pn;
        memcpy(gLogBuf + logLen, line, n);
        logLen += (uint32_t)n;
        gLogBuf[logLen++] = '\n';
    }
    IOLockUnlock(logLock);
}

void CS8409HDA::logMsg(const char *fmt, ...) {
    char b[320];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(b, sizeof b, fmt, ap);
    va_end(ap);
    logLine(b);
}

void CS8409HDA::logTrace(uint32_t n) {
    struct hdx_ctrl *h = &dev.hc;
    if (n > HDX_TRACE) n = HDX_TRACE;
    if (n > h->trace_pos) n = h->trace_pos;
    for (uint32_t i = h->trace_pos - n; i != h->trace_pos; i++)
        logMsg("  verb %08x -> %08x", h->trace_cmd[i % HDX_TRACE], h->trace_res[i % HDX_TRACE]);
}

// ---------------------------------------------------------------- DMA memory
// One physically contiguous, page-aligned block below 4 GiB, mapped for the device through IODMACommand with the PCI
// device as mapper (VT-d aware; with the IOMMU off the IOVA equals the physical address). Same pattern as AudShim.
bool CS8409HDA::dmaAlloc(IOBufferMemoryDescriptor **md, IODMACommand **dc, uint8_t **va, uint64_t *bus, uint32_t size,
                         const char *what) {
    *md = IOBufferMemoryDescriptor::inTaskWithPhysicalMask(kernel_task, kIODirectionInOut | kIOMemoryPhysicallyContiguous,
                                                           size, 0x00000000FFFFF000ULL);
    if (!*md) { logMsg("DMA %s: allocation of %u bytes failed", what, size); return false; }
    IOReturn r = (*md)->prepare();
    if (r) { (*md)->release(); *md = nullptr; logMsg("DMA %s: prepare 0x%x", what, r); return false; }
    *va = (uint8_t *)(*md)->getBytesNoCopy();
    if (!*va) { dmaFree(md, dc, va); return false; }
    bzero(*va, size);
    *dc = IODMACommand::withSpecification(kIODMACommandOutputHost64, 64, 0, IODMACommand::kMapped, 0, 128,
                                          (IOMapper *)pci, nullptr);
    if (!*dc) { dmaFree(md, dc, va); logMsg("DMA %s: no IODMACommand", what); return false; }
    r = (*dc)->setMemoryDescriptor(*md, false);
    if (!r) r = (*dc)->prepare();
    UInt64 off = 0;
    IODMACommand::Segment64 seg;
    UInt32 ns = 1;
    if (!r) r = (*dc)->gen64IOVMSegments(&off, &seg, &ns);
    if (r || ns != 1 || seg.fLength != size || (seg.fIOVMAddr & 0xFFF) ||
        (((seg.fIOVMAddr + size) >> 32) && !(r32(HDX_GCAP) & 1))) {   // above 4 GiB only if GCAP.64OK
        logMsg("DMA %s: mapping failed 0x%x (segments %u, length %llu, address 0x%llx)", what, r, ns,
             (unsigned long long)seg.fLength, (unsigned long long)seg.fIOVMAddr);
        dmaFree(md, dc, va);
        return false;
    }
    *bus = seg.fIOVMAddr;
    logMsg("DMA %s: %u bytes, device address 0x%llx, physical 0x%llx", what, size, (unsigned long long)*bus,
         (unsigned long long)(*md)->getPhysicalSegment(0, nullptr, kIOMemoryMapperNone));
    return true;
}

void CS8409HDA::dmaFree(IOBufferMemoryDescriptor **md, IODMACommand **dc, uint8_t **va) {
    if (*dc) { (*dc)->clearMemoryDescriptor(); (*dc)->release(); *dc = nullptr; }
    if (*md) { (*md)->complete(); (*md)->release(); *md = nullptr; }
    *va = nullptr;
}

static bool contains(const char *s, const char *sub) {
    size_t n = strlen(sub);
    for (; *s; s++)
        if (!strncmp(s, sub, n)) return true;
    return false;
}

// Another driver bound to the same controller would fight over CORB/RIRB and the streams.
bool CS8409HDA::otherAudioDriver(char *name, size_t len) {
    bool found = false;
    OSIterator *it = pci->getClientIterator();
    if (!it) return false;
    while (OSObject *o = it->getNextObject()) {
        IOService *c = OSDynamicCast(IOService, o);
        if (!c || c == this) continue;
        const char *cn = c->getMetaClass()->getClassName();
        if (contains(cn, "HDA") || contains(cn, "Audio") || contains(cn, "Voodoo")) {
            strlcpy(name, cn, len);
            found = true;
            break;
        }
    }
    it->release();
    return found;
}

// ---------------------------------------------------------------- IOService
IOService *CS8409HDA::probe(IOService *provider, SInt32 *score) {
    if (bootFlag("-cs8409off")) return nullptr;
    IOPCIDevice *p = OSDynamicCast(IOPCIDevice, provider);
    if (!p || p->configRead32(kIOPCIConfigVendorID) != kPciId) return nullptr;   // live id, not the device-id property
    return IOService::probe(provider, score);
}

bool CS8409HDA::start(IOService *provider) {
    if (!IOService::start(provider)) return false;
    pci = OSDynamicCast(IOPCIDevice, provider);
    if (!pci || pci->configRead32(kIOPCIConfigVendorID) != kPciId) return false;
    t0Us = nowUs();
    logLock = IOLockAlloc();
    drvLock = IOLockAlloc();
    if (!logLock || !drvLock) return false;
    uint32_t v = 5000;
    if (PE_parse_boot_argn("cs8409lingerms", &v, sizeof v)) drvLingerMs = v > 60000 ? 60000 : v;
    v = 0;
    if (PE_parse_boot_argn("cs8409capdb", &v, sizeof v)) drvCapDb = v > 20 ? 20 : v;
    micEnabled = !bootFlag("-cs8409nomic");
    anySsid = bootFlag("-cs8409anyssid");
    headset = bootFlag("-cs8409hp");

    pci->findPCICapability(kIOPCIPowerManagementCapability, &pmCap);
    pci->setMemoryEnable(true);
    map0 = pci->mapDeviceMemoryWithRegister(kIOPCIConfigBaseAddress0, kIOMapInhibitCache);
    if (!map0 || map0->getLength() < 0x4000) {
        logMsg("BAR0 not mapped (length %llu)", map0 ? (unsigned long long)map0->getLength() : 0ULL);
        OSSafeReleaseNULL(map0);
        IOLockFree(drvLock); drvLock = nullptr;
        IOLock *l = logLock; logLock = nullptr; IOLockFree(l);
        return false;
    }
    bar = (volatile uint8_t *)map0->getVirtualAddress();
    logMsg("CS8409HDA %s: %08x subsystem %08x, BAR0 0x%llx, GCAP %04x GCTL %08x, linger %u ms, cap -%u dB%s%s%s",
         CS_VERSION, pci->configRead32(kIOPCIConfigVendorID), pci->configRead32(kIOPCIConfigSubSystemVendorID),
         (unsigned long long)map0->getPhysicalAddress(), r32(0) & 0xffff, r32(HDX_GCTL), drvLingerMs, drvCapDb,
         micEnabled ? "" : ", no microphone", anySsid ? ", any subsystem" : "", headset ? ", headset codec on" : "");

    if (!dmaAlloc(&mdCmd, &dcCmd, &vaCmd, &busCmd, 4096, "commands") ||
        !dmaAlloc(&mdOut, &dcOut, &vaOut, &busOut, kStreamBytes, "playback") ||
        !dmaAlloc(&mdIn, &dcIn, &vaIn, &busIn, kStreamBytes, "capture")) {
        dmaFree(&mdIn, &dcIn, &vaIn);
        dmaFree(&mdOut, &dcOut, &vaOut);
        dmaFree(&mdCmd, &dcCmd, &vaCmd);
        OSSafeReleaseNULL(map0);
        bar = nullptr;
        IOLockFree(drvLock); drvLock = nullptr;
        IOLock *l = logLock; logLock = nullptr; IOLockFree(l);
        return false;
    }
    bzero(&dev, sizeof dev);
    dev.hc.bar = bar;
    dev.hc.os.ctx = this;
    dev.hc.os.delay_us = csDelay;
    dev.hc.os.log = csLog;
    dev.hc.os.cfg_read = csCfgRead;
    dev.hc.os.cfg_write = csCfgWrite;
    dev.cmd_mem.virt = vaCmd;  dev.cmd_mem.bus = busCmd;  dev.cmd_mem.size = 4096;
    dev.out_ring.virt = vaOut; dev.out_ring.bus = busOut; dev.out_ring.size = kRing;
    dev.out_bdl.virt = vaOut + kRing; dev.out_bdl.bus = busOut + kRing; dev.out_bdl.size = CS8409_BDL_BYTES;
    if (micEnabled) {
        dev.in_ring.virt = vaIn; dev.in_ring.bus = busIn; dev.in_ring.size = kRing;
        dev.in_bdl.virt = vaIn + kRing; dev.in_bdl.bus = busIn + kRing; dev.in_bdl.size = CS8409_BDL_BYTES;
    }

    setProperty("IOUserClientClass", "CS8409HDAUserClient");
    setProperty("AudShimInterface", micEnabled ? AUDSHIM_IFACE_VERSION : AUDSHIM_IFACE_MIN_SPEAKERS, 32);
    setProperty("AudShimCapDb", drvCapDb, 32);
    setProperty("CS8409HDAVersion", CS_VERSION);

    wl = IOWorkLoop::workLoop();
    if (wl) {
        timer = IOTimerEventSource::timerEventSource(this, timerFired);
        if (timer && wl->addEventSource(timer) != kIOReturnSuccess) OSSafeReleaseNULL(timer);
    }
    // join the power plane: system sleep (power state 0) and shutdown/restart tear the audio path down
    PMinit();
    provider->joinPMtree(this);
    if (registerPowerDriver(this, gPowerStates, 2) == kIOReturnSuccess) {
        pmJoined = true;
        changePowerStateTo(1);
    } else {
        PMstop();
        logMsg("registerPowerDriver failed; sleep/shutdown teardown relies on client death");
    }
    registerService();
    logMsg("ready: interface v%u, the hardware is only touched when a client opens it",
         micEnabled ? AUDSHIM_IFACE_VERSION : AUDSHIM_IFACE_MIN_SPEAKERS);
    return true;
}

void CS8409HDA::stop(IOService *provider) {
    if (drvLock) {
        IOLockLock(drvLock);
        drvTeardown("stop()");
        drvClient = capClient = nullptr;
        drvSuspended = true;
        IOLockUnlock(drvLock);
    }
    if (timer) { timer->cancelTimeout(); if (wl) wl->removeEventSource(timer); OSSafeReleaseNULL(timer); }
    OSSafeReleaseNULL(wl);
    if (pmJoined) { PMstop(); pmJoined = false; }
    dmaFree(&mdIn, &dcIn, &vaIn);
    dmaFree(&mdOut, &dcOut, &vaOut);
    dmaFree(&mdCmd, &dcCmd, &vaCmd);
    bar = nullptr;
    dev.hc.bar = nullptr;
    OSSafeReleaseNULL(map0);
    if (drvLock) { IOLockFree(drvLock); drvLock = nullptr; }
    IOLock *l = logLock;
    logLock = nullptr;
    if (l) IOLockFree(l);
    IOService::stop(provider);
}

IOReturn CS8409HDA::newUserClient(task_t owningTask, void *securityID, UInt32 type, OSDictionary *properties,
                                  IOUserClient **handler) {
    (void)properties;
    bool drvConn = (type == AUDSHIM_DRV_CONN_TYPE);
    if (type != 0 && !drvConn) return kIOReturnBadArgument;
    bool priv = IOUserClient::clientHasPrivilege(owningTask, kIOClientPrivilegeLocalUser) == kIOReturnSuccess ||
                IOUserClient::clientHasPrivilege(owningTask, kIOClientPrivilegeAdministrator) == kIOReturnSuccess;
    // the AudioServerPlugIn host runs as _coreaudiod (uid 202): neither console user nor admin
    uid_t u = kauth_getuid();
    if (!priv && drvConn && u == 202) priv = true;
    if (u == 0) priv = true;
    if (!priv) return kIOReturnNotPrivileged;
    CS8409HDAUserClient *uc = OSTypeAlloc(CS8409HDAUserClient);
    if (!uc) return kIOReturnNoMemory;
    uc->connType = type;
    uc->root = (u == 0);
    if (!uc->initWithTask(owningTask, securityID, type) || !uc->attach(this) || !uc->start(this)) {
        uc->detach(this);
        uc->release();
        return kIOReturnError;
    }
    *handler = uc;
    return kIOReturnSuccess;
}

IOReturn CS8409HDA::setPowerState(unsigned long state, IOService *device) {
    (void)device;
    if (!drvLock) return kIOPMAckImplied;
    IOLockLock(drvLock);
    if (state == 0) {
        if (!drvSuspended) logMsg("power state 0 (system sleep): teardown");
        drvTeardown("system sleep");
        drvSuspended = true;
    } else {
        if (drvSuspended) logMsg("power state 1: available again");
        drvSuspended = false;
    }
    IOLockUnlock(drvLock);
    return kIOPMAckImplied;
}

void CS8409HDA::systemWillShutdown(IOOptionBits spec) {
    if (drvLock) {
        IOLockLock(drvLock);
        drvTeardown(spec == kIOMessageSystemWillRestart ? "restart" : "shutdown");
        drvSuspended = true;
        IOLockUnlock(drvLock);
    }
    IOService::systemWillShutdown(spec);
}

// ---------------------------------------------------------------- driver mode (drvLock held unless noted)
void CS8409HDA::drvFail(uint32_t step, uint32_t code, const char *what) {
    drvFailStep = step;
    drvFailCode = code;
    drvFailUs = nowUs();
    logMsg("FAILED: %s (step %u, code %d)", what, step, (int)code);
}

bool CS8409HDA::drvBringUp() {
    uint64_t t0 = nowUs();
    char other[64];
    drvState = kDrvStBusy;
    if (otherAudioDriver(other, sizeof other)) {
        logMsg("another audio driver (%s) is attached to the controller: not touching it", other);
        drvFail(90, 0, "conflicting driver");
        drvState = kDrvStFailed;
        return false;
    }
    if (pmCap) {   // the function must be in D0
        uint16_t pmcsr = pci->configRead16((IOByteCount)(pmCap + 4));
        if (pmcsr & 3) {
            pci->configWrite16((IOByteCount)(pmCap + 4), (UInt16)(pmcsr & ~3u));
            IOSleep(10);
            logMsg("PCI power state D%u -> D0", pmcsr & 3);
        }
    }
    pci->setMemoryEnable(true);
    pci->setBusMasterEnable(true);
    dev.flags = (headset ? CS8409_DEV_HEADSET : 0) | (anySsid ? CS8409_DEV_ANY_SSID : 0);
    int e = cs8409_dev_bringup(&dev);
    if (e) {
        drvFail((uint32_t)dev.fail_step, (uint32_t)e, "bring-up");
        hdx_dump(&dev.hc, nullptr, nullptr);
        logTrace(24);
        cs8409_dev_teardown(&dev);
        pci->setBusMasterEnable(false);
        drvState = kDrvStFailed;
        return false;
    }
    outIdx = dev.out.index;
    inIdx = dev.in.index;
    bzero(vaOut, kRing);
    if (vaIn) bzero(vaIn, kRing);
    __sync_synchronize();
    drvBringUps++;
    capRingGen++;
    drvLastUpMs = (uint32_t)((nowUs() - t0) / 1000);
    drvState = kDrvStReady;
    logMsg("bring-up #%u in %u ms: codec %u vendor %08x subsystem %08x rev %08x, %u verbs, out SD%u in SD%u",
         drvBringUps, drvLastUpMs, dev.codec_addr, dev.codec.vendor, dev.codec.ssid, dev.codec.rev, dev.hc.verbs,
         dev.out.index, dev.in.index);
    return true;
}

bool CS8409HDA::drvStartSeq() {
    int e = cs8409_dev_out_start(&dev);
    if (e) {
        drvFail((uint32_t)dev.fail_step, (uint32_t)e, "playback start");
        hdx_dump(&dev.hc, &dev.out, nullptr);
        return false;
    }
    drvRunHost = mach_absolute_time();
    OSIncrementAtomic((volatile SInt32 *)&drvGen);
    drvStarts++;
    drvLinger = false;
    drvState = kDrvStRunning;
    if (timer) timer->setTimeoutMS(50);
    return true;
}

void CS8409HDA::drvStopSeq(const char *why) {
    cs8409_dev_out_stop(&dev);
    drvLinger = false;
    if (drvState == kDrvStRunning) drvState = kDrvStReady;
    logMsg("playback stopped (%s)", why);
}

// Anything -> IDLE: streams stopped, codec off (amplifier off, AFG D3), link in reset, bus mastering off.
void CS8409HDA::drvTeardown(const char *why) {
    if (drvState == kDrvStIdle && capState != kCapStRunning && !dev.hc.cmd_up) return;
    logMsg("teardown (%s), state %u, capture %u", why, drvState, capState);
    if (timer) timer->cancelTimeout();
    cs8409_dev_teardown(&dev);
    if (pci) pci->setBusMasterEnable(false);
    drvState = kDrvStIdle;
    drvLinger = false;
    capState = kCapStOff;
    capClient = nullptr;
}

void CS8409HDA::drvFillState(uint64_t *o) {
    o[1] = drvState; o[2] = drvFailStep; o[3] = drvFailCode;
    o[4] = drvMuted ? 0 : drvGainReq;           // "applied": the HAL applies it in software
    o[5] = kCapQ16[drvCapDb]; o[6] = drvCapDb;
    o[7] = drvStarts; o[8] = drvXruns; o[9] = 0; o[10] = drvDmaErr; o[11] = drvBringUps; o[12] = drvLastUpMs;
    o[13] = drvGainReq | ((uint64_t)(drvMuted ? 1 : 0) << 32);
    o[14] = (drvSuspended ? 1 : 0) | ((uint64_t)(drvLinger ? 1 : 0) << 1);
    o[15] = micEnabled ? AUDSHIM_IFACE_VERSION : AUDSHIM_IFACE_MIN_SPEAKERS;
}

void CS8409HDA::drvOp(CS8409HDAUserClient *c, uint64_t op, uint64_t a0, uint64_t *o) {
    for (int i = 0; i < 16; i++) o[i] = 0;
    if (!drvLock) { o[0] = kDrvErrNotReady; return; }
    IOLockLock(drvLock);
    if (op == kDrvOpState) goto out;
    if (op == kDrvOpCapState || op == kDrvOpCapStart || op == kDrvOpCapStop) {
        if (op != kDrvOpCapState) capOp(c, op, o);
        capFillState(c, o);
        IOLockUnlock(drvLock);
        return;
    }
    if (op == kDrvOpVolume) {   // recorded only (software volume in the HAL)
        if (drvClient && drvClient != c) { o[0] = kDrvErrBusy; goto out; }
        drvGainReq = (uint32_t)(a0 & 0xFFFFFFFFu) > 0x10000u ? 0x10000u : (uint32_t)(a0 & 0xFFFFFFFFu);
        drvMuted = ((a0 >> 32) & 1) != 0;
        goto out;
    }
    if (drvClient && drvClient != c) {
        // another driver connection owns the hardware; take over only when it holds nothing
        if (drvState != kDrvStIdle && drvState != kDrvStFailed) { o[0] = kDrvErrBusy; goto out; }
        if (op != kDrvOpOpen && op != kDrvOpStart) goto out;
        logMsg("ownership moves to another driver connection");
        drvClient = c;
    }
    switch (op) {
    case kDrvOpClose:
        if (drvClient == c) { drvTeardown("CLOSE"); drvClient = nullptr; }
        break;
    case kDrvOpStop:
        if (drvClient != c || drvState != kDrvStRunning || drvLinger) break;
        bzero(vaOut, kRing);        // silence at once; the DMA keeps running during the linger time
        __sync_synchronize();
        if (drvLingerMs) {
            drvLinger = true;
            drvLingerUntil = nowUs() + (uint64_t)drvLingerMs * 1000;
            if (timer) timer->setTimeoutMS(50);
        } else {
            drvStopSeq("STOP");
        }
        break;
    case kDrvOpOpen:
    case kDrvOpStart:
        if (drvSuspended) { o[0] = kDrvErrSuspended; break; }
        drvClient = c;
        if (drvState == kDrvStIdle || drvState == kDrvStFailed) {
            if (drvState == kDrvStFailed && nowUs() - drvFailUs < 3000000) { o[0] = kDrvErrRetryLater; break; }
            if (!drvBringUp()) { o[0] = kDrvErrFailed; break; }
        }
        if (op == kDrvOpStart && drvState == kDrvStRunning && drvLinger) {   // resume a lingering stream
            drvLinger = false;
            OSIncrementAtomic((volatile SInt32 *)&drvGen);   // the HAL re-anchors its clock
            drvStarts++;
            break;
        }
        if (op == kDrvOpStart && drvState == kDrvStReady && !drvStartSeq()) {
            logMsg("START failed at step %u: teardown, bring-up and one retry", drvFailStep);
            drvTeardown("start failure");
            if (!drvBringUp() || !drvStartSeq()) {
                drvTeardown("start failure (retry)");
                drvState = kDrvStFailed;
                drvFailUs = nowUs();
                o[0] = kDrvErrFailed;
            }
        }
        if (!o[0] && (op == kDrvOpStart ? drvState != kDrvStRunning
                                        : (drvState != kDrvStReady && drvState != kDrvStRunning)))
            o[0] = kDrvErrFailed;
        break;
    default:
        o[0] = kDrvErrBadOp;
    }
out:
    drvFillState(o);
    IOLockUnlock(drvLock);
}

// Lock-free (HAL real-time thread): playback DMA position from the Intel DPIB register.
void CS8409HDA::drvPos(uint64_t *o) {
    for (int i = 0; i < 8; i++) o[i] = 0;
    uint32_t st = drvState;
    o[0] = st; o[3] = drvGen; o[6] = drvXruns; o[7] = drvRunHost;
    if (st == kDrvStRunning && bar) {
        uint32_t idx = outIdx;
        uint64_t t1 = mach_absolute_time();
        uint32_t d = r32(HDX_VS_DPIB(idx));
        uint64_t t2 = mach_absolute_time();
        o[1] = d % kRing; o[2] = t1 + (t2 - t1) / 2;
        o[4] = r32(HDX_SD_BASE + HDX_SD_STRIDE * idx);
        o[5] = r32(HDX_SD_BASE + HDX_SD_STRIDE * idx + HDX_SD_LPIB);
    } else {
        o[2] = mach_absolute_time();
    }
}

void CS8409HDA::capFillState(CS8409HDAUserClient *c, uint64_t *o) {
    o[1] = drvState; o[2] = capState; o[3] = capFailStep; o[4] = capFailCode; o[5] = capStarts; o[6] = capDmaErr;
    o[7] = micEnabled ? 1 : 0;      // "microphone device present"
    o[8] = capRingGen; o[9] = capClient ? (capClient == c ? 1 : 2) : 0; o[10] = micEnabled ? 1 : 0;
    o[11] = drvBringUps; o[12] = 0xFF; o[13] = drvXruns; o[14] = 1;
    o[15] = micEnabled ? AUDSHIM_IFACE_VERSION : AUDSHIM_IFACE_MIN_SPEAKERS;
}

void CS8409HDA::capOp(CS8409HDAUserClient *c, uint64_t op, uint64_t *o) {
    if (!micEnabled) { o[0] = kDrvErrBadOp; return; }
    if (op == kDrvOpCapStop) {
        if (capClient != c) { o[0] = capClient ? kDrvErrBusy : kDrvOk; return; }
        if (capState == kCapStRunning) {
            cs8409_dev_in_stop(&dev);
            logMsg("capture stopped");
        }
        capState = kCapStOff;
        capClient = nullptr;
        return;
    }
    if (drvSuspended) { o[0] = kDrvErrSuspended; return; }
    if (capState == kCapStRunning) { o[0] = (capClient == c) ? kDrvOk : kDrvErrBusy; return; }
    if (capClient && capClient != c) { o[0] = kDrvErrBusy; return; }
    if (!drvClient || (drvClient != c && (drvState == kDrvStIdle || drvState == kDrvStFailed))) {
        drvClient = c;
    } else if (drvClient != c && drvState != kDrvStReady && drvState != kDrvStRunning) {
        o[0] = kDrvErrBusy;
        return;
    }
    if (drvState == kDrvStIdle || drvState == kDrvStFailed) {
        if (drvState == kDrvStFailed && nowUs() - drvFailUs < 3000000) { o[0] = kDrvErrRetryLater; return; }
        if (!drvBringUp()) { o[0] = kDrvErrFailed; return; }
    }
    int e = cs8409_dev_in_start(&dev);
    if (e) {
        capFailStep = (uint32_t)dev.fail_step;
        capFailCode = (uint32_t)e;
        capState = kCapStFailed;
        capClient = nullptr;
        logMsg("FAILED: capture start (step %u, code %d)", capFailStep, e);
        o[0] = kDrvErrFailed;
        return;
    }
    capClient = c;
    capStarts++;
    capRunHost = mach_absolute_time();
    OSIncrementAtomic((volatile SInt32 *)&capGen);
    capState = kCapStRunning;
    if (timer) timer->setTimeoutMS(50);
    logMsg("capture started (#%u)", capStarts);
}

// Lock-free (HAL real-time thread): capture DMA position.
void CS8409HDA::capPos(uint64_t *o) {
    for (int i = 0; i < 8; i++) o[i] = 0;
    uint32_t st = capState;
    o[0] = (st == kCapStRunning) ? 1 : 0; o[3] = capGen; o[6] = drvXruns; o[7] = capRunHost;
    if (st == kCapStRunning && bar) {
        uint32_t idx = inIdx;
        uint64_t t1 = mach_absolute_time();
        uint32_t d = r32(HDX_VS_DPIB(idx));
        uint64_t t2 = mach_absolute_time();
        o[1] = d % kRing; o[2] = t1 + (t2 - t1) / 2;
        o[4] = r32(HDX_SD_BASE + HDX_SD_STRIDE * idx);
        o[5] = r32(HDX_SD_BASE + HDX_SD_STRIDE * idx + HDX_SD_LPIB);
    } else {
        o[2] = mach_absolute_time();
    }
}

void CS8409HDA::drvClientGone(CS8409HDAUserClient *c) {
    if (!drvLock) return;
    IOLockLock(drvLock);
    if (capClient == c && drvClient != c) {     // a capture-only connection went away
        if (capState == kCapStRunning) cs8409_dev_in_stop(&dev);
        capState = kCapStOff;
        capClient = nullptr;
    }
    if (drvClient == c) {
        drvTeardown("driver connection closed (client exit or crash)");
        drvClient = nullptr;
    }
    IOLockUnlock(drvLock);
}

IOMemoryDescriptor *CS8409HDA::ringMemory(CS8409HDAUserClient *c, bool capture) {
    IOMemoryDescriptor *md = nullptr;
    if (!drvLock) return nullptr;
    IOLockLock(drvLock);
    if (!capture && drvClient == c && (drvState == kDrvStReady || drvState == kDrvStRunning) && mdOut)
        md = IOSubMemoryDescriptor::withSubRange(mdOut, 0, kRing, kIODirectionInOut);    // ring only, never the BDL
    if (capture && micEnabled && (capClient == c || drvClient == c) && mdIn && drvState != kDrvStIdle)
        md = IOSubMemoryDescriptor::withSubRange(mdIn, 0, kRing, kIODirectionInOut);     // mapped read-only
    IOLockUnlock(drvLock);
    return md;
}

// 50 ms while a stream runs: DMA error bits, deferred stop. Never waits behind a driver operation.
void CS8409HDA::timerFired(OSObject *owner, IOTimerEventSource *sender) {
    CS8409HDA *s = OSDynamicCast(CS8409HDA, owner);
    if (!s || !s->drvLock) return;
    bool again = true;
    if (IOLockTryLock(s->drvLock)) {
        if (s->drvState == kDrvStRunning && s->bar) {
            uint32_t sts = HDX_SD_BASE + HDX_SD_STRIDE * s->outIdx + HDX_SD_STS;
            uint8_t v = s->bar[sts];
            if (v & 0x18) {         // FIFOE / DESE
                s->drvDmaErr++;
                OSIncrementAtomic((volatile SInt32 *)&s->drvXruns);
                if (s->drvDmaErr <= 10) s->logMsg("playback DMA error, SD STS %02x", v);
                s->bar[sts] = 0x18;
            }
            if (s->drvLinger && nowUs() >= s->drvLingerUntil) s->drvStopSeq("deferred STOP");
        }
        if (s->capState == kCapStRunning && s->bar) {
            uint32_t sts = HDX_SD_BASE + HDX_SD_STRIDE * s->inIdx + HDX_SD_STS;
            uint8_t v = s->bar[sts];
            if (v & 0x18) {
                s->capDmaErr++;
                if (s->capDmaErr <= 10) s->logMsg("capture DMA error, SD STS %02x", v);
                s->bar[sts] = 0x18;
            }
        }
        again = s->drvState == kDrvStRunning || s->capState == kCapStRunning;
        IOLockUnlock(s->drvLock);
    }
    if (again) sender->setTimeoutMS(50);
}

// ---------------------------------------------------------------- user client
const IOExternalMethodDispatch CS8409HDAUserClient::sMethods[8] = {
    {sInfo, 0, 0, 16, 0},
    {sVerb, 1, 0, 2, 0},
    {sLog, 1, 0, 2, kIOUCVariableStructureSize},
    {sDump, 0, 0, 1, 0},
    {sNone, 0, 0, 0, 0},
    {sDrv, 2, 0, 16, 0},        // AUDSHIM_METHOD_DRV
    {sPos, 0, 0, 8, 0},         // AUDSHIM_METHOD_POS
    {sCPos, 0, 0, 8, 0},        // AUDSHIM_METHOD_CPOS
};
static_assert(AUDSHIM_METHOD_DRV == 5 && AUDSHIM_METHOD_POS == 6 && AUDSHIM_METHOD_CPOS == 7, "method numbers");

bool CS8409HDAUserClient::start(IOService *provider) {
    drv = OSDynamicCast(CS8409HDA, provider);
    return drv && IOUserClient::start(provider);
}

IOReturn CS8409HDAUserClient::clientClose() {
    if (drv && isDriver()) drv->drvClientGone(this);
    terminate();
    return kIOReturnSuccess;
}

IOReturn CS8409HDAUserClient::externalMethod(uint32_t selector, IOExternalMethodArguments *args,
                                             IOExternalMethodDispatch *dispatch, OSObject *target, void *reference) {
    (void)dispatch; (void)target; (void)reference;
    if (selector >= 8) return kIOReturnUnsupported;
    return IOUserClient::externalMethod(selector, args, (IOExternalMethodDispatch *)&sMethods[selector], this, nullptr);
}

// o[0] version, o[1] driver state, o[2] capture state, o[3] GCAP, o[4] codec mask, o[5] codec vendor, o[6] codec
// subsystem, o[7] codec revision, o[8] bring-ups, o[9] verbs, o[10] verb timeouts, o[11] fail step | code << 32,
// o[12] PCI command/status, o[13] PMCSR, o[14] GCTL (live), o[15] interface version
IOReturn CS8409HDAUserClient::sInfo(OSObject *t, void *, IOExternalMethodArguments *a) {
    CS8409HDAUserClient *uc = (CS8409HDAUserClient *)t;
    CS8409HDA *s = uc->drv;
    uint64_t *o = a->scalarOutput;
    for (int i = 0; i < 16; i++) o[i] = 0;
    if (!s || !s->drvLock) return kIOReturnNotReady;
    IOLockLock(s->drvLock);
    o[0] = CS_VERSION_NUM; o[1] = s->drvState; o[2] = s->capState; o[3] = s->r32(HDX_GCAP) & 0xffff;
    o[4] = s->dev.hc.codec_mask; o[5] = s->dev.codec.vendor; o[6] = s->dev.codec.ssid; o[7] = s->dev.codec.rev;
    o[8] = s->drvBringUps; o[9] = s->dev.hc.verbs; o[10] = s->dev.hc.timeouts;
    o[11] = s->drvFailStep | ((uint64_t)s->drvFailCode << 32);
    o[12] = s->pci->configRead32(kIOPCIConfigCommand);
    o[13] = s->pmCap ? s->pci->configRead16((IOByteCount)(s->pmCap + 4)) : 0;
    o[14] = s->r32(HDX_GCTL);
    o[15] = s->micEnabled ? AUDSHIM_IFACE_VERSION : AUDSHIM_IFACE_MIN_SPEAKERS;
    IOLockUnlock(s->drvLock);
    a->scalarOutputCount = 16;
    return kIOReturnSuccess;
}

// raw verb (root, hardware up): in[0] = command (codec address << 28 | nid << 20 | verb), out: response, status
IOReturn CS8409HDAUserClient::sVerb(OSObject *t, void *, IOExternalMethodArguments *a) {
    CS8409HDAUserClient *uc = (CS8409HDAUserClient *)t;
    CS8409HDA *s = uc->drv;
    if (!s || !s->drvLock) return kIOReturnNotReady;
    if (!uc->root) return kIOReturnNotPrivileged;
    uint32_t r = 0;
    IOLockLock(s->drvLock);
    int e = s->dev.hc.cmd_up ? cs8409_dev_verb(&s->dev, (uint32_t)a->scalarInput[0], &r) : HDX_EIO;
    if (s->dev.hc.cmd_up) s->logMsg("verb %08x -> %08x (%d) by root", (uint32_t)a->scalarInput[0], r, e);
    IOLockUnlock(s->drvLock);
    a->scalarOutput[0] = r;
    a->scalarOutput[1] = (uint64_t)(int64_t)e;
    a->scalarOutputCount = 2;
    return kIOReturnSuccess;
}

// log text from offset in[0]: out[0] total length, out[1] bytes copied (<= 4096) into the structure output
IOReturn CS8409HDAUserClient::sLog(OSObject *t, void *, IOExternalMethodArguments *a) {
    CS8409HDA *s = ((CS8409HDAUserClient *)t)->drv;
    if (!s || !s->logLock || !a->structureOutput) return kIOReturnBadArgument;
    uint32_t off = (uint32_t)a->scalarInput[0], cap = a->structureOutputSize, n = 0;
    if (cap > 4096) cap = 4096;
    IOLockLock(s->logLock);
    uint32_t len = s->logLen;
    if (off < len) {
        n = len - off < cap ? len - off : cap;
        memcpy(a->structureOutput, gLogBuf + off, n);
    }
    IOLockUnlock(s->logLock);
    a->scalarOutput[0] = len;
    a->scalarOutput[1] = n;
    a->scalarOutputCount = 2;
    a->structureOutputSize = n;
    return kIOReturnSuccess;
}

// controller + codec register dump into the log (hardware up only)
IOReturn CS8409HDAUserClient::sDump(OSObject *t, void *, IOExternalMethodArguments *a) {
    CS8409HDA *s = ((CS8409HDAUserClient *)t)->drv;
    if (!s || !s->drvLock) return kIOReturnNotReady;
    IOLockLock(s->drvLock);
    uint64_t ok = s->dev.hc.cmd_up ? 1 : 0;
    s->logMsg("dump: driver state %u, capture %u, starts %u, DMA errors %u/%u", s->drvState, s->capState, s->drvStarts,
            s->drvDmaErr, s->capDmaErr);
    hdx_dump(&s->dev.hc, s->dev.out.configured ? &s->dev.out : nullptr, s->dev.in.configured ? &s->dev.in : nullptr);
    if (ok && s->dev.codec_ok) {
        cs8409_clear_err(&s->dev.codec);
        cs8409_dump(&s->dev.codec);
    }
    IOLockUnlock(s->drvLock);
    a->scalarOutput[0] = ok;
    a->scalarOutputCount = 1;
    return kIOReturnSuccess;
}

IOReturn CS8409HDAUserClient::sNone(OSObject *, void *, IOExternalMethodArguments *) {
    return kIOReturnUnsupported;
}

IOReturn CS8409HDAUserClient::sDrv(OSObject *t, void *, IOExternalMethodArguments *a) {
    CS8409HDAUserClient *uc = (CS8409HDAUserClient *)t;
    if (!uc->drv || !uc->isDriver()) return kIOReturnNotPermitted;
    uc->drv->drvOp(uc, a->scalarInput[0], a->scalarInput[1], a->scalarOutput);
    a->scalarOutputCount = 16;
    return kIOReturnSuccess;
}

IOReturn CS8409HDAUserClient::sPos(OSObject *t, void *, IOExternalMethodArguments *a) {
    CS8409HDAUserClient *uc = (CS8409HDAUserClient *)t;
    if (!uc->drv || !uc->isDriver()) return kIOReturnNotPermitted;
    uc->drv->drvPos(a->scalarOutput);
    a->scalarOutputCount = 8;
    return kIOReturnSuccess;
}

IOReturn CS8409HDAUserClient::sCPos(OSObject *t, void *, IOExternalMethodArguments *a) {
    CS8409HDAUserClient *uc = (CS8409HDAUserClient *)t;
    if (!uc->drv || !uc->isDriver()) return kIOReturnNotPermitted;
    uc->drv->capPos(a->scalarOutput);
    a->scalarOutputCount = 8;
    return kIOReturnSuccess;
}

// memory 0: playback ring (read-write) for the owning driver connection while READY/RUNNING;
// memory 1: capture ring (read-only) for the capturing or owning connection
IOReturn CS8409HDAUserClient::clientMemoryForType(UInt32 type, IOOptionBits *options, IOMemoryDescriptor **memory) {
    if (!drv || !isDriver() || (type != AUDSHIM_MEM_RING && type != AUDSHIM_MEM_CRING)) return kIOReturnBadArgument;
    IOMemoryDescriptor *md = drv->ringMemory(this, type == AUDSHIM_MEM_CRING);
    if (!md) return kIOReturnNotReady;
    *options = (type == AUDSHIM_MEM_CRING) ? kIOMapReadOnly : 0;
    *memory = md;   // retained; the caller releases it
    return kIOReturnSuccess;
}
