# Makefile for kernel
all: kernel.bin

kernel.bin: kernel.o memory.o process.o syscall.o fs.o
    i686-elf-ld -o kernel.bin -T kernel.ld kernel.o memory.o process.o syscall.o fs.o

kernel.o: kernel.c kernel.h
    i686-elf-gcc -ffreestanding -c kernel.c -o kernel.o

memory.o: memory.c memory.h
    i686-elf-gcc -ffreestanding -c memory.c -o memory.o

process.o: process.c process.h
    i686-elf-gcc -ffreestanding -c process.c -o process.o

syscall.o: syscall.c syscall.h
    i686-elf-gcc -ffreestanding -c syscall.c -o syscall.o

fs.o: fs.c fs.h
    i686-elf-gcc -ffreestanding -c fs.c -o fs.o

clean:
    rm -f *.o *.bin
