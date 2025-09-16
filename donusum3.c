#include <stdio.h>

void rad_to_deg(float x) {
    float deg = (x * 180 / 3.1415926535);
    printf("rad: %f -> deg: %f\n", x, deg);
}

void decimal_to_binary(float x) {
    if (x == 0) {
        printf("Ondalik: 0 -> Ikilik: 0\n");
        return;
    }
    
    int decimal = (int)x;
    int binary[32];
    int i = 0;
    int original = decimal;
    
    // Ondalik sayiyi ikilik sayiya
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    
    printf("Ondalik: %d -> Ikilik: ", original);
   
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}