#include "libft.h"

char	*ft_strchr(const char *str, int a)
{
	unsigned char	c;
	int				b;

	b = 0;
	c = (unsigned char)a;
	while (str[b])
	{
		if (str[b] == c)
			return ((char *)(str + b));
		b++;
	}
	if (str[b] == c)
		return ((char *)(str + b));
	return (NULL);
}
