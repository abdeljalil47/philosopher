#include "philo.h"

void    *dinner_simuation(void *data)
{
    t_philo *philo;

    philo = (t_philo*)data;
    wait_all_threads(philo->table);
    return NULL;
}

