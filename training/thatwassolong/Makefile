NAME		=	so_long

SRCS		= 	main.c \
				sources/animations/animatecoins.c \
				sources/animations/animateplayer1.c \
				sources/animations/animateplayer2.c \
				sources/animations/animating.c \
				sources/animations/animatingenemy.c \
				sources/animations/animatingexit.c \
				sources/imageimport/images1.c \
				sources/imageimport/images2.c \
				sources/exiting.c \
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

MLX 		= 	-lmlx -framework OpenGL -framework AppKit

INCLUDES	= 	includes

RM			= 	rm -rf

all: 			$(NAME)

bonus:			${NAME}

$(NAME): 		$(OBJS)
				@$(MAKE) -C ./minilibx_mms_20200219
				@$(MAKE) -C ./minilibx_opengl_20191021
				@$(MAKE) -C ./ft_printf
				@mv minilibx_mms_20200219/libmlx.dylib .
				@mv minilibx_opengl_20191021/libmlx.a .
				@${CC} ${OBJS} ${CFLAGS} ${MLX} ./ft_printf/libftprintf.a libmlx.dylib libmlx.a -o ${NAME}

clean:
				@$(MAKE) -C ./ft_printf fclean
				@$(MAKE) -C ./minilibx_mms_20200219 clean
				@$(MAKE) -C ./minilibx_opengl_20191021 clean
				${RM} ${OBJS} 

fclean:			clean
				${RM} ${NAME}
				${RM} libmlx.dylib
				${RM} libmlx.a

re:				fclean all

.PHONY:			all clean fclean re bonus