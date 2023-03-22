/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:01:08 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/22 18:34:00 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	findp(char	**map)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (parse_singles(map))
	{
		while (map[j])
		{
			i = 0;
			while (map[j][i])
			{
				if (map[j][i] == 'P')
				{
					(data())->player.x = i * 32;
					(data())->player.y = j * 32;
					data()->player.i = i;
					data()->player.j = j;
				}
				i++;
			}
			j++;
		}
	}
}

t_point	findplayer(char	**map)
{
	int		i;
	int		j;
	t_point	point;

	j = 0;
	point.x = 0;
	point.y = 0;
	if (parse_singles(map))
	{
		while (map[j])
		{
			i = 0;
			while (map[j][i])
			{
				if (map[j][i] == 'P')
				{
					point.x = i;
					point.y = j;
				}
				i++;
			}
			j++;
		}
	}
	return (point);
}

void	find_objective(char **map)
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
			if (map[j][i] == 'C')
				k++;
			i++;
		}
		j++;
	}
	data()->map.c = k;
}
