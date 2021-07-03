#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr2;

	while (*lst)
	{
		ptr2 = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = ptr2;
	}
}
