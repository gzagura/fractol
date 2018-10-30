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
SCR 		= src/main.c src/mandel.c src/le_hook.c src/carpet.c
OBJ			= $(SRC:%.c=%.o)

.PHONY: norm all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS)  $(SCR) -I /usr/local/include -I -r ././libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

./libft/libft.a:
	@$(MAKE) -C ./libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

