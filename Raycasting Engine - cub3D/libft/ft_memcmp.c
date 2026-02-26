#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t a)
{
	size_t	b;

	b = 0;
	while (b < a)
	{
		if (*(unsigned char *)(str1 + b) != *(unsigned char *)(str2 + b))
			return (*(unsigned char *)(str1 + b) - *(unsigned char *)(str2
					+ b));
		b++;
	}
	return (0);
}
