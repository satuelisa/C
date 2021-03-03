#include <stdio.h>

void shellsort(int*, int);

int main(int argc, char** args) {
  int wanted;
  int data[8] = {92, 1, 56, 23, 32, 82, 63, 74};
  int i, n = 8;

  shellsort(data, n);
  for (i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
  return 0;
}

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
