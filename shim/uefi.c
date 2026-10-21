/*
 * Working baseline. This is the version whose red and green blocks were seen on
 * the panel: fill_rect() at rows 300-420 and 460-580, drawn before the volume
 * copy, with the same console lines. Only two things are added on top:
 * a data-cache clean over the copied volume, and the jump.
 */
#include <stdint.h>
#include "console.h"

#define FD_BASE   0xC6800000UL
#define FD_SIZE   0x369000UL
#define FB_BASE   0xF8C60000UL
#define FB_STRIDE 4480UL
#define FB_H      2436UL

extern char _Payload[];

static void
fill_rect(uint32_t y0, uint32_t y1, uint32_t colour)
{
	for (uint32_t y = y0; y < y1 && y < FB_H; y++) {
		volatile uint32_t *row = (volatile uint32_t *)(FB_BASE + y * FB_STRIDE * 4);
		for (uint32_t x = 0; x < 256; x++) {
			row[x] = colour;
		}
	}
}

static void
clean_dcache(uintptr_t start, uint64_t len)
{
	uint64_t ctr;
	uint32_t line;
	uintptr_t p;
	uintptr_t end = start + len;

	__asm__ volatile("mrs %0, ctr_el0" : "=r"(ctr));
	line = 4u << ((ctr >> 16) & 0xFu);
	for (p = start & ~(uintptr_t)(line - 1); p < end; p += line) {
		__asm__ volatile("dc civac, %0" :: "r"(p) : "memory");
	}
	__asm__ volatile("dsb sy" ::: "memory");
}

static void
copy_to_fd_base(void)
{
	volatile uint64_t *src = (volatile uint64_t *)_Payload;
	volatile uint64_t *dst = (volatile uint64_t *)FD_BASE;

	if ((uintptr_t)src == FD_BASE) {
		return;
	}
	for (uint64_t i = 0; i < FD_SIZE / 8; i++) {
		dst[i] = src[i];
	}
}

int
shim_main(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3)
{
	(void)x0; (void)x1; (void)x2; (void)x3;

	con_clear(0x00000000u);
	con_hex2("FB", "base=", FB_BASE, "stride=", FB_STRIDE);
	con_hex2("PAYLOAD", "src=", (uintptr_t)_Payload, "dst=", FD_BASE);
	con_hex2("FD", "size=", FD_SIZE, "h=", FB_H);

	/* Unchanged from the version that was seen working. */
	fill_rect(300, 420, 0x00FF0000u);
	fill_rect(460, 580, 0x0000FF00u);
	con_str("SHIM", "bands drawn: red 300-420, green 460-580");

	/* Test build: stop here without copying the volume or jumping to it. If the
	 * panel stays readable the copy was destroying the scanned-out buffer; if it
	 * still goes black, the firmware is not the cause. */
	con_str("STOP", "no copy, no jump; halting");
	for (;;) {
		__asm__ volatile("wfi");
	}
	return 0;
}
