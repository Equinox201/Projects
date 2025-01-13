
#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stk **a_head, t_stk **b_head)
{
	t_stk	*top_b;

	top_b = *b_head;
	if (top_b->next != top_b)
	{
		*b_head = top_b->next;
		top_b->next->previous = top_b->previous;
		top_b->previous->next = top_b->next;
	}
	else
		*b_head = NULL;
	if (*a_head != NULL)
	{
		top_b->next = *a_head;
		top_b->previous = (*a_head)->previous;
		(*a_head)->previous->next = top_b;
		(*a_head)->previous = top_b;
		top_b->next->previous = top_b;
	}
	else
	{
		top_b->next = top_b;
		top_b->previous = top_b;
	}
	*a_head = top_b;
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stk **a_head, t_stk **b_head)
{
	t_stk	*top_a;

	top_a = *a_head;
	if (top_a->next != top_a)
	{
		*a_head = top_a->next;
		top_a->next->previous = top_a->previous;
		top_a->previous->next = top_a->next;
	}
	else
		*a_head = NULL;
	if (*b_head != NULL)
	{
		top_a->next = *b_head;
		top_a->previous = (*b_head)->previous;
		(*b_head)->previous->next = top_a;
		(*b_head)->previous = top_a;
		top_a->next->previous = top_a;
	}
	else
	{
		top_a->next = top_a;
		top_a->previous = top_a;
	}
	*b_head = top_a;
}

void	push(t_stk **a_stack, t_stk **b_stack, int i, int c)
{
	while (i > 0)
	{
		if (c == 0)
		{
			pb(a_stack, b_stack);
			write(1, "pb\n", 3);
		}
		else
		{
			pa(a_stack, b_stack);
			write(1, "pa\n", 3);
		}
		i--;
	}
	ft_refresh_pc(*a_stack, *b_stack);
}
