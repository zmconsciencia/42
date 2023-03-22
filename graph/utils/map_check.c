/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:51:39 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/22 18:03:02 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	line_size(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	same_size(char **map)
{
	int	j;
	int	l;

	j = 0;
	l = line_count(map);
	while (j < l)
	{
		if (j == l - 1)
		{
			if (line_size(map[j]) == line_size(map[0]) - 1)
				return (1);
		}
		if (line_size(map[j]) != line_size(map[0]))
		{
			ft_putstr_fd("Not a rectangular map.\n", 2);
			return (0);
		}
		j++;
	}
	return (1);
}

int	allowed_char(char **map)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < line_count(map))
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'P' \
				&& map[j][i] != 'E' && map[j][i] != 'C' && map[j][i] != '\n')
			{
				ft_putstr_fd("Prohibited character found.\n", 2);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	repeating_chars(char **map, char c)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				k++;
			i++;
		}
		j++;
	}
	return (k);
}

int	parse_singles(char **map)
{
	int	p;
	int	e;
	int	c;

	p = repeating_chars(map, 'P');
	e = repeating_chars(map, 'E');
	c = repeating_chars(map, 'C');
	if (p != 1 || e != 1)
	{
		ft_putstr_fd("Invalid players or exits.\n", 2);
		return (0);
	}
	if (c <= 0)
	{
		ft_putstr_fd("Not enough collectibles.\n", 2);
		return (0);
	}
	return (1);
}
