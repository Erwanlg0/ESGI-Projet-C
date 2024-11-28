#ifndef CONFIG_H
#define CONFIG_H

#include <stdbool.h>

typedef struct
{
    char moveLeft;
    char moveRight;
    char drop;
    char rotate;
    char hardDrop;
    char quit;
} KeyBindings;

typedef struct
{
    KeyBindings keyBindings;
    int initialLevel;
    int gridWidth;
    int gridHeight;
} Settings;

bool LoadSettings(Settings *settings, const char *filePath);

#endif
