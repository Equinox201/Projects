
#include "so_long.h"

void	ft_init_obj(t_obj *o)
{
	if (o != NULL)
	{
		o->it = 0;
		o->items = 0;
		o->player = 0;
		o->escape = 0;
		o->dragon = 0;
	}
}

void	ft_init_map(t_maps *m)
{
	if (m != NULL)
	{
		m->map = NULL;
		m->fill = NULL;
		m->wall = NULL;
		m->fill = NULL;
		m->drag = NULL;
		m->exit = NULL;
		m->bg = NULL;
		m->chest = NULL;
		m->play = NULL;
	}
}

void	ft_init_data(t_data *d)
{
	if (d != NULL)
	{
		d->map_x = 0;
		d->map_y = 0;
		d->play_x = 0;
		d->play_y = 0;
		d->ex_x = 0;
		d->ex_x = 0;
		d->moves = 0;
		d->wind = NULL;
		d->libx = NULL;
		ft_init_obj(&(d->obj));
		ft_init_map(&(d->m_info));
	}
}
