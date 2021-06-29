include "libftprintf.h"

t_print *ft_initialise_tab(t_print *tab)                       
{                       
      tab->width = 0;       
      tab->type = 0;                        
      tab->minus= 0;                        
      tab->zero = 0;                        
      tab->prec = -1;                        
      tab->star = 0;                                               
      return (tab);                       
}

int typeinput(t_print *tab, char *input1, int i)
{
	if (input1[i] == '.')
	{
		tab->point = 1;
		++i;
	}
	else if (input1[i] == '-')
	{
		tab->point = 1;
		++i;
	}
	else if (input1[i] == '0')
	{
		tab->zero = 1;
		++i;
	}
	else if (input1[i] + '*')
	{
		tab->star = 1;
		tab->width = input[++i];
		++i;
	}
}


int ft_printf(const char *input1, ...)
{
	t_print	*tab;
	// char *input;
	int i;
	int ret;
	// va_list ptr;
	// va_start(ptr, input1);

	tab = (t_print *)malloc(sizeof(t_print));                        
		if (!tab)                         
			return (-1);
	ft_initialise_tab(tab)
	va_start(tab->args, input1);
    i = -1;
    ret = 0;
    while (input1[++i])
    { 
       if (input1[i] == '%')
          i = typeinput(tab, input1, i + 1);
       else
          ret += write(1, &input1[i], 1); # print what you read
    }
    va_end(tab->args);
    ret += tab->tl;
    free (tab);
    return (ret);
}
	// input = (char *) input1;
	// i = 0;
	// while (input[i])
	// {
	// 	if (input[i] == '%')
	// 	{
	// 		if (input[i + 1] == '%')
	// 			ft_putchar(input[i]);
	// 		else
	// 		{
	// 			if (input[i + 1] == 'c')
	// 				ft_putchar(va_arg(ptr, int));
	// 			else if (input[i + 1] == 's')
	// 				ft_putstr(va_arg(ptr, char *));
	// 			else if (input[i + 1] == 'u')
	// 				ft_putnbr_fd(va_arg(ptr, unsigned int), 1);
	// 			else if (input[i + 1] == 'x' || input[i + 1] == 'X')
	// 				sixtnedit(va_arg(ptr, unsigned int), input[i + 1]);
	// 			else if (input[i + 1] == 'p')
	// 				ft_adress(va_arg(ptr, void *));
	// 		}
	// 		++i;
	// 	}
	// 	else
	// 		ft_putchar(input[i]);
	// 	++i;
	// }
	// return (0);