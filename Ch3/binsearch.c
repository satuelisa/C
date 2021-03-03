#include <stdio.h>
#include <stdlib.h>
#define UNDEF -1

int binsearch(int, int*, int);

int main(int argc, char** args) {
  int wanted;
  int data[8] = {1, 23, 32, 56, 63, 74, 82, 92};
  int n = 8;

  wanted = 13;
  printf("%d is %sin the data\n", wanted, binsearch(wanted, data, n) != UNDEF? "" : "not ");
  wanted = 82;
  printf("%d is %sin the data\n", wanted, binsearch(wanted, data, n) != UNDEF? "" : "not ");  
  return 0;
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
