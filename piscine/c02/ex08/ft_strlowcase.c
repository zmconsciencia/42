/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:42:21 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 16:42:59 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] >= 'A' && str [i] <= 'Z'))
            str[i] = str[i] + 32;
        i++;
	}
	return (str);
}

int main(void)
{
    char str[] = "ola bro AAAAhsdj";
    char *a;

    a = ft_strlowcase(str);
    printf("%s\n", a);
}