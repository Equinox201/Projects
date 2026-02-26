#include "cub3D_bonus.h"

int	ft_extension_check(char *file)
{
	int	len;

	if (!file)
		return (ft_error_msg("Error", "No file specified", 2));
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (ft_error_msg("Error", "Invalid file extension", 2));
	return (PASS);
}

int	ft_validate_arguments(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error_msg("Error", "Invalid number of arguments", 2));
	if (ft_extension_check(argv[1]) != PASS)
		return (FAIL);
	return (PASS);
}
