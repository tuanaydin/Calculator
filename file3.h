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
    // Bu durumda fonksiyon çağrılmamalı; requires ile yasaklamak da bir seçenekti.
    // Burada yalnızca modele açıklık getirmek için ayrı davranış olarak işaretliyoruz.
    // WP bu davranışta herhangi bir garanti istemez.

  complete behaviors normal, undefined_case;
  disjoint behaviors normal, undefined_case;
*/
int f(int b);
void swap(int a, int b);
#endif
