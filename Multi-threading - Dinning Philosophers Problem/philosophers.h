
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*****************************************************************************/
/*                                    STRUCT                                 */
/*****************************************************************************/

struct	s_data;

typedef struct s_mutex
{
	int				f_id;
	pthread_mutex_t	fork;
}					t_mutex;

typedef struct s_philo
{
	int				phl_id;
	pthread_t		id;
	int				flag;
	long			e_cnt;
	long			e_last;
	pthread_mutex_t	p_lok;
	t_mutex			*r_frk;
	t_mutex			*l_frk;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo;
	long			d_time;
	long			s_time;
	long			e_time;
	long			start;
	int				eaten;
	int				limit;
	int				stop;
	pthread_t		monitor;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	eating;
	t_philo			*filo;
	t_mutex			*forks;
}					t_data;

/*****************************************************************************/
/*                                  FUNCTIONS                                */
/*****************************************************************************/

long				ft_atol(const char *str);
int					ft_isdigit(char a, char b);
int					ft_strlen(const char *str);
void				ft_print_state(t_philo *p, int id);

int					ft_messaging(int id, int y);
int					ft_freedom(t_data *data, int x, int y);
void				ft_join_threads(t_data *data);

int					ft_validation(const char *str);
void				ft_init_forks(t_data *temp);
void				ft_init_philos(t_data *temp);
int					ft_init_data(t_data *t, int argc, char **argv);
t_data				*ft_parsing(int argc, char **argv);

int					ft_everyone_ate(t_data *d);
int					ft_check_all_ate(t_data *d, int all_ate);
void				*ft_checker(void *arg);
int					ft_check_philos(t_data *d);
void				ft_single_phil(t_data *d);

void				ft_philo_eat(t_philo *p);
void				ft_philo_sleep(t_philo *p);
void				*ft_philo_life(void *arg);
int					ft_operations(t_data *d);
int					ft_check_and_break(t_philo *p);

void				ft_sleeper(long s_time);
long				ft_get_time(void);

#endif
