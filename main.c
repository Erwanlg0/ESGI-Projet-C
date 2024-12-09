#include "config/config.h"

int main() {

  FILE *file = fopen("text.txt", "r");
  char *language = malloc(sizeof(char) * 3);
  char *music = malloc(sizeof(char) * 20);
  char *difficulty = malloc(sizeof(char) * 6);

  if (file == NULL)
    return 1;

  int res = check_config(file, language, difficulty, music);
  if (!res) {
    exit(0);
  }
}
