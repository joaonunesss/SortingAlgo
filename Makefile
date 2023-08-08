# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 14:45:09 by jmarinho          #+#    #+#              #
#    Updated: 2023/08/08 13:11:48 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = src/push_swap.c src/free_and_exit.c src/moves.c src/moves2.c src/checker.c \
		src/sort_more.c src/sort_more2_execute.c src/sort_more3_push_a.c \
			src/calc_moves.c src/sort_2_3.c src/sort_4_5.c src/sort_utils.c \

NAME = push_swap

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror -g

MAKE = make -C

LIBFT_PATH = lib/libft

LIBFT = -L ${LIBFT_PATH} -lft

all: ${NAME}

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH}
		cc ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT: