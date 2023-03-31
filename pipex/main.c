/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/31 14:33:04 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac == 5)
	{	
		while (++i < ac)
		{
			if (i == 1 || i == 4)
				printf("Files: %s \n", av[i]);
			else
				printf("Commands: %s \n", av[i]);
		}
	}
	printf("Invalid number of arguments. \n");
}
