#include "../game/game.h"
#include <stdio.h>

bool saveScore(Game *game) {
  FILE *file = fopen("score.txt", "w");
  if (file == NULL) {
    printf("Erreur : impossible d'ouvrir le fichier de configuration.\n");
    return false;
  }

  fprintf(file, "Votre score de partie est %d", game->score);

  fclose(file);

  return true;
}
