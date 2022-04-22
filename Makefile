SRCS	=	srcs/main.c \
		srcs/error.c \
		srcs/check_size_map.c \
		srcs/check_character_map.c \
		srcs/display_asset_one.c	\
		srcs/display_asset_two.c	\
		srcs/key_press.c	\
		srcs/movements.c	\
		srcs/utils.c \
		srcs/init.c	\
		srcs/map.c	\
		srcs/close.c	\
		get_next_line/get_next_line.c	\
		get_next_line/get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}

HEAD	=	include/so_long.h \
		get_next_line/get_next_line.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	so_long


%.o:		%.c ${HEAD}
		${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C mlx
		${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

all:		${NAME}

clean:
			make clean -C mlx
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
