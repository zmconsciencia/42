/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:20:26 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 10:25:10 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isprint(int c)
{
    if ((c >= 0 && c <= 31) || (c == 127))
        return (0);
    else
        return (1);
}

int main(void)
{
    int a;

    a = 0;
    while (a < 128)
    {
        printf("FT - %d: %d\n", a, ft_isprint(a));
        printf("Real - %d: %d\n", a, isprint(a));
        putchar('\n');
        a++;
    }
}