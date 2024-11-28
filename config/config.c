#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool LoadSettings(Settings *settings, const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if (file == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier de configuration.\n");
        return false;
    }
}
