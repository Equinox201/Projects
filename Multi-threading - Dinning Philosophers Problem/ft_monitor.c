
#include "philosophers.h"

int	ft_everyone_ate(t_data *d)
{
	int	all_ate;

	all_ate = 1;
	if (d->limit < 0)
		return (0);
	all_ate = ft_check_all_ate(d, all_ate);
	if (all_ate)
	{
		pthread_mutex_lock(&d->death);
		d->eaten = 1;
		d->stop = 1;
		pthread_mutex_unlock(&d->death);
		return (1);
	}
	return (0);
}

int	ft_check_all_ate(t_data *d, int all_ate)
{
	int	a;

	a = 0;
	pthread_mutex_lock(&d->eating);
	while (a < d->philo)
	{
		if (d->filo[a].e_cnt < d->limit)
		{
			all_ate = 0;
			break ;
		}
		a++;
	}
	pthread_mutex_unlock(&d->eating);
	return (all_ate);
}

int	ft_check_philos(t_data *d)
{
	int		a;
	long	now;

	a = 0;
	while (a < d->philo)
	{
		pthread_mutex_lock(&d->eating);
		now = ft_get_time();
		if ((now - d->filo[a].e_last) > d->d_time)
		{
			ft_print_state(&d->filo[a], 5);
			pthread_mutex_lock(&d->death);
			d->stop = 1;
			pthread_mutex_unlock(&d->death);
			pthread_mutex_unlock(&d->eating);
			return (1);
		}
		pthread_mutex_unlock(&d->eating);
		a++;
	}
	return (0);
}

void	*ft_checker(void *arg)
{
	t_data	*d;

	d = (t_data *)arg;
	while (1)
	{
		if (ft_check_philos(d) == 1)
			return (NULL);
		if (ft_everyone_ate(d) == 1)
			return (NULL);
		usleep(500);
	}
}

/*
void	*ft_checker(void *arg)
{
	t_data	*d;
	int		a;
	long	now;

	d = (t_data *)arg;
	a = 0;
	while (1)
	{
		a = 0;
		while (a < d->philo)
		{
			pthread_mutex_lock(&d->eating);
			now = ft_get_time();
			if ((now - d->filo[a].e_last) > d->d_time)
			{
				ft_print_state(&d->filo[a], 5);
				pthread_mutex_lock(&d->death);
				d->stop = 1;
				pthread_mutex_unlock(&d->death);
				pthread_mutex_unlock(&d->eating);
				return (NULL);
			}
			pthread_mutex_unlock(&d->eating);
			a++;
		}
		if (ft_everyone_ate(d) == 1)
			return (NULL);
		usleep(500);
	}
}
*/

void	ft_single_phil(t_data *d)
{
	pthread_mutex_lock(&(d->forks[0].fork));
	ft_print_state(&(d->filo[0]), 1);
	ft_sleeper(d->e_time);
	ft_print_state(&(d->filo[0]), 5);
	pthread_mutex_unlock(&(d->forks[0].fork));
}
