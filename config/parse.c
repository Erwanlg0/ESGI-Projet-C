#include "parse.h"
#include <string.h>

char *file_to_buffer(FILE *file, char *buffer) {

  char temp[MAX_BUFFER_SIZE];

  while (fgets(temp, MAX_BUFFER_SIZE, file) != NULL) {
    strcat(buffer, temp);
  }

  return buffer;
}
