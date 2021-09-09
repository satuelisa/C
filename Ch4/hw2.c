#include <stdlib.h>
#include "tools.h"

int main(int argc, char** args) {
  unsigned int k, n = 1, c = 0, p, l;
  k = atoi(args[1]);
  while (c < k) {
    p = prime(n);
    l = p ? n : l;
    n++;
    c += p;
  }
  c = bindigits(l);
  n = 1;
  while (n <= l) {
    p = prime(n);
    if (p) {
      bits(n, c);
    }
    n++;
  }
  return 0;
}
