/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:17:21 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/02 23:17:21 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_is_negative(int nb)
{
    char neg;
    char pos;

    pos = 'P';
    neg = 'N';
    if (nb < 0 )
        write (1, &neg, 1);
    else
        write (1, &pos, 1);
    write (1, "\n", 1);
}

int main(void)
{
    ft_is_negative(-1);
    ft_is_negative(1);
}