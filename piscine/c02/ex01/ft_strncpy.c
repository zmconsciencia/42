/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:19:51 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 14:25:21 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i = 0;

    while (src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while(i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return(dest);
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        
        printf("ANTES:\nSRC: %s\nDEST: %s\n", av[2], av[1]);
        int a = ft_atoi(av[3]);
        ft_strncpy(av[1], av[2], a);
        printf("DEPOIS:\nSRC: %s\nDEST: %s\n", av[2], av[1]);
        /*
        printf("-------------------------------------\n");
        printf("ANTES:\nSRC: %s\nDEST: %s\n", av[2], av[1]);
        strncpy(av[1], av[2], ft_atoi(av[3]));
        printf("DEPOIS:\nSRC: %s\nDEST: %s\n", av[2], av[1]);
        */
    }
}