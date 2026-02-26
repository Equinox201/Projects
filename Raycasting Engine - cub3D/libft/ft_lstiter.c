#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*location;

	location = lst;
	while (location)
	{
		f(location->content);
		location = location->next;
	}
}
