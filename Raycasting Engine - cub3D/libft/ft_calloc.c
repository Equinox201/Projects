#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*a;

	if (nb * size > 2147483647)
		return (NULL);
	if (nb == 0 || size == 0)
	{
		nb = 0;
		size = 1;
	}
	a = (void *)malloc(nb * size);
	if (!a)
		return (NULL);
	ft_bzero(a, nb * size);
	return (a);
}
