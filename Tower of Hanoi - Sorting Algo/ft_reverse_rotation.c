
#include "push_swap.h"

void	rra(t_stk **head)
{
	if (*head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->previous;
}

void	rrb(t_stk **head)
{
	if (*head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->previous;
}

void	rrr(t_stk **a_stack, t_stk **b_stack)
{
	rra(a_stack);
	rrb(b_stack);
}

void	rotate(t_stk **a_stack, t_stk **b_stack, int i, int c)
{
	while (i > 0)
	{
		if (c == 0)
		{
			rra(a_stack);
			write(1, "rra\n", 4);
		}
		else if (c == 1)
		{
			rrb(b_stack);
			write(1, "rrb\n", 4);
		}
		else
		{
			rrr(a_stack, b_stack);
			write(1, "rrr\n", 4);
		}
		i--;
	}
	ft_refresh_pc(*a_stack, *b_stack);
}
