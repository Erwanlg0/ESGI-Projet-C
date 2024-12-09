#include "config.h"
#include "parse.h"

int check_config(FILE *file, char *language, char *music) {

  if (get_language(file, language) == NULL) {
    printf("Langue indisponible ou au mauvais format");
    return 1;
  }
  if (is_valid_language(language) == -1) {
    printf("Langue non prise en compte");
    return 1;
  }
  printf("La langue choisie est : %s\n", language);

  if (get_music(file, music) == NULL) {
    printf("musique indisponible ou au mauvais format");
    return 1;
  }
  if (is_valid_music(music) == -1) {
    printf("musique non pris en compte");
    return 1;
  }
  printf("La musique choisie est : %s\n", music);

  fclose(file);

  return 0;
}
