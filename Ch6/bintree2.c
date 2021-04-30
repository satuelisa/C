#include <stdio.h> // printf
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#define DEBUG 1
typedef struct treenode {
  char value;
  unsigned int counter;
  unsigned int depth;
  struct treenode* izq;
  struct treenode* der;
} node;

void erase(node* pos) {
  if (pos != NULL) {
    erase(pos->izq);
    erase(pos->der);
    free(pos);
  }
  return;
}

void set_depth(node* pos, int d) {
  if (pos == NULL) {
    return; // empty tree
  }
  pos->depth = d;
  if (pos->izq != NULL) {
    set_depth(pos->izq, d + 1);
  }
  if (pos->der != NULL) {
    set_depth(pos->der, d + 1);
  }
}

node* insert(char value, node* pos) {
  node* temp;
  if (pos == NULL) {
    pos = (node*)malloc(sizeof(node));
    pos->value = value;
    pos->counter = 1;
  } else {
    if (pos->value == value) {
      ++(pos->counter);
    } else if (pos->value > value) { // value is smaller
      temp = insert(value, pos->izq);
      if (pos->izq == NULL) {
	pos->izq = temp;
      }
    } else {
      temp = insert(value, pos->der); // value is larger
      if (pos->der == NULL) {
	pos->der = temp;
      }
    }
  }
  return pos;
}

node* eliminar(char value, node* pos) { // WORK IN PROGRESS
  node* hijo;
  int count;
  if (pos != NULL) {
    if (pos->value == value) {
      --(pos->counter);
      if (pos->counter == 0) {
#ifdef DEBUG
	printf("%c ya no tiene ocurrencias\n", value);
#endif
	if (pos->izq == NULL && pos->der == NULL) {
#ifdef DEBUG
	  printf("%c no tiene hijos\n", value);
#endif
	  free(pos);
	  return NULL;
	} else if (pos->izq != NULL && pos->der == NULL) {
	  hijo = pos->izq;
#ifdef DEBUG
	  printf("%c tiene puro hijo izq %c\n", value, hijo->value);
#endif	  
	  free(pos);
	  return hijo;
	} else if (pos->izq == NULL && pos->der != NULL) {
	  hijo = pos->der;
#ifdef DEBUG
	  printf("%c tiene puro hijo der %c\n", value, hijo->value);
#endif	  
	  free(pos);
	  return hijo;
	} else {
#ifdef DEBUG
	  printf("%c tiene dos hijos %c + %c\n", value, pos->izq->value, pos->der->value);
#endif
	  hijo = pos->der;
	  while (hijo->izq != NULL) { // encontrar el menor a la der
	    hijo = hijo->izq;
	  }
#ifdef DEBUG
	  printf("voy a colgar %c desde %c\n", pos->izq->value, hijo->value);
#endif
	  hijo->izq = pos->izq;
	  free(pos);
	  return hijo; // el hijo derecho sustituye al nodo borrado
	}
      }
    } else if (pos->value > value) {
      pos->izq = eliminar(value, pos->izq);
    } else {
      pos->der = eliminar(value, pos->der);      
    }
  }
  return pos;
}

void show(node* pos, char prefix) {
  int i;
  char suffix = ' ';
  if (pos != NULL) {
    for (i = 0; i < pos->depth; i++) {
      printf(" ");
    }
    if (pos->izq == NULL && pos->der == NULL) { // no children
      suffix = '#'; // a leaf node (dead end)
    }
    printf("%c %c (%d) %c\n", prefix, pos->value, pos->counter, suffix);
    show(pos->izq, '<');
    show(pos->der, '>');
  }
  return;
}


void alpha(node* pos) {
  if (pos != NULL) {
    alpha(pos->izq);
    printf("%c", pos->value);
    alpha(pos->der);
  }
}

typedef enum { agregar, borrar } estado;

int main() {
  node* n = NULL;
  node* tree = NULL; 
  char c;
  estado e = agregar;
  while (1) {
    switch (c = getchar()) {
    case '*':
      if (e == agregar) {
	printf("<<<\n");
	e = borrar;
      } else {
	printf(">>>\n");
	e = agregar;
      }
      break;
    case '-':
      erase(tree);
      return 0;
    case '!':
      set_depth(tree, 0);
      show(tree, '+');
      break;
    case '?':
      alpha(tree);
      printf("\n");
      break;
    default:
      if (!isspace(c)) {
	if (e == agregar) {
	  n = insert(tolower(c), tree);
	  if (tree == NULL) {
	    tree = n; // this is the root
	  }
	} else {
	  tree = eliminar(tolower(c), tree);
	}
      }
      break;
    }
  }
}
