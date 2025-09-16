#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdbool.h>
#include "exponentfile2.h"
#include "exponentfile3.h"
#include <limits.h>


double power(double x,double y) {return pow(x,y);}
double exponent(double x) {return exp(x);}
double square(double x) {return sqrt(x);}
double kupkok(double x) {return cbrt(x);}

//ACSL gövde yok annotation var   
/*@
  requires min <= max;
  ensures  \result >= min && \result <= max;
  ensures  (x < min) ==> (\result == min);
  ensures  (x > max) ==> (\result == max);
  ensures  (x >= min && x <= max) ==> (\result == x);
  assigns  \nothing;
*/
int clamp_int(int x, int min, int max);



//Body yok
int mutlak(int x);
