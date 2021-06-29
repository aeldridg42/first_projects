#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../psevdoliba/psevdoliba.h"

typedef struct	s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

int				processing_char(char c, t_flags *flags);
t_flags			ft_minus_flag(t_flags flags);
t_flags			ft_digit_flag(char c, t_flags flags);
t_flags			ft_width_flag(va_list args, t_flags flags);
int				ft_dot_flag(const char *str, int start, t_flags *flags, va_list args);
int				processing_x(unsigned int number, int lowercase, t_flags flags);
int				processing_int(int i, t_flags flags);
int				processing_percent(t_flags flags);
int				processing_pointer(unsigned long long num, t_flags flags);
int				processing_string(char *str, t_flags flags);
int				processing_uns_int(unsigned int number, t_flags flags);
int				processing_width(int width, int minus, int zero);
int				processing(int c, t_flags flags, va_list args);
int				ft_printf(const char *fmt, ...);
int				processing_input(const char *str, va_list args);
t_flags			ft_initialize(t_flags flags);
int				ft_parse(const char *str, int i, t_flags *flags, va_list args);

#endif