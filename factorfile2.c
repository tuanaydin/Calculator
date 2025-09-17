#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "factorfile2.h"
#include "factorfile3.h"

void factor(char op, unsigned int n, unsigned int r, unsigned long long *result) {
    unsigned long long sonuc = 0;
    int ok = 0;
    
    switch (toupper((unsigned char)op)) {
        case 'F':
            ok = factorial(n, &sonuc);
            if (ok) printf("%u! = %llu\n", n, sonuc);
            else    printf("Hata: faktöriyel hesapta taşma oluştu.\n");
            break;
            
        case 'P':
            ok = permutation(n, r, &sonuc);
            if (ok) printf("P(%u,%u) = %llu\n", n, r, sonuc);
            else    printf("Hata: geçersiz (r>n) veya taşma oluştu.\n");
            break;
            
        case 'C':
            ok = combination(n, r, &sonuc);
            if (ok) printf("C(%u,%u) = %llu\n", n, r, sonuc);
            else    printf("Hata: geçersiz (r>n) veya taşma oluştu.\n");
            break;
            
        default:
            printf("Geçersiz işlem kodu: '%c' (F, P veya C kullanın)\n", op);
            break;
    }
    
    // Sonucu result pointer'ına yaz
    if (result != NULL) {
        if (ok) {
            *result = sonuc;
        } else {
            *result = 0;
        }
    }
}