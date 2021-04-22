#include <stdio.h>
#include "siase.h"

int main() {
  alumno fulano;
  fulano.matr = 123456;
  fulano.pe = "ITS";
  imprime(fulano);
  fulano.matr = 1234567;
  fulano.pe = "IMA";
  imprime(fulano);  
  return 1;
}

void imprime(alumno a) {
  printf("%07d es %s\n", a.matr, a.pe);
  return;
}
