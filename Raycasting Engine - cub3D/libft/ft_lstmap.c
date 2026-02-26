#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_list;
	t_list		*new_node;
	void		*tmp;

	new_list = NULL;
	if (!del || !lst || !f)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			ft_lstclear(&new_list, (*del));
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
