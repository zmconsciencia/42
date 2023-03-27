/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:50:20 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/13 14:18:37 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_next_line(int fd)
{
	char		*c;
	static char	stack[BUFFER_SIZE + 1];
	size_t		i;

	i = -1;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (stack[++i])
			stack[i] = 0;
		return (NULL);
	}
	c = NULL;
	while (*stack || read(fd, stack, BUFFER_SIZE) > 0)
	{
		c = ft_strjoin(c, stack);
		if (clearstack(stack) != -1)
			break ;
	}
	return (c);
}
