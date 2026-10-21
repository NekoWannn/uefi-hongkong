ENTRY(_head)
SECTIONS
{
	. = 0;
	.text : { *(.text.head) *(.text*) }
	/* Both probes get copied to other addresses, so keep each in its own
	 * output section with symbols marking its extent. */
	. = ALIGN(4096);
	__probe_a_start = .;
	.probe_a : { *(.probe_a) }
	__probe_a_end = .;
	. = ALIGN(4096);
	__probe_b_start = .;
	.probe_b : { *(.probe_b) }
	__probe_b_end = .;
	.rodata : { *(.rodata*) }
	.data : { *(.data*) }
	. = ALIGN(16);
	_bss_start = .;
	.bss : { *(.bss*) *(COMMON) }
	. = ALIGN(16);
	_bss_end = .;
	. += 0x8000;
	. = ALIGN(16);
	_stack_top = .;
	. = ALIGN(4096);
	_sec_stacks = .;
	. += 8 * 0x1000;
	_end = .;
	/DISCARD/ : { *(.comment) *(.note*) *(.eh_frame*) }
}
