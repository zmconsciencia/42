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
