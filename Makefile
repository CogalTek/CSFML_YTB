##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that build the project
##

NAME	=		my_runner

CFLAGS	= 		-W -Wall -Wextra

SRC		=		./src/my_main.c					\
				./src/game/game_view.c			\

OBJ		=		$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -I../includes $(CFLAGS) $(CSFML)


apple:	$(OBJ)
		/usr/bin/arch -x86_64 gcc $(SRC) -o $(NAME) -I../includes $(CFLAGS) $(CSFML)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

debug:	CFLAGS+= -g
debug:	all

perf:	fclean
perf:	CFLAGS+= -pg
perf:	all

re:	fclean all

.PHONY:	all apple clean fclean debug perf re