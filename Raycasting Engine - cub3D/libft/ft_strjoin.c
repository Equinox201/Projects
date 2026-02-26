#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		d;
	char		*c;

	c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!c)
		return (NULL);
	d = 0;
	while (s1[d])
	{
		c[d] = s1[d];
		d++;
	}
	d = 0;
	while (s2[d])
	{
		c[ft_strlen(s1) + d] = s2[d];
		d++;
	}
	c[ft_strlen(s1) + d] = '\0';
	return (c);
}
