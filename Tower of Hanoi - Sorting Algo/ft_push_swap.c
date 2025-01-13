
#include "push_swap.h"

int	ft_is_sorted(t_stk **a_stack)
{
	t_stk	*temp;

	temp = *a_stack;
	while (temp)
	{
		if (temp->number > temp->next->number)
			return (1);
		temp = temp->next;
		if (temp-> next == *a_stack)
			break ;
	}
	return (0);
}

void	ft_first(t_stk *temp, t_stk **other)
{
	if (temp->sorted == 1)
		temp->trgt = ft_high(other);
}

void	ft_sort_two(t_stk *a_stack)
{
	int		one;
	int		two;
	t_stk	*current;

	current = a_stack;
	one = current->number;
	two = current->next->number;
	if (one > two)
	{
		ra(&a_stack);
		write(1, "sa\n", 3);
	}
	return ;
}

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

int	main(int argc, char **argv)
{
	t_stk	*a_stack;
	t_stk	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	argv++;
	if (argc == 1)
		return (0);
	a_stack = ft_init_stack_a(argv, (argc - 1));
	if (!a_stack)
		return (0);
	if (ft_lstsize(a_stack) == 2 || ft_is_sorted(&a_stack) == 0)
	{
		if (ft_lstsize(a_stack) == 2)
			ft_sort_two(a_stack);
		ft_lstclear(&a_stack);
		return (0);
	}
	ft_sort_list(a_stack);
	ft_push_all_save_three(&a_stack, &b_stack);
	ft_push_back(&a_stack, &b_stack);
	ft_lstclear(&a_stack);
	ft_lstclear(&b_stack);
	return (0);
}
