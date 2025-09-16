#include <stdio.h>
#include "hvl2.h"
#include "donusum1.h"
#include "istatistik1.h"
#include "exponentfunc1.h"
#include "factorfile1.h" 
int main() {
    int a = 10, b = 5;



    dort_islem(a, b, '+');
    dort_islem(a, b, '-');
    dort_islem(a, b, '*');
    dort_islem(a, b, '/');

 
    DonusumParams params1 = {13, 'B'};
    donusum(params1);
    
    DonusumParams params2 = {13, 'C'};
    donusum(params2);
    
    DonusumParams params3 = {13, 'X'};
    donusum(params3);
    


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

//------------------------------------------------------------------------------
    printf("\n=== Üs ve Kök Hesaplamaları ===\n\n");

      double result;
    printf("Kuvvet İşlemleri:\n");
    exponentfunc(KUVVET, 2.0, 3.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);
    
    exponentfunc(KUVVET, 5.0, 2.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);

    // e^x işlemi
    printf("Doğal Üs İşlemleri:\n");
    exponentfunc(E_USSU, 1.0, 0.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);

    // Kareköker işlemleri
    printf("Kök İşlemleri:\n");
    exponentfunc(KAREKOK, 16.0, 0.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);
    
    exponentfunc(KUPKOK, 27.0, 0.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);

    // Kare ve küp işlemleri
    printf("Kare ve Küp İşlemleri:\n");
    exponentfunc(KARE, 9.0, 0.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);
    
    exponentfunc(KUP, 3.0, 0.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);

    // Logaritma işlemleri
    printf("Logaritma İşlemleri:\n");
    exponentfunc(DOGAL_LOG, 2.718, 0.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);
    
    exponentfunc(LOG10X, 100.0, 0.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);
    
    exponentfunc(LOG_TABANLI, 8.0, 2.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);

    // N'inci kök işlemleri
    printf("N'inci Kök İşlemleri:\n");
    exponentfunc(NINCI_KOK, 32.0, 5.0, &result);
    printf("Sonuç değişkende: %.6f\n\n", result);

    // Hata durumları
    printf("Hata Durumu Testleri:\n");
    exponentfunc(KAREKOK, -4.0, 0.0, &result);
    printf("Negatif karekök hatası\n\n");
    
    exponentfunc(DOGAL_LOG, 0.0, 0.0, &result);
    printf("Sıfırın logaritması hatası\n\n");

//------------------------------------------------------------------------------
    printf("=== Faktöriyel, Permütasyon ve Kombinasyon Hesaplamaları ===\n\n");
    unsigned long long s = 0;
    // Örnek: permütasyon (geçerli örnek)
    printf("Permütasyon işlemi:\n");
    factorgenel('P', 5, 3, &s);
    printf("Dönen sonuç (değişkende): %llu\n\n", s);

    // Örnek: faktoriyel
    printf("Faktöriyel işlemi:\n");
    factorgenel('F', 10, 0, &s);
    printf("Dönen sonuç: %llu\n\n", s);

    // Örnek: kombinasyon
    printf("Kombinasyon işlemi:\n");
    factorgenel('C', 20, 6, &s);
    printf("Dönen sonuç: %llu\n\n", s);

    // Hatalı örnek (r>n olduğu için hata verir):
    printf("Hatalı örnek (r>n):\n");
    factorgenel('P', 2, 3, &s);
    printf("Dönen sonuç: %llu\n\n", s);

    // Geçersiz işlem kodu örneği
    printf("Geçersiz işlem kodu örneği:\n");
    factorgenel('X', 5, 2, &s);
    printf("Dönen sonuç: %llu\n\n", s);


    return 0;
}
