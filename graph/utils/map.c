/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:47:20 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/23 19:12:55 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ceiling_check(char **map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (map[0] == NULL || map[0][0] != '1')
	{
		free_arr(map);
		ft_putstr_fd("Error.\n", 2);
		exit(1);
	}
	while (map[0][k])
		k++;
	while (map[0][i] && i < k - 1)
	{
		if (map[0][i] != '1' || map[0][k - 1] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	floor_check(char **map)
{
	int	i;
	int	k;
	int	n;

	n = line_count(map);
	i = 0;
	k = 0;
	while (map[n - 1][k])
		k++;
	while (map[n - 1][i] && i < k - 1)
	{
		if (map[n - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_check(char **map)
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
	int	a;
	int	b;
	int	c;
	int	res;

	a = ceiling_check(map);
	b = wall_check(map);
	c = floor_check(map);
	res = a + b + c;
	if (res != 3)
	{
		ft_putstr_fd("Error.\n", 2);
		return (0);
	}
	return (1);
}

int	map_name(char *pathname)
{
	int	i;
	int	fd;

	i = -1;
	fd = 0;
	while (pathname[++i])
		;
	if (pathname[i - 1] != 'r' || pathname[i - 2] != 'e' \
		|| pathname[i - 3] != 'b' || pathname[i - 4] != '.')
		return (0);
	else
		fd = open(pathname, O_RDONLY);
	return (fd);
}
