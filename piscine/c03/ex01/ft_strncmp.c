/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:38:04 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/17 14:50:27 by jabecass         ###   ########.fr       */
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

void	ft_strncmp_test(char *s1, char *s2, unsigned int n)
{
	int res;
	int ft_res;

	res = strncmp(s1, s2, n);
	ft_res = ft_strncmp(s1, s2, n);
	if (res != ft_res)
		printf("> KO, expected: %d, got: %d\n", res, ft_res);
	else
		printf("> OK, result: %d\n", ft_res);
}

int		main(void)
{
	char	*s1 = "abcdefghi";
	char	*s2 = "abcdEfghi";
	char	s3[] = {'a', 'b', -23, 'd', 'e', 'f', 'g', 'h', 'i', '\0'};
	char	*s4 = "abcdefghi";
	char	*s5 = "abcd";
	char	*s6 = "abcdefghijklmn";
	char	*s7 = "";

	int		offset;

	offset = 0;
	printf("[1] Testing strings \"%s\" and \"%s\"\n", s1, s2);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s2, offset);
		offset++;
	}
	offset = 0;
	printf("[2] Testing strings \"%s\" and \"%s\"\n", s1, s3);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s3, offset);
		offset++;
	}
	offset = 0;
	printf("[3] Testing strings \"%s\" and \"%s\"\n", s2, s3);
	while (offset < 10)
	{
		ft_strncmp_test(s2, s3, offset);
		offset++;
	}
	offset = 0;		// Comparing equal strings. Should return 0.
	printf("[4] Testing strings \"%s\" and \"%s\" (same strings)\n", s1, s4);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s4, offset);
		offset++;
	}
	offset = 0;		// Comparing with a shorter string (s5 lenght 5).
	printf("[5] Testing strings \"%s\" and \"%s\"\n", s1, s5);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s5, offset);
		offset++;
	}
	offset = 0;		// Comparing with a longer string (s6 lenght 15).
	printf("[6] Testing strings \"%s\" and \"%s\"\n", s1, s6);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s6, offset);
		offset++;
	}
	offset = 0;		// Comparing with an empty string (s7).
	printf("[7] Testing strings \"%s\" and \"%s\"\n", s1, s7);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s7, offset);
		offset++;
	}
	return (0);
}