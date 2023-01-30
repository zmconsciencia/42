/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:55:56 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/30 21:25:02 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int min(t_stack *a)
{
	t_stack	*min;
	
	min = a;
	while(a)
	{
		if (min->num > a->num)
			min = a;
		a = a->next;
	}
	return (min->num);
}

int max(t_stack *a)
{
	t_stack	*max;
	
	max = a;
	while(a)
	{
		if (max->num < a->num)
			max = a;
		a = a->next;
	}
	return (max->num);
}

int	bestnei(t_stack *a, t_stack *b)
{
	int tmp;

	tmp = 0;
	while (b)
	{
		while (a)
		{
			if (a->num > b->num)
			{	
				//printf("%d\n", a->num);
				tmp = a->num - b->num;
			}
			a = a->next;
		}
		b = b->next;
	}
	return (tmp);
}

/* int	cost(t_stack *curr, t_stack *a, t_stack *b)
{
	int	i;
	i = pos(curr, b);
	if (i > lstsize(b) / 2)
}
 */