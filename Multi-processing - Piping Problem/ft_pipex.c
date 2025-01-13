
#include "pipex.h"

void	ft_pipe(t_pipe *data)
{
	int	a;

	a = 0;
	while (a < data->count - 1)
	{
		if (pipe(data->pipe + 2 * a) == -1)
			ft_freedom(data, "Pipe Error", 2);
		a++;
	}
}

void	ft_pipex(t_pipe *data)
{
	if (pipe(data->pipe) == -1)
		ft_freedom(data, strerror(errno), 2);
	data->id_kid = 0;
	while (data->id_kid < data->count)
	{
		if (ft_non_null(data->argv[data->id_kid + 2]) == 1)
			return (ft_messaging("", 1), free(data->process));
		data->cmd = ft_split(data->argv[data->id_kid + 2], ' ');
		if (!data->cmd)
			ft_freedom(data, "Command Split Error", 2);
		data->path = ft_command_line(data->cmd[0], data);
		data->process[data->id_kid] = fork();
		if (data->process[data->id_kid] == -1)
			ft_freedom(data, strerror(errno), 2);
		else if (data->process[data->id_kid] == 0)
			ft_child_process(data);
		ft_free_array(data->cmd);
		free(data->path);
		data->id_kid++;
	}
	ft_parent_process(data);
}

int	main(int argc, char **argv, char **envar)
{
	t_pipe	*data;
	int		exit;

	exit = 0;
	data = malloc(sizeof(t_pipe));
	if (argc != 5)
	{
		ft_messaging("", 1);
		free (data);
		return (1);
	}
	if (!envar || envar[0][0] == '\0')
		ft_freedom(data, "Environmental variables error", 2);
	data = ft_init(argc, argv, envar, data);
	ft_pipex(data);
	exit = data->exit;
	ft_free_exit(data);
	return (exit);
}
