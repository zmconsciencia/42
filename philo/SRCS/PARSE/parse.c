/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:32:53 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/21 15:41:36 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_limits(int n, int err)
{
	if (err == 1)
	{
		if (n <= 0 || n > 200)
			data()->err = 1;
	}
	else
	{
		if (n < 0)
			data()->err = 1;
	}
}

void	err_handle(int status)
{
	if (data()->err || status)
	{
		printf("INVALID ARGUMENT\n");
		exit(EXIT_FAILURE);
	}
}

void	parser(char **av)
{
	int	status;

	status = 0;
	if (!data()->err)
	{
		(data())->nb_philo = ft_atoi(av[1], &status);
		(data())->time_to_die = ft_atoi(av[2], &status);
		(data())->time_to_eat = ft_atoi(av[3], &status);
		(data())->time_to_sleep = ft_atoi(av[4], &status);
		if (av[5])
			(data())->nb_eat = ft_atoi(av[5], &status); 
	}
	err_handle(status);
}
