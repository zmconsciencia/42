/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:46 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/30 14:33:56 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *a, t_stack *b, char c)
{
	int		tmp;

	tmp = a->num;
	a->num = a->next->num;
	a->next->num = tmp;
	if (c)
		printf("s%c\n", c);
	if (c == 's')
		swap(b, a, 0);
}

void	push(t_stack **src, t_stack **dst, char c)
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
	printf("p%c\n", c);
}

void	rotate(t_stack **a, t_stack **b, char c)
{
    if (*a == NULL)
        return;
	
    t_stack *current = *a;
    while (current->next != NULL)
        current = current->next;

    current->next = *a;
    (*a)->prev = current;
    *a = (*a)->next;
    (*a)->prev = NULL;
    current->next->next = NULL;
	if (c)
		printf("r%c\n", c);
	if (c == 'r')
		rotate(b, a, 0);
}

void	reverse_rotate(t_stack **a, t_stack **b, char c)
{
    if (*a == NULL)
        return;

    t_stack *current = *a;
    while (current->next != NULL)
        current = current->next;

    current->next = *a;
    (*a)->prev = current;
    *a = current;
    (*a)->prev->next = NULL;
    (*a)->prev = NULL;
	if (c)
		printf("rr%c\n", c);
	if (c == 'r')
		rotate(b, a, 0);
}
