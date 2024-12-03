#include "config/parse.h"

int main() {

  FILE *file = fopen("text.txt", "r");
  char *buffer = malloc(sizeof(char) * MAX_BUFFER_SIZE);
  char *language = malloc(sizeof(char) * 3);

  if (file == NULL)
    return 1;

  buffer = file_to_buffer(file, buffer);
  printf("%s", buffer);

  language = is_language(buffer, language);
  if (is_valid_language(language) == 1) {
    printf("Langue non prise en compte");
    return 1;
  }
  printf("%s", language);
}
