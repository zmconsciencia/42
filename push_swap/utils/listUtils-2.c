/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listUtils-2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:17:26 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/23 09:36:06 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lmin(t_stack **a)
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

t_stack	*lmax(t_stack *a)
{
	t_stack	*max;

	max = a;
	while (a)
	{
		if (max->num < a->num)
			max = a;
		a = a->next;
	}
	return (max);
}
