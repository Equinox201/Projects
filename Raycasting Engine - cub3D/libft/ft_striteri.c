#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	a;

	a = 0;
	while (s[a])
	{
		(*f)(a, s + a);
		a++;
	}
	s[a] = '\0';
}
