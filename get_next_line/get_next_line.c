/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:50:20 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/19 16:46:01 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		printf("before: %s\n", stack);
		c = ft_strjoin(c, stack);
		printf("join: %s\n", c);
		printf("update: %s\n", stack);
		if (clearstack(stack) != -1)
			break ;
		printf("-----------\n");
	}
	return (c);
}

int main(void)
{
	int fd = open("res", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
}