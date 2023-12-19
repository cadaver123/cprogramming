#include "btree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SPACE "  "

void print_tree(Node *, int);
void push_node(Node *, Node **, int);

int main() {
  int array[20] = {43,  2,  3,  4,  12,  13, 73, 54, 33, 23,
                   101, 65, 34, 87, 545, 23, 67, 89, 90, 43};

  Node root = {.value = array[0], .left = NULL, .right = NULL};
  Node *root_ptr = &root;
  Node **root_pptr = &root_ptr;

  bool pushed_to_left = false;
  for (int i = 1; i < 20; i++) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = array[i];
    push_node(new_node, root_pptr, i);
    printf("%p\n", new_node);
  }
  print_tree(root_ptr, 0);
  return 0;
}

void print_tree(Node *leaf, int lvl) {
  int i;
  if (leaf->right) {
    print_tree(leaf->right, lvl + 1);
  }

  for (i = lvl; i > 0; i--) {
    printf(SPACE);
  }
  printf("%d\n", leaf->value);

  if (leaf->left) {
    print_tree(leaf->left, lvl + 1);
  }
}
