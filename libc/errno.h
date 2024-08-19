// libc/errno.h

#ifndef ERRNO_H
#define ERRNO_H

// Hata kodları
extern int errno;

// Hata kodu tanımları
#define EDOM    1   // Matematiksel domain hatası
#define ERANGE  2   // Aralık hatası
#define EINVAL  3   // Geçersiz argüman
#define ENOMEM  4   // Bellek yetersizliği

// Hata kodlarını almak için yardımcı işlev
const char* strerror(int errnum);

#endif // ERRNO_H
