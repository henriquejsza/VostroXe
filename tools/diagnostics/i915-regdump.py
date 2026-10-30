#!/usr/bin/env python3
# Read-only dump of display MMIO ranges of the iGPU (BAR0) on Linux, for comparing the live i915 state with macOS.
# Usage: sudo python3 regdump.py [ranges...]   (ranges like 0x61000-0x61100; default = the HDMI pipe-B set)
# Only aligned 32-bit loads through a PROT_READ mapping; the GMBUS data register (0xc510c) is never read.
import ctypes, mmap, os, sys

DEV = "/sys/bus/pci/devices/0000:00:02.0/resource0"
SKIP = {0xc510c}  # GMBUS3 data: reading pops the FIFO

DEFAULT = [
    (0x42000, 0x42004),      # SKL_FUSE_STATUS
    (0x42084, 0x42088),      # CHICKEN_MISC_2
    (0x44300, 0x44308),      # DBUF_CTL_S3/S4
    (0x4438c, 0x44390),      # MBUS_CTL
    (0x44fe8, 0x44fec),      # DBUF_CTL_S2
    (0x45008, 0x4500c),      # DBUF_CTL_S1
    (0x45400, 0x45480),      # power well CTL1..CTL4, DDI/AUX wells
    (0x45500, 0x45508),      # DC_STATE_EN
    (0x46000, 0x46004),      # CDCLK_CTL
    (0x46010, 0x46024),      # DPLL0/1/2 enable, TBT PLL
    (0x46070, 0x46074),      # CDCLK PLL enable
    (0x46140, 0x46150),      # TRANS_CLK_SEL A..D
    (0x60000, 0x60100),      # transcoder A timings (reference)
    (0x60400, 0x60410),      # TRANS_DDI_FUNC_CTL_A
    (0x61000, 0x61100),      # transcoder B timings, data/link M/N, pipe B src
    (0x61200, 0x61210),      # VIDEO_DIP_CTL_B
    (0x61400, 0x61410),      # TRANS_DDI_FUNC_CTL_B / CTL2
    (0x64000, 0x64010),      # DDI_BUF_CTL_A
    (0x64100, 0x64110),      # DDI_BUF_CTL_B
    (0x6c000, 0x6d000),      # combo PHY B
    (0x70000, 0x70100),      # pipe A misc (reference)
    (0x70180, 0x701c0),      # plane 1A
    (0x7027c, 0x70280),      # PLANE_BUF_CFG_1_A
    (0x71000, 0x71100),      # pipe B: TRANSCONF_B 0x71008, PIPEMISC_B 0x71030, MBUS DBOX 0x7103c
    (0x71180, 0x711c0),      # plane 1B: CTL/STRIDE/POS/SIZE/SURF/OFFSET
    (0x71240, 0x71290),      # plane 1B WM/BUF_CFG
    (0x710c0, 0x71100),      # cursor B WM area
    (0x7117c, 0x71180),      # CUR_BUF_CFG_B
    (0x164200, 0x164300),    # DPCLKA, DPLL CFGCR
    (0x164b00, 0x164d00),    # DPLL0/1 DIV0, SSC...
]


def parse(arg):
    a, b = arg.split("-")
    return int(a, 16), int(b, 16)


def main():
    ranges = [parse(a) for a in sys.argv[1:]] or DEFAULT
    fd = os.open(DEV, os.O_RDONLY | os.O_SYNC)
    libc = ctypes.CDLL(None, use_errno=True)
    libc.mmap.restype = ctypes.c_void_p
    libc.mmap.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_long]
    length = 0x200000
    p = libc.mmap(None, length, mmap.PROT_READ, mmap.MAP_SHARED, fd, 0)
    if p is None or p == ctypes.c_void_p(-1).value:
        sys.exit(f"mmap failed: errno {ctypes.get_errno()}")
    for lo, hi in ranges:
        for off in range(lo, hi, 4):
            if off in SKIP or off + 4 > length:
                continue
            v = ctypes.c_uint32.from_address(p + off).value
            print(f"0x{off:06x} 0x{v:08x}")
    os.close(fd)


if __name__ == "__main__":
    main()
