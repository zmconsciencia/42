/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:23:36 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/10 18:37:07 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	open_files(char *file, int flag)
{
	int	f;

	f = 0;
	if (flag)
		f = open(file, O_RDONLY);
	else
		f = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (f);
}

int	parse_files(char *infile, char *outfile)
{
	int	f1;
	int	f2;

	f1 = open(infile, O_RDONLY);
	f2 = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	return (1);
}

char	**get_path(char **envp)
{
	char	*path;
	char	**spath;
	int		j;

	j = 0;
	path = NULL;
	spath = NULL;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			path = envp[j] + 5;
			break ;
		}
		j++;
	}
	spath = ft_split(path, ':');
	return (spath);
}
