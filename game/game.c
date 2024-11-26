#include "game.h"
#include <stdlib.h>
#include <string.h>

static void SpawnTetromino(Game *game);
static const Position tetrominoShapes[TOTAL_TETROMINOS][4][TETROMINO_SIZE] = {
    /* I */
    {
        {{0, 1}, {1, 1}, {2, 1}, {3, 1}},
        {{2, 0}, {2, 1}, {2, 2}, {2, 3}},
        {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}}},
    /* O */
    {
        {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
        {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
        {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
        {{1, 0}, {2, 0}, {1, 1}, {2, 1}}},
    /* T */
    {
        {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {2, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {2, 1}, {1, 2}},
        {{1, 0}, {0, 1}, {1, 1}, {1, 2}}},
    /* S */
    {
        {{1, 0}, {2, 0}, {0, 1}, {1, 1}},
        {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
        {{1, 1}, {2, 1}, {0, 2}, {1, 2}},
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}}},
    /* Z */
    {
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        {{2, 0}, {1, 1}, {2, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {1, 2}, {2, 2}},
        {{1, 0}, {0, 1}, {1, 1}, {0, 2}}},
    /* J */
    {
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {2, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {2, 1}, {2, 2}},
        {{1, 0}, {1, 1}, {0, 2}, {1, 2}}},
    /* L */
    {
        {{2, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
        {{0, 1}, {1, 1}, {2, 1}, {0, 2}},
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}}}};

void Game_Init(Game *game)
{
    int row, col;
    for (row = 0; row < GRID_HEIGHT; row++)
    {
        for (col = 0; col < GRID_WIDTH; col++)
        {
            game->grid[row][col] = 0;
        }
    }
    game->score = 0;
    game->level = 1;
    game->linesCleared = 0;
    game->state = GAME_RUNNING;
    game->nextTetromino.type = (TetrominoType)(rand() % TOTAL_TETROMINOS);
    game->nextTetromino.rotation = 0;
    SpawnTetromino(game);
}

static void SpawnTetromino(Game *game)
{
    int i;
    TetrominoType type = game->nextTetromino.type;
    int rotation = 0;
    game->currentTetromino.type = type;
    game->currentTetromino.rotation = rotation;
    for (i = 0; i < TETROMINO_SIZE; i++)
    {
        game->currentTetromino.blocks[i].x = (GRID_WIDTH / 2) + tetrominoShapes[type][rotation][i].x;
        game->currentTetromino.blocks[i].y = tetrominoShapes[type][rotation][i].y;
    }
    game->nextTetromino.type = (TetrominoType)(rand() % TOTAL_TETROMINOS);
    game->nextTetromino.rotation = 0;
}

void Game_MoveLeft(Game *game)
{
    Tetromino movedTetromino = game->currentTetromino;
    int i;
    for (i = 0; i < TETROMINO_SIZE; i++)
    {
        movedTetromino.blocks[i].x -= 1;
    }
    if (!CheckCollision(game, &movedTetromino))
    {
        game->currentTetromino = movedTetromino;
    }
}

void Game_MoveRight(Game *game)
{
    Tetromino movedTetromino = game->currentTetromino;
    int i;
    for (i = 0; i < TETROMINO_SIZE; i++)
    {
        movedTetromino.blocks[i].x += 1;
    }
    if (!CheckCollision(game, &movedTetromino))
    {
        game->currentTetromino = movedTetromino;
    }
}

void Game_Pause(Game *game)
{
    if (game->state == GAME_RUNNING)
    {
        game->state = GAME_PAUSED;
    }
}

void Game_Resume(Game *game)
{
    if (game->state == GAME_PAUSED)
    {
        game->state = GAME_RUNNING;
    }
}

bool Game_IsGameOver(const Game *game)
{
    return game->state == GAME_OVER;
}

void Game_Drop(Game *game)
{
    Tetromino movedTetromino = game->currentTetromino;
    int i;

    for (i = 0; i < TETROMINO_SIZE; i++)
    {
        movedTetromino.blocks[i].y += 1;
    }
    if (CheckCollision(game, &movedTetromino))
    {
        SpawnTetromino(game);
        if (CheckCollision(game, &game->currentTetromino))
        {
            game->state = GAME_OVER;
        }
    }
    else
    {
        game->currentTetromino = movedTetromino;
    }
}

static void UpdateLevel(Game *game)
{
    int newLevel = (game->linesCleared / 10) + 1;
    if (newLevel > game->level)
    {
        game->level = newLevel;
    }
}

void Game_Rotate(Game *game)
{
    Tetromino rotatedTetromino = game->currentTetromino;
    rotatedTetromino.rotation = (rotatedTetromino.rotation + 1) % 4;
    TetrominoType type = rotatedTetromino.type;
    int rotation = rotatedTetromino.rotation;
    int baseX = rotatedTetromino.blocks[0].x;
    int baseY = rotatedTetromino.blocks[0].y;
    int i;

    for (i = 0; i < TETROMINO_SIZE; i++)
    {
        rotatedTetromino.blocks[i].x = baseX + tetrominoShapes[type][rotation][i].x;
        rotatedTetromino.blocks[i].y = baseY + tetrominoShapes[type][rotation][i].y;
    }

    if (!CheckCollision(game, &rotatedTetromino))
    {
        game->currentTetromino = rotatedTetromino;
    }
}

void Game_Update(Game *game)
{
    if (game->state != GAME_RUNNING)
    {
        return;
    }
    Game_Drop(game);
}