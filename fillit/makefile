# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 19:03:25 by ljeanner          #+#    #+#              #
#    Updated: 2016/12/08 16:27:57 by mulzega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  ft_checker.c \
	  ft_file_reader.c \
	  ft_map.c \
	  ft_solver.c \
	  ft_tetris.c \
	  ft_utils.c \

HEADER = fillit.h

WWW = gcc -Wall -Wextra -Werror

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(WWW) -o $@ -c $< -I $(HEADER)

default: all

.PHONY: all clean re

all:$(NAME)

$(NAME):
	@(cd libft; make fclean)
	@(cd libft; make)
	@(cd libft; make clean)
	@$(WWW) -c $(SRC)
	@$(WWW) $(LIB) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:		fclean all
