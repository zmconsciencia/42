/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:53:28 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/26 11:24:04 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_bzero(void *a, size_t n)
{
	memset(a, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	a = malloc(nmemb * size);
	if (!a)
		return (NULL);
	if (nmemb != 0)
	{
		ft_bzero(a, nmemb * size);
	}
	return (a);
}
