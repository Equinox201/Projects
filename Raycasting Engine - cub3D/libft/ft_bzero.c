#include "libft.h"

void	ft_bzero(void *str, size_t b)
{
	while (b--)
		*(unsigned char *)str ++ = 0;
}
