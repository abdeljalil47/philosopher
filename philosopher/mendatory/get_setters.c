#include "philo.h"

void    set_bool(t_mtx *mutex, long *dest, long value)
{
    mutex_handle(mutex, "LOCK");
    *dest = value;
    mutex_handle(mutex, "UNLOCK");
}

bool    get_bool(t_mtx *mutex, long *value)
{
    long    ret;

    mutex_handle(mutex, "LOCK");
    ret = *value;
    mutex_handle(mutex, "UNLOCK");
    return (ret);
}

long    get_long(t_mtx *mutex, long *value)
{
    long    ret;

    mutex_handle(mutex, "LOCK");
    ret = *value;
    mutex_handle(mutex, "UNLOCK");
    return (ret);
}

void    set_long(t_mtx *mutex, long *dest, long value)
{
    mutex_handle(mutex, "LOCK");
    *dest = value;
    mutex_handle(mutex, "UNLOCK");
}

bool    simulation_finished(t_table *table)
{
    return (get_bool(&table->table_mutex, &table->end_simulation));
}
