/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:40:48 by jabecass          #+#    #+#             */
/*   Updated: 2022/11/09 19:09:29 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conversions(va_list args, char c)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len = ft_int_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_int_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = ft_int_putnbr(va_arg(args, int));
	else if (c == '%')
		len = ft_int_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += 1;
			len += conversions(args, str[i]);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
