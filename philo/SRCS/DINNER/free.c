/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:45:36 by jabecass          #+#    #+#             */
/*   Updated: 2023/08/25 18:48:27 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{	
		data->head = philo->next;
		pthread_mutex_destroy(&philo->c_time);
		pthread_mutex_destroy(&philo->dead_mutex);
		pthread_mutex_destroy(philo->l_fork);
		pthread_mutex_destroy(philo->r_fork);
		free(philo); 
		philo = data->head;
	}
	pthread_mutex_destroy(data->forks);
	free(data->forks);
}