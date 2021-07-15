#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		prec;
}				t_flags;

t_flags	ft_minus_flag(t_flags flags);
t_flags	ft_digit_flag(char c, t_flags flags);
t_flags	ft_width_flag(va_list args, t_flags flags);
t_flags	initialize_flags(void);

char	*ft_itoa(int n);
char	*ft_uns_itoa(unsigned int n);
char	*ft_str_tolower(char *str);
char	*ft_strdup(const char *s1);
char	*ft_itoa_base(unsigned long number, int base);
char	*ft_strrev(char *str);

int		ft_isdigit(int c);
int		ft_putchar(char c);
int		ft_putwithprec(char *str, int precision);
int		ft_strlen(const char *s);
int		ft_tolower(int c);
int		ft_putstr(char *str);
int		processing_char(char c, t_flags flags);
int		ft_prec_flag(const char *str, int start, t_flags *flags, va_list args);
int		processing_x(unsigned int number, int lowercase, t_flags flags);
int		processing_int(int i, t_flags flags);
int		processing_pointer(void *adr, t_flags flags);
int		processing_string(char *str, t_flags flags);
int		proc_uns_int(unsigned int number, t_flags flags);
int		processing_width(int width, int value, int zero);
int		processing(t_flags flags, va_list args);
int		ft_printf(const char *format, ...);
int		processing_input(const char *str, va_list args);
int		ft_parse(const char *str, int i, t_flags *flags, va_list args);

#endif