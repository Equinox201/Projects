
#include "so_long.h"

char	*ft_mem_alloc_fill(int nb, int size)
{
	char	*str;
	int		len;
	int		a;

	a = 0;
	len = nb * size;
	str = malloc(nb * size);
	if (!str)
		return (NULL);
	while (a < len - 1)
	{
		str[a] = 0;
		a++;
	}
	str[a] = '\0';
	return (str);
}

int	ft_valid_symbol(char c)
{
	if (c != 'C' && c != '0' & c != '1' & c != 'E' & c != 'P')
		return (1);
	return (0);
}

int	ft_strncmp(char *str1, char *str2, int a)
{
	int	b;

	b = 0;
	if (a == 0)
		return (0);
	while (str1[b] == str2[b] && b < (a - 1) && str1[b] && str2[b])
		b++;
	return ((unsigned char)str1[b] - (unsigned char)str2[b]);
}

int	ft_file_format(char *str, int len)
{
	if (len < 5)
		return (ft_error(1));
	if (ft_strncmp(str + len - 4, ".ber", 4) == 0)
		return (0);
	else
		return (ft_error(1));
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*game;

	fd = 0;
	if (argc != 2)
		return (ft_error(1));
	if (ft_file_format(argv[1], ft_strlen(argv[1])) != 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(fd), ft_error(1));
	game = malloc(sizeof(t_data));
	if (!game)
		return (close(fd), ft_error(2));
	ft_init_data(game);
	if (ft_str_to_array(fd, game) == 1)
		return (close(fd));
	close(fd);
	if (ft_check_map(game) != 0)
		ft_end_game(game, 3);
	ft_mlx(game);
	return (0);
}
