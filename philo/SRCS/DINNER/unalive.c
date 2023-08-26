/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:51:14 by jabecass          #+#    #+#             */
/*   Updated: 2023/08/26 18:54:46 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
}

void	check_death(t_data *data)
{
	int		reps;
	t_philo	*philo;

	philo = data->head;
	reps = 0;
	while (philo != NULL)
	{
		pthread_mutex_lock(&philo->c_time);
		if (philo->time_to_die && philo->time_to_die < gettime())
		{
			unalive_philo(data);
			printf("%ld %d died\n", gettime(), philo->id);
			pthread_mutex_unlock(&philo->c_time);
			return ;
		}
		pthread_mutex_unlock(&philo->c_time);
		pthread_mutex_lock(&philo->c_eat);
		if (data->nb_eat)
			if ((philo->eat_count == data->nb_eat))
				reps++;
		pthread_mutex_unlock(&philo->c_eat);
		philo = philo->next;
	}
	if (reps == data->nb_philo)
		unalive_philo(data);
}
