/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:38:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/25 16:47:37 by jabecass         ###   ########.fr       */
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
		printf("B:\n");
		print_lst(stack_b);
		printf("%d\n", issorted(&stack_a));
		/* push(&stack_a, &stack_b);
		rotate(&stack_a);
		swap(stack_a); */
		//reverse_rotate(&stack_a);
		printf("----------------\n");
		printf("A:\n");
		print_lst(stack_a);
		printf("B:\n");
		print_lst(stack_b);
		stackclear(stack_a);
	}
}
