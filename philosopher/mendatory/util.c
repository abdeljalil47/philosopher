#include "philo.h"

//function gettimeofday(); -> n milliseconds
// int gettimeofday(struct timeval *restrict tp, void *restrict tzp);
/*
**  struct timeval tv;
**  struct timezone tz;
**  
**  tv.tv_sec -> second since 1/1/1970
**  tv.tv_usec -> Microseconds
**  tz.tz_minuteswest -> Minutes
*/ 
static void    handle_error_time(int status, const char *flag)
{
    if (status == 0)
        return ;
    else if (status == EFAULT)
		error_exit("An argument address referenced invalid memory.\n");
	else if (status == EPERM && (ft_strcmp(flag, "TIME") == 0))
		error_exit("A user other than the super-user attempted to set the time.\n");
    else
        error_exit("An unexpected error occurred while handling the pthread.\n");
}
long    get_time()
{
    struct timeval tv;

    handle_error_time(gettimeofday(NULL, NULL), "TIME");
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
