/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:50:45 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/17 14:49:59 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void add_node(t_stack** root, int node)
{
	t_stack* new = malloc(sizeof(t_stack));
	if (new == NULL){
		exit(1);
	}
	printf("finderror1\n");
	new->next = NULL;
	new->num = node;
	
	t_stack* curr = *root;
	printf("finderror2\n");
	while(curr)
	{
		
		curr = curr->next;
		printf("finderror3\n");
	}
	curr->next = new;
}

void	print_lst(t_stack *a)
{
	while (a)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
}

int main(int ac, char **av)
{
	t_stack* stack_a = 0;
	if (ac > 1)
	{
		while(++av && av)
		{
			add_node(&stack_a, atoi(*av));
		}
	}
}