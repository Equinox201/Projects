
#include "push_swap.h"

void	ft_assign_cost(t_stk *head)
{
	t_stk	*temp;
	int		len;

	temp = head;
	len = ft_lstsize(head);
	while (temp)
	{
		temp->c_rot = len - temp->position + 1;
		temp->c_rev = temp->position - 1;
		if (temp->c_rot <= temp->c_rev)
			temp->t_dir = 1;
		else
			temp->t_dir = 2;
		temp = temp->next;
		if (temp == head)
			return ;
	}
}

void	ft_big_three(t_stk *head)
{
	t_stk	*temp;
	int		len;

	temp = head;
	len = ft_lstsize(head);
	while (temp)
	{
		if (temp->sorted > len - 3)
			temp->big_t = 1;
		else
			temp->big_t = 0;
		temp = temp->next;
		if (temp == head)
			return ;
	}
}

void	ft_set_target(t_stk **head, t_stk **other)
{
	t_stk	*temp;
	t_stk	*oth;
	int		min;

	temp = *head;
	oth = *other;
	while (temp)
	{
		min = -1;
		oth = *other;
		while (oth)
		{
			if (oth->sorted < temp->sorted && (min == -1 || oth->sorted > min))
				min = oth->sorted;
			oth = oth->next;
			if (oth == *other)
				break ;
		}
		temp->trgt = min;
		ft_first(temp, other);
		ft_set_cost(temp, other);
		temp = temp->next;
		if (temp == *head)
			break ;
	}
}

void	ft_set_cost(t_stk *current, t_stk **other)
{
	t_stk	*search;
	int		cur_cst;
	int		src_cst;
	int		trigger;

	search = *other;
	src_cst = 0;
	cur_cst = ft_comp(current);
	trigger = 0;
	while (search)
	{
		if (search->sorted == current->trgt)
		{
			src_cst = ft_comp(search);
			trigger = search->t_dir;
			break ;
		}
		search = search->next;
		if (search == *other)
			break ;
	}
	current->cost = src_cst + cur_cst + 1;
	ft_common_moves(current, cur_cst, src_cst, trigger);
}

void	ft_refresh_pc(t_stk *a_stack, t_stk *b_stack)
{
	ft_position(a_stack);
	ft_assign_cost(a_stack);
	if (b_stack != NULL)
	{
		ft_position(b_stack);
		ft_assign_cost(b_stack);
	}
	ft_targeting(&a_stack, &b_stack);
}
