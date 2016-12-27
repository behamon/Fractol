# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behamon <behamon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 12:33:09 by behamon           #+#    #+#              #
#    Updated: 2016/12/14 15:01:07 by behamon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fractol

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc
FLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework OpenGL -framework AppKit -lmlx

LFT_PATH = ./libft/

SRC = julia.c mandelbrot.c burningship.c utilities.c hooks.c fractol_init.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLX_FLAGS) -L$(LFT_PATH) -lft
	@echo "$(OKC)Fractol\t: Compilation.. Prêt$(NOC)"

clean:
	@make -C $(LFT_PATH) clean

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)Fractol\t: Suppression de l'executable  : fractol $(NOC)"

re: fclean all
