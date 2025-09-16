#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "factorfile2.h"
#include "factorfile3.h"

int factor(char op, unsigned int n, unsigned int r, unsigned long long *result) {
    unsigned long long sonuc;
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
            if (result != NULL) *result = 0;
            return 0;
    }
    
  
    if (result != NULL && ok) {
        *result = sonuc;
    } else if (result != NULL) {
        *result = 0;
    }
    
    return ok;
}