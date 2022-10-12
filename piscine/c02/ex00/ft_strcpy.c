/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:04:49 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 13:13:12 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        printf("Antes:\nSRC: %s\nDEST: %s\n", av[2], av[1]);
        ft_strcpy(av[1], av[2]);
        printf("Depois:\nSRC: %s\nDEST: %s\n", av[2], av[1]);
    }
    return (0);
}