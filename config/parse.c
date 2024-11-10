#include "parse.h"
#include <string.h>

char *file_to_buffer(FILE *file, char *buffer) {

  char temp[MAX_LINE];

  while (fgets(temp, MAX_LINE, file) != NULL) {
    strcat(buffer, temp);
  }

  return buffer;
}
