#include <stdio.h>

int mystrlen(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++);
  return i;
}

int main(int argc, char** args) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("The length of <%s> is %d.\n", args[i], mystrlen(args[i]));
  }
  return 0;
}
