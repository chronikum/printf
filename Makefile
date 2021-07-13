# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:43:08 by jfritz            #+#    #+#              #
#    Updated: 2021/07/13 11:54:52 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

OBJS := *.o
SRC = ft_printf.c ft_available_types.c main.c

PUTTER = ./putter/ft_putchar.c ./putter/ft_putint.c ./putter/ft_putstr.c ./putter/ft_putuint.c ./putter/ft_put_hex.c

all: $(NAME)

${NAME}:
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	${CC} ${CFLAGS} -c ${SRC} $(PUTTER)
	ar rcs ${NAME} ${OBJS}

dev: fclean
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	${CC} ${CFLAGS} ${SRC} $(PUTTER) ${NAME}

bonus:
	${CC} ${CFLAGS} -c ${BNS}
	ar rc ${NAME} *.o

clean:
		rm -rf *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTNAME)
	cd ./libft && make fclean

re: clean ${NAME}