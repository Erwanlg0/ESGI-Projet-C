#include "config.h"
#include "parse.h"

int check_config(FILE *file, char *language, char *difficulty, char *music) {
  int language_error;
  int difficulty_error;
  int music_error;

  if (get_language(file, language) == NULL) {
    printf("Langue indisponible ou au mauvais format\n");
    language_error = 1;
  } else if (check_language(language) == -1) {
    printf("Langue non prise en compte\n");
    language_error = 1;
  } else {
    printf("La langue choisie est : %s\n", language);
  }

  if (get_music(file, music) == NULL) {
    printf("musique indisponible ou au mauvais format\n");
    music_error = 1;
  } else if (check_music(music) == -1) {
    printf("musique non pris en compte\n");
    music_error = 1;
  } else {
    printf("La musique choisie est : %s\n", music);
  }

  if (get_difficulty(file, difficulty) == NULL) {
    printf("difficulte indisponible ou au mauvais format\n");
    difficulty_error = 1;
  }

  else if (check_difficulty(difficulty) == -1) {
    printf("difficulte non pris en compte\n");
    difficulty_error = 1;
  } else {
    printf("La difficulte choisie est : %s\n", difficulty);
  }

  return !(language_error || music_error || difficulty_error);
}

int check_win_size(FILE *file, int *width, int *height) {
  int width_error;
  int height_error;

  if (get_width(file, width) == NULL) {
    printf("Largeur indisponible ou au mauvais format\n");
    width_error = 1;
  } else if (check_width(width) == -1) {
    printf("Hauteur non prise en compte\n");
    width_error = 1;
  } else {
    printf("La hauteur choisie est : %d\n", *width);
  }

  if (get_height(file, height) == NULL) {
    printf("Largeur indisponible ou au mauvais format\n");
    return 1;
  } else if (check_height(height) == -1) {
    printf("Hauteur non prise en compte\n");
    return 1;
  } else {
    printf("La hauteur choisie est : %d\n", *height);
  }

  return !(width_error || height);
}
