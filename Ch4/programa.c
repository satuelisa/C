#include <stdio.h>
#include "libreria.h"

int main(int argc, char** args) {
  int data[8] = {92, 1, 56, 23, 32, 82, 63, 74};
  int i, w, n = 8;
  shellsort(data, n);
  w = 79;
  printf("%d is %sin the data\n", w, binsearch(w, data, n) != UNDEF? "" : "not ");
  w = 82;
  printf("%d is %sin the data\n", w, binsearch(w, data, n) != UNDEF? "" : "not ");  
  return 0;
}
