
#include "push_swap.h"

void	ft_position(t_stk *head)
{
	t_stk	*temp;
	t_stk	*start;
	int		count;

	if (!head)
		return ;
	temp = head;
	start = head;
	count = 1;
	while (temp)
	{
		temp->position = count;
		temp = temp->next;
		count++;
		if (temp == start)
			return ;
	}
}

void	ft_initial_order(t_stk *head)
{
	t_stk	*temp;
	t_stk	*start;
	int		count;
	int		len;

	if (!head)
		return ;
	temp = head;
	start = head;
	count = 1;
	len = ft_lstsize(head);
	ft_position(head);
	while (temp)
	{
		temp->sorted = count;
		temp->nts = len;
		temp = temp->next;
		count++;
		if (temp == start)
			return ;
	}
}

void	ft_bbswap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_bubble_sort(int *array, int size)
{
	int	a;
	int	b;
	int	swapped;
	int	end;

	a = 0;
	end = size;
	while (a < end)
	{
		swapped = 0;
		b = 0;
		while (b < end - 1)
		{
			if (array[b] > array[b + 1])
			{
				ft_bbswap(&array[b], &array[b + 1]);
				swapped = 1;
			}
			b++;
		}
		if (swapped == 0)
			break ;
		a++;
	}
}

void	ft_sorted_order(t_stk *head, int *array, int size)
{
	t_stk	*temp;
	int		len;
	int		a;

	if (head == NULL || size == 0)
		return ;
	temp = head;
	len = 0;
	while (temp && len < size)
	{
		a = 0;
		len++;
		while (a < size && temp->number != array[a])
		{
			a++;
		}
		temp->sorted = a + 1;
		temp = temp->next;
	}
}
