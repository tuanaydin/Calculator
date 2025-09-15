#ifndef FILE3_H
#define FILE3_H

int topla(int a, int b);
int cikar(int a, int b);
int carp(int a, int b);
int bol(int a, int b);
/*@
  requires \true;
  ensures (\old(b) == 0 ==> \result == 1);
  ensures (\old(b) != 0 ==> \result == \old(b));
*/
int f(int b);
void swap(int a, int b);
#endif
