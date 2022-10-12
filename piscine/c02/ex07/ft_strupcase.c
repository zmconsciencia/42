/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:22:46 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 16:30:01 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] >= 'a' && str [i] <= 'z'))
            str[i] = str[i] - 32;
        i++;
	}
	return (str);
}

int main(void)
{
    char str[] = "ola bro AAAAhsdj";
    char *a;

    a = ft_strupcase(str);
    printf("%s\n", a);
}