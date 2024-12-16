#include <SDL2/SDL.h>
#include "input.h"

void HandleInput(Game *game, const Settings *settings)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            game->state = GAME_OVER;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;

            if (key == settings->keyBindings.moveLeft)
                Game_MoveLeft(game);
            else if (key == settings->keyBindings.moveRight)
                Game_MoveRight(game);
            else if (key == settings->keyBindings.drop)
                Game_Drop(game);
            else if (key == settings->keyBindings.rotate)
                Game_Rotate(game);
            else if (key == settings->keyBindings.hardDrop)
                Game_HardDrop(game);
            else if (key == settings->keyBindings.quit)
                game->state = GAME_OVER;
        }
    }
}
