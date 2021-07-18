NAME		=	so_long

SRCS		= 	main.c \
				sources/animatecoins.c \
				sources/animateplayer1.c \
				sources/animateplayer2.c \
				sources/animating.c \
				sources/animatingenemy.c \
				sources/animatingexit.c \
				sources/exiting.c \
				sources/images1.c \
				sources/images2.c \
				sources/parser.c \
				sources/mapdraw.c \
				sources/measuring.c \
				sources/movedraw.c \
				sources/movehook.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

OBJS		= 	${SRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	includes

INCLUDES2	=	get_next_line

all: 			$(NAME)

$(NAME): 		$(OBJS)
				@$(MAKE) -C ./minilibx__mms_20200219
				@$(MAKE) -C ./minilibx__opengl_20191021
				@$(MAKE) -C ./ft_printf
				@mv minilibx__mms_20200219/libmlx.dylib .
				@mv minilibx__opengl_20191021/libmlx.a .
				@${CC} ${OBJS} ${CFLAGS} ./ft_printf/libftprintf.a libmlx.dylib libmlx.a -o ${NAME}
clean:
				rm -rf ${OBJS} 

fclean:			clean
				rm -rf ${NAME}

re:				fclean all

.PHONY:			all clean fclean re