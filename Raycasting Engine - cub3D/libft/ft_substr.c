#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		a;
	char		*b;
	size_t		c;

	a = 0;
	c = 0;
	while (s[c])
		c ++;
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
/*
int main(void)
{
	char *result = ft_substr("0123456789", 9, 10);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	else
		printf("null\n");
}
*/
