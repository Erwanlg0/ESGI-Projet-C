#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <SDL2/SDL.h>
#include "config.h"

SDL_Keycode StringToKeycode(const char *key)
{
    if (strcmp(key, "space") == 0)
        return SDLK_SPACE;
    if (strcmp(key, "escape") == 0)
        return SDLK_ESCAPE;
    if (strlen(key) == 1)
        return SDL_Keycode(key[0]);
    return 0;
}

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
                settings->keyBindings.moveLeft = StringToKeycode(value);
            else if (strcmp(key, "moveRight") == 0)
                settings->keyBindings.moveRight = StringToKeycode(value);
            else if (strcmp(key, "drop") == 0)
                settings->keyBindings.drop = StringToKeycode(value);
            else if (strcmp(key, "rotate") == 0)
                settings->keyBindings.rotate = StringToKeycode(value);
            else if (strcmp(key, "hardDrop") == 0)
                settings->keyBindings.hardDrop = StringToKeycode(value);
            else if (strcmp(key, "quit") == 0)
                settings->keyBindings.quit = StringToKeycode(value);
        }
    }

    fclose(file);
    return true;
}
