# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relkassm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 13:49:30 by relkassm          #+#    #+#              #
#    Updated: 2019/11/28 15:33:01 by relkassm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../fractol

FLAG = -Werror -Wextra -Wall

SRC = main.c


OBJ = main.o


BIN = ../libft/libft.a ../minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) $(BIN) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
