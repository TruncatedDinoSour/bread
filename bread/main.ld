ENTRY(start)
SECTIONS
{
	. = 1M;
 
    .data : 
	{
		KEEP(*(.multiboot_header))
	}
 
    .text : 
    {
        *(.text)
    }

    .bss : {
        *(.bss)
    }
}
