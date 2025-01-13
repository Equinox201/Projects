
#include "pipex.h"

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

int	ft_str_len(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
		a++;
	return (a);
}

int	ft_new_line(char *temporary)
{
	int	a;

	a = 0;
	while (temporary[a] != '\0')
	{
		if (temporary[a] == '\n')
		{
			return (1);
		}
		a++;
	}
	return (0);
}
