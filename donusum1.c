#include <stdio.h>
#include "donusum1.h"
#include "donusum2.h"

static int is_func_valid(char op);

void donusum(DonusumParams params) {
    if (is_func_valid(params.op)) {
        internal_2_donusum(params);
    } else {
        printf("Gecersiz islem: %c\n", params.op);
    }
}

static int is_func_valid(char op) {
    switch (op) {
        case 'C':
        case 'B':
            return 1;
        default:
            return 0;
    }
}