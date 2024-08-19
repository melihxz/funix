// libc/stdio.c

#include "stdio.h"
#include "string.h"

// Giriş/Çıkış için yazma işlemi
static int vprintf_helper(void (*putch)(int, void*), void *putdat, const char *format, va_list ap) {
    const char *p;
    for (p = format; *p; p++) {
        if (*p != '%') {
            putch(*p, putdat);
            continue;
        }
        // Format karakterlerini işleme
    }
    return 0;
}

// printf işlevi
int printf(const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int ret = vprintf_helper(putch, NULL, format, ap);
    va_end(ap);
    return ret;
}

// snprintf işlevi
int snprintf(char *str, size_t size, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int ret = vsnprintf(str, size, format, ap);
    va_end(ap);
    return ret;
}

// vsnprintf işlevi
int vsnprintf(char *str, size_t size, const char *format, va_list ap) {
    // Belirli bir büyüklükte string'e yazma
    return vprintf_helper(putch, str, format, ap);
}
