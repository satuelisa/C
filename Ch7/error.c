#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 9

int input() {
  int i, count;
  char u[MAXLEN];
  char n[MAXLEN];
  char p[MAXLEN];
  scanf("%d", &count);
  if (count < 1) {
    fprintf(stderr, "Only strictly positive counts are permitted, exiting...\n");
    exit(1);
  }
  for (i = 0; i < count;) {
    scanf("%s %s %s", n, p, u);
    printf("Student %d %s (%s) is %s\n", ++i, u, n, p);
  }
  return count;
}

int main(int c, char** d) {
  int count = input();
  fprintf(stderr, "%d records processed\n", count);
  return 0;
}
