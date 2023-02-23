/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:43:30 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/23 09:32:00 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
	}
	return (1);
}

int ft_checkdoubles(t_stack *a, long int temp)
{
	while (a)
	{
		if (a->num == temp)
			return (0);
		a = a->next;
	}
	return (1);
}

void error_handle(char **tab, t_stack **a, int i)
{
	write(2, "Error\n", 6);
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	stackclear(*a);
	exit(1);
}

void checkerrors(char **tab, t_stack **a)
{
	long int tmp;
	int i;
	int	status;

	i = -1;
	status = 0;
	if (!tab)
		exit(1);
	while (tab[++i])
	{
		if (ft_strlen(tab[i]) == 1)
		{
			if (!ft_isdigit(tab[i]))
				error_handle(tab, a, i);
		}
		tmp = ft_atoi(tab[i], &status);
		if (status == 1 || !ft_checkdoubles(*a, tmp) || tmp > INT_MAX || tmp < INT_MIN)
			error_handle(tab, a, i);
		else
			add_node(a, tmp);
		free(tab[i]);
	}
	free(tab);
}
