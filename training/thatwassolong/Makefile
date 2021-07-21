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
				sources/get_next_line/get_next_line.c \
				sources/get_next_line/get_next_line_utils.c \
				sources/libft/ft_itoa.c \

OBJS		= 	${SRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

MLX 		= 	-lmlx -framework OpenGL -framework AppKit

INCLUDES	= 	includes

RM			= 	rm -rf

all: 			$(NAME)

bonus:			${NAME}

$(NAME): 		$(OBJS)
				@$(MAKE) -C ./mlx/minilibx_mms_20200219
				@$(MAKE) -C ./mlx/minilibx_opengl_20191021
				@mv mlx/minilibx_mms_20200219/libmlx.dylib .
				@mv mlx/minilibx_opengl_20191021/libmlx.a .
				@${CC} ${OBJS} ${CFLAGS} ${MLX} libmlx.dylib libmlx.a -o ${NAME}

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

clean:
				@$(MAKE) -C ./mlx/minilibx_mms_20200219 clean
				@$(MAKE) -C ./mlx/minilibx_opengl_20191021 clean
				${RM} ${OBJS} 

fclean:			clean
				${RM} ${NAME}
				${RM} libmlx.dylib
				${RM} libmlx.a

re:				fclean all

.PHONY:			all clean fclean re bonus