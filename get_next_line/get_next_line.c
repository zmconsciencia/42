/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:54:28 by jabecass          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/26 19:41:10 by jabecass         ###   ########.fr       */
=======
/*   Updated: 2022/11/24 10:38:55 by jabecass         ###   ########.fr       */
>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*c;
	static char	stack[BUFFER_SIZE + 1];
	size_t		i;

	i = -1;
	if (BUFFER_SIZE < 1 || read (fd, 0, 0) < 0)
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
<<<<<<< HEAD
=======

/* 
 int main(){
	
	int fd = open ("test", O_RDONLY);
	char *str = get_next_line(fd);
	
	printf("%s", str);
	free(str);
	close(fd);

	return (0);
} */
>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
