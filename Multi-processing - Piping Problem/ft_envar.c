
#include "pipex.h"

static char	*ft_envar_path(t_pipe *data)
{
	char	*location;
	int		a;
	int		len;

	a = 0;
	location = NULL;
	while (data->envar[a] != NULL && data->envar[a][0] != '\0')
	{
		location = ft_strnstr(data->envar[a], "PATH=", 5);
		if (location)
		{
			len = ft_strlen(location);
			location = ft_substr(location, 5, len);
			return (location);
		}
		a++;
	}
	return (location);
}

static char	**ft_final_path(char **location)
{
	int		a;
	char	*buffer;

	a = 0;
	while (location[a])
	{
		buffer = location[a];
		location[a] = ft_strjoin(location[a], "/");
		free(buffer);
		a++;
	}
	return (location);
}

static char	**ft_envar(t_pipe *data)
{
	char	*envp;
	char	**location;

	envp = ft_envar_path(data);
	if (envp == NULL)
		return (NULL);
	location = ft_split(envp, ':');
	free(envp);
	if (location == NULL)
		return (NULL);
	location = ft_final_path(location);
	if (location == NULL)
		return (NULL);
	return (location);
}

static char	*ft_command(char *cmd, char **where, t_pipe *data)
{
	int		a;
	char	*what;

	a = 0;
	what = NULL;
	while (where[a])
	{
		what = ft_strjoin(where[a], cmd);
		if (!what)
		{
			ft_free_array(where);
			ft_freedom(data, "Command Processing Error", 2);
		}
		if (access(what, F_OK | X_OK) == 0)
			return (what);
		free(what);
		a++;
	}
	return (NULL);
}

char	*ft_command_line(char *cmd, t_pipe *data)
{
	char	**where;
	char	*what;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	where = ft_envar(data);
	if (where == NULL)
		return (NULL);
	what = ft_command(cmd, where, data);
	if (what == NULL)
		ft_messaging("Invalid Command", 2);
	ft_free_array(where);
	return (what);
}
