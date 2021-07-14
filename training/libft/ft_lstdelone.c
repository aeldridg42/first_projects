#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*ptr2;

	ptr2 = lst -> next;
	del(lst -> content);
	free(lst);
	lst = ptr2;
}
