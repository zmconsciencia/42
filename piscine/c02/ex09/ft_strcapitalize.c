/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:46:01 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 18:02:24 by jabecass         ###   ########.fr       */
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

char    *ft_strcapitalize(char *str)
{
    int i = 0;
    int j = 1;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (j == 1)
				str[i] -= 32;
			    j = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			j = 0;
		else
			j = 1;
		i++;
	}
	return (str);
}

int	main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char str1[] = "diujndfvon,odficj,dc dsfovij?kl43lo+dd-sdk%cdj*dc$sdc";
	printf("%s", ft_strcapitalize(str));
	printf("\n%s\n", ft_strcapitalize(str1));
}