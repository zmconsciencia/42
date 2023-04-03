/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/03 13:51:17 by jabecass         ###   ########.fr       */
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
			if (i == 1)
				printf("%d \n", parse_infile(av[i]));
			else if (i == 4)
				printf("%d \n", parse_outfile(av[i]));
		}
	}
	printf("Invalid number of arguments. \n");
}
