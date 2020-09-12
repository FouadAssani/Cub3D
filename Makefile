# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 04:00:06 by fassani           #+#    #+#              #
#    Updated: 2020/09/12 18:16:16 by fassani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D
SRCS	= ./source/main.c \
		  ./source/engine.c \
		  ./source/keyshandler.c \
		  ./source/movefunctions.c \
		  ./source/viewfunctions.c \
		  ./source/textures.c \
		  ./source/printscreen.c \
		  ./source/ray.c \
		  ./source/draw.c \
		  ./source/init.c \
		  ./source/readconfig.c \
		  ./source/utils.c \
		  ./source/mapfunction.c \
		  ./source/item.c \
		  ./source/create_image.c \
		  ./source/verification.c \
		  ./source/free_memory.c \
		  ./source/line_map_validation.c \

OBJS	= ${SRCS:.c=.o}
INCS	= ./include/
RM		= rm -f
CC		= clang
CFLAGS	= -Wall -Wextra -Werror

Lib_MLXOPENGL = ./lib/minilibx_opengl/
MLX_OPENGL 	= ${Lib_MLXOPENGL}libmlx.a

Lib_MLXLINUX = ./lib/minilibx_linux/
MLX_LINUX 	= ${Lib_MLXLINUX}libmlx.a

Lib_MLXMAC = ./lib/minilibx_mac/
MLX_MAC	= ${ib_MLXMAC}/libmlx.dylib

Lib_FT = ./lib/libft
LIBFT 	= ${Lib_FT}/libft.a

Lib_MAPVALIDATOR = ./lib/mapvalidator
MAPVALIDATOR 	= ${Lib_MAPVALIDATOR}/mapvalidator.a

${NAME}: ${OBJS}
	make -C ${Lib_MLXLINUX}
	make -C ${Lib_FT}
	make -C ${Lib_MAPVALIDATOR}
	${CC} ${CFLAGS} -o3 ${OBJS} -I ${INCS} ${MLX_LINUX} ${LIBFT} ${MAPVALIDATOR} -lm -lbsd -lX11 -lXext -o $(NAME)

sanitize: ${OBJS}
	make -C ${Lib_MLXLINUX}
	make -C ${Lib_FT}
	make -C ${Lib_MAPVALIDATOR}
	${CC} ${CFLAGS}	-fsanitize=address -o3 ${OBJS} -I ${INCS} ${MLX_LINUX} ${LIBFT} ${MAPVALIDATOR} -lm -lbsd -lX11 -lXext -o $(NAME)

opengl: ${OBJS}
	make -C ${Lib_MLXOPENGL}
	make -C ${Lib_FT}
	${CC} ${CFLAGS} ${OBJS} -I ${INCS} ${MLX_OPENGL} ${LIBFT} -framework OpenGL -framework AppKit -o $(NAME)

mac: ${OBJS}
	make -C ${Lib_MLXMAC}
	make -C ${Lib_FT}
	${CC} ${CFLAGS} ${OBJS} -I ${INCS} ${MLX_MAC} ${LIBFT} -o $(NAME)

all:
	${NAME}

clean:
	${RM} ${OBJS}

allclean:
	${RM} ${OBJS}
	@make clean -C $(Lib_MLXOPENGL)
	@make clean -C $(Lib_MLXMAC)
	@make clean -C $(Lib_MLXLINUX)
	@make clean -C $(Lib_FT)
	@make clean -C $(Lib_MAPVALIDATOR)

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

.PHONY: all clean fclean re .c.o norm
