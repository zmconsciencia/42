/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:00:09 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/26 11:46:15 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	ret;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (size + len_src);
	else
	{
		while ((i + 1 < (size - len_dest)) && (src[i] != '\0'))
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = '\0';
	}
	ret = len_dest + len_src;
	return (ret);
}
