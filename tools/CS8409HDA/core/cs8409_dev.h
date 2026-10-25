/*
 * cs8409_dev.h: the whole device (Intel HDA controller + CS8409 codec) as used by the drivers: bring-up,
 * output/input start and stop, teardown. Shared by the macOS kext and the Linux test module; the host only
 * provides DMA memory, MMIO, delays and serialization. Unity build (include cs8409_dev.c after hdx_core.c and
 * cs8409_codec.c).
 */
#ifndef CS8409HDA_CS8409_DEV_H
#define CS8409HDA_CS8409_DEV_H

#include "hdx_core.h"
#include "cs8409_codec.h"

#define CS8409_RING_BYTES   65536u      /* AudShimDrv.h geometry: 8192 frames of S32_LE stereo */
#define CS8409_RING_FRAGS   4u          /* BDL entries of 16 KiB */
#define CS8409_BDL_BYTES    4096u
#define CS8409_OUT_TAG      1
#define CS8409_IN_TAG       1

/* bring-up steps (fail_step) */
enum {
    CS8409_STEP_NONE = 0, CS8409_STEP_ATTACH = 1, CS8409_STEP_LINK_RESET = 2, CS8409_STEP_NO_CODEC = 3,
    CS8409_STEP_CMD_IO = 4, CS8409_STEP_PROBE = 5, CS8409_STEP_SSID = 6, CS8409_STEP_CODEC_INIT = 7,
    CS8409_STEP_OUT_SETUP = 8, CS8409_STEP_OUT_START = 9, CS8409_STEP_IN_SETUP = 10, CS8409_STEP_IN_START = 11,
};

/* dev flags */
#define CS8409_DEV_HEADSET      0x01    /* initialise the CS42L42 (CS8409_F_CS42L42) */
#define CS8409_DEV_ANY_SSID     0x02    /* do not insist on subsystem 1028:0B94 */

struct cs8409_dev {
    struct hdx_ctrl hc;
    struct cs8409 codec;
    struct hdx_stream out, in;
    /* DMA memory supplied by the host before cs8409_dev_bringup */
    struct hdx_dma cmd_mem, out_ring, out_bdl, in_ring, in_bdl;
    uint32_t flags;
    int up, out_on, in_on;
    int fail_step, fail_code;
    uint32_t codec_addr;
    int codec_ok;           /* the CS8409 answered the probe: send it the shutdown sequence */
};

HDX_API int cs8409_dev_bringup(struct cs8409_dev *d);   /* controller reset + codec init, streams programmed */
HDX_API int cs8409_dev_out_start(struct cs8409_dev *d); /* restarts the output DMA at ring offset 0 */
HDX_API int cs8409_dev_out_stop(struct cs8409_dev *d);
HDX_API int cs8409_dev_in_start(struct cs8409_dev *d);
HDX_API int cs8409_dev_in_stop(struct cs8409_dev *d);
HDX_API void cs8409_dev_teardown(struct cs8409_dev *d); /* codec off, link in reset */
HDX_API int cs8409_dev_verb(struct cs8409_dev *d, uint32_t cmd, uint32_t *res);

#endif
