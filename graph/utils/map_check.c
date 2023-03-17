/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:51:39 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/17 15:59:54 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	line_size(char *map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}

int same_size(char **map)
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
				return(1);
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
	while (j < count_lines(map))
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

void	findP(char	**map)
{
	int		i;
	int		j;

	j = 0;
	if (parse_singles(map))
	{
		while (map[j])
		{
			i = 0;
			while (map[j][i])
			{
				if (map[j][i] == 'P')
				{
					(data())->player.x = i*32;
					(data())->player.y = j*32;
				}
				i++;
			}
			j++;
		}
	}
}

t_point	findPlayer(char	**map)
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

int	map_check(char **map, char *pathname)
{
	if (!border_check(map) || !same_size(map) \
		 || !allowed_char(map) || !parse_singles(map) || !map_name(pathname))
		return (0);
	return (1);
}

int	line_count(char **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

char	**load_map_zico(char **map, int fd, int line_count)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		map = load_map_zico(map, fd, line_count + 1);
	else
		map = malloc(sizeof (char *) * (line_count + 1));
	if (map)
		map[line_count] = line;
	return (map);
}

int	map_checker(char *pathname)
{
	int		fd;

	fd = map_name(pathname);
	if (fd >= 3)
	{
		t_point	size;
		t_point begin;
		char	**temp;
		
		(data())->map.map = load_map_zico(0, fd, 0);
		close(fd);
		data()->map.map_lines = line_count(data()->map.map);
		data()->map.map_elem = elem_count(data()->map.map[0]);
		size.x = elem_count(data()->map.map[0]);
		size.y = line_count(data()->map.map);
		begin = findPlayer((data())->map.map);
		temp = ft_matrixdup((data())->map.map);
		if (map_check(data()->map.map, pathname) && \
			pathFinder(flood_fill(temp, size, begin)))
			return (1);
		free(temp);
	}
	else
		ft_putstr_fd("Invalid name or map not found.\n", 2);
	return (0);
}

int	elem_count(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	return (i);
}