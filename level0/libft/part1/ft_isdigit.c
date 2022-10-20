/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:46:41 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 09:48:47 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c)
{
    if ((c >= '0' && c <= '9'))
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
        printf("FT - %d: %d\n", a, ft_isdigit(a));
        printf("Real - %d: %d\n", a, isdigit(a));
        putchar('\n');
        a++;
    }
}