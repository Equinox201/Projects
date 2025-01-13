
#include "push_swap.h"

int	ft_isdigit(char a, char b)
{
	if ((a >= 48 && a <= 57) || (a == '-'))
	{
		if (a == '-' && !(b >= 48 && b <= 57))
			return (0);
		else
			return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		a;
	long	sign;
	long	new;

	a = 0;
	sign = 1;
	new = 0;
	while (str[a] == 32 || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		new = (new * 10) + (str[a] - '0');
		a++;
	}
	return (new * sign);
}

t_stk	*ft_data_validation(char **arg, t_stk *a_head, int size)
{
	int		a;
	int		b;
	long	number;

	a = 0;
	while (a < size)
	{
		b = 0;
		while (arg[a][b])
		{
			if (ft_isdigit(arg[a][b], arg[a][b + 1]) == 0)
				return (ft_lstclear(&a_head), NULL);
			b++;
		}
		if (ft_strlen(arg[a]) > 11)
			return (ft_lstclear(&a_head), NULL);
		number = ft_atol(arg[a]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_lstclear(&a_head), NULL);
		ft_add_new_node(&a_head, number);
		a++;
	}
	return (a_head);
}

int	ft_duplicate_values(t_stk *head)
{
	t_stk	*current;
	t_stk	*compare;

	current = head;
	while (1)
	{
		compare = current->next;
		while (compare != head)
		{
			if (current->number == compare->number)
				return (1);
			compare = compare->next;
		}
		current = current->next;
		if (current == head)
			break ;
	}
	return (0);
}

t_stk	*ft_init_stack_a(char **arguments, int size)
{
	t_stk	*a_head;

	a_head = NULL;
	if (arguments == NULL)
		return (NULL);
	a_head = ft_data_validation(arguments, a_head, size);
	if (ft_lstsize(a_head) < 1)
	{
		ft_lstclear(&a_head);
		write(1, "Error\n", 6);
		return (NULL);
	}
	if (ft_duplicate_values(a_head) == 1)
	{
		ft_lstclear(&a_head);
		write(1, "Error\n", 6);
		return (NULL);
	}
	ft_initial_order(a_head);
	return (a_head);
}
