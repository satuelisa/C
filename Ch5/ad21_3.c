#include <stdio.h>
#include <stdlib.h> // atoi

float plus(float a, float b) {
  return a + b;
}

float minus(float a, float b) {
  return a - b;
}

float times(float a, float b) {
  return a * b;
}

int main(int argc, char** argv) {
  char o;
  float x, y;
  float (*f)(float, float);
  
  if (argc < 4) {
    printf("Provide <n1> <op> <n2> on command line\n");
    return 0;
  }
  x = atof(argv[1]);
  o = argv[2][0];
  y = atof(argv[3]);
  switch  (o) {
  case '+':
    f = &plus;
    break;
  case '-':
    f = &minus;
    break;
  case '*':
  case 'x':
    f = &times;
    break;
  default:
    printf("Unknown operator; use +-x\n");
    return 1;
  }
  printf("%.2f %c %.2f = %.2f\n", x, o, y, f(x, y));
  return 2;
}
