##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task1
##

SRC	 =	src/converter.c	\
		src/my_printf.c	\
		src/my_revstr.c	\
		src/print.c	\
		src/switches.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all :	$(NAME)

$(NAME):		$(OBJ)
	ar rc $(NAME)	$(OBJ)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
