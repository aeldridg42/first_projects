#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	k;
	char		nbr[12];

	k = (long int) n;
	if (n == 0)
		write(fd, "0", 1);
	if (k < 0)
	{
		write(fd, "-", 1);
		k *= -1;
	}
	n = 0;
	while (k)
	{
		nbr[n++] = k % 10 + '0';
		k /= 10;
	}
	while (n)
		write(fd, &nbr[--n], 1);
}
