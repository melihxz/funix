// libc/string.c

#include "string.h"

// String kopyalama
char *strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++) != '\0');
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    while (n && (*d++ = *src++) != '\0') {
        n--;
    }
    while (n--) {
        *d++ = '\0';
    }
    return dest;
}

// String birleştirme
char *strcat(char *dest, const char *src) {
    char *d = dest;
    while (*d) d++;
    while ((*d++ = *src++) != '\0');
    return dest;
}

char *strncat(char *dest, const char *src, size_t n) {
    char *d = dest;
    while (*d) d++;
    while (n && (*d++ = *src++) != '\0') {
        n--;
    }
    if (n == 0) {
        *d = '\0';
    }
    return dest;
}

// String uzunluğu
size_t strlen(const char *s) {
    const char *sc = s;
    while (*sc != '\0') {
        sc++;
    }
    return sc - s;
}

// String karşılaştırma
int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0;
    } else {
        return *(unsigned char *)s1 - *(unsigned char *)s2;
    }
}

// String arama
char *strchr(const char *s, int c) {
    while (*s != (char)c) {
        if (*s == '\0') {
            return NULL;
        }
        s++;
    }
    return (char *)s;
}

char *strrchr(const char *s, int c) {
    const char *last = NULL;
    do {
        if (*s == (char)c) {
            last = s;
        }
    } while (*s++);
    return (char *)last;
}

// String ayırma
char *strtok(char *str, const char *delim) {
    static char *last;
    if (str == NULL) {
        str = last;
    }
    if (str == NULL) {
        return NULL;
    }

    str += strspn(str, delim);
    if (*str == '\0') {
        last = NULL;
        return NULL;
    }

    char *token = str;
    str = strpbrk(token, delim);
    if (str == NULL) {
        last = NULL;
    } else {
        *str = '\0';
        last = str + 1;
    }

    return token;
}
