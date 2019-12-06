# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relkassm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 13:49:07 by relkassm          #+#    #+#              #
#    Updated: 2019/11/28 15:33:53 by relkassm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCOBJ = src/main.o src/julia.o src/mandelbrot.o src/burning_ship.o src/events.o src/zoom.o src/utils.o

INC  = src/fractol.h

all: $(NAME)

$(NAME): $(SRCOBJ) $(LIBOBJ) $(INC)
	Make -C src/

clean:
	Make -C src/ clean

fclean: clean
	Make -C src/ fclean
	

re: fclean all
