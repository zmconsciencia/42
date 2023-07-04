#include "philo.h"

int main(int ac, char **av)
{
	if (ac == 6)
	{
		while (ac > 1)
		{
			ft_atoi(av[ac - 1]);
			ac--;
		}
	}
	else
	{
		ft_putstr_fd("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 2);
		return (1);
	}
}