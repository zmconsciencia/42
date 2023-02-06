/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:08:38 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/27 12:22:51 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	size;
	size_t			i;
	size_t			j;

	size = (int)len;
	if (!s)
		return (NULL);
	if (size >= ft_strlen((char *)s) - start)
		size = ft_strlen((char *)s) - start;
	if (start >= ft_strlen((char *)s))
		size = 0;
	new = (char *)malloc(size + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			new[j++] = s[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}
