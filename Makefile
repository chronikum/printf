# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:43:08 by jfritz            #+#    #+#              #
#    Updated: 2021/07/05 10:38:50 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBFTNAME = libft.a

NAME=libftprintf.a

CFLAGS = -Werror -Wall -Wextra

OBJS := $(*.o)
SRC = ft_printf.c ft_utils.c ft_available_types.c

PUTTER = ./putter/ft_putchar.c ./putter/ft_putint.c ./putter/ft_putstr.c ./putter/ft_putuint.c

all: $(NAME)

${NAME}:
	make -C ./libft
	cp ./libft/$(LIBFTNAME) $(LIBFTNAME)
	${CC} ${CFLAGS} -c ${SRC}
	ar rc ${NAME} *.o

dev: fclean
	make -C ./libft
	cp ./libft/$(LIBFTNAME) $(LIBFTNAME)
	${CC} ${CFLAGS} ${SRC} $(PUTTER) ${LIBFTNAME}

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