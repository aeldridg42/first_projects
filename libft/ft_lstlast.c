#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst -> next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}
