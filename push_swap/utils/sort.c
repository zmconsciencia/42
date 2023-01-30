/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:19 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/30 17:33:56 by jabecass         ###   ########.fr       */
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
			reverse_rotate(stack_a, stack_b, 'a');
			reverse_rotate(stack_a, stack_b, 'a');
			swap(*stack_a, *stack_b, 'a');
		}
		else if (c->num > c->next->num && \
		c->next->num < c->next->next->num && c->num > c->next->next->num)
			rotate(stack_a, stack_b, 'a');
		else if (c->num > c->next->num && c->num < c->next->next->num)
			swap(*stack_a, *stack_b, 'a');
		else if (c->num < c->next->num && c->num > c->next->next->num)
			reverse_rotate(stack_a, stack_b, 'a');
		else if (c->num < c->next->num && c->num < c->next->next->num)
		{
			push(stack_a, stack_b, 'b');
			swap(*stack_a, *stack_b, 'a');
			push(stack_b, stack_a, 'a');
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
	while(!issorted(*stack_a) && lstsize(*stack_a) > 3)
		push(stack_a, stack_b, 'b');
	if (!issorted(*stack_a))
		sort3(stack_a, stack_b);
}