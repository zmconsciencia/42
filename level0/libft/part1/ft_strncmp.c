/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:30:32 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 11:31:16 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
    unsigned char c1;
    unsigned char c2;

	i = 0;
    if (n == 0)
        return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0') && (i + 1 < n))
		i++;
    c1 = s1[i];
    c2 = s2[i];
    return (c1 - c2);
}