#ifndef PSEVDOLIBA_H
# define PSEVDOLIBA_H

# include <unistd.h>
# include <stdlib.h>

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

#endif