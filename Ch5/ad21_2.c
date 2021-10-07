#include <stdio.h>
#include <stdlib.h> // atoi

float sum(float a, float b) {
  return a + b;
}

int main(int argc, char** argv) {
  float x, y;
  if (argc < 3) {
    printf("Please provide two numbers on command line\n");
    return 0;
  }
  x = atof(argv[1]);
  y = atof(argv[2]);
  printf("%.2f + %.2f = %.2f\n", x, y, sum(x, y));
  return 13;
}
