#include <stdio.h>
#include <string.h>
#include <ctype.h>

int trim(char*);

int main(int argc, char** args) {
  int o, t, i = 1;
  for (; i < argc; i++) {
    o = strlen(args[i]);
    t = trim(args[i]);
    printf("%d %s\n", o - t, args[i]);
  }
  return 0;
}

int trim(char* s) {
  int n = strlen(s) - 1;
  for (; n >= 0; n--) {
    if (!isspace(s[n])) {
      break;
    }
  }
  s[n + 1] = '\0';
  return n;
}
