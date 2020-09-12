# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/11 19:25:54 by fassani           #+#    #+#              #
#    Updated: 2020/09/11 21:13:20 by fassani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= mapvalidator.a
SRCS	= \
mapvalidator.c\
v_up.c\
v_down.c\
v_left.c\
v_right.c\
utils.c\
map_iterator.c\
map_handler.c\


OBJS	= ${SRCS:.c=.o}
INCS	= ./mapvalidator.h
LIBR	= ranlib
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rc

.c.o:
	${CC} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

.PHONY: all clean fclean re .c.o norm
