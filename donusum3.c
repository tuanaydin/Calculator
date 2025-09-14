#include <stdio.h>
#include "donusum3.h"
void rad_to_deg(int celsius) {
    int fahrenheit = (celsius * 9 / 5) + 32;
    printf("Celsius: %d -> Fahrenheit: %d\n", celsius, fahrenheit);
}

void decimal_to_binary(int decimal) {
    if (decimal == 0) {
        printf("Ondalik: 0 -> Ikilik: 0\n");
        return;
    }
    
    int binary[32];
    int i = 0;
    int original = decimal;
    
    // Ondalik sayiyi ikilik sayiya donustur
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    
    printf("Ondalik: %d -> Ikilik: ", original);
    
    // Ters sirada yazdir
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}