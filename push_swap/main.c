/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:38:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/20 17:41:53 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = 0;
	if (ac > 1)
	{
		while (++i < ac)
			checkerrors(ft_split(av[i], ' '), &stack_a);
		print_lst(stack_a);
		stackclear(stack_a);
	}
}
