#ifndef CONFIG_H
#define CONFIG_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct
{
    SDL_Keycode moveLeft;
    SDL_Keycode moveRight;
    SDL_Keycode drop;
    SDL_Keycode rotate;
    SDL_Keycode hardDrop;
    SDL_Keycode quit;
} KeyBindings;

typedef struct Settings
{
    KeyBindings keyBindings;
    int initialLevel;
    int gridWidth;
    int gridHeight;
} Settings;

SDL_Keycode StringToKeycode(const char *key);
bool LoadSettings(Settings *settings, const char *filePath);

#endif
