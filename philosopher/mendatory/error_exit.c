#include "philo.h"

void    error_exit(char *str)
{
    write(2, RED, 5);
    if (str)
        write(2, str, ft_strlen(str));
    write(2, RESET, 4);
    exit(EXIT_FAILURE);
}

void    valid_exit(char *str)
{
    write(2, GREEN, 5);
    if (str)
        write(2, str, ft_strlen(str));
    write(2, RESET, 4);
    return ;
}