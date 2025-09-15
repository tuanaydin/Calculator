#include <stdio.h>
#include "istatistik2.h"
#include "istatistik3.h"

// Internal istatiksel fonksiyonu
void internal_istatiksel(double *dizi, int boyut, char op) {
    double sonuc;
   
    switch(op) {
        case 'o':
            kullanicya();
            sonuc = hesapla_ortalama(dizi, boyut);
            printf("Ortalama: %.2f\n", sonuc);
            break;
        case 'v':
            sonuc = hesapla_varyans(dizi, boyut);
            printf("Varyans: %.2f\n", sonuc);
            break;
        case 's':
            sonuc = hesapla_standart_sapma(dizi, boyut);
            printf("Standart Sapma: %.2f\n", sonuc);
            break;
        default:
            printf("Beklenmeyen hata!\n");
            break;
    }
}