#!/bin/bash

# Derleme dizinleri
BUILD_DIR="build"
KERNEL_DIR="kernel"
TOOLCHAIN_DIR="toolchain"
ISO_DIR="iso"
OUTPUT_DIR="output"

# Temizleme işlemi
clean() {
    echo "Temizleme işlemi başlatılıyor..."
    rm -rf $BUILD_DIR
    rm -rf $ISO_DIR
    rm -rf $OUTPUT_DIR
}

# Derleme işlemi
build() {
    echo "Derleme işlemi başlatılıyor..."

    # Derleme dizinini oluştur
    mkdir -p $BUILD_DIR

    # Toolchain dizinini kontrol et
    if [ ! -d "$TOOLCHAIN_DIR" ]; then
        echo "Toolchain dizini bulunamadı: $TOOLCHAIN_DIR"
        exit 1
    fi

    # Kernel ve bootloader'ı derle
    pushd $KERNEL_DIR > /dev/null
    make clean
    make
    cp kernel.bin ../$BUILD_DIR/kernel.bin
    popd > /dev/null

    echo "Kernel derleme tamamlandı."

    # ISO imajını oluştur
    mkdir -p $ISO_DIR/boot/grub
    cp $BUILD_DIR/kernel.bin $ISO_DIR/boot/
    echo 'set timeout=0' > $ISO_DIR/boot/grub/grub.cfg
    echo 'set default=0' >> $ISO_DIR/boot/grub/grub.cfg
    echo 'menuentry "My OS" {' >> $ISO_DIR/boot/grub/grub.cfg
    echo '  multiboot /boot/kernel.bin' >> $ISO_DIR/boot/grub/grub.cfg
    echo '  boot' >> $ISO_DIR/boot/grub/grub.cfg
    echo '}' >> $ISO_DIR/boot/grub/grub.cfg

    grub-mkrescue -o $OUTPUT_DIR/os.iso $ISO_DIR

    echo "ISO imajı oluşturuldu: $OUTPUT_DIR/os.iso"
}

# Ana işlev
main() {
    case $1 in
        clean)
            clean
            ;;
        build)
            build
            ;;
        *)
            echo "Kullanım: $0 {clean|build}"
            exit 1
            ;;
    esac
}

# Betiği çalıştır
main "$@"
