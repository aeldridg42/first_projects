#include "libft/libft.h"
#include "libftprintf.h"

void	ft_adress(void *ptr)
{
	unsigned long adr = (unsigned long) &ptr;
	printf("!!!%lx!!!\n", adr);
	sixtnedit(adr, 'x');
}