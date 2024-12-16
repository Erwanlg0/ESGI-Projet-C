#include <SDL2/SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CELL_SIZE 40
#define GRID_WIDTH 20
#define GRID_HEIGHT 15


typedef struct {
    SDL_Rect blocks[4];  
    int x, y;           
} PieceL;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Projet C V1",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WINDOW_WIDTH, WINDOW_HEIGHT,
                                        SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur création fenêtre: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 
                                              SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur création renderer: %s\n", SDL_GetError());
        return 1;
    }

 
    PieceL piece = {
        .x = 5,
        .y = 5
    };

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
                        case SDLK_LEFT:  piece.x--; break;
                        case SDLK_RIGHT: piece.x++; break;
                        case SDLK_UP:    piece.y--; break;
                        case SDLK_DOWN:  piece.y++; break;
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                    }
                    break;
            }
        }

      
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

       
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        
       
        for (int x = 0; x <= GRID_WIDTH; x++) {
            SDL_RenderDrawLine(renderer, 
                             x * CELL_SIZE, 0,
                             x * CELL_SIZE, GRID_HEIGHT * CELL_SIZE);
        }
        
       
        for (int y = 0; y <= GRID_HEIGHT; y++) {
            SDL_RenderDrawLine(renderer, 
                             0, y * CELL_SIZE,
                             GRID_WIDTH * CELL_SIZE, y * CELL_SIZE);
        }

       
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        
        
        SDL_Rect verticalPart = {
            piece.x * CELL_SIZE,
            piece.y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE * 3
        };
        SDL_RenderFillRect(renderer, &verticalPart);
        
       
        SDL_Rect horizontalPart = {
            piece.x * CELL_SIZE,
            (piece.y + 2) * CELL_SIZE,
            CELL_SIZE * 2,
            CELL_SIZE
        };
        SDL_RenderFillRect(renderer, &horizontalPart);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}