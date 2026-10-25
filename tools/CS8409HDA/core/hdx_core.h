/*
 * hdx_core.h: minimal Intel HD Audio controller core (link reset, CORB/RIRB verbs by polling, one output and one
 * input stream descriptor), written once and compiled into both the macOS kext (CS8409HDA) and the Linux test
 * module (linux/cs8409test). Unity build: the host .c/.cpp includes hdx_core.c, after including the headers that
 * declare snprintf/memset for its environment. No interrupts are used: responses are polled in RIRB, the DMA
 * position is read from the Intel DPIB register.
 *
 * References: Intel High Definition Audio Specification 1.0a; Linux sound/hda/core/controller.c, stream.c and
 * sound/hda/controllers/intel.c (behaviour reproduced, not code); register snapshot of the Dell Vostro 3520
 * (8086:51C8, tools/CS8409HDA/ref/hdaregs-play.txt).
 */
#ifndef CS8409HDA_HDX_CORE_H
#define CS8409HDA_HDX_CORE_H

#if defined(__linux__) && defined(__KERNEL__)
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#ifndef HDX_API
#define HDX_API static __attribute__((unused))
#endif

/* ---- global registers (BAR0) */
#define HDX_GCAP        0x00    /* 16: OSS[15:12] ISS[11:8] BSS[7:3] NSDO[2:1] 64OK[0] */
#define HDX_VMIN        0x02
#define HDX_VMAJ        0x03
#define HDX_GCTL        0x08    /* 32: CRST[0] FCNTRL[1] UNSOL[8] */
#define HDX_WAKEEN      0x0c
#define HDX_STATESTS    0x0e    /* 16, RW1C: SDIN state change per codec address */
#define HDX_GSTS        0x10
#define HDX_LLCH        0x14    /* 16: first extended capability (SKL+) */
#define HDX_INTCTL      0x20
#define HDX_INTSTS      0x24
#define HDX_WALCLK      0x30    /* 24 MHz wall clock */
#define HDX_SSYNC       0x38
#define HDX_CORBLBASE   0x40
#define HDX_CORBUBASE   0x44
#define HDX_CORBWP      0x48
#define HDX_CORBRP      0x4a    /* RST[15] */
#define HDX_CORBCTL     0x4c    /* RUN[1] CMEIE[0] */
#define HDX_CORBSTS     0x4d
#define HDX_CORBSIZE    0x4e
#define HDX_RIRBLBASE   0x50
#define HDX_RIRBUBASE   0x54
#define HDX_RIRBWP      0x58    /* RST[15] */
#define HDX_RINTCNT     0x5a
#define HDX_RIRBCTL     0x5c    /* OIC[2] DMAEN[1] RINTCTL[0] */
#define HDX_RIRBSTS     0x5d    /* RW1C: OIS[2] INTFL[0] */
#define HDX_RIRBSIZE    0x5e
#define HDX_DPLBASE     0x70    /* DMA position buffer, ENABLE[0] */
#define HDX_DPUBASE     0x74
#define HDX_SD_BASE     0x80
#define HDX_SD_STRIDE   0x20
/* stream descriptor registers (offset from the descriptor) */
#define HDX_SD_CTL      0x00    /* 24 bit: SRST[0] RUN[1] IOCE[2] FEIE[3] DEIE[4] TP[18] DIR[19] STRM[23:20] */
#define HDX_SD_STS      0x03    /* 8, RW1C: BCIS[2] FIFOE[3] DESE[4] FIFORDY[5] */
#define HDX_SD_LPIB     0x04
#define HDX_SD_CBL      0x08
#define HDX_SD_LVI      0x0c
#define HDX_SD_FIFOW    0x0e
#define HDX_SD_FIFOS    0x10
#define HDX_SD_FMT      0x12
#define HDX_SD_BDLPL    0x18
#define HDX_SD_BDLPU    0x1c
#define HDX_SD_SRST     0x01
#define HDX_SD_RUN      0x02
#define HDX_SD_INT_MASK 0x1c
/* Intel vendor-specific registers */
#define HDX_VS_EM2      0x1030
#define HDX_VS_DPIB(i)  (0x1084 + 0x20 * (i))   /* DMA position in buffer: bytes the DMA has read/written */
/* extended capability IDs (include/sound/hda_register.h) */
#define HDX_CAP_GTS     1
#define HDX_CAP_ML      2
#define HDX_CAP_PP      3
#define HDX_CAP_SPB     4
#define HDX_CAP_DRSM    5
#define HDX_ML_LCAP     0x40    /* link 0 registers inside the multi-link capability */
#define HDX_ML_LCTL     0x44    /* SCF[3:0] SPA[16] CPA[23] */
#define HDX_ML_LOSIDV   0x48    /* output stream tags routed to link 0 */
#define HDX_PP_PPCTL    0x04    /* GPROCEN[30] PROCEN[n]: 1 = stream n decoupled (DSP) */
/* Intel PCI config registers (sound/hda/controllers/intel.c) */
#define HDX_PCI_TCSEL   0x44
#define HDX_PCI_CGCTL   0x48    /* MISCBDCGE[6]: must be 0 during link reset */
#define HDX_PCI_DEVC    0x78    /* NOSNOOP[11] */

/* stream formats (HDA spec 3.7.1): 48 kHz base, 32-bit container, 2 channels */
#define HDX_FMT_48K_32_2CH  0x0041
#define HDX_FMT_48K_16_2CH  0x0011

#define HDX_CORB_ENTRIES    256
#define HDX_RIRB_ENTRIES    256
#define HDX_CMD_BYTES       4096    /* CORB @0 (1 KiB), DMA position buffer @1024, RIRB @2048 (2 KiB) */
#define HDX_TRACE           256     /* last verbs kept for diagnostics */
#define HDX_UNSOL_Q         16

/* error codes (negative) */
enum {
    HDX_OK = 0, HDX_ETIMEDOUT = -1, HDX_ENODEV = -2, HDX_EIO = -3, HDX_EINVAL = -4, HDX_EBUSY = -5,
};

/* A DMA buffer provided by the host environment: CPU address, device (bus) address, size. Must be physically
 * contiguous as seen by the device, 128-byte aligned, and cache-coherent (snooped). */
struct hdx_dma {
    void *virt;
    uint64_t bus;
    uint32_t size;
};

/* host environment callbacks */
struct hdx_os {
    void *ctx;
    void (*delay_us)(void *ctx, uint32_t us);            /* >= 1000 us may sleep */
    void (*log)(void *ctx, const char *line);            /* optional */
    /* PCI config space with the access width Linux uses (1, 2 or 4 bytes), optional */
    uint32_t (*cfg_read)(void *ctx, uint32_t off, unsigned bytes);
    void (*cfg_write)(void *ctx, uint32_t off, uint32_t val, unsigned bytes);
};

struct hdx_ctrl {
    volatile uint8_t *bar;              /* BAR0, 16 KiB, uncached */
    struct hdx_os os;
    struct hdx_dma cmd;                 /* HDX_CMD_BYTES */
    uint16_t gcap;
    uint8_t iss, oss, bss;
    uint16_t codec_mask;                /* STATESTS after the last link reset */
    uint16_t corb_wp, rirb_rp;
    uint32_t ml_off, pp_off;            /* extended capability offsets, 0 = absent */
    int cmd_up;                         /* CORB/RIRB running */
    /* unsolicited responses seen while polling (ring) */
    uint32_t unsol_res[HDX_UNSOL_Q], unsol_ex[HDX_UNSOL_Q];
    uint32_t unsol_head, unsol_tail;
    /* statistics */
    uint32_t verbs, timeouts, spurious, unsol_seen, unsol_lost, rirb_overruns;
    /* last verbs (cmd, response) */
    uint32_t trace_cmd[HDX_TRACE], trace_res[HDX_TRACE];
    uint32_t trace_pos;
};

struct hdx_stream {
    uint8_t index;          /* stream descriptor index: 0..ISS-1 input, ISS..ISS+OSS-1 output */
    uint8_t tag;            /* stream tag 1..15 (separate tag spaces for input and output on SKL+) */
    uint8_t out;
    uint16_t fmt;
    uint32_t frags;         /* BDL entries */
    struct hdx_dma ring;    /* cyclic buffer */
    struct hdx_dma bdl;     /* >= 16 * frags bytes */
    uint32_t fifos;         /* SD FIFOS after setup */
    int configured, running;
};

HDX_API int hdx_attach(struct hdx_ctrl *h);                         /* read GCAP, find capabilities */
HDX_API void hdx_pci_quirks(struct hdx_ctrl *h);                    /* TCSEL, snoop (Intel PCH) */
HDX_API int hdx_reset_link(struct hdx_ctrl *h);                     /* full controller + link reset */
HDX_API int hdx_cmd_init(struct hdx_ctrl *h, int accept_unsol);     /* CORB/RIRB + position buffer */
HDX_API void hdx_cmd_stop(struct hdx_ctrl *h);
HDX_API void hdx_enter_reset(struct hdx_ctrl *h);                   /* teardown: everything stopped, CRST=0 */
HDX_API int hdx_verb(struct hdx_ctrl *h, uint32_t cmd, uint32_t *res);
HDX_API int hdx_poll_unsol(struct hdx_ctrl *h, uint32_t *res, uint32_t *res_ex);
HDX_API void hdx_stream_init(struct hdx_ctrl *h, struct hdx_stream *s, int out, uint8_t tag, uint16_t fmt,
                             const struct hdx_dma *ring, const struct hdx_dma *bdl, uint32_t frags);
HDX_API int hdx_stream_setup(struct hdx_ctrl *h, struct hdx_stream *s);  /* reset + program (stopped) */
HDX_API int hdx_stream_start(struct hdx_ctrl *h, struct hdx_stream *s);
HDX_API int hdx_stream_stop(struct hdx_ctrl *h, struct hdx_stream *s);
HDX_API void hdx_stream_clear(struct hdx_ctrl *h, struct hdx_stream *s); /* stop + reset + BDL address 0 */
HDX_API uint32_t hdx_stream_dpib(struct hdx_ctrl *h, const struct hdx_stream *s);
HDX_API uint32_t hdx_stream_lpib(struct hdx_ctrl *h, const struct hdx_stream *s);
HDX_API uint32_t hdx_stream_ctlsts(struct hdx_ctrl *h, const struct hdx_stream *s);
HDX_API void hdx_dump(struct hdx_ctrl *h, const struct hdx_stream *s0, const struct hdx_stream *s1);

#endif
