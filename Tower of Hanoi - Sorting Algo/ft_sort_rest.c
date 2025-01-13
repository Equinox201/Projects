
#include "push_swap.h"

void	ft_find(t_stk **a_stack, t_stk **b_stack, int sorted, int c)
{
	t_stk	*temp;
	t_stk	*start;
	int		i;

	if (c == 0)
		temp = *a_stack;
	else
		temp = *b_stack;
	start = temp;
	while (temp)
	{
		if (temp->sorted == sorted)
		{
			i = ft_comp(temp);
			if (temp->t_dir == 1)
				rotate(a_stack, b_stack, i, c);
			else
				reverse_rotate(a_stack, b_stack, i, c);
			return ;
		}
		temp = temp->next;
		if (temp == start)
			return ;
	}
}

t_stk	*ft_cost_com_ratio(t_stk **head)
{
	t_stk	*t;
	t_stk	*res;
	int		min;
	int		max;

	t = *head;
	res = NULL;
	min = t->nts;
	max = 0;
	while (t)
	{
		if (t->big_t == 0)
		{
			if (t->cost < min || (t->cost == min && t->t_com > max))
			{
				min = t->cost;
				max = t->t_com;
				res = t;
			}
		}
		t = t->next;
		if (t == *head)
			break ;
	}
	return (res);
}

void	ft_targeting(t_stk **a_stack, t_stk **b_stack)
{
	ft_set_target(a_stack, b_stack);
	if (!b_stack)
		return ;
	ft_set_target(b_stack, a_stack);
}

int	ft_high(t_stk **head)
{
	t_stk	*temp;
	int		value;

	temp = *head;
	value = 0;
	while (temp)
	{
		if (temp->sorted > value)
			value = temp->sorted;
		temp = temp->next;
		if (temp == *head)
			break ;
	}
	return (value);
}

void	ft_common_moves(t_stk *current, int c_cur, int c_src, int trigger)
{
	int	result;

	result = c_cur - c_src;
	if (result < 0)
		result *= -1;
	if (result == 0)
		result = c_cur;
	if (current->t_dir == trigger && c_src != 0 && c_cur != 0)
		current->t_com = result;
	else
		current->t_com = 0;
}
