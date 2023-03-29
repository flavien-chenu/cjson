##
## EPITECH PROJECT, 2023
## Makefile template
## File description:
## Makefile
##


_SRC =			main.c \
				key.c \
				separator.c \
				value.c \
				\
				parse/file.c \
				parse/parse.c \
				\
				types/array/append.c \
				types/array/array.c \
				types/array/get.c \
				types/array/remove.c \
				types/cjson/free.c \
				types/cjson/new.c \
				types/cjson/prop.c \
				types/cjson/set.c \
				\
				utils/charstr.c \
				utils/error.c \
				utils/file.c \
				utils/skip.c \
				utils/strcmp.c \
				utils/strdup.c \
				utils/strlen.c \
				utils/strncpy.c \
				\
				values/array.c \
				values/bool.c \
				values/null.c \
				values/number.c \
				values/object.c \
				values/string.c \

SRCDIR = 		src/

SRC =			$(addprefix $(SRCDIR), $(_SRC))
OBJ = 			$(SRC:.c=.o)

INC =			-I ./include
LIBS =

CFLAGS 	=		-W -Wall -Wextra -Werror -g

NAME =			cjson.bin

all: 			$(NAME)

$(NAME):		$(OBJ)
				@echo [$(NAME)] "\t-> building : binary"
				@gcc -o $(NAME) $(OBJ) $(INC) $(LIBS) $(CFLAGS)

%.o: %.c
				@echo [$(NAME)] "\t-> building : objects"
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@rm -f $(OBJ)
				@echo [$(NAME)] "\t-> cleaning : objects"

fclean: 		clean
				@rm -f $(NAME)
				@echo [$(NAME)] "\t-> cleaning : binary"

re: 			fclean all

style:			fclean
				coding-style . .
