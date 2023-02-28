##
## EPITECH PROJECT, 2023
## Makefile template
## File description:
## Makefile
##


_SRC =			main.c

SRCDIR = 		src/

SRC =			$(addprefix $(SRCDIR), $(_SRC))
OBJ = 			$(SRC:.c=.o)

INC =
LIBS =

CFLAGS 	=		-W -Wall -Wextra -Werror -g

NAME =			cjson

all: 			$(NAME)

$(NAME):		$(OBJ)
				@echo [$(NAME)] "\t-> building : binary"
				@gcc -o $(NAME) $(OBJ) $(INC) $(LIBS) $(CFLAGS)

%.o: %.c
				@echo [$(NAME)] "\t-> building : objects"
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@rm -f $(OBJ)
				@echo [$(NAME)] "\t-> cleaning : objects."

fclean: 		clean
				@rm -f $(NAME)
				@echo [$(NAME)] "\t-> cleaning : binary."

re: 			fclean all

style:			fclean
				coding-style . .
