
#include "pipex.h"

void	ft_execute(t_pipe *data)
{
	if (data->cmd == NULL || data->path == NULL)
		ft_freedom(data, "", 0);
	if (execve(data->path, data->cmd, data->envar) == -1)
		ft_freedom(data, strerror(errno), 2);
}

static void	ft_dup2_redirect(t_pipe *data, int ctrl)
{
	if (ctrl == 1)
	{
		if (dup2(data->fd_in, STDIN_FILENO) == -1)
			ft_freedom(data, "Input Redirect Fail", 2);
		if (dup2(data->pipe[1], STDOUT_FILENO) == -1)
			ft_freedom(data, "Output Redirect Fail", 2);
	}
	else if (ctrl == 2)
	{
		if (dup2(data->pipe[2 * data->id_kid - 2], STDIN_FILENO) == -1)
			ft_freedom(data, "Input Redirect Fail", 2);
		if (dup2(data->fd_out, STDOUT_FILENO) == -1)
			ft_freedom(data, "Output Redirect Fail", 2);
	}
	else if (ctrl == 3)
	{
		if (dup2(data->pipe[2 * (data->id_kid - 2)], STDIN_FILENO) == -1)
			ft_freedom(data, "Input Redirect Fail", 2);
		if (dup2(data->pipe[2 * (data->id_kid + 1)], STDOUT_FILENO) == -1)
			ft_freedom(data, "Output Redirect Fail", 2);
	}
}

void	ft_child_process(t_pipe *data)
{
	if (data->id_kid == 0)
		ft_dup2_redirect(data, 1);
	else if (data->id_kid == data->count - 1)
		ft_dup2_redirect(data, 2);
	else
		ft_dup2_redirect(data, 3);
	ft_close_fd(data);
	ft_execute(data);
	exit(1);
}

void	ft_parent_process(t_pipe *data)
{
	pid_t	wait;
	int		track;
	int		children;
	int		a;

	ft_close_fd(data);
	children = data->count;
	a = 0;
	while (children > 0)
	{
		wait = waitpid(-1, &track, 0);
		if (wait == -1)
		{
			ft_freedom(data, "Waitpid Error", 1);
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(track))
			a = WEXITSTATUS(track);
		children--;
	}
	ft_free_pipe(data);
	free(data->process);
	data->exit = a;
}
