#include <stdio.h> // printf
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower

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

node* insert(char value, node* pos, int d) {
  node* temp;
  if (pos == NULL) {
    pos = (node*)malloc(sizeof(node));
    pos->value = value;
    pos->counter = 1;
    pos->depth = d;
  } else {
    if (pos->value == value) {
      ++(pos->counter);
    } else if (pos->value > value) { // value is smaller
      temp = insert(value, pos->leftChild, d + 1);
      if (pos->leftChild == NULL) {
	pos->leftChild = temp;
      }
    } else {
      temp = insert(value, pos->rightChild, d + 1); // value is larger
      if (pos->rightChild == NULL) {
	pos->rightChild = temp;
      }
    }
  }
  return pos;
}

void show(node* position, char prefix) {
  int i;
  if (position != NULL) {
    for (i = 0; i < position->depth; i++) {
      printf(" ");
    }
    printf("%c %c (%d)\n", prefix, position->value, position->counter);
    show(position->leftChild, '<');
    show(position->rightChild, '>');
  }
  return;
}

int main() {
  node* n = NULL;
  node* tree = NULL; 
  char c;
  while (1) {
    switch (c = getchar()) {
    case '-':
      erase(tree);
      return 0;
    default:
      if (!isspace(c)) {
	n = insert(tolower(c), tree, 0);
	if (tree == NULL) {
	  tree = n; // this is the root
	}
	show(tree, '+');
      }
      break;
    }
  }
}
