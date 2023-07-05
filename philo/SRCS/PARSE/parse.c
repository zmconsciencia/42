/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:32:53 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/05 14:53:58 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_handle(int n, int err)
{
	if (err == 1)
	{
		if (n <= 0 || n > 200)
		{
			ft_putendl_fd("Invalid argument.", 2);
			data()->err = 1;
			return ;
		}
	}
	else
	{
		if (n < 0)
		{
			ft_putendl_fd("Invalid argument.", 2);
			data()->err = 1;
			return ;
		}
	}
}

void	parser(char **av)
{
	if (!data()->err)
	{
		data()->nb_philo = ft_atoi(av[1]);
		data()->time_to_die = ft_atoi(av[2]);
		data()->time_to_eat = ft_atoi(av[3]);
		data()->time_to_sleep = ft_atoi(av[4]);
		data()->nb_eat = ft_atoi(av[5]); 
	}
}
