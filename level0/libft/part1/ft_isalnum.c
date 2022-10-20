/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:02:55 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 10:06:31 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isalnum(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return (1);
    else
        return (0);
}

int main(void)
{
    int a;

    a = 0;
    while (a < 128)
    {
        printf("FT - %d: %d\n", a, ft_isalnum(a));
        printf("Real - %d: %d\n", a, isalnum(a));
        putchar('\n');
        a++;
    }
}