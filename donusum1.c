#include <stdio.h>
#include "donusum1.h"
#include "donusum2.h"

static int is_func_valid(char op);

void donusum(int x, int y, char op) {
    if (is_func_valid(op)) {
        internal_2_donusum(x, y, op);
    } else {
        printf("Gecersiz islem: %c\n", op);
    }
}


int is_func_valid(char op) {
    switch (op) {
        case 'C':
        case 'B':
            return 1;
        default:
            return 0;
    }
} 