#include <stdio.h>
#include "hvl2.h"

int main() {
    int a = 10, b = 5;

    hesapla(a, b, '+');
    hesapla(a, b, '-');
    hesapla(a, b, '*');
    hesapla(a, b, '/');

    return 0;
}
