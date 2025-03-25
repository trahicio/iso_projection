##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.c			\
			src/delete.c		\
			src/draw.c			\
			src/init.c			\
			src/event.c			\
			src/button.c		\
			src/check_point.c	\
			src/reset_tools.c   \

NAME	=	my_world

OBJ		=	$(SRC:.c=.o)

# CFLAGS	=  -Wall -Wextra -Werror -Iinclude

LIB		=	-lcsfml-graphics -lcsfml-window -lcsfml-system

ARGS	=	6

all: 	$(NAME)

perm: all
	@sudo chown root:root ./$(NAME) && sudo chmod 4755 ./$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

run: re
	./$(NAME) $(ARGS)

debug: fclean
	gcc $(SRC) -o $(NAME) $(CFLAGS) -g3 $(LIB)
	valgrind ./$(NAME) $(ARGS)

debug_check: fclean
	gcc $(SRC) -o $(NAME) $(CFLAGS) -g3 $(LIB)
	valgrind --leak-check=full ./$(NAME) $(ARGS)

debug_track: fclean
	gcc $(SRC) -o $(NAME) $(CFLAGS) -g3 $(LIB)
	valgrind --track-origins=yes ./$(NAME) $(ARGS)

fsanitize: fclean
	gcc $(SRC) $(CFLAGS) -g -fsanitize=address $(LIB)
	./$(NAME) $(ARGS)

gdb: fclean
	gcc $(SRC) $(CFLAGS) $(LIB) -g3
	gdb ./$(NAME) $(ARGS)

.PHONY: all clean fclean re run debug debug_check debug_track fsanitize gdb
.SILENT: run debug debug_check debug_track fsanitize gdb
