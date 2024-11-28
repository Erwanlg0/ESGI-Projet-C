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
