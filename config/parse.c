#include "parse.h"
#include <stdio.h>
#include <string.h>

char *get_language(FILE *file, char *language) {
  char temp[MAX_BUFFER_SIZE];
  int n = 0;

  while (fgets(temp, MAX_BUFFER_SIZE, file) != NULL) {
    if (strncmp(temp, "LANGUAGE=", 9) == 0) {
      n = sscanf(temp, "LANGUAGE=%2s", language);
      if (n == 1) {
        return language;
      }
    }
  }
  return NULL;
}

int is_valid_language(char *language) {
  char list_lan[2][3] = {"fr", "en"};

  for (int i = 0; i < 2; i++) {
    if (strcmp(language, list_lan[i]) == 0) {
      return 1;
    }
  }
  return -1;
}

char *get_music(FILE *file, char *music) {
  char temp[MAX_BUFFER_SIZE];
  int n = 0;

  while (fgets(temp, MAX_BUFFER_SIZE, file) != NULL) {
    if (strncmp(temp, "MUSIC=", 6) == 0) {
      n = sscanf(temp, "MUSIC=%10s", music);
      if (n == 1) {
        return music;
      }
    }
  }
  return NULL;
}

int is_valid_music(char *music) {
  char list_music[3][20] = {"classic", "mario", "elden_ring"};

  for (int i = 0; i < 3; i++) {
    if (strcmp(music, list_music[i]) == 0) {
      return 1;
    }
  }
  return -1;
}

char *get_difficulty(FILE *file, char *difficulty) {
  char temp[MAX_BUFFER_SIZE];
  int n = 0;

  while (fgets(temp, MAX_BUFFER_SIZE, file) != NULL) {
    if (strncmp(temp, "DIFFICULTY=", 11) == 0) {
      n = sscanf(temp, "DIFFICULTY=%6s", difficulty);
      if (n == 1) {
        return difficulty;
      }
    }
  }
  return NULL;
}

int check_difficulty(char *difficulty) {
  char list_difficulty[3][20] = {"easy", "normal", "hard"};

  for (int i = 0; i < 3; i++) {
    if (strcmp(difficulty, list_difficulty[i]) == 0) {
      return 1;
    }
  }
  return -1;
}
