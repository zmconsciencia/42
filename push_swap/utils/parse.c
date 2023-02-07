/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:43:30 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/07 15:15:24 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return (0);
	}
	return (1);
}

int	ft_checkdoubles(t_stack *a, long int temp)
{
	while (a)
	{
		if (a->num == temp)
			return (0);
		a = a->next;
	}
	return (1);
}

void	error_handle(char **tab, t_stack **a)
{
	int	i;

	i = 0;
	write (2, "Error\n", 6);
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	stackclear(*a);
	exit (0);
}

void	checkerrors(char **tab, t_stack **a)
{
	long int	tmp;
	int			i;

	i = -1;
	while (tab[++i])
	{
		tmp = ft_atoi(tab[i]);
		if (!ft_isdigit(tab[i]) || tmp > INT_MAX || \
			tmp < INT_MIN || !ft_checkdoubles(*a, tmp))
			error_handle(tab, a);
		else
			add_node(a, tmp);
		free (tab[i]);
	}
	free (tab);
}
