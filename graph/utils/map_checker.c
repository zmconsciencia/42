/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:58:31 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/23 19:12:37 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	map_check(char **map, char *pathname)
{
	if (!border_check(map) || !same_size(map) \
		|| !allowed_char(map) || !parse_singles(map) || !map_name(pathname))
		return (0);
	return (1);
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

int	map_checker(char *pn)
{
	int		fd;
	t_point	s;
	t_point	b;
	char	**t;

	fd = map_name(pn);
	if (fd >= 3)
	{
		(data())->map.map = load_map_zico(0, fd, 0);
		close(fd);
		data()->map.map_lines = line_count(data()->map.map);
		data()->map.map_elem = elem_count(data()->map.map[0]);
		s.x = elem_count(data()->map.map[0]);
		s.y = line_count(data()->map.map);
		b = findplayer((data())->map.map);
		if (!map_check(data()->map.map, pn))
			return (0);
		t = ft_matrixdup((data())->map.map);
		if (path_finder(flood_fill(t, s, b)) && free_arr(t))
			return (1);
		free_arr(t);
	}
	else
		ft_putstr_fd("Error.\n", 2);
	return (0);
}
