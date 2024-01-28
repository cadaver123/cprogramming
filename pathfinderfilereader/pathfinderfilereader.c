#include "pathfinderfilereader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Environment *load_file(char *filename) {
  FILE *file;
  char *line;
  int col_length = -1;
  size_t len = 0;
  Node *nodes = malloc(sizeof(void));

  file = fopen(filename, "r");

  if (file == NULL) {
    printf("No able to open the file.");

    fclose(file);
    return NULL;
  }

  for (int row = 0; getline(&line, &len, file) != -1; row++) {
    if (row == 0) {
      col_length = strlen(line);
    }

    if (col_length != strlen(line)) {
      printf("All lines should have the same length.");

      fclose(file);
      return NULL;
    }

    nodes = realloc(nodes, (row + 1) * col_length * sizeof(Node));

    printf("%s x", line);
    for (int col = 0; col < col_length; col++) {
      Node *node = malloc(sizeof(Node));
      char point_value = line[col];
      if (point_value == '.') {
        node->value = 1;
        continue;
      } else {
        node->value = point_value - '0';
      }
    }
  }

  fclose(file);
  return NULL;
}
