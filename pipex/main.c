/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/07 11:04:19 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
	{
		if (parse_files(av[1], av[4]))
			get_path(envp);
	}
	else
		ft_putstr_fd("Error. \n", 2);
	return (0);
}
