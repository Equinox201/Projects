#include "libft.h"

void	*ft_memset(void *str, int b, size_t c)
{
	size_t	d;

	d = 0;
	while (d < c)
	{
		*(unsigned char *)(str + d) = (unsigned char)b;
		d++;
	}
	return (str);
}
