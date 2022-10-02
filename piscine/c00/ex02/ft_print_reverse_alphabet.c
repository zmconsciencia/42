/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:44 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/02 23:09:44 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_print_reverse_alphabet(void)
{
    char a = 'z';

    while (a >= 'a')
    {
        write (1, &a, 1);
        a--;
    }
}

int main(void)
{
    ft_print_reverse_alphabet();
    return (0);
}