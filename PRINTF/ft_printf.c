#include "includes/ft_printf.h"

int						ft_printf(const char *printstr, ...)
{
	va_list		args;
	const char	*str;
	int			count;
	int			check;

	count = 0;
	str = ft_strdup(printstr);
	if (str == NULL)
		return (-1);
	va_start(args, printstr);
	check = processing_input(str, args);
	if (check == -1)
		return (-1);
	count += check;
	va_end(args);
	free((char*)str);
	return (count);
}