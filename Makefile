# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 11:31:17 by pguillie          #+#    #+#              #
#    Updated: 2017/12/12 11:38:17 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
INCPATH	= includes/
HEADERS	= $(addprefix $(INCPATH), fractol.h)
MLX		= -lm -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SOURCES	:= $(shell find src | grep "\.c" | grep -v "\.c.")
NB		:= $(shell find src | grep "\.c" | grep -v "\.c." | wc -l\
	| rev | cut -f 1 -d ' ' | rev)

OBJECTS	= $(SOURCES:src/%.c=obj/%.o)

RED		= \033[31m
GREEN	= \033[32m
BLUE	= \033[34m
WHITE	= \033[37m
EOC		= \033[0m

.PHONY: all clean nclean fclean re

all: $(NAME)

$(NAME): obj $(LIB) $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $(OBJECTS) $(MLX)
	@ echo "$(GREEN)[$@]: binary successfully created !$(EOC)"

obj/%.o: src/%.c $(HEADERS) Makefile
	$(eval FILE=$(shell echo $$(($(FILE) + 1))))
	$(eval PERCENT=$(shell echo $$(($(FILE) * 100 / $(NB)))))
	@ echo "[$(NAME)]: $(PERCENT)% ($(FILE)/$(NB))\r\c"
	$(CC) $(FLAGS) -I $(INCPATH) -o $@ -c $<

obj:
	mkdir -p ./obj
	@ echo "$(BLUE)[$(NAME)]: objects directory created$(EOC)"

clean:
	rm -rf obj
	@ echo "$(RED)[$(NAME)]: objects directory deleted$(EOC)"

fclean: clean
	rm -rf $(NAME)
	@ echo "$(RED)[$(NAME)]: binary file deleted$(EOC)"

re: fclean all
