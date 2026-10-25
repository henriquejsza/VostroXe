// SPDX-License-Identifier: GPL-2.0
/*
 * cs8409test: Linux test harness for the CS8409HDA core (tools/CS8409HDA/core), development only.
 *
 * It runs exactly the controller + codec code the macOS kext runs, on the Dell Vostro 3520's HDA controller
 * (8086:51C8), so the code can be validated without rebooting into macOS. It has no PCI id table: it only binds
 * to a device whose driver_override is "cs8409test" (linux/run-harness.sh moves the controller from snd_hda_intel
 * to this driver and back). DMA goes through the DMA API (IOMMU-mapped coherent buffers). No interrupts.
 *
 * debugfs /sys/kernel/debug/cs8409test:
 *   ctl    (w)  up [hp] [anyssid] | play | stop | rec | recstop | rate | pos | dump | trace | down | verb <hex>
 *   log    (r)  text log of every command
 *   oring  (rw) the 64 KiB playback ring (S32_LE stereo 48 kHz), what the HAL plug-in writes on macOS
 *   iring  (r)  the 64 KiB capture ring, oldest frame first, as captured at 'recstop'
 */
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/dma-mapping.h>
#include <linux/debugfs.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/ktime.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>

#include "hdx_core.c"
#include "cs8409_codec.c"
#include "cs8409_dev.c"

#define T_LOG_BYTES (512 * 1024)

struct t_buf {
	void *virt;
	dma_addr_t bus;
	size_t size;
};

static struct t_state {
	struct pci_dev *pdev;
	void __iomem *bar;
	struct mutex lock;
	struct cs8409_dev dev;
	struct t_buf cmd, oring, obdl, iring, ibdl;
	char *log;
	size_t loglen;
	u8 *isnap;
	struct dentry *dir;
	u64 t0;
} T;

static void t_logline(void *ctx, const char *line)
{
	u64 us = (ktime_get_ns() - T.t0) / 1000;
	size_t n = strlen(line);
	char pre[32];
	int pn = snprintf(pre, sizeof(pre), "%7llu.%03llu  ", us / 1000, us % 1000);

	if (!T.log || T.loglen + pn + n + 2 >= T_LOG_BYTES)
		return;
	memcpy(T.log + T.loglen, pre, pn);
	T.loglen += pn;
	memcpy(T.log + T.loglen, line, n);
	T.loglen += n;
	T.log[T.loglen++] = '\n';
}

static __printf(1, 2) void t_log(const char *fmt, ...)
{
	char b[256];
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(b, sizeof(b), fmt, ap);
	va_end(ap);
	t_logline(NULL, b);
}

static void t_delay(void *ctx, u32 us)
{
	if (us >= 1000)
		usleep_range(us, us + us / 8 + 50);
	else if (us >= 20)
		usleep_range(us, us + 10);
	else
		udelay(us);
}

static u32 t_cfg_read(void *ctx, u32 off, unsigned int bytes)
{
	u8 b = 0;
	u16 w = 0;
	u32 d = 0;

	if (bytes == 1) {
		pci_read_config_byte(T.pdev, off, &b);
		return b;
	}
	if (bytes == 2) {
		pci_read_config_word(T.pdev, off, &w);
		return w;
	}
	pci_read_config_dword(T.pdev, off, &d);
	return d;
}

static void t_cfg_write(void *ctx, u32 off, u32 v, unsigned int bytes)
{
	if (bytes == 1)
		pci_write_config_byte(T.pdev, off, (u8)v);
	else if (bytes == 2)
		pci_write_config_word(T.pdev, off, (u16)v);
	else
		pci_write_config_dword(T.pdev, off, v);
}

static int t_alloc(struct t_buf *b, size_t size)
{
	b->virt = dma_alloc_coherent(&T.pdev->dev, size, &b->bus, GFP_KERNEL);
	if (!b->virt)
		return -ENOMEM;
	b->size = size;
	memset(b->virt, 0, size);
	return 0;
}

static void t_free(struct t_buf *b)
{
	if (b->virt)
		dma_free_coherent(&T.pdev->dev, b->size, b->virt, b->bus);
	b->virt = NULL;
}

static struct hdx_dma t_hdx(const struct t_buf *b)
{
	struct hdx_dma d;

	d.virt = b->virt;
	d.bus = b->bus;
	d.size = (uint32_t)b->size;
	return d;
}

/* DMA rate over ~1 s from DPIB deltas (the 64 KiB ring wraps every 171 ms, sample every 10 ms) */
static void t_rate(struct hdx_stream *s, const char *name)
{
	u32 prev = hdx_stream_dpib(&T.dev.hc, s), cur, lp;
	u64 moved = 0, t0 = ktime_get_ns(), t1;
	int i;

	for (i = 0; i < 100; i++) {
		msleep(10);
		cur = hdx_stream_dpib(&T.dev.hc, s);
		moved += (cur - prev) & (CS8409_RING_BYTES - 1);
		prev = cur;
	}
	t1 = ktime_get_ns();
	lp = hdx_stream_lpib(&T.dev.hc, s);
	t_log("rate %s: %llu bytes in %llu us = %llu B/s (expected 384000), DPIB %05x LPIB %05x CTL/STS %08x", name,
	      moved, (t1 - t0) / 1000, moved * 1000000000ull / (t1 - t0), cur, lp, hdx_stream_ctlsts(&T.dev.hc, s));
}

static void t_pos(struct hdx_stream *s, const char *name)
{
	int i;

	for (i = 0; i < 12; i++) {
		u64 t = ktime_get_ns();
		u32 dp = hdx_stream_dpib(&T.dev.hc, s), lp = hdx_stream_lpib(&T.dev.hc, s);

		t_log("pos %s t=%llu ns DPIB %05x LPIB %05x lead %d", name, t % 100000000ull, dp, lp,
		      (int)((dp - lp) & (CS8409_RING_BYTES - 1)));
		udelay(250);
	}
}

static void t_trace(void)
{
	struct hdx_ctrl *h = &T.dev.hc;
	u32 n = h->trace_pos < HDX_TRACE ? h->trace_pos : HDX_TRACE, i;

	for (i = h->trace_pos - n; i != h->trace_pos; i++)
		t_log("verb %08x -> %08x", h->trace_cmd[i % HDX_TRACE], h->trace_res[i % HDX_TRACE]);
}

static ssize_t t_ctl_write(struct file *f, const char __user *ubuf, size_t len, loff_t *ppos)
{
	char cmd[80];
	size_t n = min(len, sizeof(cmd) - 1);
	char *c;
	int e = 0;
	u64 t;

	if (copy_from_user(cmd, ubuf, n))
		return -EFAULT;
	cmd[n] = 0;
	c = strim(cmd);
	mutex_lock(&T.lock);
	if (!T.pdev) {
		mutex_unlock(&T.lock);
		return -ENODEV;
	}
	t = ktime_get_ns();
	t_log("> %s", c);
	if (!strncmp(c, "up", 2)) {
		if (T.dev.up || T.dev.hc.cmd_up)
			cs8409_dev_teardown(&T.dev);
		T.dev.flags = (strstr(c, "hp") ? CS8409_DEV_HEADSET : 0) | (strstr(c, "anyssid") ? CS8409_DEV_ANY_SSID : 0);
		e = cs8409_dev_bringup(&T.dev);
		t_log("up: %d (step %d) in %llu us, %u verbs, %u timeouts", e, T.dev.fail_step,
		      (ktime_get_ns() - t) / 1000, T.dev.hc.verbs, T.dev.hc.timeouts);
	} else if (!strcmp(c, "play")) {
		e = cs8409_dev_out_start(&T.dev);
		t_log("play: %d, SD%u FIFOS %u", e, T.dev.out.index, T.dev.out.fifos);
	} else if (!strcmp(c, "stop")) {
		e = cs8409_dev_out_stop(&T.dev);
		t_log("stop: %d", e);
	} else if (!strcmp(c, "rec")) {
		e = cs8409_dev_in_start(&T.dev);
		t_log("rec: %d, SD%u FIFOS %u", e, T.dev.in.index, T.dev.in.fifos);
	} else if (!strcmp(c, "recstop")) {
		u32 pos = hdx_stream_dpib(&T.dev.hc, &T.dev.in) & (CS8409_RING_BYTES - 1);

		e = cs8409_dev_in_stop(&T.dev);
		pos &= ~7u;     /* frame aligned */
		memcpy(T.isnap, (u8 *)T.iring.virt + pos, CS8409_RING_BYTES - pos);
		memcpy(T.isnap + CS8409_RING_BYTES - pos, T.iring.virt, pos);
		t_log("recstop: %d, capture DPIB was %05x", e, pos);
	} else if (!strcmp(c, "rate")) {
		if (T.dev.out_on)
			t_rate(&T.dev.out, "out");
		if (T.dev.in_on)
			t_rate(&T.dev.in, "in");
	} else if (!strcmp(c, "pos")) {
		if (T.dev.out_on)
			t_pos(&T.dev.out, "out");
		if (T.dev.in_on)
			t_pos(&T.dev.in, "in");
	} else if (!strcmp(c, "dump")) {
		hdx_dump(&T.dev.hc, T.dev.out.configured ? &T.dev.out : NULL, T.dev.in.configured ? &T.dev.in : NULL);
		if (T.dev.hc.cmd_up && T.dev.codec_ok) {
			cs8409_clear_err(&T.dev.codec);
			cs8409_dump(&T.dev.codec);
		}
	} else if (!strcmp(c, "trace")) {
		t_trace();
	} else if (!strcmp(c, "down")) {
		cs8409_dev_teardown(&T.dev);
		t_log("down: GCTL %08x", hdx_r32(&T.dev.hc, HDX_GCTL));
	} else if (!strncmp(c, "verb ", 5)) {
		u32 v, r = 0;

		e = kstrtou32(c + 5, 16, &v);
		if (!e)
			e = cs8409_dev_verb(&T.dev, v, &r);
		t_log("verb %08x -> %08x (%d)", v, r, e);
	} else {
		t_log("unknown command");
		e = -EINVAL;
	}
	mutex_unlock(&T.lock);
	return e == -EINVAL ? -EINVAL : (ssize_t)len;
}

static ssize_t t_log_read(struct file *f, char __user *ubuf, size_t len, loff_t *ppos)
{
	ssize_t r;

	mutex_lock(&T.lock);
	r = simple_read_from_buffer(ubuf, len, ppos, T.log, T.loglen);
	mutex_unlock(&T.lock);
	return r;
}

static ssize_t t_oring_read(struct file *f, char __user *ubuf, size_t len, loff_t *ppos)
{
	if (!T.oring.virt)
		return -ENODEV;
	return simple_read_from_buffer(ubuf, len, ppos, T.oring.virt, CS8409_RING_BYTES);
}

static ssize_t t_oring_write(struct file *f, const char __user *ubuf, size_t len, loff_t *ppos)
{
	if (!T.oring.virt)
		return -ENODEV;
	return simple_write_to_buffer(T.oring.virt, CS8409_RING_BYTES, ppos, ubuf, len);
}

static ssize_t t_iring_read(struct file *f, char __user *ubuf, size_t len, loff_t *ppos)
{
	return simple_read_from_buffer(ubuf, len, ppos, T.isnap, CS8409_RING_BYTES);
}

static const struct file_operations t_ctl_fops = { .owner = THIS_MODULE, .write = t_ctl_write };
static const struct file_operations t_log_fops = { .owner = THIS_MODULE, .read = t_log_read };
static const struct file_operations t_oring_fops = { .owner = THIS_MODULE, .read = t_oring_read,
						     .write = t_oring_write };
static const struct file_operations t_iring_fops = { .owner = THIS_MODULE, .read = t_iring_read };

static int t_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
	int e;

	if (pdev->vendor != 0x8086 || pdev->device != 0x51c8)
		return -ENODEV;
	if (T.pdev)
		return -EBUSY;
	e = pci_enable_device(pdev);
	if (e)
		return e;
	e = pci_request_regions(pdev, "cs8409test");
	if (e)
		goto err_disable;
	pci_set_master(pdev);
	e = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
	if (e)
		goto err_regions;
	T.bar = pci_iomap(pdev, 0, 0x4000);
	if (!T.bar) {
		e = -ENOMEM;
		goto err_regions;
	}
	T.pdev = pdev;
	e = t_alloc(&T.cmd, HDX_CMD_BYTES) ?: t_alloc(&T.oring, CS8409_RING_BYTES) ?:
	    t_alloc(&T.obdl, CS8409_BDL_BYTES) ?: t_alloc(&T.iring, CS8409_RING_BYTES) ?:
	    t_alloc(&T.ibdl, CS8409_BDL_BYTES);
	if (e)
		goto err_free;
	memset(&T.dev, 0, sizeof(T.dev));
	T.dev.hc.bar = (volatile uint8_t *)(__force void *)T.bar;
	T.dev.hc.os.ctx = &T;
	T.dev.hc.os.delay_us = t_delay;
	T.dev.hc.os.log = t_logline;
	T.dev.hc.os.cfg_read = t_cfg_read;
	T.dev.hc.os.cfg_write = t_cfg_write;
	T.dev.cmd_mem = t_hdx(&T.cmd);
	T.dev.out_ring = t_hdx(&T.oring);
	T.dev.out_bdl = t_hdx(&T.obdl);
	T.dev.in_ring = t_hdx(&T.iring);
	T.dev.in_bdl = t_hdx(&T.ibdl);
	t_log("bound to %s: BAR0 %pR, cmd %pad, out ring %pad, in ring %pad", pci_name(pdev), &pdev->resource[0],
	      &T.cmd.bus, &T.oring.bus, &T.iring.bus);
	return 0;

err_free:
	t_free(&T.ibdl);
	t_free(&T.iring);
	t_free(&T.obdl);
	t_free(&T.oring);
	t_free(&T.cmd);
	pci_iounmap(pdev, T.bar);
	T.pdev = NULL;
err_regions:
	pci_release_regions(pdev);
err_disable:
	pci_disable_device(pdev);
	return e;
}

static void t_remove(struct pci_dev *pdev)
{
	mutex_lock(&T.lock);
	if (T.dev.up || T.dev.hc.cmd_up)
		cs8409_dev_teardown(&T.dev);
	/* leave the link out of reset, as the BIOS does: snd_hda_intel parses the extended capabilities before its
	 * own reset and reads them as 0 otherwise ("Unknown capability 0") */
	hdx_w32(&T.dev.hc, HDX_GCTL, hdx_r32(&T.dev.hc, HDX_GCTL) | 1u);
	hdx_wait32(&T.dev.hc, HDX_GCTL, 1, 1, 100, 1000);
	t_log("unbound, GCTL %08x", hdx_r32(&T.dev.hc, HDX_GCTL));
	mutex_unlock(&T.lock);
	t_free(&T.ibdl);
	t_free(&T.iring);
	t_free(&T.obdl);
	t_free(&T.oring);
	t_free(&T.cmd);
	pci_iounmap(pdev, T.bar);
	pci_release_regions(pdev);
	pci_disable_device(pdev);
	T.pdev = NULL;
}

static struct pci_driver t_driver = {
	.name = "cs8409test",
	.id_table = NULL,       /* driver_override only */
	.probe = t_probe,
	.remove = t_remove,
};

static int __init t_init(void)
{
	int e;

	mutex_init(&T.lock);
	T.t0 = ktime_get_ns();
	T.log = vzalloc(T_LOG_BYTES);
	T.isnap = vzalloc(CS8409_RING_BYTES);
	if (!T.log || !T.isnap) {
		vfree(T.log);
		vfree(T.isnap);
		return -ENOMEM;
	}
	T.dir = debugfs_create_dir("cs8409test", NULL);
	debugfs_create_file("ctl", 0200, T.dir, NULL, &t_ctl_fops);
	debugfs_create_file("log", 0400, T.dir, NULL, &t_log_fops);
	debugfs_create_file("oring", 0600, T.dir, NULL, &t_oring_fops);
	debugfs_create_file("iring", 0400, T.dir, NULL, &t_iring_fops);
	e = pci_register_driver(&t_driver);
	if (e) {
		debugfs_remove_recursive(T.dir);
		vfree(T.log);
		vfree(T.isnap);
	}
	return e;
}

static void __exit t_exit(void)
{
	pci_unregister_driver(&t_driver);
	debugfs_remove_recursive(T.dir);
	vfree(T.log);
	vfree(T.isnap);
}

module_init(t_init);
module_exit(t_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("development harness for the CS8409HDA core (Dell Vostro 3520)");
