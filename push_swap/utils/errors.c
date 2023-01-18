/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:43:30 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/18 20:12:45 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

int	ft_checkdoubles(t_stack *a, long int temp)
{
	while(a->next)
	{
		if (a->num == temp)
			return (0);
	}
	return (1);
}

void	freefunc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

int	checkerrors(char **tab, t_stack *a)
{
	long int	temp;
	int			i;
	
	i = -1;
	while(tab[++i])
	{
		temp = ft_atoi(tab[i]);
		if (ft_isdigit(tab[i]) || temp > INT_MAX || temp < INT_MIN || ft_checkdoubles(a, temp))
		{
			write(2, "Error", 7);
			freefunc(tab);
			return (1);
			exit(0);
		}
	}
	return (0);
}
