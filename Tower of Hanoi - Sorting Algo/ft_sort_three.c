
#include "push_swap.h"

void	ft_push_all_save_three(t_stk **a_stack, t_stk **b_stack)
{
	t_stk	*current;
	int		iter;

	iter = 1;
	while (ft_lstsize(*a_stack) > 3)
	{
		current = *a_stack;
		if (current->big_t == 1)
			reverse_rotate(a_stack, b_stack, 1, 0);
		else if (ft_lstsize(*b_stack) < 3)
		{
			push(a_stack, b_stack, 1, 0);
			if (ft_lstsize(*b_stack) == 3)
				ft_invert_three_num(a_stack, b_stack);
		}
		else
			ft_optimized_push(a_stack, b_stack);
	}
	ft_sort_three_num(a_stack, b_stack);
}

void	ft_optimized_push(t_stk **a_stack, t_stk **b_stack)
{
	t_stk	*a_trg;
	t_stk	*b_trg;
	int		com;

	a_trg = ft_cost_com_ratio(a_stack);
	com = a_trg->t_com;
	if (a_trg->trgt == -1 && a_trg->sorted != 1)
		a_trg->trgt = ft_high(b_stack);
	b_trg = ft_find_target(b_stack, a_trg->trgt);
	if (a_trg->t_com != 0)
	{
		if (a_trg->t_dir == 1)
			rotate(a_stack, b_stack, a_trg->t_com, 2);
		else
			reverse_rotate(a_stack, b_stack, a_trg->t_com, 2);
	}
	if ((*a_stack)->sorted != a_trg->sorted
		|| (*b_stack)->sorted != b_trg->sorted)
	{
		if ((*a_stack)->sorted != a_trg->sorted)
			ft_find(a_stack, b_stack, a_trg->sorted, 0);
		if ((*b_stack)->sorted != b_trg->sorted)
			ft_find(a_stack, b_stack, b_trg->sorted, 1);
	}
	push(a_stack, b_stack, 1, 0);
}

t_stk	*ft_find_target(t_stk **head, int target)
{
	t_stk	*temp;

	temp = *head;
	if (target == -1)
		return (temp);
	while (1)
	{
		if (temp->sorted == target)
			return (temp);
		temp = temp->next;
		if (temp == *head)
			break ;
	}
	return (NULL);
}

void	ft_sort_three_num(t_stk **a_stack, t_stk **b_stack)
{
	int		one;
	int		two;
	int		three;
	t_stk	*current;

	current = *a_stack;
	one = current->sorted;
	two = current->next->sorted;
	three = current->next->next->sorted;
	if (one > two && three > two && three > one)
		swap(a_stack, b_stack, 0);
	else if (one > two && three > two && one > three)
		reverse_rotate(a_stack, b_stack, 1, 0);
	else if (two > one && two > three && one > three)
		rotate(a_stack, b_stack, 1, 0);
	else if (two > one && two > three && three > one)
	{
		swap(a_stack, b_stack, 0);
		reverse_rotate(a_stack, b_stack, 1, 0);
	}
	else if (one > two && two > three && one > three)
	{
		swap(a_stack, b_stack, 0);
		rotate(a_stack, b_stack, 1, 0);
	}
}

void	ft_invert_three_num(t_stk **a_stack, t_stk **b_stack)
{
	int		one;
	int		two;
	int		three;
	t_stk	*current;

	current = *b_stack;
	one = current->sorted;
	two = current->next->sorted;
	three = current->next->next->sorted;
	if (one < two && three < two && three < one)
		swap(a_stack, b_stack, 1);
	else if (one < two && three < two && one < three)
		reverse_rotate(a_stack, b_stack, 1, 1);
	else if (two < one && two < three && one < three)
		rotate(a_stack, b_stack, 1, 1);
	else if (two < one && two < three && three < one)
	{
		swap(a_stack, b_stack, 1);
		reverse_rotate(a_stack, b_stack, 1, 1);
	}
	else if (one < two && one < three && two < three)
	{
		swap(a_stack, b_stack, 1);
		rotate(a_stack, b_stack, 1, 1);
	}
}
