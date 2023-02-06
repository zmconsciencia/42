/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:57:38 by jabecass          #+#    #+#             */
/*   Updated: 2022/12/14 16:06:51 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*c;
	static char	stack[1024][BUFFER_SIZE + 1];
	size_t		i;

	i = -1;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (stack[fd][++i])
			stack[fd][i] = 0;
		return (NULL);
	}
	c = NULL;
	while (*stack[fd] || read(fd, stack[fd], BUFFER_SIZE) > 0)
	{
		c = ft_strjoin(c, stack[fd]);
		if (clearstack(stack[fd]) >= 0)
			break ;
	}
	return (c);
}
