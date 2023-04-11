/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:34:50 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/11 16:55:13 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	pipex(int f1, int f2, char *cmd1, char *cmd2)
// {
// 	int		end[2];
// 	pid_t	parent;

// 	(void)f1;
// 	(void)f2;
// 	(void)cmd1;
// 	(void)cmd2;
// 	pipe(end);
// 	parent = fork();
// 	printf("%d \n", parent);
// 	if (parent < 0)
// 		return (perror("Fork: "));
// 	// if (!parent)
// 	// 	child_process(f1, cmd1);
// 	// else
// 	// 	parent_process(f2, cmd2);
// }

char	*check_path(char **path, char *cmd, char **envp)
{
	int		i;
	char	*real_path;
	char	**scmd;

	i = 0;
	scmd = divide_command(cmd);
	cmd = scmd[0];
	path = get_path(envp);
	while (path[i])
	{
		real_path = ft_strjoin(path[i], cmd);
		if (access(real_path, F_OK) == 0)
		{
			free_array(path);
			return (real_path);
		}
		free (real_path);
		i++;
	}
	free_array(path);
	return (cmd);
}

char	**divide_command(char *cmd)
{
	char	**c;

	c = ft_split(cmd, ' ');
	return (c);
}

void	execution(char **path, char *cmd, char **env)
{
	char	**command;
	char	*pathname;

	pathname = check_path(path, cmd, env);
	command = divide_command(cmd);
	execve(pathname, command, env);
}
