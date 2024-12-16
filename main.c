#include "config/config.h"

int main() {

  char *language = malloc(sizeof(char) * 3);
  char *music = malloc(sizeof(char) * 20);
  char *difficulty = malloc(sizeof(char) * 6);
  int *width = malloc(sizeof(int));
  int *height = malloc(sizeof(int));
  FILE *file = fopen("text.txt", "r");

  if (file == NULL)
    return 1;

  int res = check_config(file, language, difficulty, music);
  int error = check_win_size(file, width, height);
  if (!error || !res) {
    exit(0);
  }
}
