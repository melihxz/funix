; funix/boot/idt.asm
BITS 16
org 0x8000

idt_start:
    ; IDT yapılandırması
    idt_entry interrupt_entry

idt_end:
    idt_descriptor:
        dw idt_end - idt_start - 1
        dd idt_start

idt_entry:
    ; IDT girişi tanımlamaları

interrupt_entry:
    dw interrupt_handler
    dw 0
    db 0
    db 10001110b
    db 0

interrupt_handler:
    ; Kesme işleyici kodu
    iret
