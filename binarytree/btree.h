typedef struct Node {
  struct Node *left;
  struct Node *right;
  int value;
} Node;

void push_node(Node *new_node, Node **root, int i);
