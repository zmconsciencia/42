/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:49:03 by jabecass          #+#    #+#             */
/*   Updated: 2023/08/28 14:36:09 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickforks(t_philo *philo)
{
	if (philo->id < data()->nb_philo)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->dead_mutex);
		if (!philo->status)
			printf("%ld %d has taken a fork\n", gettime(), philo->id);
		pthread_mutex_unlock(&philo->dead_mutex);
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&philo->dead_mutex);
		if (!philo->status)
			printf("%ld %d has taken a fork\n", gettime(), philo->id);
		pthread_mutex_unlock(&philo->dead_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->dead_mutex);
		if (!philo->status)
			printf("%ld %d has taken a fork\n", gettime(), philo->id);
		pthread_mutex_unlock(&philo->dead_mutex);
	}
}

void	eat(t_philo *philo)
{
	pickforks(philo);
	pthread_mutex_lock(&philo->c_eat);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->c_eat);
	pthread_mutex_lock(&philo->dead_mutex);
	if (!philo->status)
		printf("%ld %d is eating\n", gettime(), philo->id);
	pthread_mutex_unlock(&philo->dead_mutex);
	pthread_mutex_lock(&philo->c_time);
	philo->time_to_die = gettime() + data()->time_to_die;
	pthread_mutex_unlock(&philo->c_time);
	my_usleep(data()->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(&philo->dead_mutex);
	if (!philo->status)
	{
		printf("%ld %d is sleeping\n", gettime(), philo->id);
		pthread_mutex_unlock(&philo->dead_mutex);
		my_usleep(data()->time_to_sleep);
	}
	else
		pthread_mutex_unlock(&philo->dead_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->c_time);
	philo->time_to_die = gettime() + data()->time_to_die;
	pthread_mutex_unlock(&philo->c_time);
	pthread_mutex_lock(&philo->dead_mutex);
	pthread_mutex_unlock(&philo->dead_mutex);
	if (philo->id % 2 != 0)
		my_usleep(200);
	pthread_mutex_lock(&philo->dead_mutex);
	while (!philo->status)
	{
		pthread_mutex_unlock(&philo->dead_mutex);
		pthread_mutex_lock(&philo->c_time);
		printf("%ld %d is thinking\n", gettime(), philo->id);
		pthread_mutex_unlock(&philo->c_time);
		eat(philo);
		pthread_mutex_lock(&philo->dead_mutex);
		usleep(50);
	}
	pthread_mutex_unlock(&philo->dead_mutex);
	return (NULL);
}

int	philo_to_thread(t_data *data)
{
	t_philo	*philo;
	int		reps;

	philo = data->head;
	reps = 0;
	while (philo != NULL)
	{
		pthread_create(&philo->t1, NULL, &routine, philo);
		philo = philo->next;
	}
	philo = data->head;
	usleep(50);
	while (!data->head->status)
		check_death(data, reps);
	while (philo != NULL)
	{
		pthread_join(philo->t1, NULL);
		philo = philo->next;
	}
	return (1);
}
