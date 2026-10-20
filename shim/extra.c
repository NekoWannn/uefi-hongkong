/* start.S is shared with the XNU shim, which expects these two symbols.
 * The UEFI shim never starts secondaries and installs no exception handler,
 * so provide inert definitions to satisfy the linker. */
#include <stdint.h>

void
secondary_main(uint64_t x0)
{
	(void)x0;
	for (;;) {
		__asm__ volatile("wfi");
	}
}

void
exc_handler(void *frame)
{
	(void)frame;
	for (;;) {
		__asm__ volatile("wfi");
	}
}
