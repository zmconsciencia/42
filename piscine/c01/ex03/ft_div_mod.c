/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:04 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/10 19:34:31 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_div_mod(int a, int b, int *div, int *mod)
{
    if (b != 0)
    {
        *div = a / b;
        *mod = a % b;
    }
}

int main(void)
{
    int a;
    int b;
    int x;
    int y;

    a = 50;
    b = 10;
    ft_div_mod(a, b, &x, &y);
    printf("A: %d\nB: %d\nDiv: %d\nMod: %d\n", a, b, x, y);
}