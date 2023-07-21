/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/21 18:25:45 by jabecass         ###   ########.fr       */
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
	if (data()->nb_eat)
		printf("nb_eat: %d\n", data()->nb_eat);
}

void	*routine(void *a)
{
	(void)a;
	printf("I'm philo number: %d and I have %d time to eat.\n", data()->philos->id, data()->time_to_eat);
	return (0);
}

int	philo_to_thread(void)
{
	int	i;

	i = -1;
	data()->tid = malloc(sizeof(pthread_t) * data()->nb_philo);
	if (!data()->tid)
		return (0);
	data()->philos = malloc(sizeof(t_philo) * data()->nb_philo);
	if (!data()->philos)
		return (0);
	while (++i < data()->nb_philo)
	{
		data()->philos->id = i;
		if (pthread_create(&data()->tid[i], NULL, &routine, NULL))
			return (1);
		usleep(1);
	}
	i = -1;
	while (++i < data()->nb_philo)
	{
		if (pthread_join(data()->tid[i], NULL))
			return (2);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5)
	{
		parser(av);
		philo_to_thread();
	}
	else if (ac == 6)
	{
		parser(av);
		philo_to_thread();
	}
	else
		print_error(0);
}
