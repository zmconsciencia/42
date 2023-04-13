/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/13 17:52:12 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **envp)
{
	int	i;

	i = ac - 3;
	if (ac == 5)
	{
		parse_files(av[1], av[4]);
		execution(av[2], av[3], envp);
		while (i)
		{
			waitpid(-1, NULL, 0);
			write(2, "a\n", 2);
			i--;
		}
		if (data()->tempfile)
			unlink("temp");
	}
	else
		ft_putstr_fd("Error. \n", 2);
	return (0);
}
