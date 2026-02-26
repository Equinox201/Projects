
#include "philosophers.h"

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

int	ft_strlen(const char *str)
{
	int	b;

	b = 0;
	while (str[b])
		b++;
	return (b);
}

void	ft_print_state(t_philo *p, int id)
{
	long long	a;

	a = ft_get_time() - p->data->start;
	pthread_mutex_lock(&(p->data->death));
	if (p->data->stop == 1)
	{
		pthread_mutex_unlock(&(p->data->death));
		return ;
	}
	pthread_mutex_unlock(&(p->data->death));
	pthread_mutex_lock(&(p->data->print));
	if (id == 1)
		printf("%lld %d has taken a fork\n", a, p->phl_id);
	if (id == 2)
		printf("%lld %d is eating\n", a, p->phl_id);
	if (id == 3)
		printf("%lld %d is sleeping\n", a, p->phl_id);
	if (id == 4)
		printf("%lld %d is thinking\n", a, p->phl_id);
	if (id == 5)
		printf("%lld %d died\n", a, p->phl_id);
	pthread_mutex_unlock(&(p->data->print));
}
