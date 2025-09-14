#include <stdio.h>
#include "hvl2.h"

int main() {
    int a = 10, b = 5;

    dort_islem(a, b, '+');
    dort_islem(a, b, '-');
    dort_islem(a, b, '*');
    dort_islem(a, b, '/');

    return 0;
}
