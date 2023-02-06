/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:40:48 by jabecass          #+#    #+#             */
/*   Updated: 2022/11/14 14:25:19 by jabecass         ###   ########.fr       */
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
	else if (c == 'u')
		len = int_putnbr((long)va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_puthexa(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		len = ft_puthexa(va_arg(args, unsigned int), 0);
	else if (c == 'p')
		len = ft_print_p(va_arg(args, long unsigned int));
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
