##
## EPITECH PROJECT, 2023
## Makefile template
## File description:
## Makefile
##


_SRC =			main.c \
				\
				parse/values/array.c \
				parse/values/bool.c \
				parse/values/null.c \
				parse/values/number.c \
				parse/values/object.c \
				parse/values/string.c \
				parse/file.c \
				parse/key.c \
				parse/parse.c \
				parse/separator.c \
				parse/value.c \
				\
				stringify/size/array.c \
				stringify/size/bool.c \
				stringify/size/null.c \
				stringify/size/number.c \
				stringify/size/object.c \
				stringify/size/size.c \
				stringify/size/string.c \
				stringify/array.c \
				stringify/bool.c \
				stringify/null.c \
				stringify/number.c \
				stringify/object.c \
				stringify/string.c \
				stringify/stringify.c \
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

docker:
				@docker run -it -v $(shell pwd):/project -w /project \
				epitechcontent/epitest-docker bash

style:			fclean
				coding-style . .
