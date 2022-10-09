/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 06:26:36 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/09 19:24:31 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_print_comb(void)
{
    int a;
    int b;
    int c;

    a = '0';
    while (a <= '7')
    {
        b = a + 1;
        while (b <= '8')
        {
            c = b + 1;
            while (c <= '9')
            {
                ft_putchar(a);
                ft_putchar(b);
                ft_putchar(c);
                if (a != '7')
                    write (1, ", ", 2);
                c++;
            }
            b++;
        }
        a++;
    }
    write (1, "\n", 1);
}

int main(void)
{
    ft_print_comb();
    return (0);
}