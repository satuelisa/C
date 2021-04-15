#include <stdio.h>

void intercambio(int x, int y) {
  int temporary = x;
  printf("x = %d, y = %d\n", x, y);
  x = y;
  y = temporary;
  printf("x = %d, y = %d\n", x, y);
  return;
}

void de_verdad(int* x, int* y) {
  int temporary = *x;
  printf("x = %d, y = %d\n", *x, *y);
  *x = *y;
  *y = temporary;
  printf("x = %d, y = %d\n", *x, *y);
  return;
}

int main() {
  int regular = 7;
  int similar = 8;
  int* puntero = &regular;
  int* otro = &similar;
  
  *puntero = 13;
  ++(*otro);
  (*otro)++;
  printf("%d & %d\n", regular, *otro);  
  intercambio(regular, similar);
  printf("%d & %d\n", regular, *otro);
  de_verdad(puntero, &similar);
  printf("%d & %d\n", regular, *otro);
  return 1;
}
