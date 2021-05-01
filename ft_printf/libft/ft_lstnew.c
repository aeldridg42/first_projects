#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*the_new;

	the_new = (t_list *)malloc(sizeof(content));
	if (!the_new)
		return (NULL);
	the_new -> content = content;
	the_new -> next = NULL;
	return (the_new);
}
