
#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stk **head)
{
	t_stk	*first;
	t_stk	*second;
	t_stk	*last;

	if (!head || !(*head) || !(*head)->next || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = (*head)->previous;
	first->next = second->next;
	second->next->previous = first;
	second->next = first;
	first->previous = second;
	second->previous = last;
	last->next = second;
	*head = second;
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stk **head)
{
	t_stk	*first;
	t_stk	*second;
	t_stk	*last;

	if (!head || !(*head) || !(*head)->next || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	last = (*head)->previous;
	first->next = second->next;
	second->next->previous = first;
	second->next = first;
	first->previous = second;
	second->previous = last;
	last->next = second;
	*head = second;
}

// sa & sb at the same time.
void	ss(t_stk **a_head, t_stk **b_head)
{
	sa(a_head);
	sb(b_head);
}

void	swap(t_stk **a_stack, t_stk **b_stack, int c)
{
	if (c == 0)
	{
		sa(a_stack);
		write(1, "sa\n", 3);
	}
	else if (c == 1)
	{
		sb(b_stack);
		write(1, "sb\n", 3);
	}
	else
	{
		ss(a_stack, b_stack);
		write(1, "ss\n", 3);
	}
	ft_refresh_pc(*a_stack, *b_stack);
}
