#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "config.h"

bool LoadSettings(Settings *settings, const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if (file == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier de configuration.\n");
        return false;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        char key[50], value[50];
        if (sscanf(line, "%49[^=]=%49s", key, value) == 2)
        {
            if (strcmp(key, "moveLeft") == 0)
                settings->keyBindings.moveLeft = value[0];
            else if (strcmp(key, "moveRight") == 0)
                settings->keyBindings.moveRight = value[0];
            else if (strcmp(key, "drop") == 0)
                settings->keyBindings.drop = value[0];
            else if (strcmp(key, "rotate") == 0)
                settings->keyBindings.rotate = value[0];
            else if (strcmp(key, "hardDrop") == 0)
                settings->keyBindings.hardDrop = value[0];
            else if (strcmp(key, "quit") == 0)
                settings->keyBindings.quit = value[0];
        }
    }

    fclose(file);
    return true;
}
