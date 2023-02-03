/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:19 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/03 17:28:02 by jabecass         ###   ########.fr       */
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
	while(lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->num > media(*stack_a))
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, stack_b, 'a');
	}
		
	if (!issorted(*stack_a))
		sort3(stack_a, stack_b);
}

void	bst_to_top(t_stack **stacka, t_stack **stackb, t_stack *best, int flag)
{
	t_stack	*curr;
	t_stack	**stack;

	stack = 0;
	if (flag == 1)
		stack = stacka;
	if (flag == 2)
		stack = stackb;
	curr = *stack;
	if (lstsize(best) < lstsize(*stack) / 2)
	{
		while (curr != best)
		{
			reverse_rotate(stacka, stackb, flag);
			curr = *stack;
		}
	}
	else
	{
		while (curr != best)
		{
			rotate(stacka, stackb, flag);
			curr = *stack;
		}
	}
}

void	sort_general(t_stack **stacka, t_stack **stackb)
{
	keep3(stacka, stackb);
	while (*stackb)
	{
		bst_to_top(stacka, stackb, least_cost(stacka, stackb), 2);
		bst_to_top(stacka, stackb, best_neighbour(stacka, stackb), 1);
		push(stackb, stacka, 1);
	}
	bst_to_top(stacka, stackb, lmin(stacka), 1);
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

int	media(t_stack *a)
{
	int med;

	med = 0;
	while (a)
	{
		med += a->num;
		a = a->next;
	}
	return(med/lstsize(a));
}