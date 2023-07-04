/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/04 16:38:50 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	print_error(int n)
{
	if (n == 0)
	{
		ft_putstr_fd("Usage: ./philo [number_of_philo] [time_to_die]", 2);
		ft_putstr_fd(" [time_to_eat] [time_to_sleep]", 2);
		ft_putstr_fd(" [number_of_times_each_philosopher_must_eat]\n", 2);
	}
}

void	print_program(void)
{
	printf("nb_philo: %d\n", data()->nb_philo);
	printf("time_to_die: %d\n", data()->time_to_die);
	printf("time_to_eat: %d\n", data()->time_to_eat);
	printf("time_to_sleep: %d\n", data()->time_to_sleep);
	printf("nb_eat: %d\n", data()->nb_eat);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 6)
	{
		while (i++ < ac - 1)
		{
			if (i == 1)
				data()->nb_philo = ft_atoi(av[i]);
			else if (i == 2)
				data()->time_to_die = ft_atoi(av[i]);
			else if (i == 3)
				data()->time_to_eat = ft_atoi(av[i]);
			else if (i == 4)
				data()->time_to_sleep = ft_atoi(av[i]);
			else if (i == 5)
				data()->nb_eat = ft_atoi(av[i]); 
		}
		print_program();
	}
	else
		print_error(0);
}
