/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:49:41 by jabecass          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/26 19:32:16 by jabecass         ###   ########.fr       */
=======
/*   Updated: 2022/11/23 12:37:47 by jabecass         ###   ########.fr       */
>>>>>>> 510217048a05f6ebde0cb1f5a8cf2ff2109a8b5e
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		clearstack(char *stack);

#endif