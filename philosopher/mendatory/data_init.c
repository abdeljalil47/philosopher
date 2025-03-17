#include "philo.h"

void    assign_forks(t_philo *philo, t_fork *forks, int position)
{
    int philo_nb;

    philo_nb = philo->table->philo_nbr;
    philo->first_fork = &forks[position];
    philo->second_fork = &forks[(position + 1) % philo_nb];
    if ((philo_nb % 2) == 0)
    {
        philo->first_fork = &forks[position];
        philo->second_fork = &forks[(position + 1) % philo_nb];
    }
}

void    philo_init(t_table *table)
{
    int i;
    t_philo *philo;

    i = 0;
    while (i < table->philo_nbr)
    {
        philo = table->philos + i;
        philo->id = i + 1;
        philo->full = false;
        philo->meals_counter = 0;
        philo->table = table;
        assign_forks(philo, table->forks, i);
        i++;
    }
    
}


void    data_init(t_table *table)
{
    int i;

    i = 0;
    table->end_simulation = false;
    table->all_thread_ready = false;
    table->philos = safe_allocate(sizeof(t_philo) * table->philo_nbr);
    mutex_handle(&table->table_mutex, "INIT");
    table->forks = safe_allocate(sizeof(t_fork) * table->philo_nbr);
    while (i < table->philo_nbr)
    {
        mutex_handle(&table->forks[i].fork, "INIT");
        table->forks[i].fork_id = i;
        i++;
    }
    philo_init(table);
}
