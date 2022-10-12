/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:09:19 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/12 16:10:07 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_numeric(char *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return (0);
    }
    return (1);
}

int main(void)
{
    char str[] = "1";

    printf("%d\n", ft_str_is_numeric(str));
}