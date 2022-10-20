/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:30:26 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 09:42:47 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c)
{
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
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
        printf("FT - %d: %d\n", a, ft_isalpha(a));
        printf("Real - %d: %d\n", a, isalpha(a));
        putchar('\n');
        a++;
    }
}