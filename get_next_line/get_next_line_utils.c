/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:54:05 by jabecass          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/26 19:35:20 by jabecass         ###   ########.fr       */
=======
/*   Updated: 2022/11/24 17:26:17 by jabecass         ###   ########.fr       */
>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
<<<<<<< HEAD
		i++;
	if (str[i] == '\n')
=======
>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
		i++;
	if (str[i] == '\n')
		i += 1;
	return ((i));
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ret;
	size_t	i;

	ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (str1 && str1[++i])
		ret[i] = str1[i];
	i += (!str1);
	while (*str2)
	{
		ret[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	ret[i] = 0;
	free (str1);
	return (ret);
}

int	clearstack(char *stack)
{
	int	i;
<<<<<<< HEAD
	int	j;

	j = -1;
=======

>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
	i = -1;
	while (stack[++i])
	{
		if (stack[i] == '\n')
		{
			stack[i++] = 0;
<<<<<<< HEAD
			j = 0;
=======
>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
			break ;
		}
		stack[i] = 0;
	}
<<<<<<< HEAD
	if (!j)
	{
		while (stack[i])
		{
			stack[j++] = stack[i];
			stack[i++] = 0;
		}
	}
	return (j);
=======
	return (i);
>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
}
