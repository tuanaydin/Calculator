#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "factorfile2.h"
#include "factorfile3.h"

// a*b işlemi unsigned long long sınır kontrolü
static bool safe_mul_ull(unsigned long long a, unsigned long long b, unsigned long long *out) {
    if (a == 0 || b == 0) { *out = 0; return true; }
    if (a > ULLONG_MAX / b) return false; // taşma
    *out = a * b;
    return true;
}

static unsigned long long gcd_ull(unsigned long long a, unsigned long long b) {
    while (b) { unsigned long long t = a % b; a = b; b = t; }
    return a;
}


int factorial(unsigned int n, unsigned long long *result) {
    unsigned long long acc = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        if (!safe_mul_ull(acc, i, &acc)) return 0; // taşma
    }
    *result = acc;
    return 1;
}

// nPr = n * (n-1) * ... * (n-r+1)
int permutation(unsigned int n, unsigned int r, unsigned long long *result) {
    if (r > n) return 0;
    unsigned long long acc = 1;
    for (unsigned int i = 0; i < r; ++i) {
        unsigned long long term = (unsigned long long)(n - i);
        if (!safe_mul_ull(acc, term, &acc)) return 0; // taşma
    }
    *result = acc;
    return 1;
}

// nCr – taşmayı azaltmak için her adımda sadeleştirilerek taşma azaltılır
int combination(unsigned int n, unsigned int r, unsigned long long *result) {
    if (r > n) return 0;
    // simetri: nCr == nC(n-r)
    if (r > n - r) r = n - r;
    if (r == 0) { *result = 1ULL; return 1; }

    unsigned long long res = 1ULL;
    for (unsigned int i = 1; i <= r; ++i) {
        unsigned long long num = (unsigned long long)(n - r + i); // artan pay
        unsigned long long den = (unsigned long long)i;           // artan payda

        // önce num ve den'i sadeleştirme
        unsigned long long g = gcd_ull(num, den);
        num /= g; den /= g;

        // sonra res ve den'i sadeleştir (böylece den genelde 1 olur)
        g = gcd_ull(res, den);
        res /= g; den /= g;

        // res *= num ?
        if (!safe_mul_ull(res, num, &res)) return 0;

        if (den != 1) {
            res /= den;
        }
    }
    *result = res;
    return 1;
}