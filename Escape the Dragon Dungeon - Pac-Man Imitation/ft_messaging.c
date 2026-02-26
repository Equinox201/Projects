
#include "so_long.h"

void	ft_end_message(int id)
{
	if (id == 1)
	{
		ft_printf("GAME EXIT\nTry Again!\nBetter Luck next time!\n");
		ft_printf("GAME OVER\n");
	}
	else if (id == 0)
	{
		ft_printf("GREAT SUCESS\nCongratulations\nWell Played!\n");
		ft_printf("GAME VICTORY\n");
	}
	else
		ft_printf("GAME OVER\n");
	return ;
}

int	ft_error(int id)
{
	if (id == 1)
	{
		ft_printf("GAME ERROR\nFile Error\nMap or File issue!\n");
		ft_printf("GAME OVER\n");
	}
	if (id == 2)
		ft_printf("GAME ERROR\nSplit or Malloc issue!\n");
	if (id == 3)
		ft_printf("GAME ERROR\nInvalid Map\nMap not Rectangular!\n");
	if (id == 4)
		ft_printf("GAME ERROR\nInvalid Map\nMap not Walled-in!\n");
	if (id == 5)
		ft_printf("GAME ERROR\nInvalid Items\nMin/Max 1 item to play!\n");
	if (id == 6)
		ft_printf("GAME ERROR\nInvalid Items\nUnrecognized Item!\n");
	if (id == 7)
		ft_printf("GAME ERROR\nInvalid Items\nMin 1 Player or Esc\n");
	if (id == 8)
		ft_printf("GAME ERROR\nInvalid Map\nInvalid display area!\n");
	if (id == 9)
		ft_printf("GAME ERROR\nInvalid Map\nGame can't be won!\n");
	return (1);
}

int	ft_end_game(t_data *game, int id)
{
	ft_freedom(game);
	if (game->wind)
		mlx_destroy_window(game->libx, game->wind);
	if (game->libx)
	{
		mlx_destroy_display(game->libx);
		free(game->libx);
	}
	ft_end_message(id);
	free(game);
	exit(EXIT_FAILURE);
}

void	ft_free_map(char **map)
{
	int	a;

	if (map)
	{
		a = 0;
		while (map[a])
		{
			free(map[a]);
			map[a] = NULL;
			a++;
		}
		free(map);
		map = NULL;
	}
}

void	ft_freedom(t_data *g)
{
	ft_free_map(g->m_info.map);
	ft_free_map(g->m_info.fill);
	if (g->m_info.chest)
		mlx_destroy_image(g->libx, g->m_info.chest);
	if (g->m_info.play)
		mlx_destroy_image(g->libx, g->m_info.play);
	if (g->m_info.drag)
		mlx_destroy_image(g->libx, g->m_info.drag);
	if (g->m_info.exit)
		mlx_destroy_image(g->libx, g->m_info.exit);
	if (g->m_info.bg)
		mlx_destroy_image(g->libx, g->m_info.bg);
	if (g->m_info.wall)
		mlx_destroy_image(g->libx, g->m_info.wall);
}
