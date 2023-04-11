/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:13:54 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/11 16:27:29 by jabecass         ###   ########.fr       */
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

void			ft_putstr_fd(char *s, int fd);
char			**ft_split(const char *s, char c);
unsigned int	ft_strlen(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**get_path(char **envp);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				parse_files(char *infile, char *outfile);
void			pipex(int f1, int f2, char *cmd1, char *cmd2);
int				open_files(char *file, int flag);
char			*ft_strjoin(char *s1, char *s2);
void			free_array(char **arr);
char			*check_path(char **path, char *cmd, char **envp);
char			**divide_command(char *cmd);
void			execution(char **path, char *cmd, char **env);

#endif