# Proje adını ve hedef dosyayı tanımlayın
TARGET = funix

# Derleyici ve bayraklar
CC = gcc
CFLAGS = -Wall -Wextra -nostdlib -ffreestanding -O2

# Linker ayarları
LDFLAGS = -T linker.ld

# Kök dizindeki tüm kaynak dosyalar
SRC_ROOT = kernel/main.c kernel/init.c kernel/paging.c kernel/process.c kernel/timer.c kernel/memory.c \
           drivers/disk.c drivers/keyboard.c \
           fs/vfs.c fs/ext2.c \
           net/socket.c net/tcp.c net/udp.c \
           shell/shell.c shell/parser.c \
           libc/math.c libc/errno.c libc/stdlib.c libc/string.c

# Kök dizindeki tüm header dosyalar
HEADERS = include/assert.h include/ctype.h include/stdio.h include/stddef.h include/stdint.h include/string.h \
          kernel/init.h kernel/paging.h kernel/process.h kernel/timer.h kernel/memory.h \
          drivers/disk.h drivers/keyboard.h \
          fs/vfs.h fs/ext2.h \
          net/socket.h net/tcp.h net/udp.h \
          shell/shell.h shell/parser.h \
          libc/math.h libc/errno.h libc/stdlib.h

# Assembly kaynak dosyaları
ASM_SRC = boot/boot.asm

# Nesne dosyaları
OBJS = $(SRC_ROOT:.c=.o) $(ASM_SRC:.asm=.o)

# Varsayılan hedef
all: $(TARGET)

# Hedef dosya oluşturma
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

# .c dosyalarını derleme
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# .asm dosyalarını derleme
%.o: %.asm
	nasm -f elf32 $< -o $@

# Temizlik
clean:
	rm -f $(OBJS) $(TARGET)

# Yeniden derleme için
rebuild: clean all
