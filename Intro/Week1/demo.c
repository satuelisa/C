#include <stdio.h>

int main () {
  int a, b, c, d, e;
  a = 123;
  b = 15;
  c = a % b; // residue (modulus) = leftovers from the division
  d = a / b; // integer division: how many times does it fit
  e = d * b + c;
  printf("%i is the same as %i", e, a);
  return 1;
}
