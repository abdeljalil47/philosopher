#include "philo.h"

/*
	* ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat
*/ 

int main(int ac, char *av[])
{
	t_table table;

	if (ac == 5 || ac == 6)
	{
		//1)parcint
	    ft_parc_input(&table, av, ac);
		//2)data_init
		data_init(&table);
		//3)dinner_start
		start_dinner(&table);
		//4)clean no leaks
		clean_all(&table);
	}
	else
	{
		error_exit("\nError: must be\n");
		error_exit("\tnumber_of_philosophers ");
		error_exit("time_to_die time_to_eat time_to_sleep ");
		error_exit("[number_of_times_each_philosopher_must_eat\n\n");
	}
	return 0;
}
