// libc/errno.c

#include "errno.h"

// Hata kodu değişkeni
int errno = 0;

// Hata mesajlarını döndüren işlev
const char* strerror(int errnum) {
    switch (errnum) {
        case EDOM:
            return "Math domain error";
        case ERANGE:
            return "Range error";
        case EINVAL:
            return "Invalid argument";
        case ENOMEM:
            return "Out of memory";
        default:
            return "Unknown error";
    }
}
