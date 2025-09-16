#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdbool.h>
#include "exponentfile2.h"
#include "exponentfile3.h"

/////FILE 2 static fonk kullanımları

/* y'nin tamsayı olup olmadığını basitçe kontrol et */
static bool is_integer(double v, long long* out) {
    if (!isfinite(v)) return false;
    long long n = llround(v);
    double tol = 1e-12 * (fabs(v) + 1.0);
    if (fabs(v - (double)n) <= tol) { if (out) *out = n; return true; }
    return false;
}

/* n'inci kök (n=0, çift n & negatif x vb. durumları ele alır) */
static int nth_root(double x, long long n, double* out) {
    if (!out) { errno = EINVAL; return -1; }
    if (n == 0) { errno = EDOM; return -1; }

    long long an = (n < 0) ? -n : n;

    if (x == 0.0 && n < 0) { errno = ERANGE; return -1; }  // 0'ın negatif dereceli kökü

    if (x < 0.0) {
        if ((an & 1LL) == 0) { errno = EDOM; return -1; }   // negatifin çift kökü yok (gerçekte)
        double a = pow(-x, 1.0 / (double)an);
        *out = (n > 0) ? -a : -1.0 / a;
    } else {
        double a = pow(x, 1.0 / (double)an);
        *out = (n > 0) ? a : 1.0 / a;
    }
    return 0;
}

void exponentfuncdetay(exponent_op_t op, double x, double y, double* out) {
    if (!out) return;  // Basit null check
    
    double r = 0.0;

    switch (op) {
    case EXPF_POW:
        r = power(x, y);
        printf("%.2f^%.2f = %.6f\n", x, y, r);
        break;

    case EXPF_EXP:
        r = exponent(x);
        printf("e^%.2f = %.6f\n", x, r);
        break;

    case EXPF_SQRT:
        if (x < 0.0) { 
            printf("Hata: Negatif sayının karekökü alınamaz\n");
            r = 0.0;  // Hata durumunda 0 döndür
        } else {
            r = square(x);
            printf("√%.2f = %.6f\n", x, r);
        }
        break;

    case EXPF_CBRT:
        r = kupkok(x);
        printf("∛%.2f = %.6f\n", x, r);
        break;

    case EXPF_SQ:
        r = x * x;
        printf("(%.2f)² = %.6f\n", x, r);
        break;

    case EXPF_CUBE:
        r = x * x * x;
        printf("(%.2f)³ = %.6f\n", x, r);
        break;

    case EXPF_LOGE:
        if (x <= 0.0) { 
            printf("Hata: Sıfır veya negatif sayının doğal logaritması alınamaz\n");
            r = 0.0;  // Hata durumunda 0 döndür
        } else {
            r = log(x);
            printf("ln(%.2f) = %.6f\n", x, r);
        }
        break;

    case EXPF_LOG10:
        if (x <= 0.0) { 
            printf("Hata: Sıfır veya negatif sayının log10'u alınamaz\n");
            r = 0.0;  // Hata durumunda 0 döndür
        } else {
            r = log10(x);
            printf("log₁₀(%.2f) = %.6f\n", x, r);
        }
        break;

    case EXPF_LOGB:
        if (x <= 0.0) { 
            printf("Hata: Sıfır veya negatif sayının logaritması alınamaz\n");
            r = 0.0;  // Hata durumunda 0 döndür
        } else if (!(y > 0.0) || fabs(y - 1.0) < 1e-12) { 
            printf("Hata: Geçersiz logaritma tabanı\n");
            r = 0.0;  // Hata durumunda 0 döndür
        } else {
            r = log(x) / log(y);
            printf("log₍%.2f₎(%.2f) = %.6f\n", y, x, r);
        }
        break;

    case EXPF_NTHROOT: {
        long long n;
        if (!is_integer(y, &n)) { 
            printf("Hata: Kök derecesi tamsayı olmalıdır\n");
            r = 0.0;  // Hata durumunda 0 döndür
        } else {
            // Basitleştirilmiş n'inci kök hesabı
            if (n == 0) {
                printf("Hata: Sıfırıncı kök tanımsızdır\n");
                r = 0.0;
            } else if (n > 0) {
                if (x < 0.0 && (n % 2 == 0)) {
                    printf("Hata: Negatif sayının çift dereceli kökü alınamaz\n");
                    r = 0.0;
                } else {
                    r = pow(x, 1.0 / (double)n);
                    printf("%lld√%.2f = %.6f\n", n, x, r);
                }
            } else {
                // Negatif derece
                if (x == 0.0) {
                    printf("Hata: Sıfırın negatif dereceli kökü tanımsızdır\n");
                    r = 0.0;
                } else {
                    r = 1.0 / pow(x, 1.0 / (double)(-n));
                    printf("%lld√%.2f = %.6f\n", n, x, r);
                }
            }
        }
        break;
    }

    default:
        printf("Hata: Geçersiz işlem kodu\n");
        r = 0.0;
        break;
    }

    // Sonucu out parametresine yaz
    *out = r;
}

int swapdeneme(int g, int f) {
    // Bu fonksiyonun implementasyonu gerekirse eklenebilir
    return g + f;  // Örnek implementation
}