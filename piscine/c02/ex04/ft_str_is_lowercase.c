/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:15:17 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 16:17:08 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_lowercase(char *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z'))
            i++;
        else
            return (0);
    }
    return (1);
}

int main(void)
{
    char str[] = "1";

    printf("%d\n", ft_str_is_lowercase(str));
}