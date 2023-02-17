/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmGeneral.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:58:36 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/07 15:41:41 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_general(t_stack **stack_a, t_stack **stack_b)
{
	keep3(stack_a, stack_b);
	while (*stack_b)
	{
		bst_to_top(stack_a, stack_b, least_cost(stack_a, stack_b), 'b');
		bst_to_top(stack_a, stack_b, best_neighbour(stack_a, stack_b), 'a');
		push(stack_b, stack_a, 'a');
	}
	min_top(stack_a, stack_b);
}

void	run_it(t_stack	**stack_a, t_stack **stack_b)
{
	if (!issorted(*stack_a))
	{
		if (lstsize(*stack_a) == 2)
			sort2(stack_a, stack_b);
		else if (lstsize(*stack_a) == 3)
			sort3(stack_a, stack_b);
		else if (lstsize(*stack_a) == 5 || lstsize(*stack_a) == 4)
			sort5(stack_a, stack_b);
		else if (lstsize(*stack_a) > 5)
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

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	min_top(stack_a, stack_b);
	push(stack_a, stack_b, 'b');
	if (lstsize(*stack_a) == 4)
	{
		min_top(stack_a, stack_b);
		push(stack_a, stack_b, 'b');
	}
	sort3(stack_a, stack_b);
	while (lstsize(*stack_b))
		push(stack_b, stack_a, 'a');
}
