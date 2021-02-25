#include <stdio.h>

#define MAX 80

// promesas
int saca(char l[], int max);
void copia(char meta[], char fuente[]);

int main() {
  int l = 0, m = 0;
  char linea[MAX];
  char mayor[MAX];

  while ((l = saca(linea, MAX)) > 0) { // no vacia
    if (l > m) { // es mas largo
      copia(mayor, linea);
      m = l;
    }
  }
  if (m > 0) {
    printf("mayor largo fue de %d con <%s>\n", m, mayor);
  }
  return 0;
}

int saca(char t[], int l) { // leer max l caracteres a t
  int c, i = 0;
  for (; i < l - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    t[i] = c;
  }
  t[i] = '\0'; // caracter de terminacion de string
  return i; // cual fue el largo
}

void copia(char t[], char s[]) { // target and source
  int i = 0;
  while ((t[i] = s[i]) != '\0') { // copiar hasta topar con \0
    i++;
  }
  return; // no regresa nada, es void
}

  
