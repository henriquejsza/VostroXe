// SPDX-License-Identifier: GPL-2.0
/*
 * hdaregs: one-shot, read-only snapshot of the Intel HDA controller (8086:51C8) registers while snd_hda_intel owns
 * the device, plus a few samples of the DMA position of the running output stream. Ground truth for the macOS
 * CS8409HDA driver. It maps BAR0 itself (pci_iomap does not claim the region), only reads, and never stays loaded:
 * init always returns -ECANCELED after printing (dmesg lines start with "hdaregs:").
 *
 *   insmod hdaregs.ko [samples=24] [gap_us=250]
 */
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/delay.h>
#include <linux/ktime.h>

static int samples = 24, gap_us = 250;
module_param(samples, int, 0);
module_param(gap_us, int, 0);

static int __init hdaregs_init(void)
{
	struct pci_dev *pdev = pci_get_device(0x8086, 0x51c8, NULL);
	void __iomem *b;
	u16 gcap, pmcsr, devc, llch;
	u32 cgctl, hdr;
	u8 tcsel;
	int iss, oss, bss, n, i, off, guard, run = -1;

	if (!pdev)
		return -ENODEV;
	pci_read_config_byte(pdev, 0x44, &tcsel);
	pci_read_config_dword(pdev, 0x48, &cgctl);
	pci_read_config_word(pdev, 0x78, &devc);
	pci_read_config_word(pdev, pdev->pm_cap + PCI_PM_CTRL, &pmcsr);
	pr_info("hdaregs: %s cfg TCSEL(44)=%02x CGCTL(48)=%08x DEVC(78)=%04x PMCSR=%04x D%d\n",
		pci_name(pdev), tcsel, cgctl, devc, pmcsr, pmcsr & 3);
	if (pmcsr & 3) {
		pr_info("hdaregs: not in D0, BAR0 not read\n");
		goto out_put;
	}
	b = pci_iomap(pdev, 0, 0x4000);
	if (!b) {
		pr_info("hdaregs: pci_iomap failed\n");
		goto out_put;
	}
	gcap = ioread16(b + 0x00);
	iss = (gcap >> 8) & 0xf;
	oss = (gcap >> 12) & 0xf;
	bss = (gcap >> 3) & 0x1f;
	pr_info("hdaregs: GCAP=%04x (ISS %d OSS %d BSS %d NSDO %d 64OK %d) VMIN=%02x VMAJ=%02x OUTPAY=%04x INPAY=%04x\n",
		gcap, iss, oss, bss, (gcap >> 1) & 3, gcap & 1, ioread8(b + 0x02), ioread8(b + 0x03),
		ioread16(b + 0x04), ioread16(b + 0x06));
	pr_info("hdaregs: GCTL=%08x WAKEEN=%04x STATESTS=%04x GSTS=%04x LLCH=%04x OUTSTRMPAY=%04x INSTRMPAY=%04x\n",
		ioread32(b + 0x08), ioread16(b + 0x0c), ioread16(b + 0x0e), ioread16(b + 0x10), ioread16(b + 0x14),
		ioread16(b + 0x18), ioread16(b + 0x1a));
	pr_info("hdaregs: INTCTL=%08x INTSTS=%08x WALCLK=%08x SSYNC=%08x\n",
		ioread32(b + 0x20), ioread32(b + 0x24), ioread32(b + 0x30), ioread32(b + 0x38));
	pr_info("hdaregs: CORB LBASE=%08x UBASE=%08x WP=%04x RP=%04x CTL=%02x STS=%02x SIZE=%02x\n",
		ioread32(b + 0x40), ioread32(b + 0x44), ioread16(b + 0x48), ioread16(b + 0x4a), ioread8(b + 0x4c),
		ioread8(b + 0x4d), ioread8(b + 0x4e));
	pr_info("hdaregs: RIRB LBASE=%08x UBASE=%08x WP=%04x RINTCNT=%04x CTL=%02x STS=%02x SIZE=%02x\n",
		ioread32(b + 0x50), ioread32(b + 0x54), ioread16(b + 0x58), ioread16(b + 0x5a), ioread8(b + 0x5c),
		ioread8(b + 0x5d), ioread8(b + 0x5e));
	pr_info("hdaregs: ICS=%04x DPLBASE=%08x DPUBASE=%08x\n", ioread16(b + 0x68), ioread32(b + 0x70),
		ioread32(b + 0x74));
	pr_info("hdaregs: VS EM1=%08x INRC=%08x OUTRC=%08x FIFOTRK=%08x FIFOTRK2=%08x EM2=%08x EM3L=%08x EM3U=%08x\n",
		ioread32(b + 0x1000), ioread32(b + 0x1004), ioread32(b + 0x1008), ioread32(b + 0x100c),
		ioread32(b + 0x1010), ioread32(b + 0x1030), ioread32(b + 0x1038), ioread32(b + 0x103c));
	pr_info("hdaregs: VS EM4L=%08x EM4U=%08x LTRP=%04x D0I3C=%02x PCE=%02x L2MAGC=%08x L2LAHPT=%08x\n",
		ioread32(b + 0x1040), ioread32(b + 0x1044), ioread16(b + 0x1048), ioread8(b + 0x104a),
		ioread8(b + 0x104b), ioread32(b + 0x1050), ioread32(b + 0x1054));

	n = iss + oss + bss;
	for (i = 0; i < n && i < 30; i++) {
		void __iomem *sd = b + 0x80 + 0x20 * i;
		u32 ctl = ioread32(sd + 0x00);

		if ((ctl & 0x02) && i >= iss && i < iss + oss && run < 0)
			run = i;
		pr_info("hdaregs: SD%-2d %s CTL=%06x STS=%02x LPIB=%08x CBL=%08x LVI=%04x FIFOW=%04x FIFOS=%04x FMT=%04x FIFOL=%04x BDL=%08x%08x DPIB=%08x EFIFOS=%08x\n",
			i, i < iss ? "in " : i < iss + oss ? "out" : "bi ", ctl & 0xffffff, ctl >> 24,
			ioread32(sd + 0x04), ioread32(sd + 0x08), ioread16(sd + 0x0c), ioread16(sd + 0x0e),
			ioread16(sd + 0x10), ioread16(sd + 0x12), ioread16(sd + 0x14), ioread32(sd + 0x1c),
			ioread32(sd + 0x18), ioread32(b + 0x1084 + 0x20 * i), ioread32(b + 0x1094 + 0x20 * i));
	}

	/* extended capability chain (SKL+), IDs as in include/sound/hda_register.h:
	 * 1 GTS (time sync), 2 ML (multi-link), 3 PP (processing pipe), 4 SPB, 5 DRSM */
	llch = ioread16(b + 0x14);
	for (off = llch, guard = 0; off && off < 0x4000 - 0x80 && guard < 8; guard++) {
		hdr = ioread32(b + off);
		pr_info("hdaregs: CAP @%04x hdr=%08x id=%u ver=%u next=%04x\n", off, hdr, (hdr >> 16) & 0xfff,
			hdr >> 28, hdr & 0xffff);
		switch ((hdr >> 16) & 0xfff) {
		case 2: /* multi-link: link 0 registers at +0x40 */
			pr_info("hdaregs:   ML MLCD=%08x L0 LCAP=%08x LCTL=%08x LOSIDV=%08x LSDIID=%08x LPSOO=%04x LPSIO=%04x LWALFC=%08x LOUTPAY=%08x LINPAY=%08x\n",
				ioread32(b + off + 0x04), ioread32(b + off + 0x40), ioread32(b + off + 0x44),
				ioread32(b + off + 0x48), ioread32(b + off + 0x4c), ioread16(b + off + 0x50),
				ioread16(b + off + 0x52), ioread32(b + off + 0x58), ioread32(b + off + 0x60),
				ioread32(b + off + 0x70));
			break;
		case 3: /* processing pipe */
			pr_info("hdaregs:   PP PPCTL=%08x PPSTS=%08x\n", ioread32(b + off + 0x04), ioread32(b + off + 0x08));
			break;
		default:
			pr_info("hdaregs:   +4=%08x +8=%08x +c=%08x +10=%08x\n", ioread32(b + off + 4),
				ioread32(b + off + 8), ioread32(b + off + 0xc), ioread32(b + off + 0x10));
			break;
		}
		off = hdr & 0xffff;
	}

	if (run >= 0) {
		u64 t0 = ktime_get_ns();

		pr_info("hdaregs: sampling SD%d (running output stream): t_us LPIB DPIB WALCLK\n", run);
		for (i = 0; i < samples; i++) {
			u64 t = ktime_get_ns();
			u32 lpib = ioread32(b + 0x80 + 0x20 * run + 0x04);
			u32 dpib = ioread32(b + 0x1084 + 0x20 * run);
			u32 wall = ioread32(b + 0x30);

			pr_info("hdaregs:   %6llu %08x %08x %08x\n", (t - t0) / 1000, lpib, dpib, wall);
			udelay(gap_us);
		}
	} else {
		pr_info("hdaregs: no running output stream\n");
	}
	pci_iounmap(pdev, b);
out_put:
	pci_dev_put(pdev);
	return -ECANCELED;	/* one-shot */
}
module_init(hdaregs_init);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("one-shot read-only Intel HDA register snapshot");
