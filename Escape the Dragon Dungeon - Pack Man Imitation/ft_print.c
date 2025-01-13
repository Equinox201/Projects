
#include "so_long.h"

void	print_int(int number, int *len)
{
	char	*decimal;

	decimal = "0123456789";
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
		(*len)++;
	}
	if (number > 9)
		print_int(number / 10, len);
	write(1, &decimal[number % 10], 1);
	(*len)++;
}

void	print_char(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	print_str(char *string, int *len)
{
	if (string == NULL)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (*string != '\0')
	{
		print_char(*string, len);
		string++;
	}
}

static void	identify_format(va_list content, char format, int *len)
{
	if (format == 'c')
		print_char(va_arg(content, int), len);
	else if (format == 's')
		print_str(va_arg(content, char *), len);
	else if (format == 'd')
		print_int(va_arg(content, int), len);
}

int	ft_printf(const char *input, ...)
{
	va_list		content;
	int			len;
	int			b;

	b = 0;
	len = 0;
	if (!input)
		return (0);
	va_start(content, input);
	while (input[b])
	{
		if (input[b] == '%')
		{
			b++;
			identify_format(content, input[b], &len);
		}
		else
		{
			write(1, &input[b], 1);
			len++;
		}
		b++;
	}
	va_end(content);
	return (len);
}
