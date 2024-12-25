#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "../game/game.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 800

bool Graphics_Init(SDL_Window **window, SDL_Renderer **renderer);
void Graphics_Quit(SDL_Window *window, SDL_Renderer *renderer);
void Graphics_DrawGrid(SDL_Renderer *renderer);
void Graphics_DrawPiece(SDL_Renderer *renderer, const Tetromino *tetromino);
void Graphics_DrawGridBlocks(SDL_Renderer *renderer, const Game *game);
void Graphics_Present(SDL_Renderer *renderer);

#endif
