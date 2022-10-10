/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:40:43 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/10 12:35:02 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int a;
    int b;
    
    a = 50;
    b = 5;
    printf("Antes\nA: %d\nB: %d\n", a, b);
    ft_swap(&a, &b);
    printf("Depois\nA: %d\nB: %d\n", a, b);
}
