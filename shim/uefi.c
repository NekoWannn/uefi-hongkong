/*
 * Stage the UEFI firmware from the proven bare-metal shim instead of letting
 * BootShim jump blind: draw on the framebuffer first, so a black screen can be
 * attributed to the panel, to the copy, or to the firmware itself.
 *
 * The payload is the SILICIUM_UEFI.fd image; it must end up at FD_BASE with
 * the MMU and caches off, exactly what BootShim would have done.
 */
#include <stdint.h>
#include "console.h"

#define FD_BASE   0xC6800000UL
#define FD_SIZE   0x369000UL

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

	/* Two bands the eye cannot miss, drawn before anything else runs. */
	fill_rect(300, 420, 0x00FF0000u);
	fill_rect(460, 580, 0x0000FF00u);
	con_str("SHIM", "bands drawn: red 300-420, green 460-580");

	/* Execute the volume where ABL loaded it. The shim itself runs from this
	 * region, so it is certainly fetchable; FD_BASE may not be. */
	con_str("COPY", "skipped: running in place");
	con_hex2("DTB", "x0=dtb=", (uint32_t)x0, "entry=", (uint32_t)(uintptr_t)_Payload);

	__asm__ volatile(
		"dsb sy; ic iallu; dsb sy; isb\n"
		"mov x0, %0\n"
		"br  %1\n"
		:
		: "r"((uint64_t)x0), "r"((uint64_t)(uintptr_t)_Payload)
		: "memory");
	return 0;
}
