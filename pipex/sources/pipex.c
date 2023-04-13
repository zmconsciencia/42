/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:34:50 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/13 17:53:32 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

char	*check_path(char *cmd, char **envp)
{
	int		i;
	char	*real_path;
	char	**scmd;
	char	**path;

	i = 0;
	scmd = ft_split(cmd, ' ');
	path = get_path(envp);
	while (path[i])
	{
		real_path = ft_strjoin(path[i], scmd[0]);
		if (access(real_path, F_OK) == 0)
		{
			free_array(path);
			free_array (scmd);
			return (real_path);
		}
		free (real_path);
		i++;
	}
	free_array(path);
	free_array (scmd);
	return (ft_strdup(cmd));
}

void	execution(char *cmd, char *cmd2, char **env)
{
	char	**command;
	char	*pathname;
	int		fd;
	int		pipe_fds[2];

	pathname = check_path(cmd, env);
	command = ft_split(cmd, ' ');
	if (pipe(pipe_fds) == -1)
		perror("");
	fd = fork();
	if (fd == -1)
		perror("");
	if (fd == 0)
	{
		printf("%s \n", pathname);
		dup2(data()->infile_fd, 0);
		dup2(pipe_fds[1], 1);
		close((data())->infile_fd);
		close((data())->outfile_fd);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		execve(pathname, command, env);
		free (pathname);
		free_array (command);
		exit(1);
	}
	free_array (command);
	free (pathname);
	pathname = check_path(cmd2, env);
	command = ft_split(cmd2, ' ');
	fd = fork();
	if (fd == 0)
	{
		printf("%s \n", pathname);
		dup2(pipe_fds[0], 0);
		dup2((data())->outfile_fd, 1);
		close((data())->infile_fd);
		close((data())->outfile_fd);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		execve(pathname, command, env);
		free (pathname);
		free_array (command);
		exit(1);
	}
	close((data())->infile_fd);
	close((data())->outfile_fd);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	free_array (command);
	free (pathname);
}
