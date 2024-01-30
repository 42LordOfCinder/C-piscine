# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 20:40:34 by gmassoni          #+#    #+#              #
#    Updated: 2023/08/02 19:31:17 by gmassoni         ###   ########.fr        #
#    Updated: 2023/08/01 21:57:42 by lbouet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADERS = ./includes/

SRCS = utils/ft_append.c \
	   utils/ft_is_in_charset.c \
	   utils/ft_putstr.c \
	   utils/ft_split.c \
	   utils/ft_strcat.c \
	   utils/ft_strlen.c \
	   utils/ft_strncpy.c \
	   utils/get_next_line.c \
	   utils/ft_atoi.c \
	   utils/ft_isdigit.c \
	   utils/ft_isspace.c \
	   utils/ft_strtablen.c \
	   utils/ft_strdup.c \
	   utils/ft_putstrerror.c \
	   src/main.c \
	   src/ft_get_file_size.c \
	   src/ft_get_map_content.c \
	   src/ft_handle_args.c \
	   src/ft_handle_stdin.c \
	   src/check/ft_check_map.c \
	   src/check/ft_check_header.c \
	   src/resolve/ft_resolve.c \
	   src/resolve/ft_is_obstacle.c \
	   src/resolve/ft_draw.c \
	   src/resolve/ft_display.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${SRCS} -I ${HEADERS} -o ${NAME} -g

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
