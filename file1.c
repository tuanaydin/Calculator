#include <stdio.h>
#include "file1.h"
#include "file2.h"

static int is_func_valid(char op);

void deneme(int x, int y, char op) {
    if (is_func_valid(op)) {
        internal_2_deneme(x, y, op);
    } else {
        printf("Gecersiz islem: %c\n", op);
    }
}
//deneme123
int is_func_valid(char op) {
    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}
