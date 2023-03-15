/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:47:20 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/14 18:09:20 by jabecass         ###   ########.fr       */
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
	int	k;

	n = count_lines(map);
	i = 0;
	j = 0;
	k = 0;
	while (map[0][k])
		k++;
	if (map[n])
	while (map[j])
	{
		if (j == 0)
		{
			while (map[j][i] && i < k - 1)
			{
				if (map[j][i] != '1' || map[j][k - 1] != '\n')
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
		if (map[j][0] != '1' || map[j][k - 2] != '1')
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
	{
		ft_putstr_fd("Map not closed\n", 2);
		return (0);
	}
	return (1);
}

int		map_name(char *pathname)
{
	int	i;
	int	fd;

	i = -1;
	fd = 0;
	while (pathname[++i])
		 ;
	if (pathname[i - 1] != 'r' || pathname[i - 2] != 'e' || pathname[i - 3] != 'b' || pathname[i - 4] != '.')
		return (0);
	else
		fd = open(pathname, O_RDONLY);
	return (fd);
}