/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:20:46 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/23 16:19:15 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_matrixdup(char **map)
{
	char	**map2;
	int		i;
	int		j;

	i = 0;
	map2 = malloc(sizeof (char *) * (data()->map.map_lines + 1));
	while (i < data()->map.map_lines)
	{
		j = -1;
		map2[i] = malloc(sizeof (char) * data()->map.map_elem + 1);
		map2[i][data()->map.map_elem] = 0;
		while (++j < data()->map.map_elem)
			map2[i][j] = map[i][j];
		i++;
	}
	map2[data()->map.map_lines] = 0;
	return (map2);
}

void	f_fill(char **tab, t_point size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == '1' || (tab[row][col] != 'P' \
		&& tab[row][col] != '0' && \
			tab[row][col] != 'C' && tab[row][col] != 'E'))
		return ;
	tab[row][col] = '1';
	f_fill(tab, size, row -1, col);
	f_fill(tab, size, row +1, col);
	f_fill(tab, size, row, col - 1);
	f_fill(tab, size, row, col + 1);
}

char	**flood_fill(char **tab, t_point size, t_point begin)
{
	f_fill(tab, size, begin.y, begin.x);
	return (tab);
}

int	path_finder(char	**map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P' || map[j][i] == 'C' || map[j][i] == 'E')
			{
				ft_putstr_fd("Impossible path", 2);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}
