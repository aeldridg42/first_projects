#include "libft.h"

static int	first(char const *s1, char const *set)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (s1[k])
	{
		while ((s1[k] != set[i]) && set[i])
			i++;
		if (s1[k] == set[i])
			k++;
		else
			break ;
		i = 0;
	}
	return (k);
}

static int	last(char const *s1, char const *set, int l, int k)
{
	int		i;

	i = 0;
	while (l > k)
	{
		while ((s1[l] != set[i]) && set[i])
			i++;
		if (s1[l] == set[i])
			l--;
		else
			break ;
		i = 0;
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		l;
	int		k;
	int		b;
	char	*mass;

	l = 0;
	b = 0;
	if (!s1 || !set)
		return (NULL);
	k = first(s1, set);
	while (s1[l])
		l++;
	l -= 1;
	l = last(s1, set, l, k);
	if (l != k || (l == k && (k != 0 || s1[l + 1] == '\0')))
		b = l - k + 1;
	mass = (char *)malloc(sizeof(char) * (b + 1));
	b = 0;
	if (!mass)
		return (NULL);
	if (k != l || (l == k && (k != 0 || s1[l + 1] == '\0')))
		while (k <= l)
			mass[b++] = s1[k++];
	mass[b] = '\0';
	return (mass);
}
