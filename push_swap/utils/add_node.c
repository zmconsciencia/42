/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:50:45 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/24 14:19:30 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node(t_stack **root, int node)
{
	t_stack	*new;
	t_stack	*temp;

	new = malloc(sizeof(t_stack));
	temp = *root;
	if (!root)
		return ;
	if (!new)
		exit(1);
	new->num = node;
	new->next = NULL;
	new->prev = NULL;
	if (temp)
	{	
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
		*root = new;
}

void	print_lst(t_stack *a)
{
	while (a)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
}

void	stackclear(t_stack *a)
{
	t_stack	*temp;

	if (!a)
		return ;
	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
}
