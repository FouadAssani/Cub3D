# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 04:00:06 by fassani           #+#    #+#              #
#    Updated: 2020/08/02 11:16:57 by fassani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= \
base/ft_atoi.c\
base/ft_bzero.c\
base/ft_isalnum.c\
base/ft_isalpha.c\
base/ft_isascii.c\
base/ft_isdigit.c\
base/ft_isprint.c\
base/ft_memccpy.c\
base/ft_memchr.c\
base/ft_memcmp.c\
base/ft_memcpy.c\
base/ft_memmove.c\
base/ft_memset.c\
base/ft_strchr.c\
base/ft_strlcat.c\
base/ft_strlcpy.c\
base/ft_strlen.c\
base/ft_strncmp.c\
base/ft_strnstr.c\
base/ft_strrchr.c\
base/ft_tolower.c\
base/ft_toupper.c\
base/ft_strdup.c\
base/ft_calloc.c\
base/ft_strjoin.c\
base/ft_putstr_fd.c\
base/ft_putchar_fd.c\
base/ft_putnbr_fd.c\
base/ft_putendl_fd.c\
base/ft_substr.c\
base/ft_strtrim.c\
base/ft_itoa.c\
base/ft_strmapi.c\
base/ft_split.c\
get_next_line/get_next_line.c\
ft_printf/ft_printf.c\
ft_printf/ft_putunsignednbr_fd.c\
ft_printf/parse.c\
ft_printf/parse_step.c\
ft_printf/read_array.c\
ft_printf/show_c.c\
ft_printf/show_i.c\
ft_printf/show_i_step.c\
ft_printf/show_i_step2.c\
ft_printf/show_p.c\
ft_printf/show_s.c\
ft_printf/show_u.c\
ft_printf/show_u_step.c\
ft_printf/show_x.c\
ft_printf/show_x_step.c\
ft_printf/unsignednbr_tobase.c\
extra/ft_newline.c\



OBJS	= ${SRCS:.c=.o}
INCS	= ./includes/
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
