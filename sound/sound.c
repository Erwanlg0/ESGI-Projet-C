#include <SDL2/SDL_mixer.h>

if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
{
    printf("Erreur d'initialisation: %s\n", SDL_GetError());
    return 1;
}

if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
{
    printf("Erreur d'initialisation: %s\n", Mix_GetError());
    SDL_Quit();
    return 1;
}