/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:51:39 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/11 10:53:32 by jabecass         ###   ########.fr       */
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

int	allowed_char(char **map)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	i = 0;
	c = map[j][i];
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
				return (0);
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
		return (0);
	if (c <= 0)
		return (0);
	return (1);
}

int	map_check(char **map, char *name)
{
	if (!border_check(map) || !map_name(name) || !same_size(map) || !allowed_char(map) || !parse_singles(map))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
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

int	map_checker(char *map_path)
{
	int		fd;

	fd = check_map_name(map_path);
	if (fd >= 3)
	{
		(data())->map.map = load_map_zico(0, fd, 0);
		close(fd);
		data()->map.map_lines = line_count(data()->map.map);
		data()->map.map_elem = elem_count(data()->map.map[0]);
		if (check_rect(data()->map.map) && check_walls(data()->map.map) && \
			check_components(data()->map.map) && check_path(data()->map.map))
			return (1);
	}
	else
		handle_msg("Map not found!");
	return (0);
}