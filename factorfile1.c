#include <stdio.h>
#include "factorfile1.h"
#include "factorfile2.h"


void factorgenel(char op, unsigned int n, unsigned int r, unsigned long long *result) {
    factor(op, n, r, result);
}