#include "libft.h"

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
