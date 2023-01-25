/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:19 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/25 16:59:24 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	issorted(t_stack **a)
{
	t_stack *curr = *a;
	while(curr && curr->next)
	{
		if (!(curr->num < curr->next->num))
			return (0);
		curr = curr->next;
	}
	return 1;
}