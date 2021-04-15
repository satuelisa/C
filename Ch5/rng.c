#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** args) {
  int count = atoi(args[1]);
  int limit = atoi(args[2]);
  int i;
  if (argc > 3) {
    srand(atoi(args[3]));
  } else {
    srand(time(NULL));
  }
  for (i = 0; i < count; i++) {
    printf("%d\n", rand() % (limit + 1));
  }
  return 0;
}
