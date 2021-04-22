#include <stdio.h> // for printf
#include "siase.h" // our new header

int main() {
  alumno fulano;
  struct estudiante wey;
  fulano.matr = 123456;
  fulano.pe = "ITS";
  imprime(fulano);
  wey.matr = 1234567;
  wey.pe = "IMA";
  imprime(wey);  
  return 1;
}

void imprime(alumno a) {
  // print the first field always with seven digits
  // add leading zeroes to fill the digits if they are fewer
  printf("%07d es %s\n", a.matr, a.pe);
  return;
}
