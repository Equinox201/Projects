
#include "so_long.h"

int	ft_str_to_array(int fd, t_data *game)
{
	char	*array;
	int		size;

	array = ft_mem_alloc_fill(1200, sizeof(char));
	if (!array)
		return (1);
	size = read(fd, array, 1200);
	if (size == -1 || size > 620)
	{
		free(array);
		return (ft_error(1));
	}
	game->m_info.map = ft_split(array, '\n');
	game->m_info.fill = ft_split(array, '\n');
	if (!game->m_info.map || !game->m_info.fill)
	{
		ft_free_map(game->m_info.map);
		ft_free_map(game->m_info.fill);
		return (ft_error(3));
	}
	free(array);
	close (fd);
	return (0);
}

int	ft_check_map(t_data *game)
{
	if (ft_rectangle(game->m_info.map, game) == 1)
		return (1);
	if (ft_walled_in(game->m_info.map, game) == 1)
		return (1);
	if (ft_flood(game->m_info.fill, game) == 1)
		return (1);
	return (0);
}

int	ft_rectangle(char **array, t_data *game)
{
	int	row;
	int	len;
	int	col;

	row = 0;
	col = -1;
	while (array[row])
	{
		len = ft_strlen(array[row]);
		if (col == -1)
			col = len;
		if (col != len)
			return (ft_error(3));
		row++;
	}
	if (row < 3 || col < 3)
		return (ft_error(8));
	if (row > 17 || col - 1 > 30)
		return (ft_error(8));
	game->map_x = col;
	game->map_y = row;
	return (0);
}

int	ft_walled_in(char **array, t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if ((y == 0 || y == game->map_y - 1) && array[y][x] != '1')
				return (ft_error(4));
			if ((x == 0 || x == game->map_x - 1) && array[y][x] != '1')
				return (ft_error(4));
			if (ft_valid_symbol(array[y][x]) == 1)
				return (ft_error(6));
			if (ft_object_counter(game, array[y][x], y, x) != 0)
				return (ft_error(ft_object_counter(game, array[y][x], y, x)));
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_object_counter(t_data *game, char c, int y, int x)
{
	if (c == 'C')
	{
		game->obj.items++;
		game->obj.it++;
		if (game->obj.items < 1)
			return (5);
	}
	if (c == 'E')
	{
		game->obj.escape++;
		game->ex_y = y;
		game->ex_x = x;
		if (game->obj.escape > 1 || game->obj.escape < 1)
			return (7);
	}
	if (c == 'P')
	{
		game->obj.player++;
		game->play_x = x;
		game->play_y = y;
		if (game->obj.player > 1 || game->obj.player < 1)
			return (7);
	}
	return (0);
}
