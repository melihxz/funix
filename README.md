# Funix

Funix project is a development project that includes a Unix-like operating system kernel and user-space applications. Funix project features a kernel, file system, memory management, process management, and system calls.

## Features

- **Kernel**: A simple kernel with process management, memory management, and file system support.
- **User Space**: A basic shell and utility functions.
- **ISO Creation**: Ability to create an ISO image for the kernel and user-space applications.
- **Build**: Building and ISO image creation using `Makefile`.

## Installation

Follow these steps to build the project:

1. Install required tools:
   - `gcc`
   - `grub`
   - `qemu`

2. Clone the repository:
   ```bash
   git clone https://github.com/melihxz/funix.git
   cd funix
   ```

3. Build and create the ISO image:
   ```bash
   make
   ```

4. To test the ISO image, use `qemu`:
   ```bash
   qemu-system-x86_64 -cdrom output/os.iso
   ```

## Contributing

To contribute to the project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Create a pull request.

## License

This project is licensed under the [MIT License](LICENSE).