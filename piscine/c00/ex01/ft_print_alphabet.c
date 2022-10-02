/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:01:27 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/02 23:01:27 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_print_alphabet(void)
{
    char a = 'a';

    while (a <= 'z')
    {
        write (1, &a, 1);
        a++;
    }
}

int main(void)
{
    ft_print_alphabet();
    return (0);
}
