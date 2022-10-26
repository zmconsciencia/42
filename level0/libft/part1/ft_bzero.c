/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:31:53 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/26 11:14:01 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

/*
void	bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
*/


void	bzero(void *s, size_t n)
{
	char	*t;

	t = (char *)s;
	while (n > 0)
	{
		t[n - 1] = 0;
		n--;
	}
	return (s);
}