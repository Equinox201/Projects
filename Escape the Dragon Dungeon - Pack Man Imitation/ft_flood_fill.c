
#include "so_long.h"

void	ft_fill(char **board, t_data *game, t_fill *pos)
{
	char	c;

	if (pos->y < 0 || pos->y >= (game->map_y) || pos->x < 0
		|| pos->x >= (game->map_x) || board[pos->y][pos->x] == '1')
		return ;
	if (board[pos->y][pos->x] == '1' || board[pos->y][pos->x] == 'x')
		return ;
	c = board[pos->y][pos->x];
	board[pos->y][pos->x] = 'x';
	ft_object_count(game, c);
	ft_fill(board, game, &(t_fill){pos->x - 1, pos->y});
	ft_fill(board, game, &(t_fill){pos->x + 1, pos->y});
	ft_fill(board, game, &(t_fill){pos->x, pos->y - 1});
	ft_fill(board, game, &(t_fill){pos->x, pos->y + 1});
}

int	ft_flood(char **array, t_data *game)
{
	char	**board;
	t_fill	*position;

	board = array;
	position = malloc(sizeof(t_fill));
	if (!position)
		return (1);
	position->x = game->play_x;
	position->y = game->play_y;
	ft_fill(board, game, position);
	free(position);
	if (game->obj.dragon == 0 && game->obj.player == 0 && game->obj.items == 0
		&& game->obj.escape == 0)
		return (0);
	return (ft_error(9));
}

void	ft_object_count(t_data *game, char c)
{
	if (c == 'C')
		game->obj.items--;
	if (c == 'E')
		game->obj.escape--;
	if (c == 'D')
		game->obj.dragon--;
	if (c == 'P')
		game->obj.player--;
}
