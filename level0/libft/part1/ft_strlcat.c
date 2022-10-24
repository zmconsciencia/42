/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:00:09 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/20 16:51:06 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	n_dest;
	size_t	n_src;
	size_t	i;
	size_t	ret;

	i = 0;
	n_dest = ft_strlen(dest);
	n_src = ft_strlen(src);
	if (size <= n_dest)
		return (size + n_src);
	else
	{
		while ((i + 1 < (size - n_dest)) && (src[i] != '\0'))
		{
			dest[n_dest + i] = src[i];
			i++;
		}
		dest[n_dest + i] = '\0';
	}
	ret = n_dest + n_src;
	return (ret);
}

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void			ft_strlcat_test(char *dest, char *ft_dest, char *src, unsigned int size)
{
	unsigned int	return_value;
	unsigned int	ft_return_value;

	return_value = strlcat(dest, src, size);
	ft_return_value = ft_strlcat(ft_dest, src, size);
	if (return_value != ft_return_value)
		printf("> KO, expected: %u, got: %u\n", return_value, ft_return_value);
	else if (strcmp(dest, ft_dest) != 0)
		printf("> KO, expected: %s, got: %s\n", dest, ft_dest);
	else
		printf("> OK, result: %s\n", ft_dest);
}

int				main(void)
{
	char			*src;
	char			*dest;
	char			*ft_dest;

	// invalid case, dest is non null terminated in the first size - 1 bytes.
	src = "stuv";
	dest = "abcdefghijklmnopr";
	ft_dest = "abcdefghijklmnopr";
	ft_strlcat_test(dest, ft_dest, src, 0);
    printf("%ld\n", ft_strlcat(dest, src, 0));
    printf("%ld\n", strlcat(dest, src, 0));
	ft_strlcat_test(dest, ft_dest, src, 1);
    printf("%ld\n", ft_strlcat(dest, src, 1));
    printf("%ld\n", strlcat(dest, src, 1));
	ft_strlcat_test(dest, ft_dest, src, 4);
    printf("%ld\n", ft_strlcat(dest, src, 4));
    printf("%ld\n", strlcat(dest, src, 4));
	ft_strlcat_test(dest, ft_dest, src, 10);
    printf("%ld\n", ft_strlcat(dest, src, 10));
    printf("%ld\n", strlcat(dest, src, 10));
	// valid case, dest is null terminated in the first size - 1 bytes, modified and terminated
	src = "ghijkl";
	dest = strcpy(calloc(13, sizeof(char)), "abcdef");
	ft_dest = strcpy(calloc(13, sizeof(char)), "abcdef");
	ft_strlcat_test(dest, ft_dest, src, 8);
    printf("%ld\n", ft_strlcat(dest, src, 8));
    printf("%ld\n", strlcat(dest, src, 8));
	ft_strlcat_test(dest, ft_dest, src, 10);
    printf("%ld\n", ft_strlcat(dest, src, 10));
    printf("%ld\n", strlcat(dest, src, 10));
	return (0);
}