#include "includes/ft_printf.h"

int						ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	va_start(args, format);
	count = processing_input(format, args);
	if (count == -1)
		return (-1);
	va_end(args);
	return (count);
}