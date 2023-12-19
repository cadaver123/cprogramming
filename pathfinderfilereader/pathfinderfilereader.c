#include "pathfinderfilereader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Environment *load_file(char *filename) {
  FILE *file;
  char *line;
  int col_count = -1;
  size_t len = 0;

  file = fopen(filename, "r");

  if (file == NULL) {
    printf("No able to open the file.");

    fclose(file);
    return NULL;
  }

  while (getline(&line, &len, file) != -1) {
    if (col_count == -1) {
      col_count = strlen(line);
    } else if (col_count != strlen(line)) {
      printf("All line should have the same length.");

      fclose(file);
      return NULL;
    }

    printf(line);
  }

  fclose(file);
  return NULL;
}
