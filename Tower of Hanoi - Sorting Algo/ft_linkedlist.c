
#include "push_swap.h"

int	ft_lstsize(t_stk *lst)
{
	t_stk	*temp;
	int		count;

	if (!lst)
		return (0);
	temp = lst;
	count = 1;
	while (temp->next != lst)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	ft_lstclear(t_stk **lst)
{
	t_stk	*temp;
	t_stk	*next;

	temp = *lst;
	next = 0;
	while (temp != NULL && (next == NULL || temp != *lst))
	{
		next = temp->next;
		ft_delnode(temp);
		temp = next;
	}
	*lst = NULL;
}

void	ft_delnode(t_stk *node)
{
	if (!node)
		return ;
	free(node);
}

t_stk	*ft_lstnew(int number)
{
	t_stk	*new_node;

	new_node = (t_stk *)malloc(sizeof(t_stk));
	if (!new_node)
		return (NULL);
	new_node->previous = new_node;
	new_node->number = number;
	new_node->next = new_node;
	return (new_node);
}

void	ft_add_new_node(t_stk **head, int number)
{
	t_stk	*new_node;
	t_stk	*last;

	new_node = ft_lstnew(number);
	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->previous = new_node;
		return ;
	}
	last = (*head)->previous;
	new_node->next = *head;
	new_node->previous = last;
	last->next = new_node;
	(*head)->previous = new_node;
}
