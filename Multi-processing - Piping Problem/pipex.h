
#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_pipex
{
	char	**argv;
	char	**envar;
	int		argc;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		count;
	int		id_kid;
	pid_t	*process;
	char	**cmd;
	char	*path;
	int		exit;
}			t_pipe;

/*****************************************************************************/
/*                                  FUNCTIONS                                */
/*****************************************************************************/

void		ft_pipex(t_pipe *data);
void		ft_pipe(t_pipe *data);

void		ft_execute(t_pipe *data);
void		ft_child_process(t_pipe *data);
void		ft_parent_process(t_pipe *data);

int			ft_non_null(char *str);
void		ft_close_fd(t_pipe *data);
void		ft_input_output(t_pipe *data);
void		ft_free_pipe(t_pipe *data);
void		ft_free_exit(t_pipe *data);

char		*ft_command_line(char *cmd, t_pipe *data);

void		ft_free_array(char **array);
void		ft_freedom(t_pipe *data, char *str, int id);
void		ft_messaging(char *str, int id);
void		ft_init_data(t_pipe *data);
t_pipe		*ft_init(int argc, char **argv, char **envar, t_pipe *data);

/*****************************************************************************/
/*                                  UTILS                                    */
/*****************************************************************************/

void		ft_putstr_fd(char *s, int fd, int ctrl);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t a);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnstr(const char *hay, const char *ndl, size_t a);
char		*ft_strdup(const char *str);
char		*ft_substr(const char *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		**ft_split(char const *s, char c);

/*****************************************************************************/
/*                                   GNL                                     */
/*****************************************************************************/

char		*get_next_line(int fd);
char		*ft_read_to_temp(char *temporary, int fd);
char		*ft_join_to_temp(char *temporary, char *read_result);
int			ft_str_len(char *str);
int			ft_new_line(char *read_result);
char		*ft_mem_alloc_fill(int nb, int size);
char		*ft_temp_to_extract(char *temporary);
char		*ft_clear_for_next(char *temporary);

#endif
