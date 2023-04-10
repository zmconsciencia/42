/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/10 17:43:32 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **envp)
{
	char	*string;
	char	**list;
	
	if (ac == 5)
	{
		// if (parse_files(av[1], av[4]))
		// {
		// 	get_path(envp);
		// 	pipex(open(av[1], 1), open_files(av[4], 0), av[2], av[3]);
		// }
		list = get_path(envp);
		string = check_path(&string, av[2], envp);
		printf("%s \n", string);
		free (string);
		free_array(list);
	}
	else
		ft_putstr_fd("Error. \n", 2);
	return (0);
}
