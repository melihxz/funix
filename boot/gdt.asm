; funix/boot/gdt.asm
BITS 16
org 0x8000

gdt_start:
    ; GDT yapısı
    gdt_entry null_descriptor
    gdt_entry code_segment
    gdt_entry data_segment

gdt_end:
    ; GDT yapılandırma verisi
    gdt_descriptor:
        dw gdt_end - gdt_start - 1
        dd gdt_start

gdt_entry:
    ; GDT girişi tanımlamaları

null_descriptor:
    dw 0
    dw 0
    db 0
    db 0
    db 0
    db 0

code_segment:
    dw 0
    dw 0xFFFF
    db 0
    db 10011010b
    db 11001111b

data_segment:
    dw 0
    dw 0xFFFF
    db 0
    db 10010010b
    db 11001111b

gdt_descriptor db 0x00, 0x00, 0x00
