#include "btree.h"

void push_node(Node *new_node, Node **root, int i) {
  if ((*root)->value > new_node->value) {
    new_node->left = *root;
    *root = new_node;
    return;
  } else {
    if (!(*root)->left) {
      (*root)->left = new_node;
      return;
    }
    if (!(*root)->right) {
      (*root)->right = new_node;
      return;
    }

    if ((*root)->left->value > new_node->value) {
      new_node->left = (*root)->left;
      (*root)->left = new_node;
      return;
    }
    if ((*root)->right->value > new_node->value) {
      new_node->right = (*root)->right;
      (*root)->right = new_node;
      return;
    }

    if (i % 2 == 0) {
      push_node(new_node, &(*root)->left, i - 1);
    } else {
      push_node(new_node, &(*root)->right, i - 1);
    }
  }
}
