/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/05 14:54:38 by jabecass         ###   ########.fr       */
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
		while (++i < 6)
			err_handle(ft_atoi(av[i]), i);
		parser(av);
		print_program();
	}
	else
		print_error(0);
}
