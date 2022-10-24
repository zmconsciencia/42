/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:10:37 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/19 17:16:45 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    int f;

    f = nb;
    if (nb < 0)
        return (0);
    if (nb < 2)
        return (1);
    f *= ft_recursive_factorial(f - 1);
    return (f);
}

int	ft_recursive_factorial(int nb);

int	main(void)
{
	int nb;
	int res;

	nb = -5;
	while (nb <= 10)
	{
		res = ft_recursive_factorial(nb);
		printf("> n = %d, n! = %d\n", nb, res);
		nb++;
	}
	return (0);
}