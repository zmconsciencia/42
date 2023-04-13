/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:23:36 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/13 17:22:07 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_files(char *infile, char *outfile)
{
	(data())->infile_fd = open(infile, O_RDONLY);
	(data())->outfile_fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if ((data())->infile_fd == -1)
	{
		perror(infile);
		(data())->infile_fd = open("temp", O_CREAT, 0644);
		(data())->tempfile++;
	}
	if ((data())->outfile_fd == -1)
		perror(outfile);
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

// void	switch_fds(char *infile, char *outfile)
// {
// 	int	arr[2];

// 	pipe(arr);
// 	dup2(data()->infile_fd, 0);
// 	dup2(data()->outfile_fd, 1);
// }
