# Funix OS

Funix OS is a project that involves creating a simple operating system kernel along with basic drivers. It serves as a learning tool for those interested in understanding how to develop and compile an operating system kernel.

## Features

- Basic kernel structure
- Disk and keyboard drivers
- Simple file system (ext2)
- Network stack (TCP/UDP)
- Basic command-line interface (shell)
- Basic C library (math, errno, stdlib, string)

## Requirements

- `gcc` (GNU Compiler Collection)
- `nasm` (Netwide Assembler)
- `make` (Build automation tool)
- An x86 emulator or real hardware (QEMU, VirtualBox, etc.)

## Build Instructions

To compile and run the project, follow these steps:

1. **Clone the Project Repository:**
   ```bash
   git clone https://github.com/melihxz/funix.git
   cd funix
   ```

2. **Compile the Project:**
   ```bash
   make
   ```

   This command compiles the kernel and all modules, generating the executable `funix`.

3. **Clean Up:**
   ```bash
   make clean
   ```

   This command removes all temporary files created during the build process.

4. **Run the Project:**
   ```bash
   qemu-system-x86_64 -drive format=raw,file=funix.img
   ```

   You can test the operating system using QEMU.

## Project Structure

- **`boot/`**: Boot phase and bootloader code.
- **`kernel/`**: Kernel code and core functionalities.
- **`drivers/`**: Disk, keyboard, and other drivers.
- **`fs/`**: File system implementations.
- **`net/`**: Networking stack.
- **`shell/`**: Command-line interface.
- **`libc/`**: Basic C library.
- **`include/`**: General header files.
- **`Makefile`**: Project build file.
- **`linker.ld`**: Linker script.
