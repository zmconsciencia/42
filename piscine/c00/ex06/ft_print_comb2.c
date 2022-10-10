/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 06:46:16 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/10 10:02:29 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_print_comb2(void)
{
    int a;
    int b;

    a = 0;
    while(a < 99)
    {
        b = a + 1;
        while(b < 100)
        {
            ft_putchar(a / 10 + '0');
            ft_putchar(a % 10 + '0');
            ft_putchar(' ');
            ft_putchar(b / 10 + '0');
            ft_putchar(b % 10 + '0');
            if (a == 98 && b == 99)
            {
            }
            else
                write (1, ", ", 2);
            b++;
        }
        a++;
    }
    write (1, "\n", 1);
}

int main(void)
{
    ft_print_comb2();
    return(0);
}