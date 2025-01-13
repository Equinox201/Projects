
#include "philosophers.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000));
}

void	ft_sleeper(long s_time)
{
	long	start;
	long	now;
	long	elapsed;
	long	target;

	start = ft_get_time();
	elapsed = 0;
	while (elapsed < s_time)
	{
		now = ft_get_time();
		elapsed = now - start;
		target = s_time - elapsed;
		if (target > 1)
			usleep((target * 1000) / 2);
	}
}
