#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct s_print                       
{                        
    va_list  args;                 
    int     width;                      
    int     type;
    int		minus;
	int		zero;
	int		prec;
	int		star;
}    			t_print;

int ft_printf(const char *input, ...);
void ft_putstr(char *s);
int counter(const char *input1, ...);
void sixtnedit(unsigned int input, char x1);
void	ft_adress(void *ptr);