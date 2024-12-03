#include "parse.h"
#include <stdio.h>
#include <string.h>

char *file_to_buffer(FILE *file, char *buffer) {

  char temp[MAX_BUFFER_SIZE];

  while (fgets(temp, MAX_BUFFER_SIZE, file) != NULL) {
    strcat(buffer, temp);
  }

  return buffer;
}

char *is_language(char *buffer, char language[3]) {
  int n;
  char *line = strtok(buffer, "\n");

  while (line != NULL) {
    if (strstr(line, "Language =") == line) {
      n = sscanf(line, "Language = %2s", language);
    }

    line = strtok(NULL, "\n");
  }

  return n == 1 ? language : NULL;
}

int is_valid_language(char *language) {
  char list_lan[2][2] = {"fr", "en"};
  int count;

  for (int i = 0; i < 2; i++) {
    if (language == list_lan[i]) {
      count = 1;
    }
  }
  return count == 1 ? 0 : 1;
}
