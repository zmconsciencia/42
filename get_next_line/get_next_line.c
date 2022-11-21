/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:54:28 by jabecass          #+#    #+#             */
/*   Updated: 2022/11/21 16:18:22 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*c;
	static char	stack[BUFFER_SIZE + 1];

	c = NULL;
	while (read(fd, stack, BUFFER_SIZE))
	{
		c = ft_strjoin(c, stack);
	}
	return (c);
}

//void	clearStack()

/* int main(){
	
	int fd = open ("test", O_RDONLY);
	char *str = get_next_line(fd);
	
	printf("%s", str);
	free(str);
	close(fd);

	return (0);
} */