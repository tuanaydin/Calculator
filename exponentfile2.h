//İç kısımda yer alan fonksiyonun header'ı

#ifndef EXPONENTFILE2_H
#define EXPONENTFILE2_H


// typedef enum {
//     POW,      // x^y
//     EXP,      // e^x
//     SQRT,     // sqrt(x)
//     CBRT,     // cbrt(x)
//     SQ,       // x^2
//     CUBE,     // x^3
//     LOGE,     // ln(x)
//     LOG10,    // log10(x)
//     LOGB,     // log_y(x)  --> log(x)/log(y)
//     NTHROOT   // n'inci kök, n = y
// } op_t;

typedef enum {
    EXPF_POW,      // x^y
    EXPF_EXP,      // e^x
    EXPF_SQRT,     // sqrt(x)
    EXPF_CBRT,     // cbrt(x)
    EXPF_SQ,       // x^2
    EXPF_CUBE,     // x^3
    EXPF_LOGE,     // ln(x)
    EXPF_LOG10,    // log10(x)
    EXPF_LOGB,     // log_y(x)  --> log(x)/log(y)
    EXPF_NTHROOT   // n'inci kök, n = y
} exponent_op_t;

/* İstersen Türkçe takma adlarla da çağırabilirsin */
#define KUVVET       EXPF_POW
#define E_USSU       EXPF_EXP
#define KAREKOK      EXPF_SQRT
#define KUPKOK       EXPF_CBRT
#define KARE         EXPF_SQ
#define KUP          EXPF_CUBE
#define DOGAL_LOG    EXPF_LOGE
#define LOG10X       EXPF_LOG10
#define LOG_TABANLI  EXPF_LOGB
#define NINCI_KOK    EXPF_NTHROOT

int exponentfuncdetay(exponent_op_t op, double x, double y, double* out);


#endif // EXPONENTFILE2_H