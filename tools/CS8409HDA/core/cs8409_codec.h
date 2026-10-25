/*
 * cs8409_codec.h: programming of the Cirrus Logic CS8409 HDA bridge on the Dell Vostro 3520 ("Warlock MLK",
 * subsystem 1028:0B94): speakers on ASP2 (TI amplifier, enable = GPIO1), headset on ASP1 through a CS42L42
 * (reset = GPIO5, interrupt = GPIO4, I2C tunnelled through the vendor widget 0x47 coefficients), DMIC on DMIC1.
 * OS independent: the host provides a verb transport. Unity build (include cs8409_codec.c from the host source).
 *
 * Every sequence reproduces what the Linux driver (sound/hda/codecs/cirrus/cs8409*.c) sends on this machine, as
 * recorded in tools/CS8409HDA/ref/trace-play.txt and trace-rec.txt.
 */
#ifndef CS8409HDA_CS8409_CODEC_H
#define CS8409HDA_CS8409_CODEC_H

#if defined(__linux__) && defined(__KERNEL__)
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#ifndef HDX_API
#define HDX_API static __attribute__((unused))
#endif

#define CS8409_VENDOR_ID        0x10138409u
#define CS8409_SSID_WARLOCK_MLK 0x10280b94u

/* widgets */
#define CS8409_NID_AFG          0x01
#define CS8409_NID_DAC_HP       0x02    /* ASP1 TX A -> CS42L42 headphones */
#define CS8409_NID_DAC_SPK      0x0a    /* ASP2 TX A -> speaker amplifier */
#define CS8409_NID_ADC_HSMIC    0x12    /* ASP1 RX A <- CS42L42 headset mic */
#define CS8409_NID_ADC_DMIC     0x22    /* DMIC1 */
#define CS8409_NID_PIN_HP       0x24
#define CS8409_NID_PIN_SPK      0x2c
#define CS8409_NID_PIN_HSMIC    0x34
#define CS8409_NID_PIN_DMIC     0x44
#define CS8409_NID_VPW          0x47    /* vendor processing widget: coefficients */

/* GPIOs */
#define CS8409_GPIO_SPK_EN      0x02    /* GPIO1: speaker amplifier enable (Warlock) */
#define CS8409_GPIO_CS42L42_INT 0x10    /* GPIO4 */
#define CS8409_GPIO_CS42L42_RST 0x20    /* GPIO5: 1 = out of reset */

/* flags for cs8409_init */
#define CS8409_F_CS42L42        0x01    /* bring the CS42L42 (headset) out of reset and initialise it */

/* HDA verbs (Linux AC_VERB_*): cmd = addr << 28 | nid << 20 | verb << 8 | payload */
#define CSV_GET_PARAMETER           0xf00
#define CSV_GET_POWER_STATE         0xf05
#define CSV_GET_CONV                0xf06
#define CSV_GET_PIN_WIDGET_CONTROL  0xf07
#define CSV_GET_GPIO_DATA           0xf15
#define CSV_GET_GPIO_MASK           0xf16
#define CSV_GET_GPIO_DIRECTION      0xf17
#define CSV_GET_SUBSYSTEM_ID        0xf20
#define CSV_GET_STREAM_FORMAT       0xa00
#define CSV_GET_AMP_GAIN_MUTE       0xb00
#define CSV_GET_PROC_COEF           0xc00
#define CSV_SET_STREAM_FORMAT       0x200
#define CSV_SET_AMP_GAIN_MUTE       0x300
#define CSV_SET_PROC_COEF           0x400
#define CSV_SET_COEF_INDEX          0x500
#define CSV_SET_PROC_STATE          0x703
#define CSV_SET_POWER_STATE         0x705
#define CSV_SET_CHANNEL_STREAMID    0x706
#define CSV_SET_PIN_WIDGET_CONTROL  0x707
#define CSV_SET_UNSOLICITED_ENABLE  0x708
#define CSV_SET_GPIO_DATA           0x715
#define CSV_SET_GPIO_MASK           0x716
#define CSV_SET_GPIO_DIRECTION      0x717
#define CSV_SET_GPIO_WAKE_MASK      0x718
#define CSV_SET_GPIO_UNSOL_MASK     0x719

/* CS8409 coefficient indexes (enum cs8409_coefficient_index_registers) */
#define CS8409_DEV_CFG1             0x00
#define CS8409_DEV_CFG2             0x01
#define CS8409_DEV_CFG3             0x02
#define CS8409_ASP1_CLK_CTRL1       0x03
#define CS8409_ASP1_CLK_CTRL2       0x04
#define CS8409_ASP1_CLK_CTRL3       0x05
#define CS8409_ASP2_CLK_CTRL1       0x06
#define CS8409_ASP2_CLK_CTRL2       0x07
#define CS8409_ASP2_CLK_CTRL3       0x08
#define CS8409_DMIC_CFG             0x09
#define CS8409_BEEP_CFG             0x0a
#define CS8409_ASP1_A_TX_CTRL1      0x19
#define CS8409_ASP1_A_TX_CTRL2      0x1a
#define CS8409_ASP2_A_TX_CTRL1      0x29
#define CS8409_ASP2_A_TX_CTRL2      0x2a
#define CS8409_ASP1_A_RX_CTRL1      0x39
#define CS8409_ASP1_A_RX_CTRL2      0x3a
#define CS8409_I2C_ADDR             0x59
#define CS8409_I2C_CTRL             0x5b
#define CS8409_I2C_STS              0x5c
#define CS8409_I2C_QWRITE           0x5d
#define CS8409_I2C_QREAD            0x5e
#define CS8409_PRE_SCALE_ATTN2      0x68
#define CS8409_PAD_CFG_SLW_RATE     0x82
#define CS8409_TEST_MODE            0xc0
#define CS8409_GPIO_HYST            0xc5

#define CS42L42_I2C_ADDR            0x90    /* 0x48 << 1 */
#define CS42L42_DEVID_AB            0x1001  /* reads 0x42 0xa4 0x2x: chip id 0x42a42 */
#define CS42L42_HP_CTL              0x2001
#define CS42L42_MIXER_CHA_VOL       0x2301
#define CS42L42_MIXER_CHB_VOL       0x2303
#define CS42L42_CODEC_STATUS        0x1308
#define CS42L42_TSRS_PLUG_STATUS    0x130f

struct cs8409 {
    void *ctx;
    int (*verb)(void *ctx, uint32_t cmd, uint32_t *res);  /* 0 = response received */
    void (*delay_us)(void *ctx, uint32_t us);
    void (*log)(void *ctx, const char *line);             /* optional */
    uint32_t addr;          /* codec address on the link */
    uint32_t vendor, ssid, rev;
    uint32_t gpio_data;     /* last value written with SET_GPIO_DATA */
    int err;                /* first transport error since the last cs8409_clear_err */
    int i2c_page;           /* CS42L42 page register cache, -1 = unknown */
    uint32_t i2c_ops, i2c_errors;
    int cs42l42_on;
    uint32_t cs42l42_id;
};

HDX_API int cs8409_probe(struct cs8409 *c);                 /* vendor/subsystem/revision, 0 = CS8409 */
HDX_API int cs8409_init(struct cs8409 *c, uint32_t flags);   /* AFG D0 + full bridge init (resume path) */
HDX_API int cs8409_stream_on(struct cs8409 *c, uint32_t nid, uint8_t tag, uint16_t fmt);
HDX_API int cs8409_stream_off(struct cs8409 *c, uint32_t nid);
HDX_API int cs8409_speaker(struct cs8409 *c, int on);       /* amplifier GPIO + pin control */
HDX_API int cs8409_dmic_on(struct cs8409 *c, uint8_t tag, uint16_t fmt);
HDX_API int cs8409_dmic_off(struct cs8409 *c);
HDX_API int cs8409_shutdown(struct cs8409 *c);              /* everything off, AFG D3 */
HDX_API uint32_t cs8409_coef_get(struct cs8409 *c, uint32_t idx);
HDX_API void cs8409_coef_set(struct cs8409 *c, uint32_t idx, uint32_t val);
HDX_API int cs42l42_read(struct cs8409 *c, uint32_t reg);   /* < 0 = error */
HDX_API int cs42l42_write(struct cs8409 *c, uint32_t reg, uint32_t val);
HDX_API void cs8409_dump(struct cs8409 *c);
HDX_API void cs8409_clear_err(struct cs8409 *c);

#endif
