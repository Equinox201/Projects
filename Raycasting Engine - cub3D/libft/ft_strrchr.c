#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	char			*b;
	int				c;
	unsigned char	d;

	b = NULL;
	c = 0;
	d = (unsigned char)a;
	while (str[c])
	{
		if (str[c] == d)
			b = (char *)(str + c);
		c++;
	}
	if (str[c] == d)
		return ((char *)(str + c));
	return (b);
}
