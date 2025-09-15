#include <stdio.h>
#include "hvl2.h"
#include "donusum1.h"
#include "istatistik1.h"
int main() {
    int a = 10, b = 5;

    dort_islem(a, b, '+');
    dort_islem(a, b, '-');
    dort_islem(a, b, '*');
    dort_islem(a, b, '/');

    // Derece donusumu ornegi (Celsius to Fahrenheit)
    donusum(2, 'C');
    
    // Ondalik sayidan ikilik sayiya donusum ornegi
    donusum(13, 'B');
    
    // Gecersiz islem ornegi
    donusum(10, 'X');



    double sayilar[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    int boyut = 10;
    
    printf("Veri seti: ");
    for(int i = 0; i < boyut; i++) {
        printf("%.1f ", sayilar[i]);
    }
    printf("\n\n");
    
    // Ortalama hesaplama
    istatistik(sayilar, boyut, 'o');
    
    // Varyans hesaplama
    istatistik(sayilar, boyut, 'v');
    
    // Standart sapma hesaplama
    istatistik(sayilar, boyut, 's');
    
    // Geçersiz işlem testi
    istatistik(sayilar, boyut, 'x');




    return 0;
}
