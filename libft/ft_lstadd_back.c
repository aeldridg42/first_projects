#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (new == NULL)
		return ;
	else if (*lst == NULL || lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}
