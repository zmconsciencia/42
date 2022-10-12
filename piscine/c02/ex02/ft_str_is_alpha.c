/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:29:58 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 16:07:55 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_alpha(char *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);
    while (str[i])
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            i++;
        else
            return (0);
    }
    return (1);
}

int main(void)
{
    char str[] = "1";

    printf("%d\n", ft_str_is_alpha(str));
}