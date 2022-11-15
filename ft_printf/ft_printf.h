/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:41:04 by jabecass          #+#    #+#             */
/*   Updated: 2022/11/14 14:30:58 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int		ft_printf(const char *c, ...);
size_t	conversions(va_list args, char c);
int		ft_int_putchar(char c);
int		ft_int_putstr(char *s);
int		ft_int_putnbr(int n);
size_t	countdigits(long int n);
int		int_percent(char c);
int		int_putnbr(long int a);
size_t	ft_puthexa(unsigned long n, int base);
size_t	ft_size_hex(long unsigned int n);
size_t	ft_print_p(unsigned long int p);

#endif