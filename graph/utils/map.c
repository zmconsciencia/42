/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:47:20 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/10 15:47:34 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (*map != NULL)
	{
		i++;
		map++;
	}
	return (i);
}

int	ceiling_floor_check(char **map)
{
	int	n;
	int i;
	int	j;

	n = count_lines(map);
	i = 0;
	j = 0;
	while (map[j])
	{
		if (j == 0 || j == n - 1)
		{
			while (map[j][i])
			{
				if (map[j][i] != '1')
					return (0);
				i++;
			}
		}
		j++;
	}
	return (1);
}

int wall_check(char **map)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (map[0][k])
		k++;
	while (map[j])
	{
		if (map[j][0] != '1' || map[j][k - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	border_check(char **map)
{
	int a;
	int b;
	int res;

	a = ceiling_floor_check(map);
	b = wall_check(map);
	res = a + b;
	if (res != 2)
		return (0);
	return (1);
}

int		map_name(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
		 ;
	if (map[i - 1] != 'r' && map[i - 2] != 'e' && map[i - 3] != 'b')
		return (0);
	return (1);
}