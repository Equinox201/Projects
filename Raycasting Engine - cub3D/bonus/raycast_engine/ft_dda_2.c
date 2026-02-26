#include "cub3D_bonus.h"

void	ft_dda_algo(t_data *d, t_track *t, t_play *p)
{
	int	cross;
	int	check;

	cross = ft_dda_prep(t, p);
	t->tile = '0';
	while (cross == 0)
	{
		ft_dda_step(t);
		check = ft_ray_check(d, t);
		if (check == 1)
		{
			t->tile = '1';
			break ;
		}
		else if (check == 2)
		{
			t->tile = d->map.fl_map[t->map.y][t->map.x];
			cross = 1;
		}
	}
	ft_line_len(d, t, p);
}
