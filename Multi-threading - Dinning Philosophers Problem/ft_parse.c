
#include "philosophers.h"

int	ft_validation(const char *str)
{
	int	number;
	int	a;

	a = 0;
	if (ft_strlen(str) > 11)
		return (-1);
	while (str[a])
	{
		if (ft_isdigit(str[a], str[a + 1]) == 0)
			return (-1);
		a++;
	}
	number = ft_atol(str);
	if (number < 1 || number > INT_MAX)
		return (-1);
	return (number);
}

void	ft_init_forks(t_data *temp)
{
	int	a;

	a = 0;
	while (a < temp->philo)
	{
		temp->forks[a].f_id = a;
		pthread_mutex_init(&temp->forks[a].fork, NULL);
		a++;
	}
}

void	ft_init_philos(t_data *temp)
{
	int	a;

	a = 0;
	while (a < temp->philo)
	{
		temp->filo[a].phl_id = a + 1;
		temp->filo[a].flag = 0;
		temp->filo[a].e_cnt = 0;
		temp->filo[a].e_last = temp->start;
		temp->filo[a].data = temp;
		pthread_mutex_init(&temp->filo[a].p_lok, NULL);
		if ((temp->filo[a].phl_id % 2) == 0)
		{
			temp->filo[a].l_frk = &temp->forks[a];
			temp->filo[a].r_frk = &temp->forks[(a + 1) % temp->philo];
		}
		else
		{
			temp->filo[a].l_frk = &temp->forks[(a + 1) % temp->philo];
			temp->filo[a].r_frk = &temp->forks[a];
		}
		a++;
	}
}

int	ft_init_data(t_data *t, int argc, char **argv)
{
	t->philo = ft_validation(argv[1]);
	if (t->philo > 300 || t->philo < 1)
		return (-1);
	t->d_time = ft_validation(argv[2]);
	t->e_time = ft_validation(argv[3]);
	t->s_time = ft_validation(argv[4]);
	t->limit = -1;
	t->eaten = 0;
	t->stop = 0;
	pthread_mutex_init(&t->death, NULL);
	pthread_mutex_init(&t->eating, NULL);
	pthread_mutex_init(&t->print, NULL);
	if (argc == 6)
	{
		t->limit = ft_validation(argv[5]);
		if (t->limit <= 0)
			return (-1);
	}
	if (t->philo == -1 || t->d_time == -1 || t->e_time == -1 || t->s_time == -1)
		return (-1);
	return (0);
}

t_data	*ft_parsing(int argc, char **argv)
{
	t_data	*temp;

	temp = malloc(sizeof(t_data) * 1);
	if (!temp)
		return (free(temp), NULL);
	if (ft_init_data(temp, argc, argv) == -1)
		return (free(temp), NULL);
	temp->forks = malloc(sizeof(t_mutex) * temp->philo);
	if (!temp->forks)
		return (free(temp), NULL);
	ft_init_forks(temp);
	temp->filo = malloc(sizeof(t_philo) * temp->philo);
	if (!temp->forks)
		return (free(temp), NULL);
	ft_init_philos(temp);
	return (temp);
}
