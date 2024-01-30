# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 02:16:41 by gmassoni          #+#    #+#              #
#    Updated: 2023/07/28 21:55:46 by gmassoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADERS = ./includes/

SRCS = srcs/ft_putchar.c \
	srcs/ft_swap.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS} ${HEADERS}ft.h

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
