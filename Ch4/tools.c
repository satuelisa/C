#include <math.h>
#include <stdio.h>
#include "tools.h"

int prime(unsigned int n) { 
  if (n < 4) {
    return TRUE;
  }
  if (n % 2 == 0) {
    return FALSE;
  }
  for (int div = 3; div < (int)ceil(sqrt(n)) && div < n; div += 2) {
     if (n % div == 0) {
      return FALSE;
    }
  }
  return TRUE;
}

float mylog2(float n) {
  return (log(n) / log(2));
}

int bindigits(unsigned int n) {
  return (int)floor(mylog2(n)) + 1;
}

void bits(unsigned int n, unsigned int l) {
  int i;
  for (i = l - 1; i >= 0; i--) {
    printf("%d", ((1 << i) & n) ? 1 : 0);
  }
  printf("\n");
  return;
}

