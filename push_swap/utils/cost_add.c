/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:58:36 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/06 17:22:48 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_general(t_stack **stacka, t_stack **stackb)
{
	keep3(stacka, stackb);
	while (*stackb)
	{
		bst_to_top(stacka, stackb, least_cost(stacka, stackb), 'b');
		bst_to_top(stacka, stackb, best_neighbour(stacka, stackb), 'a');
		push(stackb, stacka, 'a');
	}
	bst_to_top(stacka, stackb, lmin(stacka), 'a');
}

void	run_it(t_stack	**stack_a, t_stack **stack_b)
{
	if (!issorted(*stack_a))
	{
		if (lstsize(*stack_a) == 2)
			sort2(stack_a, stack_b);
		else if (lstsize(*stack_a) == 3)
			sort3(stack_a, stack_b);
		else if (lstsize(*stack_a) > 3)
			sort_general(stack_a, stack_b);
	}
}

long int	yo(t_stack *a)
{
	int	med;

	med = 0;
	if (a)
	{
		med = 0;
		while (a)
		{
			med += a->num;
			a = a->next;
		}
	}
	return (med);
}

int	media(t_stack *a)
{
	if (lstsize(a) > 0)
		return (yo(a) / lstsize(a));
	return (-1);
}
