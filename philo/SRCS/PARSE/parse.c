/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:32:53 by jabecass          #+#    #+#             */
/*   Updated: 2023/08/25 19:56:35 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_limits(int n, int err)
{
	if (err == 1)
	{
		if (n <= 0 || n > 200)
			data()->err = 1;
	}
	else
	{
		if (n <= 0 || n > INT_MAX)
			data()->err = 1;
	}
	return (n);
}

int	parser(char **av)
{
	int	status;

	status = 0;
	if (av[1][0] == '1')
	{
		printf("%d 1 died\n", ft_atoi(av[2], &status));
		return (0);
	}
	(data())->nb_philo = set_limits(ft_atoi(av[1], &status), 1);
	(data())->time_to_die = set_limits(ft_atoi(av[2], &status), 0);
	(data())->time_to_eat = set_limits(ft_atoi(av[3], &status), 0);
	(data())->time_to_sleep = set_limits(ft_atoi(av[4], &status), 0);
	if (av[5])
		(data())->nb_eat = set_limits(ft_atoi(av[5], &status), 0);
	if (!data()->err && status)
		data()->err = 1;
	return (1);
}
