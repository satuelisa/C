#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1

int factorial(int k) {
  if (k == 1) {
    return 1;
  } else if (k < 1) {
    return ERROR;
  }
  return k * factorial(k - 1);
}

int palindrome(char* s, int start, int end) {
  if (start >= end) {
    return TRUE;
  } else if (s[start] != s[end]) {
    return FALSE;
  }
  return palindrome(s, start + 1, end - 1);
}

int main(int c, char** a) {
  int i, l, f;

  f = factorial(c);
  if (f != ERROR) {
    printf("%d! = %d\n", c, f);
  }
  for (i = 1; i < c; i++) {
    l = strlen(a[i]);
    printf("%s is %sa palindrome\n", a[i], palindrome(a[i], 0, l - 1) ? "" : "not ");
  }
  return 0;
}
