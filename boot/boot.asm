; funix/boot/boot.asm
BITS 16
org 0x7C00

; Bootloader kodu
start:
    ; Video modunu ayarla
    mov ax, 0x03
    int 0x10

    ; Çekirdek yüklemesi için boot sektöründen okunan veriyi 0x1000 adresine taşı
    mov si, kernel_load_msg
    call print_string

    ; Çekirdek yüklemesi
    mov ax, 0x1000
    mov ds, ax
    mov es, ax
    mov bx, 0x1000
    mov cx, 1
    mov ah, 0x02
    int 0x13

    ; Boşluğa geçiş
    jmp $

print_string:
    ; Ekrana string yazma fonksiyonu
    mov ah, 0x0E
print_loop:
    lodsb
    cmp al, 0
    je done
    int 0x10
    jmp print_loop
done:
    ret

kernel_load_msg db 'Loading kernel...', 0
times 510 - ($ - $$) db 0
dw 0xAA55
