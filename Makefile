# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:43:08 by jfritz            #+#    #+#              #
#    Updated: 2021/07/15 09:22:50 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

OBJS := *.o
SRC = ft_printf.c ft_available_types.c

PUTTER = ./putter/ft_putchar.c ./putter/ft_putint.c ./putter/ft_putstr.c ./putter/ft_putuint.c ./putter/ft_put_hex.c

${NAME}:
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	${CC} ${CFLAGS} -c ${SRC} $(PUTTER)
	ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean

re: fclean ${NAME}