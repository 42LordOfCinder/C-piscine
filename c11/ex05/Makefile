NAME = do-op

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADERS = ./includes/

SRCS = srcs/main.c \
	   srcs/ft_atoi.c \
	   srcs/ft_do_op.c \
	   srcs/ft_operations.c \
	   srcs/ft_putnbr.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${SRCS} -I ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
