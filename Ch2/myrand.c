#include <stdio.h>
#include <stdlib.h> // atoi
#define A 1103515256
#define B 12345
#define C 65536
#define D 32768
unsigned long int next = 1;

int myrand() {
  next = A * next + B;
  return (unsigned int)(next / C) % D;
}

void mysrand(unsigned int seed) {
  next = seed;
  return;
}

int main(int argc, char** args) {
  int i, n;
  mysrand(atoi(args[1])); // set seed
  n = atoi(args[2]);

  for (i = 0; i < n; i++) {
    printf("%d ",  myrand());
  }
  printf("\n");
  return 1;
}
