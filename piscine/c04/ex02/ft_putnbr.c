/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:17:19 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 18:17:21 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb == 2147483647)
        write (1, "2147483647", 10);
    else if (nb < 0)
    {
        nb = -nb;
        ft_putchar('-');
        ft_putnbr(nb);
    }
    else if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
    else
        ft_putchar(nb + '0');
}

int main(void)
{
    ft_putnbr(-2147483646);
    write (1, "\n", 1);
    return(0);
}