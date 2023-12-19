#ifndef PATHREADER_H
#define PATHREADER_H
enum Direction { L, LU, U, RU, R, RB, B, LB };

typedef struct Node Node;
typedef struct Environment Environment;

struct Node {
  Node *neighbours[8];
};

struct Environment {
  int size_x;
  int size_y;
  Node *nodes;
};

Environment *load_file(char *filename);
#endif
