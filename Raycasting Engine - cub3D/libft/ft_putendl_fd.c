#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	a;

	a = 0;
	if (!s)
		return ;
	while (s[a])
	{
		write(fd, &s[a], 1);
		a++;
	}
	write(fd, "\n", 1);
}
