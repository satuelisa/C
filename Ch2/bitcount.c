#include <stdio.h> // printf
#include <stdlib.h> // atoi

int bitcount(unsigned);

int main(int argc, char** args) {
  int i;
  for (i = 1; i < argc; i++) {
    printf("%s -> %d\n", args[i], bitcount((unsigned)atoi(args[i])));
  }
}

int bitcount(unsigned x) {
  int b = 0;
  for (; x != 0; x >>= 1) {
    if (x % 2 == 1) {
      b++;
    }
  }
  return b;
}

