/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:43:30 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/20 16:00:02 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;
	
	i = -1;
	while(str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

int	ft_checkdoubles(t_stack *a, long int temp)
{
	while(a)
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
	//print_lst(*a);
	write(2, "Error\n", 6);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
	stackclear(*a);
	exit(0);
}

void	checkerrors(char **tab, t_stack **a)
{
	long int	temp;
	int			i;
	
	i = -1;
	while(tab[++i])
	{
		
		temp = ft_atoi(tab[i]);
		if (!ft_isdigit(tab[i]) || temp > INT_MAX || temp < INT_MIN || !ft_checkdoubles(*a, temp))
			error_handle(tab, a);
		else
			add_node(a, temp);
		free(tab[i]);
	}
	free(tab);

}
