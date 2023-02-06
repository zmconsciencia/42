/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:19 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/06 17:16:34 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	issorted(t_stack *a)
{
	while (a && a->next)
	{
		if (!(a->num < a->next->num))
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*c;

	c = *stack_a;
	if (!(issorted(c)))
	{
		if (c->num > c->next->num && c->next->num > c->next->next->num)
		{
			rotate(stack_a, stack_b, 'a');
			swap(*stack_a, *stack_b, 'a');
		}
		else if (c->num > c->next->num && \
		c->next->num < c->next->next->num && c->num > c->next->next->num)
			rotate(stack_a, stack_b, 'a');
		else if (c->num > c->next->num && c->num < c->next->next->num)
			swap(*stack_a, *stack_b, 'a');
		else if (c->num < c->next->num && c->num > c->next->next->num)
			reverse_rotate(stack_a, stack_b, 'a');
		else if (c->num < c->next->num && c->num < c->next->next->num && \
		c->next->num > c->next->next->num)
		{
			swap(*stack_a, *stack_b, 'a');
			rotate(stack_a, stack_b, 'a');
		}
	}
}

void	sort2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*c;

	c = *stack_a;
	if (!(issorted(c)))
		swap(*stack_a, *stack_b, 'a');
}

void	keep3(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->num < media(*stack_a))
		{
			push(stack_a, stack_b, 'b');
			if ((*stack_b)->num < media(*stack_b))
				rotate(stack_b, stack_a, 'b');
		}
		else
			rotate(stack_a, stack_b, 'a');
	}
}

void	bst_to_top(t_stack **a, t_stack **b, t_stack *best, char c)
{
	t_stack	*curr;
	t_stack	**stack;

	if (c == 'a')
		stack = a;
	if (c == 'b')
		stack = b;
	curr = *stack;
	if (lstsize(best) < lstsize(*stack) / 2)
	{
		while (curr != best)
		{
			reverse_rotate(stack, stack, c);
			curr = *stack;
		}
	}
	else if (lstsize(best) > lstsize(*stack) / 2)
	{
		while (curr != best)
		{
			rotate(stack, stack, c);
			curr = *stack;
		}
	}
}
