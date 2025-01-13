
#include "so_long.h"

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;
	size_t	c;

	a = 0;
	c = 0;
	if (s == NULL)
		return (NULL);
	while (s[c])
		c++;
	if (start > c)
		len = 0;
	else if (len > c - start)
		len = c - start;
	b = (char *)malloc(sizeof(char) * (len + 1));
	if (!b)
		return (NULL);
	while (a < len)
	{
		b[a] = s[start + a];
		a++;
	}
	b[a] = '\0';
	return (b);
}

void	ft_update_position(t_data *game, int px, int py)
{
	if (game->m_info.map[py][px] == 'E')
	{
		game->m_info.map[game->play_y][game->play_x] = '0';
		game->m_info.map[py][px] = 'P';
	}
	else if (game->m_info.map[py][px] == 'C')
	{
		game->obj.it--;
		game->m_info.map[game->play_y][game->play_x] = '0';
		game->m_info.map[py][px] = 'P';
	}
	else if (game->m_info.map[py][px] == '0')
	{
		game->m_info.map[game->play_y][game->play_x] = '0';
		game->m_info.map[py][px] = 'P';
	}
	if (game->m_info.map[game->ex_y][game->ex_x] == '0')
		game->m_info.map[game->ex_y][game->ex_x] = 'E';
	game->play_y = py;
	game->play_x = px;
	game->moves++;
}

int	ft_check(t_data *game)
{
	if (game->obj.it == 0 && game->play_x == game->ex_x
		&& game->play_y == game->ex_y)
		return (2);
	else if (game->obj.items == 0)
		return (1);
	return (0);
}

void	ft_mlx(t_data *game)
{
	ft_create_game_window(game);
	mlx_hook(game->wind, 17, 0, ft_end_game, game);
	mlx_key_hook(game->wind, ft_key_bind, game);
	mlx_loop(game->libx);
	ft_end_game(game, 1);
}
