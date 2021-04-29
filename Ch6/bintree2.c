#include <stdio.h> // printf
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#define DEBUG 1
typedef struct treenode {
  char value;
  unsigned int counter;
  unsigned int depth;
  struct treenode* leftChild;
  struct treenode* rightChild;
} node;

void erase(node* pos) {
  if (pos != NULL) {
    erase(pos->leftChild);
    erase(pos->rightChild);
    free(pos);
  }
  return;
}

void set_depth(node* pos, int d) {
  pos->depth = d;
  if (pos->leftChild != NULL) {
    set_depth(pos->leftChild, d + 1);
  }
  if (pos->rightChild != NULL) {
    set_depth(pos->rightChild, d + 1);
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
      temp = insert(value, pos->leftChild);
      if (pos->leftChild == NULL) {
	pos->leftChild = temp;
      }
    } else {
      temp = insert(value, pos->rightChild); // value is larger
      if (pos->rightChild == NULL) {
	pos->rightChild = temp;
      }
    }
  }
  return pos;
}

node* eliminar(char value, node* pos) { // WORK IN PROGRESS
  node* hijo;
  node* padre;
  node* izq;
  node* der;
  int count;
  if (pos != NULL) {
    if (pos->value == value) {
      --(pos->counter);
      if (pos->counter == 0) {
#ifdef DEBUG
	printf("%c ya no tiene ocurrencias\n", value);
#endif
	if (pos->leftChild == NULL && pos->rightChild == NULL) {
#ifdef DEBUG
	  printf("%c no tiene hijos\n", value);
#endif
	  free(pos);
	  return NULL;
	} else if (pos->leftChild != NULL && pos->rightChild == NULL) {
	  hijo = pos->leftChild;
#ifdef DEBUG
	  printf("%c tiene puro hijo izq %c\n", value, hijo->value);
#endif	  
	  free(pos);
	  return hijo;
	} else if (pos->leftChild == NULL && pos->rightChild != NULL) {
	  hijo = pos->rightChild;
#ifdef DEBUG
	  printf("%c tiene puro hijo der %c\n", value, hijo->value);
#endif	  
	  free(pos);
	  return hijo;
	} else {
	  izq = pos->leftChild;
	  der = pos->rightChild;
#ifdef DEBUG
	  printf("%c tiene dos hijos %c + %c\n", value, izq->value, der->value);
#endif
	  hijo = der;
	  while (hijo->leftChild != NULL) { // encontrar el menor a la der
	    padre = hijo;
	    hijo = hijo->leftChild;
	  }
	  if (hijo != NULL) {
#ifdef DEBUG
	    printf("voy a mover %c desde %c\n", hijo->value, padre->value);
#endif
	    padre->leftChild = NULL;
	    hijo->leftChild = izq;
	    hijo->rightChild = der;
	    return hijo; // sustituye al nodo borrado
	  } else {
	    der->leftChild = izq;
	    return der;
	  }
	}
      }
    } else if (pos->value > value) {
      pos->leftChild = eliminar(value, pos->leftChild);
    } else {
      pos->rightChild = eliminar(value, pos->rightChild);      
    }
  }
  return pos;
}

void show(node* position, char prefix) {
  int i;
  char suffix = ' ';
  if (position != NULL) {
    for (i = 0; i < position->depth; i++) {
      printf(" ");
    }
    if (position->leftChild == NULL && position->rightChild == NULL) { // no children
      suffix = '#'; // a leaf node (dead end)
    }
    printf("%c %c (%d) %c\n", prefix, position->value, position->counter, suffix);
    show(position->leftChild, '<');
    show(position->rightChild, '>');
  }
  return;
}


void alpha(node* position) {
  if (position != NULL) {
    alpha(position->leftChild);
    printf("%c", position->value);
    alpha(position->rightChild);
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
