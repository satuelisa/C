#include <stdio.h>

void squeeze(char s[], char c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++) {
    if (s[i] != c) {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
  return;
}

int main(int count, char** a) {
  int i = 2;
  char c = a[1][0];
  for (; i < count; i++) {
    squeeze(a[i], c);
    printf("%s\n", a[i]); 
  }
  return 0;
}
