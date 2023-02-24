/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:25:35 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/23 09:35:55 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_int_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_int_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
	return (countdigits(n));
}

size_t	countdigits(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i += 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	int_putnbr(long int a)
{
	int	n;

	n = (unsigned int)a;
	if (n < 0)
	{
		n = -n;
		int_putnbr(n);
	}
	else if (n > 9)
	{
		int_putnbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
	return (countdigits(n));
}
