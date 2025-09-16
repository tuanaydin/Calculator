#include <stdio.h>
#include "factorfile1.h"
#include "factorfile2.h"


int factorgenel(char op, unsigned int n, unsigned int r, unsigned long long *result) {
    return factor(op, n, r, result);
}