/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:52:20 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 17:58:48 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char    *strchr(const char *s, int c);

{
    while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}