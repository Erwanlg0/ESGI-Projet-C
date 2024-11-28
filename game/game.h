#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <stdbool.h>

struct Settings;

#define GRID_WIDTH 10
#define GRID_HEIGHT 20
#define TETROMINO_SIZE 4
#define TOTAL_TETROMINOS 7

typedef enum
{
    SHAPE_I,
    SHAPE_O,
    SHAPE_T,
    SHAPE_S,
    SHAPE_Z,
    SHAPE_J,
    SHAPE_L
} TetrominoType;

typedef struct
{
    int x;
    int y;
} Position;

typedef struct
{
    TetrominoType type;
    int rotation;
    Position blocks[TETROMINO_SIZE];
} Tetromino;

typedef enum
{
    GAME_RUNNING,
    GAME_PAUSED,
    GAME_OVER
} GameState;

typedef struct
{
    uint8_t grid[GRID_HEIGHT][GRID_WIDTH];
    Tetromino currentTetromino;
    Tetromino nextTetromino;
    int score;
    int level;
    int linesCleared;
    GameState state;
} Game;

void Game_Init(Game *game, const struct Settings *settings);
void Game_Update(Game *game);
void Game_MoveLeft(Game *game);
void Game_MoveRight(Game *game);
void Game_Rotate(Game *game);
void Game_Drop(Game *game);
void Game_HardDrop(Game *game);
void Game_Pause(Game *game);
void Game_Resume(Game *game);
bool Game_IsGameOver(const Game *game);

#endif
