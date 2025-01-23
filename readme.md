gcc -o tetris main.c graphics/graphics.c game/game.c config/config.c input/input.c utils/utils.c -Iconfig -Igame -Igraphics -Iinput -Iutils -lSDL2
