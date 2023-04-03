/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:23:36 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/03 15:19:19 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parse_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error \n", 2);
		exit(1);
	}
	return (fd);
}

int	parse_outfile(char *outfile)
{
	int	fd;

	fd = open(outfile, O_RDONLY);
	if (fd == -1)
		fd = open(outfile, O_CREAT);
	return (fd);
}
