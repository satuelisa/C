#include <stdio.h>

int main() {
  long nc;
  for (nc = 0; getchar() != EOF; nc++); // los for son tan chiquillos
  printf("A total of %ld characters.\n",  nc);
  return 1;
}
