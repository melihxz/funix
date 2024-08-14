/* kernel.ld */
OUTPUT_FORMAT("elf32")
ENTRY(kmain)
SECTIONS {
    . = 1M;
    .text : {
        *(.text)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
}
