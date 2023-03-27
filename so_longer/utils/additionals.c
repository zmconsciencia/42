/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:55:58 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/22 17:59:50 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_putchar_fd(char c, int fd)
{
	if (!write (fd, &c, 1))
		exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	line_count(char **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

int	elem_count(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	return (i);
}
