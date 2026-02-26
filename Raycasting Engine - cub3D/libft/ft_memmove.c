#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	void	*a;

	a = dest;
	if ((!dest && !src) || dest == src)
		return (dest);
	if (dest > src)
	{
		while (size--)
			((char *)dest)[size] = ((char *)src)[size];
	}
	else
	{
		while (size--)
		{
			*(char *)dest++ = *(char *)src++;
		}
	}
	return (a);
}
/*
int main()
{
	char source[] = "Hellow World";
	char destination[8];
	int num_string[] = {1,2,3,4,5,6,7,8,9};

	ft_memmove(destination, source, sizeof(source));
	printf("%p\n",ft_memmove(destination, source, sizeof(source)));
	printf("%s\n",destination);

	ft_memmove(num_string + 1, num_string, 4*sizeof(int));
	printf("%p\n",ft_memmove(num_string + 1, num_string, 4*sizeof(int)));
	return (0);
}
*/
