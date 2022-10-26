/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:25:57 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/26 10:34:54 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t n)
{
	char	*t;

	t = (char *)b;
	while (n > 0)
	{
		t[n - 1] = c;
		n--;
	}
	return (b);
}
