##
## EPITECH PROJECT, 2023
## My_ls
## File description:
## Ls
##

SRC	=	./main.c \
		./my_strcmp.c \
		./commands.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)
	rm ./*.o
	rm ./libmy.a

$(NAME):	$(OBJ)
	make -C printf
	gcc -Wall -Werror -o $(NAME) $(OBJ) libmy.a

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
