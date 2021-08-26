#include <stdio.h>
#include <limits.h>

#define CONSTANT 17897
#define LONGERCONST 908098L
#define MAXLEN 20

int lengthOfString(char s[]) {
  int l = 0;
  while (s[l] != '\0') {
    l++;
  }
  return l;
}

int main() {

  enum valorDeVerdad { FALSO, VERDADERO };
  typedef enum valorDeVerdad bool;
  bool something = FALSO;
  
  // integers  
  short int a, b, c; // explain in comment
  int otro_numero = 12;
  long int somePeople = 123765;

  // character
  char other = 'a', d = '\n';

  // decimal values
  float x = 0.12; // floating point
  double y = 12323.23; // m * b^e [m] [e] b constant

  char line[MAXLEN + 1];
  
  line[0] = 'h';
  line[1] = 'o';
  line[2] = 'l';
  line[3] = 'a';
  line[4] = '\0';
  line[5] = 'z';
  line[6] = '.';
  line[7] = '!';
  line[8] = 'y';
  line[10] = 'z';

  printf("my truth value is %d when it is false\n", something);
  something = VERDADERO;
  printf("my truth value is %d when it is true\n", something);  
  printf("Int max is %d\n", INT_MAX);
  printf("Long int max is %ld\n", LONG_MAX);
  printf("my string is %s\n", line);
  printf("my string has length %d\n", lengthOfString(line));
  a = 23;
  b = 4;
  c = a % b;
  printf("%d mod %d is %d\n", a, b, c);
  a = 'a' - 'A';
  printf("The ASCII code for %c is %d.\n", '0', '0');
  printf("The numerical value for %c is %d.\n", '7', '7' - '0');
  other = 'P';
  printf("%c in lower case is %c\n", other, other + a);
  other = 'w';
  printf("%c in upper case is %c\n", other, other - a);

  a = 17;
  printf("a %d\n", a);
  printf("++a %d\n", ++a);
  printf("a %d\n", a);  
  printf("a++ %d\n", a++);
  printf("a %d\n", a);  
  printf("--a %d\n", --a);
  printf("a %d\n", a);  
  printf("a-- %d\n", a--);
  printf("a %d\n", a);  

  
  return 0;
}
