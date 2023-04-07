/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:34:50 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/07 13:45:26 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	// if (!parent)
	// 	child_process(f1, cmd1);
	// else
	// 	parent_process(f2, cmd2);
}