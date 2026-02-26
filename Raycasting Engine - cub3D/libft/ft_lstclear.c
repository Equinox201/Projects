#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*location;
	t_list		*to_clear;

	location = *lst;
	to_clear = 0;
	while (location)
	{
		if (location->next)
			to_clear = location->next;
		else
			to_clear = 0;
		del(location->content);
		free(location);
		location = to_clear;
	}
	*lst = NULL;
}
