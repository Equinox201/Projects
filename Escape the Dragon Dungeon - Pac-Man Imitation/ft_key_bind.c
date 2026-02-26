
#include "so_long.h"

void	ft_left(t_data *game)
{
	int	px;
	int	py;

	px = game->play_x - 1;
	py = game->play_y;
	if (game->m_info.map[py][px] == '1')
		return ;
	else
	{
		ft_update_position(game, px, py);
		ft_printf("Number of Movements = %d\n", game->moves);
		if (ft_check(game) == 2)
			ft_end_game(game, 0);
		ft_create_visual(game);
	}
}

void	ft_down(t_data *game)
{
	int	px;
	int	py;

	px = game->play_x;
	py = game->play_y + 1;
	if (game->m_info.map[py][px] == '1')
		return ;
	else
	{
		ft_update_position(game, px, py);
		ft_printf("Number of Movements = %d\n", game->moves);
		if (ft_check(game) == 2)
			ft_end_game(game, 0);
		ft_create_visual(game);
	}
}

void	ft_up(t_data *game)
{
	int	px;
	int	py;

	px = game->play_x;
	py = game->play_y - 1;
	if (game->m_info.map[py][px] == '1')
		return ;
	else
	{
		ft_update_position(game, px, py);
		ft_printf("Number of Movements = %d\n", game->moves);
		if (ft_check(game) == 2)
			ft_end_game(game, 0);
		ft_create_visual(game);
	}
}

void	ft_right(t_data *game)
{
	int	px;
	int	py;

	px = game->play_x + 1;
	py = game->play_y;
	if (game->m_info.map[py][px] == '1')
		return ;
	else
	{
		ft_update_position(game, px, py);
		ft_printf("Number of Movements = %d\n", game->moves);
		if (ft_check(game) == 2)
			ft_end_game(game, 0);
		ft_create_visual(game);
	}
}

int	ft_key_bind(int key, t_data *game)
{
	if (key == 65307)
		ft_end_game(game, 1);
	if (key == 97 || key == 65361)
		ft_left(game);
	if (key == 115 || key == 65364)
		ft_down(game);
	if (key == 119 || key == 65362)
		ft_up(game);
	if (key == 100 || key == 65363)
		ft_right(game);
	return (0);
}
