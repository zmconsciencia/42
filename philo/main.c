/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/24 16:25:44 by jabecass         ###   ########.fr       */
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

int	gettime(void)
{
	struct timeval	tv;
	int				time;

	time = 0;
	if (!gettimeofday(&tv, NULL))
	{
		time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		time = time - data()->start_time;
	}
	return (time);
}

void	*routine(void *philos_pointer)
{
	t_philo			*philo;

	philo = (t_philo *) philos_pointer;
	if (philo->id == 0 || philo->id % 2 == 0)
	{
		printf("%dms EVEN is eating ID:%d\n", gettime(), philo->id);
		philo->eating = 1;
	}
	else
		printf("%dms ODD is sleeping ID:%d\n", gettime(), philo->id);
	philo->eating = 0;
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
		if (pthread_create(&data()->tid[i], NULL, &routine, data()->philos))
			return (1);
		if (data()->philos->eating)
			usleep(data()->time_to_eat * 1000);
		else
			usleep(data()->time_to_sleep * 1000);
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
	data()->start_time = gettime();
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
