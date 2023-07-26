/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/26 14:48:09 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
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

void	pickforks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf("%d philo %d takes fork.\n", gettime(), philo->id);
	pthread_mutex_lock(philo->l_fork);
	printf("%d philo %d takes fork.\n", gettime(), philo->id);
}

// void	*routine(void *philos_pointer)
// {
// 	int				i;
// 	t_philo			*philo;

// 	philo = (t_philo *) philos_pointer;
// 	i = -1;
// 	while (++i < data()->nb_eat)
// 	{
// 		pickforks(philo);
// 		usleep(data()->time_to_eat * 1000);
// 		pthread_mutex_unlock(philo->l_fork);
// 		pthread_mutex_unlock(philo->r_fork);
// 		usleep(data()->time_to_sleep * 1000);
// 		printf("%d philo %d is thinking.\n", gettime(), philo->id);
// 	}
// 	return (0);
// }

int	philo_to_thread(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{
		printf("%d, %d, L: %p, R: %p\n", philo->id, philo->time_to_die, philo->l_fork, philo->r_fork);
		philo = philo->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	data()->start_time = gettime();
	if (ac == 5)
	{
		parser(av);
		philo_to_thread(data());
	}
	else if (ac == 6)
	{
		parser(av);
		init(data());
		philo_to_thread(data());
	}
	else
		printf("ERROR.\n");
}
