#include <stdio.h>
#include "hvl2.h"

int main() {
    int a = 10, b = 5;

    dort_islem(a, b, '+');
    dort_islem(a, b, '-');
    dort_islem(a, b, '*');
    dort_islem(a, b, '/');

  //  donusum(1, 180, 0);   // 180 derece -> radyan
   // donusum(2, 42, 0);    // 42 ondalık -> ikilik


    return 0;
}
