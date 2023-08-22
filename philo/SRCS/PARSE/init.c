/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:25:30 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/26 14:49:45 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	alloc(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return ;
}

void	fork_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
}

t_philo	*init_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)ft_calloc(data->nb_philo, sizeof(t_philo));
	philo->id = id + 1;
	philo->time_to_die = data->time_to_die;
	philo->l_fork = &data->forks[id];
	philo->r_fork = &data->forks[(id + 1) % data->nb_philo];
	return (philo);
}

void	add_to_list(t_philo *philo)
{
	t_philo	*curr;

	curr = data()->head;
	if (!curr)
		data()->head = philo;
	else
	{
		while (curr->next != 0)
			curr = curr->next;
		curr->next = philo;
		if (!curr->next)
			data()->tail = philo;
	}
}

void	init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	alloc(data);
	fork_init(data);
	while (i < data->nb_philo)
	{
		philo = init_philo(i, data);
		add_to_list(philo);
		i++;
	}
}
