#ifndef FILE3_H
#define FILE3_H

int topla(int a, int b);
int cikar(int a, int b);
int carp(int a, int b);
int bol(int a, int b);
/*@
  behavior normal:
    assumes b == 0;
    ensures \result == 1;
    assigns \nothing;

  behavior undefined_case:
    assumes b != 0;
    ensures \result == 1;
    assigns \nothing;
  complete behaviors normal, undefined_case;
  disjoint behaviors normal, undefined_case;
*/
int f(int b);
void swap(int a, int b);
#endif
