/*
 * cs8409_dev.c: see cs8409_dev.h. Unity build only.
 */
#include "cs8409_dev.h"

static int cs8409_dev_codec_verb(void *ctx, uint32_t cmd, uint32_t *res)
{
    return hdx_verb(&((struct cs8409_dev *)ctx)->hc, cmd, res);
}

static void cs8409_dev_delay(void *ctx, uint32_t us)
{
    hdx_delay(&((struct cs8409_dev *)ctx)->hc, us);
}

static void cs8409_dev_log(void *ctx, const char *line)
{
    struct cs8409_dev *d = (struct cs8409_dev *)ctx;
    if (d->hc.os.log)
        d->hc.os.log(d->hc.os.ctx, line);
}

static int cs8409_dev_fail(struct cs8409_dev *d, int step, int code)
{
    d->fail_step = step;
    d->fail_code = code ? code : -1;
    hdx_log(&d->hc, "bring-up failed at step %d (code %d)", step, d->fail_code);
    return d->fail_code;
}

HDX_API int cs8409_dev_verb(struct cs8409_dev *d, uint32_t cmd, uint32_t *res)
{
    if (!d->hc.cmd_up)
        return HDX_EIO;
    return hdx_verb(&d->hc, cmd, res);
}

HDX_API int cs8409_dev_bringup(struct cs8409_dev *d)
{
    uint32_t a;
    int e;

    d->up = d->out_on = d->in_on = 0;
    d->fail_step = d->fail_code = 0;
    d->codec_ok = 0;
    d->hc.cmd = d->cmd_mem;
    e = hdx_attach(&d->hc);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_ATTACH, e);
    hdx_pci_quirks(&d->hc);
    e = hdx_reset_link(&d->hc);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_LINK_RESET, e);
    e = hdx_cmd_init(&d->hc, 0);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_CMD_IO, e);
    hdx_log(&d->hc, "controller up: GCAP %04x (ISS %u OSS %u), codec mask %04x, ML@%04x PP@%04x", d->hc.gcap,
            d->hc.iss, d->hc.oss, d->hc.codec_mask, d->hc.ml_off, d->hc.pp_off);
    if (!d->hc.codec_mask)
        return cs8409_dev_fail(d, CS8409_STEP_NO_CODEC, HDX_ENODEV);

    d->codec.ctx = d;
    d->codec.verb = cs8409_dev_codec_verb;
    d->codec.delay_us = cs8409_dev_delay;
    d->codec.log = cs8409_dev_log;
    for (a = 0; a < 15; a++) {
        if (!(d->hc.codec_mask & (1u << a)))
            continue;
        d->codec.addr = a;
        e = cs8409_probe(&d->codec);
        hdx_log(&d->hc, "codec %u: vendor %08x subsystem %08x revision %08x%s", a, d->codec.vendor, d->codec.ssid,
                d->codec.rev, e ? (d->codec.err ? " (no response)" : "") : " <- CS8409");
        if (!e)
            break;
    }
    if (a >= 15)
        return cs8409_dev_fail(d, CS8409_STEP_PROBE, HDX_ENODEV);
    d->codec_addr = a;
    d->codec_ok = 1;
    if (d->codec.ssid != CS8409_SSID_WARLOCK_MLK && !(d->flags & CS8409_DEV_ANY_SSID))
        return cs8409_dev_fail(d, CS8409_STEP_SSID, HDX_ENODEV);
    e = cs8409_init(&d->codec, (d->flags & CS8409_DEV_HEADSET) ? CS8409_F_CS42L42 : 0);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_CODEC_INIT, e);

    hdx_stream_init(&d->hc, &d->out, 1, CS8409_OUT_TAG, HDX_FMT_48K_32_2CH, &d->out_ring, &d->out_bdl,
                    CS8409_RING_FRAGS);
    e = hdx_stream_setup(&d->hc, &d->out);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_OUT_SETUP, e);
    if (d->in_ring.virt) {
        hdx_stream_init(&d->hc, &d->in, 0, CS8409_IN_TAG, HDX_FMT_48K_32_2CH, &d->in_ring, &d->in_bdl,
                        CS8409_RING_FRAGS);
        e = hdx_stream_setup(&d->hc, &d->in);
        if (e)
            return cs8409_dev_fail(d, CS8409_STEP_IN_SETUP, e);
    }
    d->up = 1;
    return 0;
}

/* Output: SD reset + reprogram (DPIB restarts at 0), converters on the stream tag (once per bring-up), RUN */
HDX_API int cs8409_dev_out_start(struct cs8409_dev *d)
{
    int e;

    if (!d->up)
        return HDX_EIO;
    if (d->out_on)
        return 0;
    cs8409_clear_err(&d->codec);
    e = hdx_stream_setup(&d->hc, &d->out);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_OUT_SETUP, e);
    if (hdx_r8(&d->hc, HDX_SD_BASE + HDX_SD_STRIDE * d->out.index) == 0xff)
        return cs8409_dev_fail(d, CS8409_STEP_OUT_SETUP, HDX_EIO);
    if (!(cs_r(&d->codec, CS8409_NID_DAC_SPK, CSV_GET_CONV, 0) >> 4)) {
        e = cs8409_stream_on(&d->codec, CS8409_NID_DAC_SPK, d->out.tag, d->out.fmt);
        if (!e && (d->flags & CS8409_DEV_HEADSET))
            e = cs8409_stream_on(&d->codec, CS8409_NID_DAC_HP, d->out.tag, d->out.fmt);
        if (e)
            return cs8409_dev_fail(d, CS8409_STEP_OUT_START, e);
    }
    e = hdx_stream_start(&d->hc, &d->out);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_OUT_START, e);
    d->out_on = 1;
    return 0;
}

HDX_API int cs8409_dev_out_stop(struct cs8409_dev *d)
{
    int e = 0;

    if (d->out_on)
        e = hdx_stream_stop(&d->hc, &d->out);
    d->out_on = 0;
    return e;
}

HDX_API int cs8409_dev_in_start(struct cs8409_dev *d)
{
    int e;

    if (!d->up || !d->in_ring.virt)
        return HDX_EIO;
    if (d->in_on)
        return 0;
    cs8409_clear_err(&d->codec);
    e = hdx_stream_setup(&d->hc, &d->in);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_IN_SETUP, e);
    e = cs8409_dmic_on(&d->codec, d->in.tag, d->in.fmt);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_IN_START, e);
    e = hdx_stream_start(&d->hc, &d->in);
    if (e)
        return cs8409_dev_fail(d, CS8409_STEP_IN_START, e);
    d->in_on = 1;
    return 0;
}

HDX_API int cs8409_dev_in_stop(struct cs8409_dev *d)
{
    int e = 0;

    if (d->in_on) {
        e = hdx_stream_stop(&d->hc, &d->in);
        cs8409_clear_err(&d->codec);
        cs8409_dmic_off(&d->codec);
    }
    d->in_on = 0;
    return e;
}

HDX_API void cs8409_dev_teardown(struct cs8409_dev *d)
{
    if (d->hc.cmd_up) {
        if (d->out.configured)
            hdx_stream_clear(&d->hc, &d->out);
        if (d->in.configured)
            hdx_stream_clear(&d->hc, &d->in);
        if (d->codec_ok)
            cs8409_shutdown(&d->codec);
    }
    if (d->hc.bar && hdx_r16(&d->hc, HDX_GCAP) != 0xffff)
        hdx_enter_reset(&d->hc);
    d->codec_ok = 0;
    d->up = d->out_on = d->in_on = 0;
}
