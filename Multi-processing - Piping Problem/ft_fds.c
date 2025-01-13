
#include "pipex.h"

void	ft_input_output(t_pipe *data)
{
	data->fd_in = open(data->argv[1], O_RDONLY, 644);
	if (data->fd_in == -1)
	{
		ft_messaging(strerror(errno), 2);
		data->fd_in = open("/dev/null", O_RDONLY, 644);
	}
	data->fd_out = open(data->argv[data->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
		ft_messaging(strerror(errno), 2);
}

void	ft_close_fd(t_pipe *data)
{
	int	a;

	a = 0;
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	while (a < (data->count - 1) * 2)
	{
		close(data->pipe[a]);
		a++;
	}
}

void	ft_free_pipe(t_pipe *data)
{
	int	a;

	a = 0;
	if (data->pipe)
	{
		while (a < (data->count - 1) * 2)
		{
			if (data->pipe[a] != -1)
			{
				close(data->pipe[a]);
				data->pipe[a] = -1;
			}
			a++;
		}
		free(data->pipe);
		data->pipe = NULL;
	}
}

void	ft_free_exit(t_pipe *data)
{
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	if (data->pipe != NULL)
		free(data->pipe);
	free(data);
}
