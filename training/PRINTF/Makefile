NAME		=	libftprintf.a

SRCS		= 	ft_printf.c \
				sources/proc_char.c \
				sources/flags.c \
				sources/proc_x.c \
				sources/proc_int.c \
				sources/proc_pointer.c \
				sources/proc_string.c \
				sources/proc_uns_int.c \
				sources/proc_width.c \
				sources/processing.c \
				sources/parsing.c \
				psevdoliba/ft_base.c \
				psevdoliba/ft_help.c \
				psevdoliba/ft_help1.c \
				psevdoliba/ft_itoa.c \

OBJS		= 	${SRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	includes

all: 			$(NAME)

$(NAME): 		$(OBJS)
				ar rc $(NAME) $(OBJS)

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

clean:
				rm -rf ${OBJS} 

fclean:			clean
				rm -rf ${NAME}

re:				fclean all

.PHONY:			all clean fclean re