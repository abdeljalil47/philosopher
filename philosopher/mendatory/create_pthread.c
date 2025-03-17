#include "philo.h"

static void	handle_pthread_error(int status, const char *flag)
{
	int	flag_creat;
	int	flag_join;
	int	flag_detach;

	if (status == 0)
		return ;
	flag_creat = (ft_strcmp(flag, "CREAT") == 0);
	flag_join = (ft_strcmp(flag, "JOIN") == 0);
	flag_detach = (ft_strcmp(flag, "DETACH") == 0);
	if (status == EINVAL && flag_creat)
		error_exit("Invalid settings in attr.\n");
	if (status == EINVAL && (flag_join || flag_detach))
		error_exit("Invalid settings in attr.\n");
	else if (status == ESRCH)
		error_exit("No thread with the ID thread could be found.");
	else if (status == EAGAIN)
		error_exit("Insufficient resources to create another thread, or a system-imposed limit on the number of threads was encountered.\n");
	else if (status == EPERM)
		error_exit("No permission to set the scheduling policy and parameters specified in attr.\n");
	else if (status == EDEADLK)
		error_exit("A deadlock was detected (e.g., two threads tried to join with each other)\n");
	else
		error_exit("An unexpected error occurred while handling the pthread.\n");
}

void	pthread_handle(pthread_t *thread, void *(*start_routine)(void *), void *arg, const char *flag)
{
	if (ft_strcmp(flag, "CREAT") == 0)
		handle_pthread_error(pthread_create(thread, NULL, start_routine, arg), flag);
	else if (ft_strcmp(flag, "DETACH") == 0)
		handle_pthread_error(pthread_detach(*thread), flag);
	else if (ft_strcmp(flag, "JOIN") == 0)
		handle_pthread_error(pthread_join(*thread, NULL), flag);
	else
		error_exit("\tWrong flag for pthread handle\n");
}

static void	handle_mutex_error(int status, const char *flag)
{
	int	flag_lock;
	int	flag_unlock;
	int	flag_init;

	if (status == 0)
		return ;
	flag_lock = (ft_strcmp(flag, "LOCK") == 0);
	flag_unlock = (ft_strcmp(flag, "UNLOCK") == 0);
	flag_init = (ft_strcmp(flag, "INIT") == 0);
	if (status == EINVAL && (flag_lock || flag_unlock))
		error_exit("The value specified by mutex does not refer to an initialized mutex object.\n");
	else if (status == EINVAL && flag_init)
		error_exit("The value specified by mutex is invalid.\n");
	else if (status == EDEADLK)
		error_exit("The current thread already owns the mutex.\n");
	else if (status == EPERM)
		error_exit("The current thread does not own the mutex.\n");
	else if (status == EBUSY)
		error_exit("The mutex could not be acquired because it was already locked.\n");
	else
		error_exit("An unexpected error occurred while handling the mutex.\n");
}

void	mutex_handle(t_mtx *mutul, const char *flag)
{
	if (ft_strcmp(flag, "INIT") == 0)
		handle_error_mutex(pthread_mutex_init(mutul, NULL), flag);
	else if (ft_strcmp(flag, "LOCK") == 0)
		handle_error_mutex(pthread_mutex_lock(mutul), flag);
	else if (ft_strcmp(flag, "UNLOCK") == 0)
		handle_error_mutex(pthread_mutex_unlock(mutul), flag);
	else if (ft_strcmp(flag, "DESTROY") == 0)
		handle_error_mutex(pthread_mutex_destroy(mutul), flag);
	else
		error_exit("\tWrong flag for mutex handle\n");
}
