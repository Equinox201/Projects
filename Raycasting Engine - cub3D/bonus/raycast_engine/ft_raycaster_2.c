#include "cub3D_bonus.h"

void	*ft_pxl_init(size_t count, size_t size)
{
	void			*px;
	unsigned char	*p;
	size_t			a;

	px = malloc(count * size);
	if (!px)
		return (NULL);
	p = (unsigned char *)px;
	a = count * size;
	while (a--)
		*p++ = 0;
	return (px);
}

void	ft_pxl_fill(t_data *d)
{
	ft_free_framebuffers(d);
	ft_alloc_pxl_rows(d);
	ft_alloc_zbuffer(d);
}

void	ft_display_wind(t_data *d, t_img *p, int x, int y)
{
	int	dot;

	if (d->pxl[y][x] > 0)
	{
		dot = y * (p->line / 4) + x;
		p->addr[dot] = d->pxl[y][x];
	}
	else if (y < d->mapy / 2)
	{
		dot = y * (p->line / 4) + x;
		p->addr[dot] = *(d->text.rgb_c);
	}
	else if (y < d->mapy - 1)
	{
		dot = y * (p->line / 4) + x;
		p->addr[dot] = *(d->text.rgb_g);
	}
}

void	ft_display(t_data *d)
{
	t_img	p;
	int		x;
	int		y;

	y = 0;
	ft_img_init(&p);
	p.img = mlx_new_image(d->mlx, d->mapx, d->mapy);
	if (p.img == NULL)
		ft_die_alloc(d, "MLX Image Failure");
	p.addr = (int *)mlx_get_data_addr(p.img, &p.bpp, &p.line, &p.endian);
	while (y < d->mapy)
	{
		x = 0;
		while (x < d->mapx)
		{
			ft_display_wind(d, &p, x, y);
			x++;
		}
		y++;
	}
	ft_render_coins(d, &p);
	mlx_put_image_to_window(d->mlx, d->wind, p.img, 0, 0);
	mlx_destroy_image(d->mlx, p.img);
	ft_render_minimap(d);
}
