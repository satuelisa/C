#include <stdio.h>
#include <ctype.h> 

#define VOWEL 0
#define CONSONANT 1
#define DIGIT 2
#define SPACE 3
#define OTHER 4
#define MAX 5

int main() {
  char i;
  int j, c[MAX]; 

  for (j = 0; j < MAX; j++) {
    c[j] = 0;
  }
  
  
  while ((i = getchar()) != '\n') {
    if (isdigit(i)) {
      c[DIGIT]++;
    } else if (isspace(i)) {
      c[SPACE]++;      
    } else if (isalpha(i)) {
      i = toupper(i);
      if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
	c[VOWEL]++;
      } else {
	c[CONSONANT]++;	
      }
    } else {
      c[OTHER]++;
    }
  }
  printf("There were %d digits.\n", c[DIGIT]);
  printf("There were %d spaces.\n", c[SPACE]);
  printf("There were %d vowels.\n", c[VOWEL]);
  printf("There were %d consonants.\n", c[CONSONANT]);
  printf("There were %d other characters.\n", c[OTHER]);
  return 0;
}
