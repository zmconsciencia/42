/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:13:54 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/13 17:31:24 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_data {
	char	*path;
	int		infile_fd;
	int		outfile_fd;
	int		tempfile;
}	t_data;

void			ft_putstr_fd(char *s, int fd);
char			**ft_split(const char *s, char c);
unsigned int	ft_strlen(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**get_path(char **envp);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			parse_files(char *infile, char *outfile);
void			pipex(int f1, int f2, char *cmd1, char *cmd2);
char			*ft_strjoin(char *s1, char *s2);
void			free_array(char **arr);
char			*check_path(char *cmd, char **envp);
void			execution(char *cmd, char *cmd2, char **env);
t_data			*data(void);
void			switch_fds(char *infile, char *outfile);
char			*ft_strdup(char *s);

#endif