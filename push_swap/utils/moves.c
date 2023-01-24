/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:46 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/24 14:30:02 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *list)
{
	int		tmp;

	tmp = list->num;
	list->num = list->next->num;
	list->next->num = tmp;
}

void	push(t_stack **src, t_stack **dst)
{	
	t_stack	*tmp;

	tmp = *src;
	if (tmp->next)
	{
		*src = tmp->next;
		(*src)->prev = NULL;
	}
	else
		*src = NULL;
	tmp->next = *dst;
	tmp->prev = NULL;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
}
