/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:19 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/30 16:51:41 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	issorted(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	while (curr && curr->next)
	{
		if (!(curr->num < curr->next->num))
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	sort3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*c;

	c = *stack_a;
	if (!(issorted(&c)))
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
	if (!(issorted(&c)))
		swap(*stack_a, *stack_b, 'a');
}