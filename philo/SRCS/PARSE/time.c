/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:54:21 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/26 14:54:33 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	gettime(void)
{
	struct timeval	tv;
	time_t			time;

	time = 0;
	if (!gettimeofday(&tv, NULL))
	{
		time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		time = time - data()->start_time;
	}
	return (time);
}
