#include <stdio.h>
#include "file2.h"
#include "file3.h"

void internal_2_deneme(int x, int y, char op) {
    int result = 0;

    switch (op) {
        case '+': result = topla(x, y); break;
        case '-': result = cikar(x, y); break;
        case '*': result = carp(x, y); break;
        case '/': 
            if (y != 0) 
                result = bol(x, y); 
            else {
                printf("Hata: 0'a bolme\n");
                return;
            }
            break;
        default:
            printf("Islem bulunamadi\n");
            return;
    }

    printf("%d %c %d = %d\n", x, op, y, result);
}
