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
	printf("%ld philo %d takes fork.\n", gettime(), philo->id);
	pthread_mutex_lock(philo->l_fork);
	printf("%ld philo %d takes fork.\n", gettime(), philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(400);
	pthread_mutex_lock(&philo->c_time);
	philo->time_to_die = gettime() + data()->time_to_die;
	pthread_mutex_unlock(&philo->c_time);
	while (!philo->status)
	{
		pickforks(philo);
		printf("%ld philo %d is eating.\n", gettime(), philo->id);
		pthread_mutex_lock(&philo->c_time);
		philo->time_to_die = gettime() + data()->time_to_die;
		pthread_mutex_unlock(&philo->c_time);
		usleep(data()->time_to_eat * 1000);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		printf("%ld philo %d is sleeping.\n", gettime(), philo->id);
		usleep(data()->time_to_sleep * 1000);
		printf("%ld philo %d is thinking.\n", gettime(), philo->id);
	}
	return (NULL);
}

void	unalive_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{
		pthread_mutex_lock(&philo->dead_mutex);
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{
		philo->status = 1;
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{
		pthread_mutex_unlock(&philo->dead_mutex);
		philo = philo->next;
	}
	exit(0);
}

void	check_death(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{
		pthread_mutex_lock(&philo->c_time);
		if (philo->time_to_die && philo->time_to_die < gettime())
		{
			// unalive_philo(data);
			printf("%ld philo %d died, with time to die -> %ld\n", gettime(), philo->id, philo->time_to_die);
			pthread_mutex_unlock(&philo->c_time);
			exit(1);
		}
		pthread_mutex_unlock(&philo->c_time);
		philo = philo->next;
	}
}

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
	usleep(200);
	while (!data->head->status)
		check_death(data);
	while (philo != NULL)
	{
		pthread_join(philo->t1, NULL);
		philo = philo->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo *philo;

	philo = data()->head;
	data()->start_time = gettime();
	if (ac == 5 || ac == 6)
	{
		parser(av);
		init(data());
		while (philo != NULL)
		{
			pthread_mutex_init(&philo->c_time, NULL);
			pthread_mutex_init(&philo->dead_mutex, NULL);
			philo = philo->next;
		}
		philo_to_thread(data());
		printf("SUCCESS.\n");
	}
	else
		printf("ERROR.\n");
}
