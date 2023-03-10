/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:51:39 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/10 16:31:14 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int same_size(char **map)
{
	int j;
	int	i;
	int k;

	j = 0;
	i = 0;
	while (map[0][i])
		i++;
	while (map[j])
	{
		k = 0;
		while (map[j][k])
			k++;
		if (k != i)
			return (0);
		j++;
	}
	return (1);
}

int	map_check(char **map, char *name)
{
	if (!border_check(map) || !map_name(name) || !same_size(map))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}