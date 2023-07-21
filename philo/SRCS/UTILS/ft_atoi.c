/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:38:21 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/21 15:40:37 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, int *e)
{
	size_t	i;
	size_t	sign;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		*e = 1;
	return (res * sign);
}
