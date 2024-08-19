// libc/math.c

#include "math.h"

// Newton yöntemiyle karekök hesaplama
double sqrt(double x) {
    if (x < 0) return -1; // Negatif sayılar için hata kodu
    double guess = x / 2.0;
    double epsilon = 0.00001;
    while (guess * guess - x > epsilon || guess * guess - x < -epsilon) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

// Üs alma işlemi
double pow(double base, double exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Trigonometrik işlevler
double sin(double x) {
    // Taylor serisi ile sinüs hesaplama
    double term = x;
    double result = 0.0;
    int n = 1;
    for (int i = 0; i < 10; i++) {
        result += term;
        term *= -x * x / (2 * n * (2 * n + 1));
        n++;
    }
    return result;
}

double cos(double x) {
    // Taylor serisi ile kosinüs hesaplama
    double term = 1.0;
    double result = 0.0;
    int n = 1;
    for (int i = 0; i < 10; i++) {
        result += term;
        term *= -x * x / (2 * n * (2 * n - 1));
        n++;
    }
    return result;
}

double tan(double x) {
    return sin(x) / cos(x);
}

double asin(double x) {
    // Yaklaşık hesaplama
    return atan(x / sqrt(1 - x * x));
}

double acos(double x) {
    // Yaklaşık hesaplama
    return atan(sqrt(1 - x * x) / x);
}

double atan(double x) {
    // Yaklaşık hesaplama
    return x - (x * x * x) / 3 + (x * x * x * x * x) / 5;
}

double atan2(double y, double x) {
    if (x > 0) {
        return atan(y / x);
    } else if (x < 0 && y >= 0) {
        return atan(y / x) + M_PI;
    } else if (x < 0 && y < 0) {
        return atan(y / x) - M_PI;
    } else if (x == 0 && y > 0) {
        return M_PI / 2;
    } else if (x == 0 && y < 0) {
        return -M_PI / 2;
    }
    return 0;
}
