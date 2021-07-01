NAME = libftprintf.a

sources = 	ft_printf.c \
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

OBJECTS = ft_printf.o \
		proc_char.o \
		flags.o \
		proc_x.o \
		proc_int.o \
		proc_pointer.o \
		proc_string.o \
		proc_uns_int.o \
		proc_width.o \
		processing.o \
		parsing.o \
		ft_base.o \
		ft_help.o \
		ft_help1.o \
		ft_itoa.o \

INCLUDES = includes/ft_printf.h


all: $(NAME)

$(NAME): 	$(OBJECTS)

$(OBJECTS): $(sources) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(sources)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all