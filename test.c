#include <stdio.h>
#include "hvl2.h"
#include "donusum1.h"
int main() {
    int a = 10, b = 5;

    dort_islem(a, b, '+');
    dort_islem(a, b, '-');
    dort_islem(a, b, '*');
    dort_islem(a, b, '/');

    // Derece donusumu ornegi (Celsius to Fahrenheit)
    donusum(25, 0, 'C');
    
    // Ondalik sayidan ikilik sayiya donusum ornegi
    donusum(13, 0, 'B');
    
    // Gecersiz islem ornegi
    donusum(10, 5, 'X');


    return 0;
}
