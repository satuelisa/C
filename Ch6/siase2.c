#include <stdio.h>
#include "siase2.h"

int main() {
  alumno fulano;
  fulano.c = 0;
  fulano.matr = 123456;
  fulano.pe = "ITS";
  imprime(&fulano);
  fulano.pe = "IMA";
  imprime(&fulano);  
  return 1;
}

void imprime(alumno* a) {
  (a->c)++;
  printf("%07d es %s y ha sido accedido %d veces\n", a->matr, a->pe, a->c);
  return;
}
