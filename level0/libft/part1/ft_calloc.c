/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:38:34 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/26 14:57:10 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*a;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	i = 0;
	a = malloc(nmemb * size);
	if (!a)
		return (NULL);
	if (nmemb != 0)
	{
		while (i < nmemb)
		{
			a[i] = 0;
			i++;
		}
		return ((void *)a);
	}
	return ((void *)a);
}
