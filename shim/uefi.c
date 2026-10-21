/*
 * Stage the UEFI firmware from the bare-metal shim, and prove that code placed
 * at FD_BASE can actually be fetched and executed. Every earlier attempt ended
 * with the firmware silent, so before blaming its contents, run a stub there:
 * if the panel shows the stub's stripes, the region executes and the fault is
 * inside the volume; if nothing appears, the region itself cannot run code.
 */
#include <stdint.h>
#include "console.h"

#define FD_BASE   0xC6800000UL
#define FD_SIZE   0x369000UL

extern char _Payload[];

/* Position independent, no literal pool: builds the frame buffer address with
 * movz/movk so the block can be copied anywhere and still run. */
__asm__(
  ".pushsection .stub,\"ax\",%progbits\n"
  ".globl hk_stub_start\n"
  "hk_stub_start:\n"
  "  movz x1, #0xC600\n"
  "  movk x1, #0xF8C6, lsl #16\n"
  "  add  x1, x1, #0x0A80000\n"        /* row 600: 600 * 4480 * 4 */
  "  movz w0, #0xFF00, lsl #16\n"      /* red */
  "  mov  x2, #512\n"
  "1:\n"
  "  str  w0, [x1], #4\n"
  "  subs x2, x2, #1\n"
  "  b.ne 1b\n"
  "  movz x1, #0xC600\n"
  "  movk x1, #0xF8C6, lsl #16\n"
  "  add  x1, x1, #0x0F00000\n"        /* row 960 */
  "  movz w0, #0x00FF\n"               /* green */
  "  mov  x2, #512\n"
  "2:\n"
  "  str  w0, [x1], #4\n"
  "  subs x2, x2, #1\n"
  "  b.ne 2b\n"
  "3:\n"
  "  b 3b\n"
  ".globl hk_stub_end\n"
  "hk_stub_end:\n"
  ".popsection\n"
);

extern char hk_stub_start[];
extern char hk_stub_end[];

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
	(void)x1; (void)x2; (void)x3;

	con_clear(0x00000000u);
	con_hex2("FB", "base=", FB_BASE, "stride=", FB_STRIDE);
	con_hex2("PAYLOAD", "src=", (uintptr_t)_Payload, "dst=", FD_BASE);

	copy_to_fd_base();
	con_str("COPY", "volume copied");

	/* Writes to FD_BASE may be dropped: the region can belong to TZ or be an
	 * XPU-protected carveout. Read the pattern back before blaming fetch. */
	{
		volatile uint32_t *p = (volatile uint32_t *)FD_BASE;
		p[0] = 0xDEADBEEFu;
		p[0x40] = 0x12345678u;
		__asm__ volatile("dsb sy" ::: "memory");
		con_hex2("RAM", "w0=", 0xDEADBEEFu, "r0=", p[0]);
		con_hex2("RAM", "w1=", 0x12345678u, "r1=", p[0x40]);
	}

	/* Control for the previous run: the same stub, executed where it was
	 * linked. If the stripes appear here but not at FD_BASE, the stub is fine
	 * and 0xC6800000 is what refuses to run code. */
	con_str("RUN", "stub in place (expect stripes at 600/960)");

	__asm__ volatile(
		"dsb sy\n"
		"ic iallu\n"
		"dsb sy\n"
		"isb\n"
		"br  %0\n"
		:
		: "r"((uint64_t)hk_stub_start)
		: "memory");
	return 0;
}
