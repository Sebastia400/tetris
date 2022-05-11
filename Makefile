##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/ -lmyprintf

SFLAGS = -std=c99 -lncurses

SRC		=	sources/

SRC_C	=	main.c				\
			basicfunctions.c	\
			basicfunctions2.c	\
			basicfunctions3.c	\
			basicfunctions4.c 	\
			basicfunctions5.c 	\
			param_funcs.c		\
			param_funcs2.c 		\
			get_params_funcs.c	\
			get_tetriminos.c	\
			colisions.c 		\
			colisions2.c		\
			movements.c			\
			movements_2.c 		\
			manage_keys.c		\
			rotate.c			\
			print.c 			\
			print2.c 			\
			create_map.c 		\
			print_debug.c		\
			init_funcs.c		\
			game_status.c		\
			array_funcs.c		\
			array_funcs2.c		\
			extra_funcs.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./includes -g

NAME = tetris

all: $(NAME)

libmyprintf:
	make re -C lib/my_printf/

$(NAME): libmyprintf $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFLAGS) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my_printf/

re:	fclean all
	make clean
