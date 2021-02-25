#include <stdio.h>

int main() {
  long nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }
  printf("A total of %ld characters.\n",  nc);
  return 1;
}
