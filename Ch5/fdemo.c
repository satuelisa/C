#include <stdio.h>
#include <ctype.h>

int sum(int x, int y) {
  return x + y;
}

int product(int x, int y) {
  return x * y;
}

int main() {
  int a, b;
  char o;
  int (*op)(int, int); // puntero a subrutina

  a = getchar() - '0';
  o = getchar();
  b = getchar() - '0';
  switch (o) {
  case '+':
    op = &sum;
    break;
  case '*':
  case 'x':
    op = &product;
    break;
  default:
    printf("Unknown operator %c. Sorry.\n", o);
    return 2;
  }
  printf("    = %d\n", op(a, b));
  return 1;
}
