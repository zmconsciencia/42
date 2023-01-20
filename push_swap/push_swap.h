/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:57:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/20 15:51:47 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_stack;

char		**ft_split(const char *s, char c);
long int	ft_atoi(const char *str);
void		print_lst(t_stack *a);
void		add_node(t_stack **root, int node);
void		stackclear(t_stack *a);
void		checkerrors(char **tab, t_stack **a);
int			ft_isdigit(char *str);
void		error_handle(char **tab, t_stack **a);
int			ft_checkdoubles(t_stack *a, long int temp);



#endif