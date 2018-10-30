# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gzagura <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 13:56:54 by gzagura           #+#    #+#              #
#    Updated: 2018/08/28 13:56:56 by gzagura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Werror -Wextra
NAME		= fractol
SRC_NAME 	= main.c mandel.c le_hook.c zoom.c multi_thread.c
LIBFT_DIR	= ./libft/
LIBFT		= ./libft/libft.a
SRC			=$(addprefix ./src/, $(SRC_NAME))
OBJ			= $(SRC:%.c=%.o)

.PHONY: norm all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) $(OBJ) -I /usr/local/include -I -r $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c $(LIBFT) ./include/fractol.h
	echo chlen
	gcc $(CFLAGS) -c $< -I -o $@ 

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
