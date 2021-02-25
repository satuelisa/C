#include <stdio.h>
#include <string.h> // strlen
#define TRUE 1
#define FALSE 0

void squeeze(char t[], char skip[], int n) {
  int i, j ,k, ignore;
  
  for (i = j = 0; t[i] != '\0'; i++) {
    ignore = FALSE;
    for (k = 0; k < n; k++) {
      if (t[i] == skip[k]) {
	ignore = TRUE;
	break;
      }
    }
    if (!ignore) {
      t[j++] = t[i];
    }
  }
  t[j] = '\0';
  return;
}

int main(int count, char** a) {
  int i = 2;
  char* s = a[1];
  int k = strlen(s);
  for (; i < count; i++) {
    squeeze(a[i], s, k);
    printf("%s\n", a[i]); 
  }
  return 0;
}
