# Makefile

# Derleyici ve bayraklar
CC = gcc
CFLAGS = -Wall -Iuserland -Ikernel -nostdlib -nostartfiles -ffreestanding -g

# Dizinler
KERNEL_DIR = kernel
USERLAND_DIR = userland
BUILD_DIR = build
ISO_DIR = iso
OUTPUT_DIR = output

# Dosyalar
KERNEL_SRC = $(KERNEL_DIR)/kernel.c $(KERNEL_DIR)/memory.c $(KERNEL_DIR)/process.c $(KERNEL_DIR)/fs.c $(KERNEL_DIR)/syscall.c
USERLAND_SRC = $(USERLAND_DIR)/shell.c $(USERLAND_DIR)/utils.c

KERNEL_OBJ = $(BUILD_DIR)/kernel.o $(BUILD_DIR)/memory.o $(BUILD_DIR)/process.o $(BUILD_DIR)/fs.o $(BUILD_DIR)/syscall.o
USERLAND_OBJ = $(BUILD_DIR)/shell.o $(BUILD_DIR)/utils.o

TARGET_KERNEL = $(BUILD_DIR)/kernel.bin
TARGET_USERLAND = $(BUILD_DIR)/userland.bin

# Varsayılan hedef
all: kernel userland iso

# Çekirdek derleme
$(TARGET_KERNEL): $(KERNEL_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(KERNEL_OBJ): $(KERNEL_SRC)
	mkdir -p $(BUILD_DIR)
	for src in $(KERNEL_SRC); do \
		$(CC) -c $$src -o $(BUILD_DIR)/$$(basename $$src .c).o $(CFLAGS); \
	done

# Kullanıcı alanı derleme
$(TARGET_USERLAND): $(USERLAND_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(USERLAND_OBJ): $(USERLAND_SRC)
	mkdir -p $(BUILD_DIR)
	for src in $(USERLAND_SRC); do \
		$(CC) -c $$src -o $(BUILD_DIR)/$$(basename $$src .c).o $(CFLAGS); \
	done

# ISO oluşturma
iso: $(TARGET_KERNEL) $(TARGET_USERLAND)
	mkdir -p $(ISO_DIR)/boot/grub
	cp $(TARGET_KERNEL) $(ISO_DIR)/boot/
	cp $(TARGET_USERLAND) $(ISO_DIR)/boot/
	echo 'set timeout=0' > $(ISO_DIR)/boot/grub/grub.cfg
	echo 'set default=0' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo 'menuentry "My OS" {' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '  boot' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '}' >> $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(OUTPUT_DIR)/os.iso $(ISO_DIR)

# Temizleme
clean:
	rm -rf $(BUILD_DIR) $(ISO_DIR) $(OUTPUT_DIR)/os.iso
