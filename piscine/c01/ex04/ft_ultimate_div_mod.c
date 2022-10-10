/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:44:36 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/10 20:01:55 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_ultimate_div_mod(int *a, int *b)
{
    int x;
    int y;

    x = *a;
    y = *b;
    if (b != 0)
    {
        *a = x / y;
        *b = x % y;
    }
}

int main(void)
{
    int a;
    int b;

    a = 50;
    b = 10;
    printf("ANTES:\na: %d\nb: %d\n", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("DEPOIS:\na: %d\nb: %d\n", a, b);
}