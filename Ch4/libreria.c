#include "libreria.h"

void shellsort(int v[], int n) {
  int i, j, g, t;
  for (g = n / 2; g > 0; g >>= 1) {
    for (i = g; i < n; i++) {
      for (j = i - g; j >= 0 && v[j] > v[j + g]; j -= g) {
	t = v[j]; // swap
	v[j] = v[j + g];
	v[j + g] =  t;
      }
    }
  }
  return;
}

int binsearch(int x, int v[], int n) {
  int l = 0, h = n - 1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (x < v[m]) {
      h = m - 1;
    } else if (x > v[m]) {
      l = m + 1;
    } else {
      return m;
    }
  }
  return UNDEF;
}
