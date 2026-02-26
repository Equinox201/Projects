#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	b;

	b = 0;
	while (str[b])
		b++;
	return (b);
}
