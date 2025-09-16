#include <stdio.h>
#include "istatistik3.h"

// Ortalama 
double hesapla_ortalama(double *dizi, int boyut) {
    double toplam = 0.0;

    for(int i = 0; i < boyut; i++) {
        toplam += dizi[i];
    }
    kullaniciya();
    return toplam / boyut;
}

//Varyans
double hesapla_varyans(double *dizi, int boyut) {
    double ortalama = hesapla_ortalama(dizi, boyut);
    double varyans_toplam = 0.0;
    
    for(int i = 0; i < boyut; i++) {
        double fark = dizi[i] - ortalama;
        varyans_toplam += fark * fark;
    }
    
    return varyans_toplam / boyut;
}

// Standart sapma hesaplama 
double hesapla_standart_sapma(double *dizi, int boyut) {
    double varyans = hesapla_varyans(dizi, boyut);
    
    //  karekök  
    if(varyans == 0.0) return 0.0;
    
    double tahmin = varyans / 2.0;
    double onceki_tahmin;
    
    do {
        onceki_tahmin = tahmin;
        tahmin = (tahmin + varyans / tahmin) / 2.0;
    } while(tahmin != onceki_tahmin && (tahmin - onceki_tahmin > 0.0001 || onceki_tahmin - tahmin > 0.0001));
    
    return tahmin;
}