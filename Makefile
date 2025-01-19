CC	=	gcc

LDFLAGS = -lSDL2main -lSDL2 

SRC	=	$(wildcard *.c) $(wildcard config/*.c) $(wildcard graphics/*.c) $(wildcard game/*.c) $(wildcard input/*.c) $(wildcard utils/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -I../config -I../graphics -I../game -I../input -I../utils $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
