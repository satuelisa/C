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

int main() {
  node* n = NULL;
  node* tree = NULL; 
  char c;
  while (1) {
    switch (c = getchar()) {
    case '-':
      erase(tree);
      return 0;
    case '!':
      show(tree, '+');
      break;
    case '?':
      alpha(tree);
      printf("\n");
    default:
      if (!isspace(c)) {
	n = insert(tolower(c), tree, 0);
	if (tree == NULL) {
	  tree = n; // this is the root
	}
      }
      break;
    }
  }
}
