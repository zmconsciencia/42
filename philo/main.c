/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/26 14:54:39 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	pickforks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf("%d philo %d takes fork.\n", gettime(), philo->id);
	pthread_mutex_lock(philo->l_fork);
	printf("%d philo %d takes fork.\n", gettime(), philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pickforks(philo);
		philo->status = 1;
		printf("%d philo %d is eating.\n", gettime(), philo->id);
		usleep(data()->time_to_eat * 1000);
		philo->status = 0;
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		printf("%d philo %d is sleeping.\n", gettime(), philo->id);
		usleep(data()->time_to_sleep * 1000);
		printf("%d philo %d is thinking.\n", gettime(), philo->id);
	}
	return (NULL);
}

void	unalive_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{
		pthread_mutex_lock(data->dead_mutex);
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{
		data->dead = 1;
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{
		pthread_mutex_unlock(data->dead_mutex);
		philo = philo->next;
	}
}

// void	check_death(t_data *data)
// {

// }

int	philo_to_thread(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{
		pthread_create(&philo->t1, NULL, &routine, philo);
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{
		pthread_join(philo->t1, NULL);
		philo = philo->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	data()->start_time = gettime();
	if (ac == 5 || ac == 6)
	{
		parser(av);
		init(data());
		philo_to_thread(data());
		printf("SUCCESS.\n");
	}
	else
		printf("ERROR.\n");
}
