CC	=	gcc

LDFLAGS = -lSDL2main -lSDL2 

SRC	=	$(wildcard *.c) $(wildcard config/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -I../config $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
