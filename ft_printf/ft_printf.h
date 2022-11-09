/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:41:04 by jabecass          #+#    #+#             */
/*   Updated: 2022/11/09 19:05:51 by jabecass         ###   ########.fr       */
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
int		countdigits(int n);
int		int_percent(char c);

#endif