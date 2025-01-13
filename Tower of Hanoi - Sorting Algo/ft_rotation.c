
#include "push_swap.h"

void	ra(t_stk **head)
{
	if (*head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->next;
}

void	rb(t_stk **head)
{
	if (*head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->next;
}

void	rr(t_stk **a_stack, t_stk **b_stack)
{
	ra(a_stack);
	rb(b_stack);
}

void	reverse_rotate(t_stk **a_stack, t_stk **b_stack, int i, int c)
{
	while (i > 0)
	{
		if (c == 0)
		{
			ra(a_stack);
			write(1, "ra\n", 3);
		}
		else if (c == 1)
		{
			rb(b_stack);
			write(1, "rb\n", 3);
		}
		else
		{
			rr(a_stack, b_stack);
			write(1, "rr\n", 3);
		}
		i--;
	}
	ft_refresh_pc(*a_stack, *b_stack);
}
