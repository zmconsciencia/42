/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:55:14 by jabecass          #+#    #+#             */
/*   Updated: 2023/04/14 15:59:23 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_close(int *pipe_fds)
{
	close((data())->infile_fd);
	close((data())->outfile_fd);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}
