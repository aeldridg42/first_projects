#include "../includes/ft_printf.h"

static int	ft_in_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (save_i < 0 && flags.prec >= 0)
		ft_putchar('-');
	if (flags.prec >= 0)
		char_count += processing_width(flags.prec - 1, ft_strlen(d_i) - 1, 1);
	char_count += ft_putwithprec(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	if (flags.prec >= 0 && flags.prec < ft_strlen(d_i))
		flags.prec = ft_strlen(d_i);
	if (flags.prec >= 0)
	{
		flags.width -= flags.prec;
		char_count += processing_width(flags.width, 0, 0);
	}
	else
		char_count += processing_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	return (char_count);
}

int			processing_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flags.prec == 0 && i == 0)
	{
		char_count += processing_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.prec >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.prec == -1)
			ft_putwithprec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	if (i == -2147483648)
		d_i = ft_strdup("2147483648");
	else
		d_i = ft_itoa(i);
	if (d_i == NULL)
		return (-1);
	char_count += ft_put_part_int(d_i, save_i, flags);
	free(d_i);
	return (char_count);
}