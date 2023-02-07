/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecurrss <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:55:56 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/07 15:31:01 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*best_neighbour(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*curr;
	t_stack	*best;
	int		diff;

	diff = INT_MAX;
	curr = *stack_a;
	best = 0;
	while (curr)
	{
		if (curr->num > (*stack_b)->num && curr->num - (*stack_b)->num < diff)
		{
			best = curr;
			diff = curr->num - (*stack_b)->num;
		}
		curr = curr->next;
	}
	if (!best)
		best = lmin(stack_a);
	return (best);
}

int	bn_cost(t_stack **stack_a, t_stack **curr)
{
	int		bn_cost;
	t_stack	*bn;

	bn = best_neighbour(stack_a, curr);
	bn_cost = 0;
	if (lstsize(bn) < lstsize(*stack_a) / 2)
		bn_cost = lstsize(bn);
	else
		bn_cost = lstsize(*stack_a) - lstsize(bn);
	return (bn_cost);
}

t_stack	*least_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		cost;
	int		least_cost;
	int		i;
	t_stack	*curr;
	t_stack	*least;

	cost = 0;
	least_cost = INT_MAX;
	i = 0;
	curr = *stack_b;
	while (curr && ++i)
	{
		cost = (i > lstsize(*stack_b) / 2) * lstsize(curr) + \
		(i <= lstsize(*stack_b) / 2) * (lstsize(*stack_b) - lstsize(curr));
		cost += bn_cost(stack_a, &curr);
		if (cost < least_cost)
		{
			least_cost = cost;
			least = curr;
		}
		curr = curr->next;
	}
	return (least);
}
