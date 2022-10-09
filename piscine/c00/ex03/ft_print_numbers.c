/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:13:56 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/02 23:13:56 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_numbers(void)
{
    int i;

    i = '0';
    while (i <= '9')
    {
        write (1, &i, 1);
        i++;
    }
}

int main(void)
{
    ft_print_numbers();
    return (0);
}