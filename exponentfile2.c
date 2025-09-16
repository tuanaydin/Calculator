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

int exponentfuncdetay(exponent_op_t op, double x, double y, double* out)
//int exponentfuncdetay(op_t op, double x, double y, double* out) 
{
    if (!out) { errno = EINVAL; return -1; }
    errno = 0;

    double r = 0.0;

    switch (op) {
    case EXPF_POW:
        r =  power(x, y);//eklendi
        break;

    case EXPF_EXP:
        r = exponent(x);
        break;

    case EXPF_SQRT:
        if (x < 0.0) { errno = EDOM; return -1; }
        r = square(x);
        break;

    case EXPF_CBRT:
        r = kupkok(x);           // negatifler için geçerli
        break;

    case EXPF_SQ:
        r = x * x;
        break;

    case EXPF_CUBE:
        r = x * x * x;
        break;

    case EXPF_LOGE:
        if (x <= 0.0) { errno = EDOM; return -1; }
        r = log(x);
        break;

    case EXPF_LOG10:
        if (x <= 0.0) { errno = EDOM; return -1; }
        r = log10(x);
        break;

    case EXPF_LOGB:
        if (x <= 0.0) { errno = EDOM; return -1; }
        if (!(y > 0.0) || fabs(y - 1.0) < 1e-12) { errno = EDOM; return -1; }
        r = log(x) / log(y);
        break;

    case EXPF_NTHROOT: {
        long long n;
        if (!is_integer(y, &n)) { errno = EDOM; return -1; }
        return nth_root(x, n, out);  // sonuç burada yazıldı
    }

    default:
        errno = EINVAL; return -1;
    }

    /* Ortak sonuç doğrulama: NaN -> EDOM, +/-Inf -> ERANGE */
    if (!isfinite(r)) { errno = isnan(r) ? EDOM : ERANGE; return -1; }
    *out = r;
    return 0;
}

    
    int swapdeneme(int g,int f);



