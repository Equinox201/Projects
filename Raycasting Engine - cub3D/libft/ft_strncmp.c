#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t a)
{
	size_t	b;

	b = 0;
	if (a == 0)
		return (0);
	while (str1[b] == str2[b] && b < (a - 1) && str1[b] && str2[b])
		b++;
	return ((unsigned char)str1[b] - (unsigned char)str2[b]);
}
