ENTRY(_start)

SECTIONS
{
    /* İlk olarak, çekirdeğin .text bölümü, yani kod kısmı yerleştirilir */
    . = 1M;
    .text :
    {
        *(.multiboot)        /* Multiboot başlığı */
        *(.text)             /* Tüm kodlar */
        *(.rodata)           /* Tüm salt okunur veriler */
    }

    /* .data bölümü, global değişkenler vb. burada yer alır */
    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        *(.data)
    }

    /* .bss bölümü, sıfırlanmış global ve statik değişkenler için */
    .bss : AT(ADDR(.data) + SIZEOF(.data))
    {
        __bss_start = .;
        *(.bss)
        *(COMMON)
        __bss_end = .;
    }

    /* Stack bölgesi */
    .stack (NOLOAD) :
    {
        __stack_bottom = .;
        . = . + 64K; /* 64 KB'lik bir stack alanı */
        __stack_top = .;
    }

    /* Bellek haritası simgeleri */
    _end = .;
}
