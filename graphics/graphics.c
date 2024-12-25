#include "graphics.h"
#include <stdbool.h>
#include <stdio.h>

#define CELL_SIZE 40 // taille px

static SDL_Color tetrominoColors[] = {
    {0, 0, 0, 255},     // Vide
    {255, 0, 0, 255},   // I
    {255, 255, 0, 255}, // O
    {128, 0, 128, 255}, // T
    {0, 255, 0, 255},   // S
    {255, 0, 255, 255}, // Z
    {0, 0, 255, 255},   // J
    {255, 128, 0, 255}, // L
};

bool Graphics_Init(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur d'initialisation SDL: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow(
        "Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!*window)
    {
        printf("Erreur création fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer)
    {
        printf("Erreur création renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
    SDL_RenderClear(*renderer);
    return true;
}

void Graphics_Quit(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics_DrawGrid(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int x = 0; x <= GRID_WIDTH; x++)
    {
        SDL_RenderDrawLine(renderer, x * CELL_SIZE, 0, x * CELL_SIZE, GRID_HEIGHT * CELL_SIZE);
    }

    for (int y = 0; y <= GRID_HEIGHT; y++)
    {
        SDL_RenderDrawLine(renderer, 0, y * CELL_SIZE, GRID_WIDTH * CELL_SIZE, y * CELL_SIZE);
    }
}

void Graphics_DrawPiece(SDL_Renderer *renderer, const Tetromino *tetromino)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    for (int i = 0; i < TETROMINO_SIZE; i++)
    {
        SDL_Rect rect = {
            tetromino->blocks[i].x * CELL_SIZE,
            tetromino->blocks[i].y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE};

        SDL_SetRenderDrawColor(renderer, tetrominoColors[tetromino->type + 1].r,
                               tetrominoColors[tetromino->type + 1].g,
                               tetrominoColors[tetromino->type + 1].b, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

void Graphics_DrawGridBlocks(SDL_Renderer *renderer, const Game *game)
{
    for (int y = 0; y < GRID_HEIGHT; y++)
    {
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            if (game->grid[y][x] != 0)
            {
                SDL_Rect rect = {x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
                SDL_SetRenderDrawColor(renderer, tetrominoColors[game->grid[y][x]].r,
                                       tetrominoColors[game->grid[y][x]].g,
                                       tetrominoColors[game->grid[y][x]].b, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

void Graphics_Present(SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}
