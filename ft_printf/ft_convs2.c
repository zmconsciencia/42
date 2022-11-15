/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:56:59 by jabecass          #+#    #+#             */
/*   Updated: 2022/11/14 14:32:51 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa(long unsigned int n, int base)
{
	char	*set;

	if (base)
			set = "0123456789abcdef";
	else
			set = "0123456789ABCDEF";
	if (n > 15)
		ft_puthexa(n / 16, base);
	ft_putchar_fd(set[n % 16], 1);
	return (ft_size_hex((long)n));
}

size_t	ft_size_hex(long unsigned int n)
{
	size_t				size;
	long unsigned int	div;

	div = n;
	size = 0;
	if (n == 0)
		return (1);
	while (div != 0)
	{
		size++;
		div /= 16;
	}
	return (size);
}

size_t	ft_print_p(unsigned long int p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	ft_putstr_fd("0x", 1);
	ft_puthexa(p, 1);
	return (ft_size_hex(p) + 2);
}
