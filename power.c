#include <stdio.h>

int power(int b, int e); // promesa que habra funcion

int main() {
  int b = 2, desde = 3, hasta = 12;
  for (int i = desde; i < hasta; i++) {
    printf("%d a la %d vale %d\n", b, i, power(b, i));
  }
  return 0;
}

int power(int base, int exp) { // implementacion
  int p = 1; // comenzando con un uno
  for (int i = 0; i < exp; i++) { // exp veces
    p *= base; // multiplicas
  }
  return p; // es la potencia
}
