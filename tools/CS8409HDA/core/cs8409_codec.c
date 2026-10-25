/*
 * cs8409_codec.c: see cs8409_codec.h. Unity build only (needs snprintf from the host environment).
 */
#include "cs8409_codec.h"

#define cs_log(c, ...) do { \
    if ((c)->log) { char cs_lb_[200]; snprintf(cs_lb_, sizeof(cs_lb_), __VA_ARGS__); (c)->log((c)->ctx, cs_lb_); } \
} while (0)

struct cs8409_coef { uint8_t idx; uint16_t val; };
struct cs42l42_reg { uint16_t reg; uint8_t val; uint16_t delay_us; };

/* cs8409_cs42l42_hw_cfg (Linux), order kept: PLLs, ASP formats and clocks, DMIC, pads, GPIO hysteresis */
static const struct cs8409_coef cs8409_hw_cfg[] = {
    { CS8409_DEV_CFG1, 0xb008 },        /* +PLL1/2_EN, +I2C_EN */
    { CS8409_DEV_CFG2, 0x0002 },        /* ASP1/2_EN=0, ASP1_STP=1 */
    { CS8409_DEV_CFG3, 0x0a80 },        /* ASP1/2_BUS_IDLE=10, +GPIO_I2C */
    { CS8409_ASP1_A_TX_CTRL1, 0x0800 }, /* ASP1.A TX: LAP=0, LSZ=24 bits, LCS=0 */
    { CS8409_ASP1_A_TX_CTRL2, 0x0820 }, /* RAP=0, RSZ=24 bits, RCS=32 */
    { CS8409_ASP2_A_TX_CTRL1, 0x0800 }, /* ASP2.A TX: LAP=0, LSZ=24 bits, LCS=0 */
    { CS8409_ASP2_A_TX_CTRL2, 0x2800 }, /* RAP=1, RSZ=24 bits, RCS=0 */
    { CS8409_ASP1_A_RX_CTRL1, 0x0800 }, /* ASP1.A RX: LAP=0, LSZ=24 bits, LCS=0 */
    { CS8409_ASP1_A_RX_CTRL2, 0x0800 }, /* RAP=0, RSZ=24 bits, RCS=0 */
    { CS8409_ASP1_CLK_CTRL1, 0x8000 },  /* ASP1: LCHI=00h */
    { CS8409_ASP1_CLK_CTRL2, 0x28ff },  /* MC/SC_SRCSEL=PLL1, LCPR=FFh */
    { CS8409_ASP1_CLK_CTRL3, 0x0062 },  /* MCEN=0, FSD=011, SCPOL_IN/OUT=0, SCDIV=1:4 */
    { CS8409_ASP2_CLK_CTRL1, 0x801f },  /* ASP2: LCHI=1Fh */
    { CS8409_ASP2_CLK_CTRL2, 0x283f },  /* MC/SC_SRCSEL=PLL1, LCPR=3Fh */
    { CS8409_ASP2_CLK_CTRL3, 0x805c },  /* 5050=1, MCEN=0, FSD=010, SCPOL_IN/OUT=1, SCDIV=1:16 */
    { CS8409_DMIC_CFG, 0x0023 },        /* DMIC1_MO=10b, DMIC1/2_SR=1 */
    { CS8409_BEEP_CFG, 0x0000 },        /* ASP1/2_BEEP=0 */
    { CS8409_DEV_CFG2, 0x0062 },        /* ASP1/2_EN=1, ASP1_STP=1 */
    { CS8409_DEV_CFG1, 0x9008 },        /* -PLL2_EN */
    { CS8409_PRE_SCALE_ATTN2, 0x0000 }, /* TX2.A pre-scale attenuation 0 dB */
    { CS8409_PAD_CFG_SLW_RATE, 0xfc03 },/* ASP1/2_xxx_EN=1, ASP1/2_MCLK_EN=0, DMIC1_SCL_EN=1 */
    { CS8409_TEST_MODE, 0x9999 },       /* test mode on */
    { CS8409_GPIO_HYST, 0x0000 },       /* GPIO hysteresis 30 us */
    { CS8409_TEST_MODE, 0x0000 },       /* test mode off */
};

/* cs42l42_init_reg_seq (Linux); addresses checked against include/sound/cs42l42.h */
static const struct cs42l42_reg cs42l42_init_seq[] = {
    { 0x1010, 0xb0, 0 },    /* I2C_TIMEOUT */
    { 0x1d01, 0x00, 0 },    /* ADC_CTL */
    { 0x1d02, 0x06, 0 },
    { 0x1d03, 0x9f, 0 },    /* ADC_VOLUME */
    { 0x1107, 0x01, 0 },    /* OSC_SWITCH */
    { 0x1009, 0x02, 0 },    /* MCLK_CTL */
    { 0x1007, 0x03, 0 },    /* SRC_CTL */
    { 0x1201, 0x00, 0 },    /* MCLK_SRC_SEL */
    { 0x1208, 0x13, 0 },    /* ASP_FRM_CFG */
    { 0x1205, 0xff, 0 },    /* FSYNC_P_LOWER */
    { 0x1206, 0x00, 0 },    /* FSYNC_P_UPPER */
    { 0x1207, 0x20, 0 },    /* ASP_CLK_CFG */
    { 0x1202, 0x0d, 0 },    /* SPDIF_CLK_CFG */
    { 0x2a02, 0x02, 0 },    /* ASP_RX_DAI0_CH1_AP_RES */
    { 0x2a03, 0x00, 0 },
    { 0x2a04, 0x00, 0 },
    { 0x2a05, 0x02, 0 },    /* CH2 */
    { 0x2a06, 0x00, 0 },
    { 0x2a07, 0x20, 0 },
    { 0x2a08, 0x02, 0 },    /* CH3 */
    { 0x2a09, 0x00, 0 },
    { 0x2a0a, 0x80, 0 },
    { 0x2a0b, 0x02, 0 },    /* CH4 */
    { 0x2a0c, 0x00, 0 },
    { 0x2a0d, 0xa0, 0 },
    { 0x2a01, 0x0c, 0 },    /* ASP_RX_DAI0_EN */
    { 0x2902, 0x01, 0 },    /* ASP_TX_CH_EN */
    { 0x2903, 0x02, 0 },    /* ASP_TX_CH_AP_RES */
    { 0x2904, 0x00, 0 },    /* ASP_TX_CH1_BIT_MSB */
    { 0x2905, 0x00, 0 },    /* ASP_TX_CH1_BIT_LSB */
    { 0x2901, 0x01, 0 },    /* ASP_TX_SZ_EN */
    { 0x1101, 0x0a, 0 },    /* PWR_CTL1 */
    { 0x1102, 0x84, 0 },    /* PWR_CTL2 */
    { 0x2301, 0x3f, 0 },    /* MIXER_CHA_VOL: muted */
    { 0x2303, 0x3f, 0 },    /* MIXER_CHB_VOL */
    { 0x2302, 0x3f, 0 },    /* MIXER_ADC_VOL */
    { 0x2001, 0x0d, 0 },    /* HP_CTL */
    { 0x1b75, 0xb6, 0 },    /* MIC_DET_CTL1 */
    { 0x1b73, 0xc2, 0 },    /* TIPSENSE_CTL */
    { 0x1129, 0x01, 0 },    /* HS_CLAMP_DISABLE */
    { 0x1121, 0xf3, 0 },    /* HS_SWITCH_CTL */
    { 0x1103, 0x20, 0 },    /* PWR_CTL3 */
    { 0x1105, 0x00, 0 },    /* RSENSE_CTL2 */
    { 0x1112, 0x00, 0 },    /* RSENSE_CTL3 */
    { 0x1113, 0x80, 0 },    /* TSENSE_CTL */
    { 0x1c03, 0xc0, 0 },    /* HS_BIAS_CTL */
    { 0x1101, 0x02, 10000 },/* PWR_CTL1, then 10 ms */
    { 0x1316, 0xff, 0 },    /* ADC_OVFL_INT_MASK */
    { 0x1317, 0xff, 0 },    /* MIXER_INT_MASK */
    { 0x1318, 0xff, 0 },    /* SRC_INT_MASK */
    { 0x1319, 0xff, 0 },    /* ASP_RX_INT_MASK */
    { 0x131a, 0xff, 0 },    /* ASP_TX_INT_MASK */
    { 0x131b, 0xff, 0 },    /* CODEC_INT_MASK */
    { 0x131c, 0xff, 0 },    /* SRCPL_INT_MASK */
    { 0x131e, 0xff, 0 },    /* VPMON_INT_MASK */
    { 0x131f, 0xff, 0 },    /* PLL_LOCK_INT_MASK */
    { 0x1320, 0xff, 0 },    /* TSRS_PLUG_INT_MASK */
    { 0x1b79, 0xff, 0 },    /* DET_INT1_MASK */
    { 0x1b7a, 0xff, 0 },    /* DET_INT2_MASK */
};

/* cs42l42_suspend() power-down sequence */
static const struct cs42l42_reg cs42l42_pdn_seq[] = {
    { 0x1f06, 0x02, 0 },    /* DAC_CTL2 */
    { 0x1129, 0x00, 0 },    /* HS_CLAMP_DISABLE */
    { 0x2301, 0x3f, 0 },    /* MIXER_CHA_VOL */
    { 0x2302, 0x3f, 0 },    /* MIXER_ADC_VOL */
    { 0x2303, 0x3f, 0 },    /* MIXER_CHB_VOL */
    { 0x2001, 0x0d, 0 },    /* HP_CTL */
    { 0x2a01, 0x00, 0 },    /* ASP_RX_DAI0_EN */
    { 0x1207, 0x00, 0 },    /* ASP_CLK_CFG */
    { 0x1101, 0xfe, 0 },    /* PWR_CTL1 */
    { 0x1102, 0x8c, 0 },    /* PWR_CTL2 */
    { 0x1101, 0xff, 0 },    /* PWR_CTL1 */
};

static void cs_delay(struct cs8409 *c, uint32_t us)
{
    if (c->delay_us)
        c->delay_us(c->ctx, us);
}

static int cs_v(struct cs8409 *c, uint32_t nid, uint32_t verb, uint32_t parm, uint32_t *res)
{
    uint32_t cmd = (c->addr << 28) | ((nid & 0x7f) << 20) | (verb << 8) | parm, r = 0;
    int e;

    if (c->err) {                   /* fail fast: the link or the codec stopped answering */
        if (res)
            *res = 0;
        return c->err;
    }
    e = c->verb(c->ctx, cmd, &r);
    if (e)
        c->err = e;
    if (res)
        *res = e ? 0 : r;
    return e;
}

static void cs_w(struct cs8409 *c, uint32_t nid, uint32_t verb, uint32_t parm)
{
    cs_v(c, nid, verb, parm, 0);
}

static uint32_t cs_r(struct cs8409 *c, uint32_t nid, uint32_t verb, uint32_t parm)
{
    uint32_t r = 0;
    cs_v(c, nid, verb, parm, &r);
    return r;
}

HDX_API void cs8409_clear_err(struct cs8409 *c)
{
    c->err = 0;
}

HDX_API uint32_t cs8409_coef_get(struct cs8409 *c, uint32_t idx)
{
    cs_w(c, CS8409_NID_VPW, CSV_SET_COEF_INDEX, idx);
    return cs_r(c, CS8409_NID_VPW, CSV_GET_PROC_COEF, 0);
}

HDX_API void cs8409_coef_set(struct cs8409 *c, uint32_t idx, uint32_t val)
{
    cs_w(c, CS8409_NID_VPW, CSV_SET_COEF_INDEX, idx);
    cs_w(c, CS8409_NID_VPW, CSV_SET_PROC_COEF, val & 0xffff);
}

static void cs_gpio(struct cs8409 *c, uint32_t data)
{
    c->gpio_data = data & 0xff;
    cs_w(c, CS8409_NID_AFG, CSV_SET_GPIO_DATA, c->gpio_data);
}

HDX_API int cs8409_probe(struct cs8409 *c)
{
    c->err = 0;
    c->vendor = cs_r(c, 0x00, CSV_GET_PARAMETER, 0x00);
    c->rev = cs_r(c, 0x00, CSV_GET_PARAMETER, 0x02);
    c->ssid = cs_r(c, CS8409_NID_AFG, CSV_GET_SUBSYSTEM_ID, 0);
    if (c->err)
        return c->err;
    return c->vendor == CS8409_VENDOR_ID ? 0 : -2;
}

static int cs_afg_power(struct cs8409 *c, uint32_t d)
{
    uint32_t i, st = 0;

    cs_w(c, CS8409_NID_AFG, CSV_SET_POWER_STATE, d);
    for (i = 0; i < 100; i++) {
        st = cs_r(c, CS8409_NID_AFG, CSV_GET_POWER_STATE, 0);
        if (c->err)
            return c->err;
        if (((st >> 4) & 0xf) == d)
            return 0;
        cs_delay(c, 1000);
    }
    cs_log(c, "AFG power state D%u not reached (%08x)", d, st);
    return -1;
}

/* ---- CS42L42 over the CS8409 I2C master (cs8409_i2c_* in Linux) */
static int cs_i2c_wait(struct cs8409 *c)
{
    uint32_t i;

    /* Linux reads I2C_STS right away, then every 2 ms; the status reads 0 until the transfer is done (~1.8 ms
     * at 100 kHz), then 0x38. Poll every 100 us, 20 ms at most. */
    for (i = 0; i < 200; i++) {
        uint32_t st = cs8409_coef_get(c, CS8409_I2C_STS);
        if (c->err)
            return c->err;
        if (st & 0x18)
            return 0;
        cs_delay(c, 100);
    }
    c->i2c_errors++;
    return -1;
}

static void cs_i2c_clock(struct cs8409 *c, int on)
{
    uint32_t v = cs8409_coef_get(c, CS8409_DEV_CFG1);
    cs8409_coef_set(c, CS8409_DEV_CFG1, on ? (v | 0x8) : (v & ~0x8u));
}

static int cs_i2c_page(struct cs8409 *c, uint32_t reg)
{
    if (c->i2c_page == (int)(reg >> 8))
        return 0;
    cs8409_coef_set(c, CS8409_I2C_QWRITE, reg >> 8);
    if (cs_i2c_wait(c)) {
        c->i2c_page = -1;
        return -1;
    }
    c->i2c_page = (int)(reg >> 8);
    return 0;
}

HDX_API int cs42l42_write(struct cs8409 *c, uint32_t reg, uint32_t val)
{
    c->i2c_ops++;
    if (cs_i2c_page(c, reg))
        return -1;
    cs8409_coef_set(c, CS8409_I2C_QWRITE, ((reg & 0xff) << 8) | (val & 0xff));
    return cs_i2c_wait(c);
}

HDX_API int cs42l42_read(struct cs8409 *c, uint32_t reg)
{
    c->i2c_ops++;
    if (cs_i2c_page(c, reg))
        return -1;
    cs8409_coef_set(c, CS8409_I2C_QREAD, (reg & 0xff) << 8);
    if (cs_i2c_wait(c))
        return -1;
    return (int)(cs8409_coef_get(c, CS8409_I2C_QREAD) & 0xff);
}

static int cs42l42_seq(struct cs8409 *c, const struct cs42l42_reg *s, uint32_t n)
{
    uint32_t i;
    int bad = 0;

    for (i = 0; i < n; i++) {
        if (cs42l42_write(c, s[i].reg, s[i].val))
            bad++;
        if (s[i].delay_us)
            cs_delay(c, s[i].delay_us);
    }
    return bad;
}

/* cs42l42_resume() + cs42l42_enable_jack_detect() */
static int cs42l42_up(struct cs8409 *c)
{
    int id0, id1, id2, hp, bad;

    cs_gpio(c, c->gpio_data | CS8409_GPIO_CS42L42_RST);
    cs_delay(c, 12000);
    c->i2c_page = -1;
    cs8409_coef_set(c, CS8409_I2C_ADDR, CS42L42_I2C_ADDR);
    cs_i2c_clock(c, 1);
    id0 = cs42l42_read(c, CS42L42_DEVID_AB);
    id1 = cs42l42_read(c, CS42L42_DEVID_AB + 1);
    id2 = cs42l42_read(c, CS42L42_DEVID_AB + 2);
    c->cs42l42_id = (uint32_t)((id0 & 0xff) << 12 | (id1 & 0xff) << 4 | ((id2 & 0xff) >> 4));
    if (id0 < 0 || id1 < 0 || id2 < 0 || c->cs42l42_id != 0x42a42) {
        cs_log(c, "CS42L42 not found (id %d %d %d)", id0, id1, id2);
        return -1;
    }
    bad = cs42l42_seq(c, cs42l42_init_seq, sizeof(cs42l42_init_seq) / sizeof(cs42l42_init_seq[0]));
    cs42l42_read(c, 0x1308);        /* clear interrupts: CODEC_STATUS, DET_INT_STATUS1/2, TSRS_PLUG_STATUS */
    cs42l42_read(c, 0x1309);
    cs42l42_read(c, 0x130a);
    cs42l42_read(c, 0x130f);
    hp = cs42l42_read(c, CS42L42_HP_CTL);
    if (hp >= 0)
        cs42l42_write(c, CS42L42_HP_CTL, (uint32_t)hp & ~0x0cu);    /* unmute analog A/B, full scale 0 dB */
    cs42l42_write(c, 0x1b70, 0x20); /* HSBIAS_SC_AUTOCTL = hsbias_hiz */
    cs42l42_write(c, 0x1b71, 0xc1); /* WAKE_CTL: clear WAKE# */
    cs_delay(c, 2500);
    cs42l42_write(c, 0x1b71, 0xc0);
    cs42l42_read(c, 0x130f);
    cs42l42_write(c, 0x1320, 0xf3); /* TSRS_PLUG_INT_MASK: tip sense interrupts on */
    c->cs42l42_on = 1;
    if (bad)
        cs_log(c, "CS42L42 init: %d register writes failed", bad);
    return bad ? -1 : 0;
}

/* cs42l42_suspend() */
static void cs42l42_down(struct cs8409 *c)
{
    uint32_t i;
    int st = 0;

    cs_i2c_clock(c, 1);
    cs42l42_seq(c, cs42l42_pdn_seq, sizeof(cs42l42_pdn_seq) / sizeof(cs42l42_pdn_seq[0]));
    for (i = 0; i < 125; i++) {     /* PDN_DONE, 250 ms at most */
        st = cs42l42_read(c, CS42L42_CODEC_STATUS);
        if (st < 0 || (st & 1))
            break;
        cs_delay(c, 2000);
    }
    if (st >= 0 && !(st & 1))
        cs_log(c, "CS42L42: timeout waiting for PDN_DONE");
    cs42l42_write(c, 0x1102, 0x9c); /* PWR_CTL2 */
    c->cs42l42_on = 0;
    c->i2c_page = -1;
    cs_gpio(c, c->gpio_data & ~(uint32_t)CS8409_GPIO_CS42L42_RST);
}

HDX_API int cs8409_init(struct cs8409 *c, uint32_t flags)
{
    uint32_t i;
    int ret;

    c->err = 0;
    c->i2c_page = -1;
    c->cs42l42_on = 0;
    ret = cs_afg_power(c, 0);
    if (ret)
        return ret;
    /* unused ADCs off (Linux power_save_node) */
    cs_w(c, CS8409_NID_ADC_DMIC, CSV_SET_POWER_STATE, 3);
    cs_w(c, 0x23, CSV_SET_POWER_STATE, 3);
    /* cs8409_cs42l42_init_verbs */
    cs_w(c, CS8409_NID_AFG, CSV_SET_GPIO_WAKE_MASK, 0x18);
    cs_w(c, CS8409_NID_VPW, CSV_SET_PROC_STATE, 0x01);
    cs8409_coef_set(c, CS8409_DEV_CFG3, 0x0080);    /* GPIO 6,7 in I2C mode */
    cs8409_coef_set(c, CS8409_I2C_CTRL, 0x0200);    /* 100 kHz */
    /* pins (generic init) */
    cs_w(c, CS8409_NID_PIN_SPK, CSV_SET_PIN_WIDGET_CONTROL, 0x40);
    cs_w(c, CS8409_NID_PIN_HP, CSV_SET_PIN_WIDGET_CONTROL, 0x40);
    cs_w(c, CS8409_NID_PIN_DMIC, CSV_SET_PIN_WIDGET_CONTROL, 0x20);
    cs_w(c, CS8409_NID_PIN_HSMIC, CSV_SET_PIN_WIDGET_CONTROL, 0x20);
    /* cs8409_cs42l42_hw_init: GPIO 1,5 outputs, speaker amplifier on, CS42L42 still in reset */
    cs_w(c, CS8409_NID_AFG, CSV_SET_GPIO_MASK, 0x3f);
    cs_w(c, CS8409_NID_AFG, CSV_SET_GPIO_DIRECTION, CS8409_GPIO_SPK_EN | CS8409_GPIO_CS42L42_RST);
    cs_gpio(c, CS8409_GPIO_SPK_EN);
    for (i = 0; i < sizeof(cs8409_hw_cfg) / sizeof(cs8409_hw_cfg[0]); i++)
        cs8409_coef_set(c, cs8409_hw_cfg[i].idx, cs8409_hw_cfg[i].val);
    if (c->err)
        return c->err;
    if (flags & CS8409_F_CS42L42)
        cs42l42_up(c);              /* failure only costs the headset */
    else
        cs_i2c_clock(c, 0);
    return c->err;
}

HDX_API int cs8409_stream_on(struct cs8409 *c, uint32_t nid, uint8_t tag, uint16_t fmt)
{
    cs_w(c, nid, CSV_SET_CHANNEL_STREAMID, (uint32_t)(tag & 0xf) << 4);
    cs_delay(c, 1000);              /* Linux: msleep(1) between stream id and format */
    cs_w(c, nid, CSV_SET_STREAM_FORMAT, fmt);
    return c->err;
}

HDX_API int cs8409_stream_off(struct cs8409 *c, uint32_t nid)
{
    cs_w(c, nid, CSV_SET_CHANNEL_STREAMID, 0);
    cs_w(c, nid, CSV_SET_STREAM_FORMAT, 0);
    return c->err;
}

HDX_API int cs8409_speaker(struct cs8409 *c, int on)
{
    cs_gpio(c, on ? (c->gpio_data | CS8409_GPIO_SPK_EN) : (c->gpio_data & ~(uint32_t)CS8409_GPIO_SPK_EN));
    cs_w(c, CS8409_NID_PIN_SPK, CSV_SET_PIN_WIDGET_CONTROL, on ? 0x40 : 0x00);
    return c->err;
}

/* DMIC1 capture through ADC 0x22 (Linux trace-rec: pin 0x44 IN, boost 2 = +20 dB, D0, stream). The ADC gain is
 * 0x33 = 0 dB (Amp-In caps offset 0x33, 1 dB steps): PipeWire had raised it to 0x3f (+12 dB), and the XeSpeakers
 * plug-in applies its own input gain (default +12 dB) on top. */
HDX_API int cs8409_dmic_on(struct cs8409 *c, uint8_t tag, uint16_t fmt)
{
    uint32_t i, st;

    cs_w(c, CS8409_NID_PIN_DMIC, CSV_SET_PIN_WIDGET_CONTROL, 0x20);
    cs_w(c, CS8409_NID_PIN_DMIC, CSV_SET_AMP_GAIN_MUTE, 0x5002);    /* input amp R, boost step 2 */
    cs_w(c, CS8409_NID_PIN_DMIC, CSV_SET_AMP_GAIN_MUTE, 0x6002);    /* input amp L */
    cs_w(c, CS8409_NID_ADC_DMIC, CSV_SET_AMP_GAIN_MUTE, 0x5033);    /* ADC input amp R, 0 dB, unmuted */
    cs_w(c, CS8409_NID_ADC_DMIC, CSV_SET_AMP_GAIN_MUTE, 0x6033);
    cs_w(c, CS8409_NID_ADC_DMIC, CSV_SET_POWER_STATE, 0);
    for (i = 0; i < 20; i++) {
        st = cs_r(c, CS8409_NID_ADC_DMIC, CSV_GET_POWER_STATE, 0);
        if (c->err || ((st >> 4) & 0xf) == 0)
            break;
        cs_delay(c, 1000);
    }
    return cs8409_stream_on(c, CS8409_NID_ADC_DMIC, tag, fmt);
}

HDX_API int cs8409_dmic_off(struct cs8409 *c)
{
    cs8409_stream_off(c, CS8409_NID_ADC_DMIC);
    cs_w(c, CS8409_NID_ADC_DMIC, CSV_SET_POWER_STATE, 3);
    return c->err;
}

/* cs8409_cs42l42_suspend() + snd_hda_shutup_pins() + converters off + AFG D3. Starts with a clean error state;
 * the first transport error stops the rest (the codec is then unreachable anyway, and the link reset that
 * follows in cs8409_dev_teardown turns everything off). */
HDX_API int cs8409_shutdown(struct cs8409 *c)
{
    c->err = 0;
    cs_w(c, CS8409_NID_AFG, CSV_SET_GPIO_UNSOL_MASK, 0);
    cs_w(c, CS8409_NID_AFG, CSV_SET_UNSOLICITED_ENABLE, 0);
    if (c->cs42l42_on)
        cs42l42_down(c);
    cs_i2c_clock(c, 0);
    cs_w(c, CS8409_NID_PIN_HP, CSV_SET_PIN_WIDGET_CONTROL, 0);
    cs_w(c, CS8409_NID_PIN_SPK, CSV_SET_PIN_WIDGET_CONTROL, 0);
    cs_w(c, CS8409_NID_PIN_HSMIC, CSV_SET_PIN_WIDGET_CONTROL, 0);
    cs_w(c, CS8409_NID_PIN_DMIC, CSV_SET_PIN_WIDGET_CONTROL, 0);
    cs8409_stream_off(c, CS8409_NID_DAC_SPK);
    cs8409_stream_off(c, CS8409_NID_DAC_HP);
    cs8409_stream_off(c, CS8409_NID_ADC_DMIC);
    cs_gpio(c, 0);                  /* speaker amplifier off, CS42L42 in reset */
    cs_w(c, CS8409_NID_AFG, CSV_SET_POWER_STATE, 3);
    cs_w(c, CS8409_NID_ADC_DMIC, CSV_SET_POWER_STATE, 3);
    cs_w(c, 0x23, CSV_SET_POWER_STATE, 3);
    return c->err;
}

HDX_API void cs8409_dump(struct cs8409 *c)
{
    static const uint8_t idx[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x19, 0x1a,
                                   0x29, 0x2a, 0x39, 0x3a, 0x59, 0x5b, 0x5c, 0x68, 0x82 };
    char b[256];
    uint32_t i, n = 0;

    cs_log(c, "codec vendor %08x ssid %08x rev %08x | AFG power %08x | GPIO mask %02x dir %02x data %02x",
           c->vendor, c->ssid, c->rev, cs_r(c, CS8409_NID_AFG, CSV_GET_POWER_STATE, 0),
           cs_r(c, CS8409_NID_AFG, CSV_GET_GPIO_MASK, 0), cs_r(c, CS8409_NID_AFG, CSV_GET_GPIO_DIRECTION, 0),
           cs_r(c, CS8409_NID_AFG, CSV_GET_GPIO_DATA, 0));
    cs_log(c, "pins 24 %02x 2c %02x 34 %02x 44 %02x | conv 0a %02x fmt %04x | 02 %02x fmt %04x | 22 %02x fmt %04x D%u",
           cs_r(c, CS8409_NID_PIN_HP, CSV_GET_PIN_WIDGET_CONTROL, 0),
           cs_r(c, CS8409_NID_PIN_SPK, CSV_GET_PIN_WIDGET_CONTROL, 0),
           cs_r(c, CS8409_NID_PIN_HSMIC, CSV_GET_PIN_WIDGET_CONTROL, 0),
           cs_r(c, CS8409_NID_PIN_DMIC, CSV_GET_PIN_WIDGET_CONTROL, 0),
           cs_r(c, CS8409_NID_DAC_SPK, CSV_GET_CONV, 0), cs_r(c, CS8409_NID_DAC_SPK, CSV_GET_STREAM_FORMAT, 0),
           cs_r(c, CS8409_NID_DAC_HP, CSV_GET_CONV, 0), cs_r(c, CS8409_NID_DAC_HP, CSV_GET_STREAM_FORMAT, 0),
           cs_r(c, CS8409_NID_ADC_DMIC, CSV_GET_CONV, 0), cs_r(c, CS8409_NID_ADC_DMIC, CSV_GET_STREAM_FORMAT, 0),
           (cs_r(c, CS8409_NID_ADC_DMIC, CSV_GET_POWER_STATE, 0) >> 4) & 0xf);
    b[0] = 0;
    for (i = 0; i < sizeof(idx) && n < sizeof(b) - 16; i++)
        n += (uint32_t)snprintf(b + n, sizeof(b) - n, "%s%02x=%04x", i ? " " : "coef ", idx[i],
                                cs8409_coef_get(c, idx[i]) & 0xffff);
    if (c->log)
        c->log(c->ctx, b);
    cs_log(c, "CS42L42 %s id %05x i2c ops %u errors %u, transport err %d", c->cs42l42_on ? "on" : "off",
           c->cs42l42_id, c->i2c_ops, c->i2c_errors, c->err);
}
