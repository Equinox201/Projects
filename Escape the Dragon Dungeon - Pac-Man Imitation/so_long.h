
#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*****************************************************************************/
/*                                  STRUCTURE                                */
/*****************************************************************************/

typedef struct t_fill
{
	int		x;
	int		y;
}			t_fill;

typedef struct t_objects
{
	int		items;
	int		it;
	int		player;
	int		escape;
	int		dragon;
}			t_obj;

typedef struct t_map
{
	char	**map;
	char	**fill;
	void	*wall;
	void	*bg;
	void	*drag;
	void	*exit;
	void	*chest;
	void	*play;
}			t_maps;

typedef struct t_data
{
	int		map_x;
	int		map_y;
	int		play_x;
	int		play_y;
	int		ex_x;
	int		ex_y;
	int		moves;
	int		collected;
	void	*wind;
	void	*libx;
	t_obj	obj;
	t_maps	m_info;
}			t_data;

/*****************************************************************************/
/*                                  FUNCTIONS                                */
/*****************************************************************************/

int			ft_str_to_array(int fd, t_data *game);
int			ft_walled_in(char **array, t_data *game);
int			ft_rectangle(char **array, t_data *game);
int			ft_check_map(t_data *game);

void		ft_fill(char **board, t_data *game, t_fill *pos);
int			ft_flood(char **array, t_data *game);

int			ft_object_counter(t_data *game, char c, int y, int x);
void		ft_object_count(t_data *game, char c);
int			ft_file_format(char *str, int len);

int			ft_strncmp(char *str1, char *str2, int a);
int			ft_valid_symbol(char c);
char		*ft_mem_alloc_fill(int nb, int size);

void		ft_mlx(t_data *game);
void		ft_create_game_window(t_data *g);
void		ft_create_visual(t_data *g);
void		ft_images(t_data *g);
void		ft_img_win(t_data *g, int x, int y, char c);
int			ft_key_bind(int key, t_data *game);

int			ft_end_game(t_data *game, int id);
void		ft_end_message(int id);
void		ft_freedom(t_data *game);
void		ft_free_map(char **map);

void		ft_right(t_data *game);
void		ft_left(t_data *game);
void		ft_down(t_data *game);
void		ft_up(t_data *game);

void		ft_update_position(t_data *game, int px, int py);
int			ft_check(t_data *game);

char		**ft_split(char *s, char c);
int			ft_strlen(char *str);
int			ft_printf(const char *input, ...);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_error(int id);

void		ft_init_obj(t_obj *o);
void		ft_init_map(t_maps *m);
void		ft_init_data(t_data *d);

#endif
