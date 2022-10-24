/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:25:57 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 16:46:29 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t n)
{
	char	*p;

	p = (char *)b;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (b);
}