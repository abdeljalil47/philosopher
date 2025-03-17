#include "philo.h"

static int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int ft_sign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int check_argument(char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (av[j])
	{
		i = 0;
		if (av[j][i] == '\0')
			return (0);
		while (av[j][i] && av[j][i] == 32)
			i++;
		while (av[j][i])
		{
			if (!(ft_sign(av[j][i]) || ft_isdigit(av[j][i])))
				return (0);
			else if (ft_sign(av[j][i]) && !ft_isdigit(av[j][i + 1]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

static int check_parcinte(char **s)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i] && s[j][i] == 32)
			i++;
		if (s[j][i] == '-' || s[j][i] == '+')
			i++;
		while (s[j][i])
		{
			if (s[j][i] == 32)
				i++;
			if (!ft_isdigit(s[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int ft_parc_input(t_table *table, char **av, int ac)
{
	if (!check_argument(av + 1) || !check_parcinte(av + 1))
		return 0;
	table->philo_nbr = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]) * 1e3; // convert then to usec for function sleep()
	table->time_to_eat = ft_atoi(av[3]) * 1e3;
	table->time_to_sleep = ft_atoi(av[4]) * 1e3;
	if (table->time_to_die < 6e4 || table->time_to_eat < 6e4 || table->time_to_sleep < 6e4)// what is timestamp
		error_exit("Use timestamps major than 60ms");
	if (av[5])
		table->num_limit_meals = ft_atoi(av[5]);
	else
		table->num_limit_meals = -1;
	return 1;
}
