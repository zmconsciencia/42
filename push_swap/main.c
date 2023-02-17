/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:38:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/17 14:45:20 by jabecass         ###   ########.fr       */
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
			if(*av[i]) 
				checkerrors(ft_split(av[i], ' '), &stack_a);
			else
				error_handle(NULL, &stack_a, 0);
		run_it(&stack_a, &stack_b);
		if (!issorted(stack_a))
			run_it(&stack_a, &stack_b);
		stackclear(stack_a);
		stackclear(stack_b);
	}
}
