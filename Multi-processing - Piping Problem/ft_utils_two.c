
#include "pipex.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	d;

	d = 0;
	if (size > 0)
	{
		while (d < (size - 1) && src[d])
		{
			dest[d] = src[d];
			d++;
		}
		dest[d] = '\0';
	}
	while (src[d])
		d++;
	return (d);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;
	size_t	c;

	a = 0;
	c = 0;
	while (s[c])
		c++;
	if (start > c)
		len = 0;
	else if (len > c - start)
		len = c - start;
	b = (char *)malloc(sizeof(char) * (len + 1));
	if (!b)
		return (NULL);
	while (a < len && s[start + a])
	{
		b[a] = s[start + a];
		a++;
	}
	b[a] = '\0';
	return (b);
}

char	*ft_strdup(const char *str)
{
	int		a;
	char	*dup;

	a = 0;
	while (str[a])
		a++;
	dup = (char *)malloc(sizeof(*str) * (a + 1));
	if (!dup)
		return (NULL);
	a = 0;
	while (str[a])
	{
		dup[a] = str[a];
		a++;
	}
	dup[a] = '\0';
	return (dup);
}

int	ft_non_null(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] != ' ')
			return (0);
		a ++;
	}
	return (1);
}
