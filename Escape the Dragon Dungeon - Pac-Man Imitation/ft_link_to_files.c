
#include "so_long.h"

void	ft_images(t_data *g)
{
	int	p;

	p = 64;
	g->m_info.bg = mlx_xpm_file_to_image(g->libx, "objects/bg.xpm", &p, &p);
	g->m_info.wall = mlx_xpm_file_to_image(g->libx, "objects/wall.xpm", &p, &p);
	g->m_info.chest = mlx_xpm_file_to_image(g->libx, "objects/chest.xpm", &p,
			&p);
	g->m_info.drag = mlx_xpm_file_to_image(g->libx, "objects/drag.xpm", &p, &p);
	g->m_info.play = mlx_xpm_file_to_image(g->libx, "objects/play.xpm", &p, &p);
	g->m_info.exit = mlx_xpm_file_to_image(g->libx, "objects/exit.xpm", &p, &p);
}

void	ft_img_win(t_data *g, int x, int y, char c)
{
	int	a;
	int	b;

	a = x * 64;
	b = y * 64;
	if (c == '0')
		mlx_put_image_to_window(g->libx, g->wind, g->m_info.bg, a, b);
	else if (c == 'C')
		mlx_put_image_to_window(g->libx, g->wind, g->m_info.chest, a, b);
	else if (c == '1')
		mlx_put_image_to_window(g->libx, g->wind, g->m_info.wall, a, b);
	else if (c == 'P')
		mlx_put_image_to_window(g->libx, g->wind, g->m_info.play, a, b);
	else if (c == 'E')
		mlx_put_image_to_window(g->libx, g->wind, g->m_info.exit, a, b);
}

void	ft_create_visual(t_data *g)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < g->map_y)
	{
		x = 0;
		while (x < g->map_x)
		{
			c = g->m_info.map[y][x];
			ft_img_win(g, x, y, c);
			x++;
		}
		y++;
	}
}

// if (g->m_info.map[y][x] == '0')
// 	mlx_put_image_to_window(g->libx, g->wind, g->m_info.bg, a, b);
// else if (g->m_info.map[y][x] == 'C')
// 	mlx_put_image_to_window(g->libx, g->wind, g->m_info.chest,
// 		a, b);
// else if (g->m_info.map[y][x] == '1')
// 	mlx_put_image_to_window(g->libx, g->wind, g->m_info.wall, a, b);
// else if (g->m_info.map[y][x] == 'P')
// 	mlx_put_image_to_window(g->libx, g->wind, g->m_info.play, a, b);
// else if (g->m_info.map[y][x] == 'E')
// 	mlx_put_image_to_window(g->libx, g->wind, g->m_info.exit, a, b);

// void	print_2d_array(char **array, int rows, int cols)
// {
// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < cols; j++)
// 		{
// 			printf("%c ", array[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

void	ft_create_game_window(t_data *game)
{
	char	*name;
	int		x;
	int		y;

	x = game->map_x * 64;
	y = game->map_y * 64;
	name = "Escape the Dragon Dugeon";
	game->libx = mlx_init();
	if (!game->libx)
	{
		exit(EXIT_FAILURE);
	}
	game->wind = mlx_new_window(game->libx, x, y, name);
	if (!game->wind)
	{
		ft_end_game(game, 1);
		exit(EXIT_FAILURE);
	}
	ft_images(game);
	ft_create_visual(game);
}
