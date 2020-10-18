ENTRY(Reset_Handler)

/*
 * STM32F103C8T6 hardware
 *
 * RAM   = 20K
 * FLASH = 128K
 */

_ram            = 0x20000000; /* start of ram */
_estack         = 0x20005000; /* end of ram */
_min_heap_size  = 0x0;
_min_stack_size = 0x100;

MEMORY
{
	FLASH(rx)    : ORIGIN = 0x08000000, LENGTH = 128K
	RAM(rwx)     : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.isr_vector :
	{
		. = ALIGN(4);
		KEEP(*(.isr_vector))
		. = ALIGN(4);
	} > FLASH

	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text*)
		*(.rodata)
		*(.rodata*)
		*(.glue_7)
		*(.glue_7t)

		KEEP (*(.init))
		KEEP (*(.fini))

		. = ALIGN(4);
	} > FLASH

	_sidata = .;
	.data : AT (_sidata)
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data*)

		. = ALIGN(4);
		_edata = .;
	} > RAM

	. = ALIGN(4);
	.bss :
	{
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss)
		*(.bss*)
		*(COMMON)

		. = ALIGN(4);
		_ebss = .;
		__bss_end__ = _ebss;
	} > RAM

	PROVIDE(end = _ebss);
	PROVIDE(_end = _ebss);

	._user_heap_stack :
	{
		. = ALIGN(4);
		. = . + _min_heap_size;
		. = . + _min_stack_size;
		. = ALIGN(4);
	} > RAM

	/DISCARD/ :
	{
		libc.a(*)
		libm.a(*)
		libgcc.a(*)
	}

}
