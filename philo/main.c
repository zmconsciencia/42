/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/08/28 11:43:21 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = data()->head;
	data()->start_time = gettime();
	if (ac == 5 || ac == 6)
	{
		if (parser(av))
		{
			if (!data()->err)
			{
				init(data());
				while (philo != NULL)
				{
					pthread_mutex_init(&philo->c_time, NULL);
					pthread_mutex_init(&philo->dead_mutex, NULL);
					philo = philo->next;
				}
				philo_to_thread(data());
			}
			else
				printf("INVALID ARGUMENT.\n");
		}
	}
	else
		printf("ERROR.\n");
}
