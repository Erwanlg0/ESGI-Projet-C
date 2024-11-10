CC	=	gcc

LDFLAGS = -lSDL2main -lSDL2 

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -I includes $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
