#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/time.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

// mutex: init destroy lock unlock
/*
** pthread: create join detach
** Case Error :
CREAT-> EPERM | EAGAIN
JOIN -> EDEADLK | ESRCH
DETACH->ESRCH
*/

typedef pthread_mutex_t	t_mtx;
typedef struct table t_table;

typedef struct fork
{
	t_mtx	fork;
	int		fork_id;
}		t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
}		t_philo;

typedef struct table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	bool	all_thread_ready;
	t_mtx	table_mutex;
	t_fork	*forks;
	t_philo	*philos;
}		t_table;


void	error_exit(char *str);
int		ft_parc_input(t_table *table, char **av, int ac);
void	*safe_allocate(size_t data);
long	ft_atoi(char *str);
int		ft_strcmp(const char *s1, char *s2);
size_t	ft_strlen(const char *str);
long    get_time();


void	mutex_handle(t_mtx *mutul, const char *flag);
void	pthread_handle(pthread_t *thread, void *(*start_routine)(void *), void *arg, const char *flag);


void    data_init(t_table *table);

void    set_bool(t_mtx *mutex, long *dest, long value);
bool    get_bool(t_mtx *mutex, long *value);
long    get_long(t_mtx *mutex, long *value);
void    set_long(t_mtx *mutex, long *dest, long value);
bool    simulation_finished(t_table *table);
//*** testing only
void	valid_exit(char *str);
// end testing

#endif