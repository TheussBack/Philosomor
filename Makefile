# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 20:29:44 by hrobin            #+#    #+#              #
#    Updated: 2023/05/09 11:13:08 by hrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc


SRCS =	error.c \
		main.c \
		init.c \
		parse.c \
		time.c \
		utils.c


OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror -g3

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
	    ${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:    ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
