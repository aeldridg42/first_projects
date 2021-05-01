#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		++i;
		if (lst -> next == NULL)
			break ;
		lst = lst -> next;
	}
	return (i);
}
