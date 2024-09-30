#include <stdio.h>
#include <stdlib.h>
#include "src/parser.h"


int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  int number_line = get_number_line_in_file(argv[1]);

  printf("Number of lines in file: %d\n", number_line);

  return 0;


}


