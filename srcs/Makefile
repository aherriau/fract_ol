# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherriau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 12:48:16 by aherriau          #+#    #+#              #
#    Updated: 2017/12/05 13:28:24 by aherriau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export CC = cc

export CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRC = ./srcs/main.c ./srcs/ft_init_mlx.c ./srcs/ft_init_fractal.c\
	  ./srcs/ft_process.c ./srcs/ft_tools.c\
	  ./srcs/ft_key_hook.c ./srcs/ft_key_tools.c ./srcs/ft_key_tools_2.c\
	  ./srcs/ft_mouse_hook.c ./srcs/ft_mouse_hook_2.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`


all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) -o $@ $^ -L $(LIBFT_DIR) -lft -lmlx -framework OpenGL\
		-framework AppKit -framework OpenCL
	@echo "$(green)Compilation finished: $(NAME)$(reset)"

%.o: %.c ./srcs/fract_ol.h
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	@$(MAKE) $@ -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "$(green)Object files deleted: $(NAME)$(reset)"

fclean: clean
	@$(MAKE) $@ -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(green)Executable file deleted: $(NAME)$(reset)"

re: fclean all
