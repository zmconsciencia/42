/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:12:43 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 10:18:49 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    else
        return (0);
}

int main(void)
{
    int a;

    a = 0;
    while (a < 228)
    {
        printf("FT - %d: %d\n", a, ft_isascii(a));
        printf("Real - %d: %d\n", a, isascii(a));
        putchar('\n');
        a++;
    }
}