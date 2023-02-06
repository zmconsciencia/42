/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:50:27 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/31 18:52:02 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > i)
		end--;
	str = (char *)malloc(sizeof(char) * (end - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)(s1 + i), (end - i + 1));
	return (str);
}
