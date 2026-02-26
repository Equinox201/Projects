
#include "philosophers.h"

void	ft_philo_eat(t_philo *p)
{
	pthread_mutex_lock(&(p->l_frk->fork));
	ft_print_state(p, 1);
	pthread_mutex_lock(&(p->r_frk->fork));
	ft_print_state(p, 1);
	pthread_mutex_lock(&(p->data->eating));
	pthread_mutex_lock(&(p->p_lok));
	p->e_last = ft_get_time();
	p->e_cnt++;
	pthread_mutex_unlock(&(p->p_lok));
	ft_print_state(p, 2);
	pthread_mutex_unlock(&(p->data->eating));
	ft_sleeper(p->data->e_time);
	pthread_mutex_unlock(&(p->l_frk->fork));
	pthread_mutex_unlock(&(p->r_frk->fork));
}

void	ft_philo_sleep(t_philo *p)
{
	ft_print_state(p, 3);
	ft_sleeper(p->data->s_time);
}

void	*ft_philo_life(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->phl_id % 2 != 0)
		usleep(1000);
	while (1)
	{
		if (ft_check_and_break(p))
			break ;
		ft_philo_eat(p);
		if (ft_check_and_break(p))
			break ;
		ft_philo_sleep(p);
		if (ft_check_and_break(p))
			break ;
		ft_print_state(p, 4);
	}
	return (NULL);
}

int	ft_check_and_break(t_philo *p)
{
	int	result;

	pthread_mutex_lock(&(p->data->death));
	result = (p->data->stop == 1 || p->data->eaten == 1);
	pthread_mutex_unlock(&(p->data->death));
	return (result);
}

int	ft_operations(t_data *d)
{
	int	p;

	p = 0;
	d->start = ft_get_time();
	if (d->philo == 1)
	{
		ft_single_phil(d);
		return (ft_freedom(d, 0, 0));
	}
	while (p < d->philo)
	{
		if (pthread_create(&d->filo[p].id, NULL, ft_philo_life, &(d->filo[p])))
			return (ft_freedom(d, 3, p));
		pthread_mutex_lock(&(d->filo[p].p_lok));
		d->filo[p].e_last = ft_get_time();
		pthread_mutex_unlock(&(d->filo[p].p_lok));
		p++;
	}
	if (pthread_create(&d->monitor, NULL, ft_checker, d))
		return (ft_freedom(d, 3, -1));
	ft_join_threads(d);
	return (ft_freedom(d, 0, 0));
}
