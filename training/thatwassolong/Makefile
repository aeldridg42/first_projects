NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I. -Imlx
SRC		= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main.c ft_printf/libftprintf.a
OBJ		= $(SRC:%.c=%.o)

.PHONY: all re clean fclean mlx 

.o: .c
	$(CC) $(CFLAGS) -Imlx $< -o $@

all: mlx  $(NAME)

$(NAME): $(OBJ) so_long.h
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

mlx:
	make -C mlx/

clean:
	make -C mlx/ clean
	make -C ft_printf/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f mlx/libmlx.a
	rm -f ft_printf/libftprintf.a
	rm -f $(NAME)

re: fclean all