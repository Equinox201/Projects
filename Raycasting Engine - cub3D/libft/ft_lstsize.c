#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*location;
	int		a;

	location = lst;
	a = 0;
	while (location)
	{
		location = location->next;
		a++;
	}
	return (a);
}
