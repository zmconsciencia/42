/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:55:56 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/01 17:46:28 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *lmin(t_stack **a)
{
	t_stack	*min;
	t_stack	*curr;

	min = *a;
	curr = *a;
	while (curr)
	{
		if (curr->num < min->num)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

t_stack *lmax(t_stack *a)
{
	t_stack	*max;
	
	max = a;
	while(a)
	{
		if (max->num < a->num)
			max = a;
		a = a->next;
	}
	return (max);
}

t_stack	*best_neighbour(t_stack **stacka, t_stack **stackb)
{
	t_stack	*ca;
	t_stack	*best;
	int		diff;

	diff = INT_MAX;
	ca = *stacka;
	best = 0;
	while (ca)
	{
		if (ca->num > (*stackb)->num && ca->num - (*stackb)->num < diff)
		{
			best = ca;
			diff = ca->num - (*stackb)->num;
		}
		ca = ca->next;
	}
	if (!best)
		best = lmin(stacka);
	return (best);
}

int	bn_cost(t_stack **stacka, t_stack **curr)
{
	int		bn_cost;
	t_stack	*bn;

	bn = best_neighbour(stacka, curr);
	bn_cost = 0;
	if (lstsize(bn) < lstsize(*stacka) / 2)
		bn_cost = lstsize(bn);
	else
		bn_cost = lstsize(*stacka) - lstsize(bn);
	return (bn_cost);
}

t_stack	*least_cost(t_stack **stacka, t_stack **stackb)
{
	int		cost;
	int		least_cost;
	int		i;
	t_stack	*curr;
	t_stack	*least;

	cost = 0;
	least_cost = INT_MAX;
	i = 0;
	curr = *stackb;
	while (curr && ++i)
	{
		cost = (i > lstsize(*stackb) / 2) * lstsize(curr) + \
		(i <= lstsize(*stackb) / 2) * (lstsize(*stackb) - lstsize(curr));
		cost += bn_cost(stacka, &curr);
		if (cost < least_cost)
		{
			least_cost = cost;
			least = curr;
		}
		curr = curr->next;
	}
	return (least);
}