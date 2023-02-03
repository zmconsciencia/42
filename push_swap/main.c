/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:38:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/03 15:48:04 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 0;
	stack_a = 0;
	stack_b = NULL;
	if (ac > 1)
	{
		while (++i < ac)
			checkerrors(ft_split(av[i], ' '), &stack_a);
		printf("A:\n");
		print_lst(stack_a);
		printf("----------------\n");
		run_it(&stack_a, &stack_b);
		printf("----------------\n");
		printf("A:\n");
		print_lst(stack_a);
		printf("----------------\n");
		stackclear(stack_a);
		stackclear(stack_b);
	}
}
