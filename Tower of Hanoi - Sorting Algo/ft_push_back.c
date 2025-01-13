
#include "push_swap.h"

void	final_check(t_stk **a_stack)
{
	int		a;
	t_stk	*temp;

	a = 1;
	temp = *a_stack;
	while (temp)
	{
		if (a != temp->sorted)
		{
			write(1, "Error SORT\n", 11);
			return ;
		}
		a++;
		temp = temp->next;
		if (temp == *a_stack)
			break ;
	}
	if (ft_lstsize(*a_stack) != temp->nts)
	{
		write(1, "Error SORT\n", 11);
		return ;
	}
}

void	ft_push_back(t_stk **a_stack, t_stk **b_stack)
{
	t_stk	*temp;
	int		len;

	if (ft_lstsize(*b_stack) > 0)
	{
		temp = ft_find_target(b_stack, ft_high(b_stack));
		if (temp->t_dir == 1)
			rotate(a_stack, b_stack, temp->c_rot, 1);
		else
			reverse_rotate(a_stack, b_stack, temp->c_rev, 1);
		len = ft_lstsize(*b_stack);
		push(a_stack, b_stack, len, 1);
	}
	final_check(a_stack);
}

int	ft_comp(t_stk *temp)
{
	if (temp->c_rot <= temp->c_rev)
		return (temp->c_rot);
	else
		return (temp->c_rev);
}

void	ft_sort_list(t_stk *head)
{
	int		size;
	int		*array;
	int		a;
	t_stk	*temp;

	temp = head;
	a = 0;
	size = ft_lstsize(head);
	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	while (temp && a < size)
	{
		array[a] = temp->number;
		a++;
		temp = temp->next;
	}
	ft_bubble_sort(array, size);
	ft_sorted_order(head, array, size);
	free(array);
	ft_assign_cost(head);
	ft_big_three(head);
}
