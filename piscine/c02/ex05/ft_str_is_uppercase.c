/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:16:09 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 16:16:41 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_uppercase(char *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);
    while (str[i])
    {
        if ((str[i] >= 'A' && str[i] <= 'Z'))
            i++;
        else
            return (0);
    }
    return (1);
}

int main(void)
{
    char str[] = "1";

    printf("%d\n", ft_str_is_uppercase(str));
}