#include <stdio.h>
#include "siase2.h"
#define CUPO 3

int main() {
  alumno grupo[CUPO];
  int i;
  for (i = 0; i < CUPO; i++) {
    grupo[i].c = 0; // inicialmente todos en ceros
  }
  grupo[0].matr = 1234567;
  grupo[1].matr = 7654321;
  grupo[2].matr = 123456; // no le pongas ceros en frente, se hace bolas
  grupo[0].pe = "IAS";
  grupo[1].pe = "IEC";
  grupo[2].pe = "IME";
  for (i = 0; i < CUPO; i++) {  
    imprime(grupo + i); // imprime todos
  }
  return 1;
}

void imprime(alumno* a) {
  (a->c)++;
  printf("%07d es %s y ha sido accedido %d veces\n", a->matr, a->pe, a->c);
  return;
}
