/*
 * hdx_core.c: see hdx_core.h. Unity build only: include this file from the host source after the headers that
 * declare memset() and snprintf() (macOS kernel: <libkern/libkern.h>; Linux kernel: <linux/kernel.h>,
 * <linux/string.h>). Not thread-safe: the host serializes every call except hdx_stream_dpib/lpib/ctlsts.
 */
#include "hdx_core.h"

#define HDX_SDO(s) (HDX_SD_BASE + HDX_SD_STRIDE * (uint32_t)(s)->index)
#define HDX_BARRIER() __sync_synchronize()

#define hdx_log(h, ...) do { \
    if ((h)->os.log) { char hdx_lb_[200]; snprintf(hdx_lb_, sizeof(hdx_lb_), __VA_ARGS__); (h)->os.log((h)->os.ctx, hdx_lb_); } \
} while (0)

static inline uint8_t hdx_r8(struct hdx_ctrl *h, uint32_t o) { return *(volatile uint8_t *)(h->bar + o); }
static inline uint16_t hdx_r16(struct hdx_ctrl *h, uint32_t o) { return *(volatile uint16_t *)(h->bar + o); }
static inline uint32_t hdx_r32(struct hdx_ctrl *h, uint32_t o) { return *(volatile uint32_t *)(h->bar + o); }
static inline void hdx_w8(struct hdx_ctrl *h, uint32_t o, uint8_t v) { *(volatile uint8_t *)(h->bar + o) = v; }
static inline void hdx_w16(struct hdx_ctrl *h, uint32_t o, uint16_t v) { *(volatile uint16_t *)(h->bar + o) = v; }
static inline void hdx_w32(struct hdx_ctrl *h, uint32_t o, uint32_t v) { *(volatile uint32_t *)(h->bar + o) = v; }

static void hdx_delay(struct hdx_ctrl *h, uint32_t us)
{
    if (h->os.delay_us)
        h->os.delay_us(h->os.ctx, us);
}

/* poll until (reg & mask) == want, every step_us, at most tries times; 1 = reached */
static int hdx_wait8(struct hdx_ctrl *h, uint32_t o, uint8_t mask, uint8_t want, uint32_t step_us, uint32_t tries)
{
    uint32_t i;
    for (i = 0; i <= tries; i++) {
        if ((hdx_r8(h, o) & mask) == want)
            return 1;
        if (i < tries)
            hdx_delay(h, step_us);
    }
    return 0;
}

static int hdx_wait32(struct hdx_ctrl *h, uint32_t o, uint32_t mask, uint32_t want, uint32_t step_us, uint32_t tries)
{
    uint32_t i;
    for (i = 0; i <= tries; i++) {
        if ((hdx_r32(h, o) & mask) == want)
            return 1;
        if (i < tries)
            hdx_delay(h, step_us);
    }
    return 0;
}

static int hdx_wait16(struct hdx_ctrl *h, uint32_t o, uint16_t mask, uint16_t want, uint32_t step_us, uint32_t tries)
{
    uint32_t i;
    for (i = 0; i <= tries; i++) {
        if ((hdx_r16(h, o) & mask) == want)
            return 1;
        if (i < tries)
            hdx_delay(h, step_us);
    }
    return 0;
}

static int hdx_have_cfg(struct hdx_ctrl *h)
{
    return h->os.cfg_read && h->os.cfg_write;
}

static uint32_t hdx_cfg_read(struct hdx_ctrl *h, uint32_t off, unsigned bytes)
{
    return hdx_have_cfg(h) ? h->os.cfg_read(h->os.ctx, off, bytes) : 0;
}

static void hdx_cfg_write(struct hdx_ctrl *h, uint32_t off, uint32_t v, unsigned bytes)
{
    if (hdx_have_cfg(h))
        h->os.cfg_write(h->os.ctx, off, v, bytes);
}

HDX_API int hdx_attach(struct hdx_ctrl *h)
{
    uint32_t off, hdr, guard;

    h->gcap = hdx_r16(h, HDX_GCAP);
    if (h->gcap == 0xffff)
        return HDX_ENODEV;      /* not decoding memory or powered off */
    h->iss = (h->gcap >> 8) & 0xf;
    h->oss = (h->gcap >> 12) & 0xf;
    h->bss = (h->gcap >> 3) & 0x1f;
    if (!h->oss || !h->iss)
        return HDX_ENODEV;
    h->ml_off = h->pp_off = 0;
    off = hdx_r16(h, HDX_LLCH);
    for (guard = 0; off >= 0x100 && off < 0x3f00 && guard < 8; guard++) {
        hdr = hdx_r32(h, off);
        if (hdr == 0xffffffffu)
            break;
        switch ((hdr >> 16) & 0xfff) {
        case HDX_CAP_ML: h->ml_off = off; break;
        case HDX_CAP_PP: h->pp_off = off; break;
        default: break;
        }
        off = hdr & 0xffff;
    }
    return HDX_OK;
}

/* PCI config tweaks of Linux azx_init_pci() for Intel PCH (SCH snoop type): TCSEL (byte) = TC0, DEVC (word)
 * NOSNOOP = 0 */
HDX_API void hdx_pci_quirks(struct hdx_ctrl *h)
{
    uint32_t v;

    if (!hdx_have_cfg(h))
        return;
    v = hdx_cfg_read(h, HDX_PCI_TCSEL, 1);
    if (v & 0x7) {
        hdx_cfg_write(h, HDX_PCI_TCSEL, v & ~0x7u, 1);
        hdx_log(h, "TCSEL %02x -> %02x", v, v & ~0x7u);
    }
    v = hdx_cfg_read(h, HDX_PCI_DEVC, 2);
    if (v & 0x800) {
        hdx_cfg_write(h, HDX_PCI_DEVC, v & ~0x800u, 2);
        hdx_log(h, "DEVC %04x -> %04x (snoop on)", v, v & ~0x800u);
    }
}

HDX_API void hdx_cmd_stop(struct hdx_ctrl *h)
{
    hdx_w8(h, HDX_CORBCTL, hdx_r8(h, HDX_CORBCTL) & (uint8_t)~0x03);
    hdx_w8(h, HDX_RIRBCTL, hdx_r8(h, HDX_RIRBCTL) & (uint8_t)~0x07);
    hdx_wait8(h, HDX_CORBCTL, 0x02, 0, 10, 100);
    hdx_wait8(h, HDX_RIRBCTL, 0x02, 0, 10, 100);
    h->cmd_up = 0;
}

static void hdx_stop_all_streams(struct hdx_ctrl *h)
{
    uint32_t i, n = (uint32_t)h->iss + h->oss + h->bss;

    for (i = 0; i < n && i < 30; i++) {
        uint32_t o = HDX_SD_BASE + HDX_SD_STRIDE * i;
        uint8_t c = hdx_r8(h, o + HDX_SD_CTL);
        if (c & (HDX_SD_RUN | HDX_SD_INT_MASK))
            hdx_w8(h, o + HDX_SD_CTL, c & (uint8_t)~(HDX_SD_RUN | HDX_SD_INT_MASK));
    }
    for (i = 0; i < n && i < 30; i++)
        hdx_wait8(h, HDX_SD_BASE + HDX_SD_STRIDE * i + HDX_SD_CTL, HDX_SD_RUN, 0, 10, 100);
}

/* intel_init_lctl(): only acts when the link clock (SCF) is still the 6 MHz based default */
static void hdx_init_lctl(struct hdx_ctrl *h)
{
    static const int pref[] = { 2, 3, 1, 4, 5 };
    uint32_t o, v, cap, scf = 0, i;

    if (!h->ml_off)
        return;
    o = h->ml_off + HDX_ML_LCTL;
    v = hdx_r32(h, o);
    if (v & 0xf)
        return;
    if (((v >> 16) & 1) != ((v >> 23) & 1))
        return;
    cap = hdx_r32(h, h->ml_off + HDX_ML_LCAP);
    for (i = 0; i < sizeof(pref) / sizeof(pref[0]); i++)
        if (cap & (1u << pref[i])) {
            scf = (uint32_t)pref[i];
            break;
        }
    hdx_w32(h, o, v & ~(1u << 16));
    if (hdx_wait32(h, o, 1u << 23, 0, 10, 50)) {
        hdx_delay(h, 100);
        v = (hdx_r32(h, o) & ~0xfu) | scf;
        hdx_w32(h, o, v);
    }
    hdx_w32(h, o, hdx_r32(h, o) | (1u << 16));
    hdx_wait32(h, o, 1u << 23, 1u << 23, 10, 50);
    hdx_delay(h, 100);
    hdx_log(h, "multi-link LCTL %08x (SCF set to %u)", hdx_r32(h, o), scf);
}

/* Linux snd_hdac_bus_reset_link(full_reset) inside hda_intel_init_chip(): DMA stopped, MISCBDCGE off, CRST
 * low >= 100 us, CRST high, wait for the codecs' state-change requests. Leaves CORB/RIRB stopped. */
HDX_API int hdx_reset_link(struct hdx_ctrl *h)
{
    uint32_t cg = 0;
    int ret = HDX_OK, have_cfg = hdx_have_cfg(h);

    hdx_cmd_stop(h);
    hdx_stop_all_streams(h);
    hdx_w32(h, HDX_INTCTL, 0);
    hdx_w32(h, HDX_DPLBASE, 0);
    hdx_w32(h, HDX_DPUBASE, 0);
    if (have_cfg) {
        cg = hdx_cfg_read(h, HDX_PCI_CGCTL, 4);
        hdx_cfg_write(h, HDX_PCI_CGCTL, cg & ~0x40u, 4);
    }
    if (hdx_r32(h, HDX_GCTL) & 1)
        hdx_w16(h, HDX_STATESTS, 0x7fff);
    hdx_w32(h, HDX_GCTL, hdx_r32(h, HDX_GCTL) & ~1u);
    if (!hdx_wait32(h, HDX_GCTL, 1, 0, 100, 1000)) {
        hdx_log(h, "link reset: CRST stuck at 1 (GCTL %08x)", hdx_r32(h, HDX_GCTL));
        ret = HDX_ETIMEDOUT;
        goto out;
    }
    hdx_delay(h, 1000);
    hdx_w32(h, HDX_GCTL, hdx_r32(h, HDX_GCTL) | 1u);
    if (!hdx_wait32(h, HDX_GCTL, 1, 1, 100, 1000)) {
        hdx_log(h, "link reset: CRST stuck at 0 (GCTL %08x)", hdx_r32(h, HDX_GCTL));
        ret = HDX_ETIMEDOUT;
        goto out;
    }
    {
        uint32_t i;
        for (i = 0; i < 50 && !(hdx_r16(h, HDX_STATESTS) & 0x7fff); i++)
            hdx_delay(h, 1000);
    }
    hdx_delay(h, 1000);
    h->codec_mask = hdx_r16(h, HDX_STATESTS) & 0x7fff;
    hdx_w16(h, HDX_STATESTS, 0x7fff);
out:
    if (have_cfg)
        hdx_cfg_write(h, HDX_PCI_CGCTL, hdx_cfg_read(h, HDX_PCI_CGCTL, 4) | 0x40u, 4);
    if (ret == HDX_OK)
        hdx_init_lctl(h);
    return ret;
}

/* Linux snd_hdac_bus_init_cmd_io(), without interrupts */
HDX_API int hdx_cmd_init(struct hdx_ctrl *h, int accept_unsol)
{
    uint64_t a = h->cmd.bus;
    uint32_t gctl;

    if (!h->cmd.virt || h->cmd.size < HDX_CMD_BYTES || (a & 127))
        return HDX_EINVAL;
    memset(h->cmd.virt, 0, HDX_CMD_BYTES);
    HDX_BARRIER();
    hdx_cmd_stop(h);

    hdx_w32(h, HDX_CORBLBASE, (uint32_t)a);
    hdx_w32(h, HDX_CORBUBASE, (uint32_t)(a >> 32));
    hdx_w8(h, HDX_CORBSIZE, 0x02);                          /* 256 entries */
    hdx_w16(h, HDX_CORBWP, 0);
    hdx_w16(h, HDX_CORBRP, 0x8000);
    hdx_wait16(h, HDX_CORBRP, 0x8000, 0x8000, 1, 1000);     /* some controllers never report the bit */
    hdx_w16(h, HDX_CORBRP, 0);
    if (!hdx_wait16(h, HDX_CORBRP, 0x80ff, 0, 1, 1000)) {
        hdx_log(h, "CORB read pointer reset failed (CORBRP %04x)", hdx_r16(h, HDX_CORBRP));
        return HDX_EIO;
    }
    hdx_w8(h, HDX_CORBSTS, 0x01);
    hdx_w8(h, HDX_CORBCTL, 0x02);                           /* CORB DMA run */

    hdx_w32(h, HDX_RIRBLBASE, (uint32_t)(a + 2048));
    hdx_w32(h, HDX_RIRBUBASE, (uint32_t)((a + 2048) >> 32));
    hdx_w8(h, HDX_RIRBSIZE, 0x02);
    hdx_w16(h, HDX_RIRBWP, 0x8000);                         /* write pointer reset */
    hdx_w16(h, HDX_RINTCNT, 1);
    hdx_w8(h, HDX_RIRBSTS, 0x05);
    hdx_w8(h, HDX_RIRBCTL, 0x02);                           /* RIRB DMA, no interrupt */
    h->corb_wp = 0;
    h->rirb_rp = 0;
    h->unsol_head = h->unsol_tail = 0;

    hdx_w32(h, HDX_DPUBASE, (uint32_t)((a + 1024) >> 32));  /* DMA position buffer, as Linux */
    hdx_w32(h, HDX_DPLBASE, (uint32_t)(a + 1024) | 1u);

    gctl = hdx_r32(h, HDX_GCTL);
    gctl = accept_unsol ? (gctl | 0x100u) : (gctl & ~0x100u);
    hdx_w32(h, HDX_GCTL, gctl);

    if (!hdx_wait8(h, HDX_CORBCTL, 0x02, 0x02, 10, 100) || !hdx_wait8(h, HDX_RIRBCTL, 0x02, 0x02, 10, 100)) {
        hdx_log(h, "CORB/RIRB did not start (CORBCTL %02x RIRBCTL %02x)", hdx_r8(h, HDX_CORBCTL),
                hdx_r8(h, HDX_RIRBCTL));
        return HDX_EIO;
    }
    h->cmd_up = 1;
    return HDX_OK;
}

HDX_API void hdx_enter_reset(struct hdx_ctrl *h)
{
    hdx_stop_all_streams(h);
    hdx_cmd_stop(h);
    hdx_w32(h, HDX_INTCTL, 0);
    hdx_w32(h, HDX_DPLBASE, 0);
    hdx_w32(h, HDX_DPUBASE, 0);
    hdx_w32(h, HDX_GCTL, hdx_r32(h, HDX_GCTL) & ~1u);
    hdx_wait32(h, HDX_GCTL, 1, 0, 100, 1000);
}

/* consume RIRB entries up to the hardware write pointer; returns the solicited response for codec addr if one
 * was found (1), queueing unsolicited ones */
static int hdx_rirb_take(struct hdx_ctrl *h, unsigned addr, uint32_t *res)
{
    volatile uint32_t *rirb = (volatile uint32_t *)((uint8_t *)h->cmd.virt + 2048);
    uint16_t wp = hdx_r16(h, HDX_RIRBWP);
    int got = 0;

    if (wp == 0xffff)
        return -1;
    if (hdx_r8(h, HDX_RIRBSTS) & 0x04) {
        h->rirb_overruns++;
        hdx_w8(h, HDX_RIRBSTS, 0x04);
    }
    wp &= 0xff;
    HDX_BARRIER();
    while (h->rirb_rp != wp) {
        uint32_t r, ex;
        h->rirb_rp = (uint16_t)((h->rirb_rp + 1) & 0xff);
        r = rirb[h->rirb_rp * 2];
        ex = rirb[h->rirb_rp * 2 + 1];
        if (ex & 0x10) {
            h->unsol_seen++;
            if (h->unsol_head - h->unsol_tail < HDX_UNSOL_Q) {
                h->unsol_res[h->unsol_head % HDX_UNSOL_Q] = r;
                h->unsol_ex[h->unsol_head % HDX_UNSOL_Q] = ex;
                h->unsol_head++;
            } else {
                h->unsol_lost++;
            }
        } else if (!got && (ex & 0xf) == addr) {
            *res = r;
            got = 1;
        } else {
            h->spurious++;
        }
    }
    return got;
}

HDX_API int hdx_verb(struct hdx_ctrl *h, uint32_t cmd, uint32_t *res)
{
    volatile uint32_t *corb = (volatile uint32_t *)h->cmd.virt;
    unsigned addr = cmd >> 28;
    uint32_t r = 0, i;
    uint16_t wp;
    int got;

    if (!h->cmd_up)
        return HDX_EIO;
    if (hdx_rirb_take(h, 0xff, &r) < 0)     /* drain stale entries; 0xff matches no codec */
        return HDX_EIO;
    wp = (uint16_t)((h->corb_wp + 1) & 0xff);
    if ((hdx_r16(h, HDX_CORBRP) & 0xff) == wp)
        return HDX_EBUSY;                   /* CORB full: cannot happen with one command in flight */
    corb[wp] = cmd;
    HDX_BARRIER();
    hdx_w16(h, HDX_CORBWP, wp);
    h->corb_wp = wp;
    h->verbs++;
    /* responses take ~60 us on this codec (Linux trace); poll every 2 us for the first 200 us, then every 20 us,
     * give up after ~100 ms */
    for (i = 0; i < 5100; i++) {
        got = hdx_rirb_take(h, addr, &r);
        if (got < 0)
            return HDX_EIO;
        if (got) {
            h->trace_cmd[h->trace_pos % HDX_TRACE] = cmd;
            h->trace_res[h->trace_pos % HDX_TRACE] = r;
            h->trace_pos++;
            if (res)
                *res = r;
            return HDX_OK;
        }
        hdx_delay(h, i < 100 ? 2 : 20);
    }
    h->timeouts++;
    h->trace_cmd[h->trace_pos % HDX_TRACE] = cmd;
    h->trace_res[h->trace_pos % HDX_TRACE] = 0xdeadbeefu;
    h->trace_pos++;
    hdx_log(h, "verb %08x: no response (CORBWP %04x CORBRP %04x RIRBWP %04x RIRBSTS %02x)", cmd,
            hdx_r16(h, HDX_CORBWP), hdx_r16(h, HDX_CORBRP), hdx_r16(h, HDX_RIRBWP), hdx_r8(h, HDX_RIRBSTS));
    return HDX_ETIMEDOUT;
}

HDX_API int hdx_poll_unsol(struct hdx_ctrl *h, uint32_t *res, uint32_t *res_ex)
{
    uint32_t r;

    if (h->cmd_up)
        hdx_rirb_take(h, 0xff, &r);
    if (h->unsol_head == h->unsol_tail)
        return 0;
    *res = h->unsol_res[h->unsol_tail % HDX_UNSOL_Q];
    *res_ex = h->unsol_ex[h->unsol_tail % HDX_UNSOL_Q];
    h->unsol_tail++;
    return 1;
}

HDX_API void hdx_stream_init(struct hdx_ctrl *h, struct hdx_stream *s, int out, uint8_t tag, uint16_t fmt,
                             const struct hdx_dma *ring, const struct hdx_dma *bdl, uint32_t frags)
{
    memset(s, 0, sizeof(*s));
    s->out = out ? 1 : 0;
    s->index = out ? h->iss : 0;    /* first output / first input descriptor, as Linux picks */
    s->tag = tag;
    s->fmt = fmt;
    s->frags = frags;
    s->ring = *ring;
    s->bdl = *bdl;
}

static int hdx_stream_reset(struct hdx_ctrl *h, struct hdx_stream *s)
{
    uint32_t o = HDX_SDO(s);

    hdx_w8(h, o + HDX_SD_CTL, hdx_r8(h, o + HDX_SD_CTL) & (uint8_t)~(HDX_SD_RUN | HDX_SD_INT_MASK));
    hdx_wait8(h, o + HDX_SD_CTL, HDX_SD_RUN, 0, 10, 100);
    hdx_w8(h, o + HDX_SD_STS, HDX_SD_INT_MASK);
    hdx_w8(h, o + HDX_SD_CTL, hdx_r8(h, o + HDX_SD_CTL) | HDX_SD_SRST);
    hdx_wait8(h, o + HDX_SD_CTL, HDX_SD_SRST, HDX_SD_SRST, 10, 100);
    hdx_w8(h, o + HDX_SD_CTL, hdx_r8(h, o + HDX_SD_CTL) & (uint8_t)~HDX_SD_SRST);
    if (!hdx_wait8(h, o + HDX_SD_CTL, HDX_SD_SRST, 0, 10, 100)) {
        hdx_log(h, "SD%u stays in reset (CTL %08x)", s->index, hdx_r32(h, o + HDX_SD_CTL));
        return HDX_ETIMEDOUT;
    }
    s->running = 0;
    return HDX_OK;
}

HDX_API int hdx_stream_setup(struct hdx_ctrl *h, struct hdx_stream *s)
{
    uint32_t o = HDX_SDO(s), i, frag, ctl, v;
    volatile uint32_t *bdl = (volatile uint32_t *)s->bdl.virt;
    int ret;

    if (s->frags < 2 || s->frags > 256 || !s->ring.size || s->ring.size % s->frags ||
        (s->ring.size / s->frags) % 128 || (s->ring.bus & 127) || (s->bdl.bus & 127) ||
        s->bdl.size < 16 * s->frags || !bdl)
        return HDX_EINVAL;
    ret = hdx_stream_reset(h, s);
    if (ret)
        return ret;
    frag = s->ring.size / s->frags;
    for (i = 0; i < s->frags; i++) {
        uint64_t a = s->ring.bus + (uint64_t)i * frag;
        bdl[4 * i + 0] = (uint32_t)a;
        bdl[4 * i + 1] = (uint32_t)(a >> 32);
        bdl[4 * i + 2] = frag;
        bdl[4 * i + 3] = 0;             /* no IOC: no interrupts are used */
    }
    HDX_BARRIER();
    ctl = hdx_r32(h, o + HDX_SD_CTL) & 0x00ffffffu;
    ctl &= ~(0x00f00000u | HDX_SD_RUN | HDX_SD_INT_MASK | HDX_SD_SRST);
    ctl |= (uint32_t)s->tag << 20;
    hdx_w32(h, o + HDX_SD_CTL, ctl);
    hdx_w32(h, o + HDX_SD_CBL, s->ring.size);
    hdx_w16(h, o + HDX_SD_FMT, s->fmt);
    hdx_w16(h, o + HDX_SD_LVI, (uint16_t)(s->frags - 1));
    hdx_w32(h, o + HDX_SD_BDLPL, (uint32_t)s->bdl.bus);
    hdx_w32(h, o + HDX_SD_BDLPU, (uint32_t)(s->bdl.bus >> 32));
    s->fifos = hdx_r16(h, o + HDX_SD_FIFOS);
    if (h->pp_off) {                    /* coupled (legacy) DMA for this stream */
        v = hdx_r32(h, h->pp_off + HDX_PP_PPCTL);
        if (v & (1u << s->index)) {
            hdx_w32(h, h->pp_off + HDX_PP_PPCTL, v & ~(1u << s->index));
            hdx_log(h, "PPCTL %08x: PROCEN%u cleared", v, s->index);
        }
    }
    if (s->out && h->ml_off) {          /* output stream tag must be valid on link 0 */
        v = hdx_r32(h, h->ml_off + HDX_ML_LOSIDV);
        if (!(v & (1u << s->tag))) {
            hdx_w32(h, h->ml_off + HDX_ML_LOSIDV, v | (1u << s->tag));
            hdx_log(h, "LOSIDV %08x: stream tag %u enabled", v, s->tag);
        }
    }
    v = hdx_r32(h, HDX_SSYNC);
    if (v & (1u << s->index))
        hdx_w32(h, HDX_SSYNC, v & ~(1u << s->index));
    if (hdx_r32(h, o + HDX_SD_CBL) != s->ring.size || hdx_r16(h, o + HDX_SD_FMT) != s->fmt) {
        hdx_log(h, "SD%u setup readback mismatch: CBL %08x FMT %04x", s->index, hdx_r32(h, o + HDX_SD_CBL),
                hdx_r16(h, o + HDX_SD_FMT));
        return HDX_EIO;
    }
    s->configured = 1;
    return HDX_OK;
}

HDX_API int hdx_stream_start(struct hdx_ctrl *h, struct hdx_stream *s)
{
    uint32_t o = HDX_SDO(s);

    if (!s->configured)
        return HDX_EINVAL;
    hdx_w8(h, o + HDX_SD_STS, HDX_SD_INT_MASK);
    hdx_w8(h, o + HDX_SD_CTL, (uint8_t)((hdx_r8(h, o + HDX_SD_CTL) & ~HDX_SD_INT_MASK) | HDX_SD_RUN));
    s->running = hdx_wait8(h, o + HDX_SD_CTL, HDX_SD_RUN, HDX_SD_RUN, 10, 100);
    return s->running ? HDX_OK : HDX_ETIMEDOUT;
}

HDX_API int hdx_stream_stop(struct hdx_ctrl *h, struct hdx_stream *s)
{
    uint32_t o = HDX_SDO(s);
    int ok;

    hdx_w8(h, o + HDX_SD_CTL, hdx_r8(h, o + HDX_SD_CTL) & (uint8_t)~(HDX_SD_RUN | HDX_SD_INT_MASK));
    ok = hdx_wait8(h, o + HDX_SD_CTL, HDX_SD_RUN, 0, 10, 100);
    hdx_w8(h, o + HDX_SD_STS, HDX_SD_INT_MASK);
    s->running = 0;
    return ok ? HDX_OK : HDX_ETIMEDOUT;
}

HDX_API void hdx_stream_clear(struct hdx_ctrl *h, struct hdx_stream *s)
{
    uint32_t o = HDX_SDO(s);

    hdx_stream_stop(h, s);
    hdx_stream_reset(h, s);
    hdx_w32(h, o + HDX_SD_BDLPL, 0);
    hdx_w32(h, o + HDX_SD_BDLPU, 0);
    hdx_w32(h, o + HDX_SD_CTL, hdx_r32(h, o + HDX_SD_CTL) & 0x000f0000u);  /* tag 0, keep TP/stripe bits */
    s->configured = 0;
}

HDX_API uint32_t hdx_stream_dpib(struct hdx_ctrl *h, const struct hdx_stream *s)
{
    return hdx_r32(h, HDX_VS_DPIB(s->index));
}

HDX_API uint32_t hdx_stream_lpib(struct hdx_ctrl *h, const struct hdx_stream *s)
{
    return hdx_r32(h, HDX_SDO(s) + HDX_SD_LPIB);
}

HDX_API uint32_t hdx_stream_ctlsts(struct hdx_ctrl *h, const struct hdx_stream *s)
{
    return hdx_r32(h, HDX_SDO(s) + HDX_SD_CTL);
}

HDX_API void hdx_dump(struct hdx_ctrl *h, const struct hdx_stream *s0, const struct hdx_stream *s1)
{
    const struct hdx_stream *ss[2];
    int i;

    ss[0] = s0;
    ss[1] = s1;
    hdx_log(h, "GCAP %04x GCTL %08x STATESTS %04x INTCTL %08x INTSTS %08x WALCLK %08x SSYNC %08x",
            hdx_r16(h, HDX_GCAP), hdx_r32(h, HDX_GCTL), hdx_r16(h, HDX_STATESTS), hdx_r32(h, HDX_INTCTL),
            hdx_r32(h, HDX_INTSTS), hdx_r32(h, HDX_WALCLK), hdx_r32(h, HDX_SSYNC));
    hdx_log(h, "CORB %08x%08x WP %04x RP %04x CTL %02x STS %02x SIZE %02x | RIRB %08x%08x WP %04x CTL %02x STS %02x SIZE %02x | DPL %08x%08x",
            hdx_r32(h, HDX_CORBUBASE), hdx_r32(h, HDX_CORBLBASE), hdx_r16(h, HDX_CORBWP), hdx_r16(h, HDX_CORBRP),
            hdx_r8(h, HDX_CORBCTL), hdx_r8(h, HDX_CORBSTS), hdx_r8(h, HDX_CORBSIZE), hdx_r32(h, HDX_RIRBUBASE),
            hdx_r32(h, HDX_RIRBLBASE), hdx_r16(h, HDX_RIRBWP), hdx_r8(h, HDX_RIRBCTL), hdx_r8(h, HDX_RIRBSTS),
            hdx_r8(h, HDX_RIRBSIZE), hdx_r32(h, HDX_DPUBASE), hdx_r32(h, HDX_DPLBASE));
    if (h->ml_off)
        hdx_log(h, "ML@%04x LCAP %08x LCTL %08x LOSIDV %08x", h->ml_off, hdx_r32(h, h->ml_off + HDX_ML_LCAP),
                hdx_r32(h, h->ml_off + HDX_ML_LCTL), hdx_r32(h, h->ml_off + HDX_ML_LOSIDV));
    if (h->pp_off)
        hdx_log(h, "PP@%04x PPCTL %08x", h->pp_off, hdx_r32(h, h->pp_off + HDX_PP_PPCTL));
    hdx_log(h, "EM2 %08x verbs %u timeouts %u spurious %u unsol %u lost %u rirb overruns %u",
            hdx_r32(h, HDX_VS_EM2), h->verbs, h->timeouts, h->spurious, h->unsol_seen, h->unsol_lost,
            h->rirb_overruns);
    for (i = 0; i < 2; i++) {
        const struct hdx_stream *s = ss[i];
        uint32_t o;
        if (!s)
            continue;
        o = HDX_SDO(s);
        hdx_log(h, "SD%u %s CTL %08x LPIB %08x DPIB %08x CBL %08x LVI %04x FIFOS %04x FMT %04x BDL %08x%08x",
                s->index, s->out ? "out" : "in", hdx_r32(h, o + HDX_SD_CTL), hdx_r32(h, o + HDX_SD_LPIB),
                hdx_r32(h, HDX_VS_DPIB(s->index)), hdx_r32(h, o + HDX_SD_CBL), hdx_r16(h, o + HDX_SD_LVI),
                hdx_r16(h, o + HDX_SD_FIFOS), hdx_r16(h, o + HDX_SD_FMT), hdx_r32(h, o + HDX_SD_BDLPU),
                hdx_r32(h, o + HDX_SD_BDLPL));
    }
}
