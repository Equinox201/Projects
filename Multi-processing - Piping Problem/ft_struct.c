
#include "pipex.h"

void	ft_free_array(char **array)
{
	int	a;

	a = 0;
	if (array[a] == NULL)
		free (array);
	while (array[a])
	{
		free(array[a]);
		a++;
	}
	free(array);
}

void	ft_freedom(t_pipe *data, char *str, int id)
{
	if (data)
	{
		ft_close_fd(data);
		if (data->pipe != NULL)
			free(data->pipe);
		if (data->process != NULL)
			free(data->process);
		if (data->cmd != NULL)
			ft_free_array(data->cmd);
		if (data->path != NULL)
			free(data->path);
		free(data);
	}
	ft_messaging(str, id);
	exit(0);
}

void	ft_messaging(char *str, int id)
{
	if (id == 0)
		return ;
	ft_putstr_fd("Pipex : ", 2, 0);
	if (id == 1)
		ft_putstr_fd("<file1> <cmd1> <cmd2> <file2>", 2, 1);
	else if (id == 2)
		ft_putstr_fd(str, 2, 1);
}

void	ft_init_data(t_pipe *data)
{
	data->argv = NULL;
	data->envar = NULL;
	data->pipe = NULL;
	data->process = NULL;
	data->cmd = NULL;
	data->path = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
	data->count = 0;
	data->id_kid = -1;
	data->exit = 0;
}

t_pipe	*ft_init(int argc, char **argv, char **envar, t_pipe *data)
{
	ft_init_data(data);
	data->argc = argc;
	data->envar = envar;
	data->argv = argv;
	ft_input_output(data);
	data->count = argc - 3;
	data->process = malloc(sizeof * data->process * data->count);
	if (!data->process)
		ft_freedom(data, strerror(errno), 2);
	data->pipe = malloc(sizeof * data->pipe * 2 * (data->count - 1));
	if (!data->pipe)
		ft_freedom(data, "Pipe Error", 2);
	ft_pipe(data);
	return (data);
}
