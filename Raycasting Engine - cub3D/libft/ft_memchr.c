#include "libft.h"

void	*ft_memchr(const void *str, int a, size_t size)
{
	size_t	b;

	b = 0;
	while (b < size)
	{
		if (*(unsigned char *)(str + b) == (unsigned char)a)
			return ((void *)(str + b));
		b++;
	}
	return (NULL);
}
