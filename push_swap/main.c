/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:38:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/18 15:47:01 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack* stack_a = 0;
	char **tab;
	int j;
	int i = 0;
	if (ac > 1)
	{
		while(++i < ac)
		{
			tab = ft_split(av[i], ' ');
			j = -1;
			while (tab[++j])
			{
				add_node(&stack_a, ft_atoi(tab[j]));
				free(tab[j]);
			}
			free(tab);
		}
		print_lst(stack_a);
		stackclear(stack_a);
	}
}