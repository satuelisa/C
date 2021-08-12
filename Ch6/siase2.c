#include <stdio.h>
#include "siase2.h"

int main() {
  alumno fulano;
  fulano.c = 0;
  fulano.matr = 1726302;
  fulano.pe = "ITS";
  imprime(&fulano); // first access
  fulano.pe = "IMA"; // change of study program
  imprime(&fulano);  // second access
  return 1;
}

void imprime(alumno* a) {
  (a->c)++; //  update the access counter
  printf("%07d es %s y ha sido accedido %d veces\n", a->matr, a->pe, a->c);
  return;
}
