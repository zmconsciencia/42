/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/11 16:28:12 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **envp)
{
	char	**list;

	if (ac == 5)
	{
		list = get_path(envp);
		execution(list, av[2], envp);
		free_array(list);
	}
	else
		ft_putstr_fd("Error. \n", 2);
	return (0);
}
