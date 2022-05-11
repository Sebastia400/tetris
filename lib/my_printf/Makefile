##
## EPITECH PROJECT, 2021
## d10
## File description:
##

SRC		=	 sources/

SRC_C	=	my_printf.c				\
			do_op.c					\
			functions_ce_f.c		\
			functions_cg_x_cs_g.c	\
			functions_cx_p_o_u_cb.c	\
			functions_id.c			\
			functions_s_c_e.c		\
			my_put_nbr.c			\
			my_putstr.c				\
			my_putchar.c			\
			my_revstr.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

OBJ	= 	$(SRCS_C:.c=.o) ##Quitar los .c

NAME	=	libmyprintf.a  ##Nombre archivo

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp ./includes/bsprintf.h ../../includes/

all:	$(NAME)

copy:   $(COPY)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all