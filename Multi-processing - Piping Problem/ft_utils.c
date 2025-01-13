
#include "pipex.h"

void	ft_putstr_fd(char *s, int fd, int ctrl)
{
	size_t	a;

	a = 0;
	if (!s)
		return ;
	while (s[a])
	{
		write(fd, &s[a], 1);
		a++;
	}
	if (ctrl == 1)
		write(fd, "\n", 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	b;

	b = 0;
	if (!str)
		return (b);
	while (str[b])
		b++;
	return (b);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	d;
	char	*c;

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

char	*ft_strnstr(const char *hay, const char *ndl, size_t a)
{
	size_t	b;
	size_t	c;

	b = 0;
	c = 0;
	while (ndl[c])
		c++;
	if (c == 0 || hay == ndl)
		return ((char *)hay);
	while (hay[b] && b < a)
	{
		c = 0;
		while (hay[b + c] == ndl[c] && (b + c) < a)
		{
			if (ndl[c + 1] == '\0')
				return ((char *)hay + b);
			c++;
		}
		b++;
	}
	return (0);
}
