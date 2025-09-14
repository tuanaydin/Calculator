#include <stdio.h>
#include "donusum2.h"
#include "donusum3.h"


void internal_2_donusum(int x, int y, char op) {
    switch(op) {
        case 'C':
            printf("rad-Derece donusumu islemi baslatiliyor...\n");
            rad_to_deg(x);
            break;
        case 'B':
            printf("Ondalik sayidan ikilik sayiya donusum islemi baslatiliyor...\n");
            decimal_to_binary(x);
            break;
        default:
            printf("Bilinmeyen islem kodu: %c\n", op);
            break;
    }
}