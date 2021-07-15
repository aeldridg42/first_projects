NAME		=	libftprintf.a

SRCS		= 	base/ft_printf.c \
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
				help_functions/ft_itoa_base.c \
				help_functions/ft_help.c \
				help_functions/ft_help1.c \
				help_functions/ft_itoa.c \

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