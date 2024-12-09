#include "config/config.h"

int main() {

  FILE *file = fopen("text.txt", "r");
  char *language = malloc(sizeof(char) * 3);
  char *music = malloc(sizeof(char) * 20);

  if (file == NULL)
    return 1;

  int res = check_config(file, language, music);
  if (!res) {
    exit(0);
  }
}
