/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:43:33 by jabecass          #+#    #+#             */
/*   Updated: 2022/10/19 17:51:15 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    int res;
    
    res = nb;
    if (power < 0)
        return (0);
    else if (power == 0)
        return (1);
    else if(power == 1)
        return (nb);
    else
        res *= ft_recursive_power(res, power - 1);
    return (res);
}

int	ft_recursive_power(int nb, int power);

void ft_recursive_power_test(int nb, int power)
{
	int res;

	res = ft_recursive_power(nb, power);
	printf(" nb = %d, power = %d, result: %d\n", nb, power, res);
}

int	main(void)
{
	int nb;
	int power;

	// testando potencias negativas(deve retornar 0)
	printf("[1] Potencias negativas(deve retornar 0)\n");
	nb = -4;
	while (nb <= 4)
	{
		power = -4;
		while (power < 0)
		{
			ft_recursive_power_test(nb, power);
			power++;
		}
		nb++;
	}
	// testando potencias 0(deve retornar 1)
	printf("[2] Potencias 0(deve retornar 1)\n");
	nb = -4;
	power = 0;
	while (nb <= 4)
	{
		ft_recursive_power_test(nb, power);
		nb++;
	}
	// testando potencias 0(deve retornar 1)
	printf("[3] Potencias positivas(deve retornar o numero elevado a potencia)\n");
	nb = -4;
	while (nb <= 4)
	{
		power = 1;
		while (power <= 4)
		{
			ft_recursive_power_test(nb, power);
			power++;
		}
		nb++;
	}
	return (0);
}