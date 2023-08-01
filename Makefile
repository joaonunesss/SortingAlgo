# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 14:45:09 by jmarinho          #+#    #+#              #
#    Updated: 2023/08/01 17:21:03 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = push_swap.c aux.c moves.c moves2.c check_errors.c \
		ps_sort_big.c ps_sort_big2.c ps_sort_big3.c \
			ps_strat.c ps_strat2.c sort_2_3.c sort_4_5.c ps_sort_utils.c \
				printing.c \

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