#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#define PRESENT 1 // true
#define ABSENT 0 // false
#define ACTIVE 1 // true
#define INACTIVE 0 // false
#define UNDEFINED INT_MAX
#define COUNT 3

// #define DEBUG 42 // hide extra printouts
#define VERBOSE 7 // some intermediate printouts

int main() {
  int var[COUNT]; // A at 0, B at 1, C at 2
  int ov, lv, rv; // current values
  int p, read, aux; // auxiliary
  int l, r, o, assign, skip; // definition flags
  char c;

  p = read = ov = lv = rv = UNDEFINED;
  l = r = o = ABSENT;
  assign = skip = INACTIVE;

  for (p = 0; p < COUNT; p++) { 
    var[p] = UNDEFINED; // initially undefined
  }
  
  while ((c = getchar()) != EOF) {
#ifdef DEBUG
    if (c != '\n') {
      printf("Read as input <%c>.\n", c);
      if (skip == ACTIVE) {
	printf("Skipping input <%c>.\n", c);
      }
    }
#endif          
    if (c == '\n') { // newline
      if (o == PRESENT) {
	printf("The value of the expression is %d.\n", ov);
      }
      skip = INACTIVE;
    } else if (skip == ACTIVE) {
#ifdef VERBOSE
      printf("Skipping input <%c>.\n", c);
#endif
      continue;
    } else if (isdigit(c)) { // a number
      aux = c - '0'; // single digit value
#ifdef DEBUG
      printf("Processing a digit %d.\n", aux);
#endif
      if (assign == ACTIVE) { // a variable is actively being assigned
	if (p == UNDEFINED) {
	  printf("ERROR: Attempting to assign before identifying the variable.\n");
	  skip = ACTIVE;	  
	} else {
#ifdef DEBUG
	  printf("Assigning value %d to variable position %d.\n", aux, p);
#endif
	  var[p] = aux;
	  assign = INACTIVE;
	  read = p = UNDEFINED;
	  printf("Variable set to %d.\n", aux);
	  continue;
	}
      } else { // being used
#ifdef DEBUG
	printf("Storing the value <%d> to an operand.\n", aux);
#endif
	if (l == ABSENT) {
	  lv = aux;
	  l = PRESENT;
#ifdef DEBUG
	  printf("It went to the left side.\n");
#endif	  
	  continue;
	} else if (r == ABSENT) {
	  rv = aux;
	  r = PRESENT;
#ifdef DEBUG
	  printf("It went to the right side.\n");
#endif	  	  
	  continue;
	} else {
	  printf("ERROR: Too many operands.\n");
	  skip = ACTIVE;	  
	}
      }
    } else if (isalpha(c)) { // a letter
      c = toupper(c);
#ifdef DEBUG
      printf("Accessing [%c].\n", c);
#endif      
      p = c - 'A';
      if (p >= COUNT) {
	printf("ERROR: unknown variable (only ABC exist).\n");
	skip = ACTIVE;
      } else {
	if (assign == ACTIVE) { // it is being defined
#ifdef DEBUG
	  printf("A variable is being defined for position <%d>.\n", p);
#endif      
	} else { // not being assigned but being used
#ifdef DEBUG
	  printf("A variable at position <%d> is being used.\n", p);
#endif      
	  aux = var[p]; // get its value
	  if (aux == UNDEFINED) {
	    printf("ERROR: variable %c undefined.\n", c);
	    skip = ACTIVE;	    
	  } else { // this part would make a neat subroutine :)
	    if (l == ABSENT) {
	      lv = aux;
	      l = PRESENT;
	      continue;
	    } else if (r == ABSENT) {
	      rv = aux;
	      r = PRESENT;
	      continue;
	    } else {
	      printf("ERROR: Too many operands.\n");
	      skip = ACTIVE;	      
	    }	  
	  }
	}
      }	  
    } else { // an operator
#ifdef DEBUG
      printf("Expecting an operator.\n");
#endif            
      if (c == '=') { // assigning a variable (using notation =A2 to assign 2 to A)
	assign = ACTIVE;
	continue;
      }
      if (!(l == PRESENT && r == PRESENT)) {
	printf("ERROR: Missing operand.\n");
	skip = ACTIVE;
      } else {
	switch (c) {
	case '+':
	  ov = lv + rv;
#ifdef VERBOSE
	  printf("Calculating %d + %d = %d.\n", lv, rv, ov);
#endif            		
	  o = PRESENT;
	  break;	
	case '-':
	  ov = lv - rv;
#ifdef VERBOSE
	  printf("Calculating %d - %d = %d.\n", lv, rv, ov);
#endif            			
	  o = PRESENT;
	  break;
	case '*':
	  ov = lv * rv;
#ifdef VERBOSE
	  printf("Calculating %d * %d = %d.\n", lv, rv, ov);
#endif            				
	  o = PRESENT;
	  break;	
	default: 
	  printf("ERROR: Unknown operator (only +*- are known).\n");
	  skip = ACTIVE;	
	}
	if (o == PRESENT) { // a new value was computed
	  lv = ov;
	  l = PRESENT;
	  r = ABSENT;
#ifdef DEBUG
	  printf("Moved the result to the left side.\n");
#endif
	  continue; // no reset
	}
      }
    }
    l = r = o = ABSENT; // reset
#ifdef DEBUG
    printf("Resetting the operands.\n");
#endif            	    
  }
  printf("Bye!\n");
  return 0;
}
