#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*new_element;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new_element = *lst;
	while (new_element->next)
		new_element = new_element->next;
	new_element->next = new;
}
