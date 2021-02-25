#include <stdio.h>
#include <string.h> // strstr

#define MAX 80
#define TRUE 1
#define FALSE 0

int main() {
  int c, skip = FALSE, bold = FALSE, fresco;
  while ((c = getchar()) != EOF) {
    if (c == '<') { // si comienza un tag
      skip = TRUE;
      fresco = TRUE;
    } else if  (c == '>') { // si cierra un tag
      skip = FALSE;
    } else if (!skip) { // si no estamos omitiendo
      if (c == ' ' && bold) {
	putchar('_');
      } else {
	putchar(c);
      }
    } else { // si estamos omitiendo y no es <>
      if (fresco && c == 'h') { // si es un h (version de hueva de checar por heading)
	bold = TRUE; // empezar bold
      } else if (c == '/') { // si va cerrando un tag
	bold = FALSE; // quitar bold (version hueva)
      }
      fresco = FALSE;
    }
  }
  return 0;
}

  
