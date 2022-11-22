/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:54:28 by jabecass          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:33 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	clearstack(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == '\n')
		{
			stack[i] = 0;
			break ;
		}
		i++;
		stack[i] = 0;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char		*c;
	static char	stack[BUFFER_SIZE + 1];

	c = NULL;
	while (read(fd, stack, BUFFER_SIZE) > 0)
	{
		c = ft_strjoin(c, stack);
		if (clearstack(stack) != -1)
			break ;
	}
	return (c);
}

/* 
 int main(){
	
	int fd = open ("test", O_RDONLY);
	char *str = get_next_line(fd);
	
	printf("%s", str);
	free(str);
	close(fd);

	return (0);
}  */