#include <stdio.h>
#define DIFF 'a' - 'A'

int mylower(char c) {
  return (c >= 'A' && c <= 'Z') ? c + DIFF : c;
}

int main(int argc, char** args) {
  int c;
  while ((c = getchar()) != EOF) {
    putchar(mylower(c));
  }
  return 0;
}
