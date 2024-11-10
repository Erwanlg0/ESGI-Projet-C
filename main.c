#include "config/parse.h"

int main() {

  FILE *file = fopen("text.txt", "r");
  char *buffer = malloc(sizeof(char) * MAX_LINE);

  if (file == NULL)
    return 1;

  buffer = file_to_buffer(file, buffer);
  printf("%s", buffer);
}
