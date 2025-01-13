
#include "so_long.h"

static int	count_substr(char *str, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (str == NULL)
		return (0);
	while (str[a])
	{
		if (str[a] != c)
		{
			b++;
			while (str[a] && str[a] != c)
				a++;
		}
		else if (str[a] == c)
			a++;
	}
	return (b);
}

static void	ft_free(char **nstr, size_t d)
{
	while (d > 0)
	{
		d--;
		free(*(nstr + d));
	}
	free(nstr);
}

static int	word_len(char const *str, char c)
{
	int	h;

	h = 0;
	while (str[h] && str[h] != c)
		h++;
	return (h);
}

static char	**fill_newstr(char **nstr, int e, char const *str, char c)
{
	int	f;
	int	g;

	f = 0;
	g = 0;
	while (f < e)
	{
		while (str[g] && str[g] == c)
			g++;
		*(nstr + f) = ft_substr(str, g, word_len(&str[g], c));
		if (!*(nstr + f))
		{
			ft_free(nstr, f);
			return (0);
		}
		while (str[g] && str[g] != c)
			g++;
		f++;
	}
	*(nstr + f) = NULL;
	return (nstr);
}

char	**ft_split(char *s, char c)
{
	char	**newstr;
	int		h;

	if (!s)
		return (NULL);
	h = count_substr(s, c);
	newstr = (char **)malloc(sizeof(char *) * (h + 1));
	if (!newstr)
		return (NULL);
	newstr = fill_newstr(newstr, h, s, c);
	return (newstr);
}
