/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:58:31 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/22 18:00:10 by jabecass         ###   ########.fr       */
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

int	map_checker(char *pathname)
{
	int		fd;
	t_point	size;
	t_point	begin;
	char	**temp;

	fd = map_name(pathname);
	if (fd >= 3)
	{
		(data())->map.map = load_map_zico(0, fd, 0);
		close(fd);
		data()->map.map_lines = line_count(data()->map.map);
		data()->map.map_elem = elem_count(data()->map.map[0]);
		size.x = elem_count(data()->map.map[0]);
		size.y = line_count(data()->map.map);
		begin = findplayer((data())->map.map);
		temp = ft_matrixdup((data())->map.map);
		if (map_check(data()->map.map, pathname) && \
			path_finder(flood_fill(temp, size, begin)))
			return (1);
		free(temp);
	}
	else
		ft_putstr_fd("Invalid name or map not found.\n", 2);
	return (0);
}
