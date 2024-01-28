#include "astar.h"
#include "../pathfinderfilereader/pathfinderfilereader.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Enter filename as the first argument.\n");
    return 0;
  }

  Environment *environment = load_file(argv[1]);
}
