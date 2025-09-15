#include <stdio.h>
#include "istatistik1.h"
#include "istatistik2.h"

static int is_func_valid(char op);

// Ana istatiksel fonksiyonu
void istatistik(double *dizi, int boyut, char op)
{
    if (is_func_valid(op))
    {
        internal_istatiksel(dizi, boyut, op);
    }
    else
    {
        printf("Gecersiz islem: %c\n", op);
    }
}
int is_func_valid(char op)
{
    switch (op)
    {
    case 'o':
    case 'v':
    case 's':
        return 1;
    default:
        return 0;
    }
}
