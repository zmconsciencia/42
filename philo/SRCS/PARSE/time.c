/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:54:21 by jabecass          #+#    #+#             */
/*   Updated: 2023/08/24 16:25:06 by jabecass         ###   ########.fr       */
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

void	my_usleep(int time_ms)
{
	struct timeval	t;
	__uint64_t		start;
	__uint64_t		end;

	gettimeofday(&t, NULL);
	start = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	end = start + time_ms;
	while (start < end)
	{
		gettimeofday(&t, NULL);
		start = (t.tv_sec * 1000) + (t.tv_usec / 1000);
		usleep(100);
	}
}
