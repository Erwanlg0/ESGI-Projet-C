#include "config/save_score.h"
#include "game/game.h"
#include "graphics/graphics.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  if (!Graphics_Init(&window, &renderer)) {
    return 1;
  }

  Game game;
  Settings settings = {.initialLevel = 1};
  Game_Init(&game, &settings);

  bool running = true;
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
          Game_MoveLeft(&game);
          break;
        case SDLK_RIGHT:
          Game_MoveRight(&game);
          break;
        case SDLK_UP:
          Game_Rotate(&game);
          break;
        case SDLK_DOWN:
          Game_Drop(&game);
          break;
        case SDLK_SPACE:
          Game_HardDrop(&game);
          break;
        case SDLK_ESCAPE:
          running = false;
          break;
        }
        break;
      }
    }

    Game_Update(&game);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    Graphics_DrawGrid(renderer);
    Graphics_DrawGridBlocks(renderer, &game);
    Graphics_DrawPiece(renderer, &game.currentTetromino);

    Graphics_Present(renderer);
    SDL_Delay(1000);
  }

  saveScore(&game);
  Graphics_Quit(window, renderer);
  return 0;
}
