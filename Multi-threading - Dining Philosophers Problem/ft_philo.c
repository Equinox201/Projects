
#include "philosophers.h"

void	ft_join_threads(t_data *data)
{
	int	a;

	a = 0;
	while (a < data->philo)
	{
		pthread_join(data->filo[a].id, NULL);
		a++;
	}
	pthread_join(data->monitor, NULL);
}

int	ft_freedom(t_data *data, int x, int y)
{
	int	a;

	a = 0;
	if (!data)
		return (ft_messaging(x, y));
	if (data->forks)
	{
		while (a < data->philo)
		{
			pthread_mutex_destroy(&(data->forks[a].fork));
			a++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&(data->death));
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->eating));
	if (data->filo)
		free(data->filo);
	free(data);
	return (ft_messaging(x, y));
}

int	ft_messaging(int id, int y)
{
	if (id == 1)
	{
		printf("Format Error : ./philosophers ");
		printf("<#_of_philo> <time_to_die> ");
		printf("<time_to_eat> <time_to_sleep> ");
		printf("[<#_of_times_philo_must_eat>]\n");
	}
	if (id == 2)
		printf("Mutex Error : Mutex Initialization Error\n");
	if (id == 3)
	{
		printf("Thread Error : Error creating thread for ");
		if (y == -1)
			printf("monitor");
		else
			printf("philosopher #%d", (y + 1));
	}
	if (id == 4)
		printf("Malloc Issue");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc < 5 || argc > 6)
		return (ft_messaging(1, 0));
	data = ft_parsing(argc, argv);
	if (data == NULL)
		return (ft_freedom(data, 1, 0));
	ft_operations(data);
	return (0);
}
