#include <stdio.h>
#define MAX 80

char linea[MAX];
char mayor[MAX];
int m = 0;

int saca();
void copia();

int main() {
  int l = 0;
  extern int m;
  while ((l = saca()) > 0) { // no vacia
    if (l > m) { // es mas largo
      copia();
      m = l;
    }
  }
  if (m > 0) {
    printf("mayor largo fue de %d con <%s>\n", m, mayor);
  }
  return 0;
}

int saca() {
  extern char linea[];
  int c, i = 0;
  for (; i < MAX - 1; i++) {
    c = getchar();
    if (c == EOF) { // not using && anymore
      break;
    } else if (c == '\n') {
      i++; // si da cero, termina de leer
      break;
    }
    linea[i] = c;
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return i; // cual fue el largo
}

void copia() {
  extern char linea[], mayor[];
  int i = 0;
  while ((mayor[i] = linea[i]) != '\0') { // copiar hasta topar con \0
    i++;
  }
  return;
}

  
