/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:38:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/18 20:07:24 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack* stack_a = 0;
	char **tab;
	int i = 0;
	int j;
	if (ac > 1)
	{
		while(++i < ac)
		{
			tab = ft_split(av[i], ' ');
			j = -1;
			while (tab[++j])
			{
				if (!checkerrors(&tab[j], stack_a))
				add_node(&stack_a, ft_atoi(tab[j]));
			}
		}
		print_lst(stack_a);
		stackclear(stack_a);
	}
}
