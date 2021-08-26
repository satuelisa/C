#include <stdio.h> 
int main() { 
  char c;
  int omitir = 0;
  int sustituir = 0;
  int brincar = 0;
  while ((c = getchar()) != EOF) { 
    if (c == '<') {  
      omitir = 1;
      c = getchar();
      if (c == '/') {
	sustituir = 0;
	if ((c = getchar()) == 's') {
	  if ((c = getchar()) == 'c') {
	    brincar = 0;
	  }
	}
      } else {
	if (c == 'h' || c == 's') {
	  if (c == 's' && (c = getchar()) == 'c') {
	    brincar = 1;
	  } 
	  sustituir = 1;
	}
      }
    } else if (c == '>') {   
      omitir = 0;
    } else {
      if  (omitir == 0 && brincar == 0) {   
	if (c == ' ') {  
	  if (sustituir == 1) {
	    c = '_'; 
	  } 
	}
	putchar(c);     
      }
    }
  }   
  return 0;
} 
