/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:57:13 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/06 17:15:29 by jabecass         ###   ########.fr       */
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
# include <stdarg.h>

typedef struct s_list
{
	int				num;
	struct s_list	*prev;
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
void		swap(t_stack *a, t_stack *b, char c);
void		push(t_stack **src, t_stack **dst, char c);
void		rotate(t_stack **a, t_stack **b, char c);
void		reverse_rotate(t_stack **a, t_stack **b, char c);
int			issorted(t_stack *a);
void		sort3(t_stack **stack_a, t_stack **stack_b);
void		sort2(t_stack **stack_a, t_stack **stack_b);
void		keep3(t_stack **stack_a, t_stack **stack_b);
int			lstsize(t_stack *a);
t_stack		*best_neighbour(t_stack **stacka, t_stack **stackb);
t_stack		*lmax(t_stack *a);
t_stack		*lmin(t_stack **a);
int			bn_cost(t_stack **stacka, t_stack **curr);
t_stack		*least_cost(t_stack **stacka, t_stack **stackb);
void		bst_to_top(t_stack **a, t_stack **b, t_stack *best, char c);
void		sort_general(t_stack **stacka, t_stack **stackb);
void		run_it(t_stack	**stack_a, t_stack **stack_b);
long int	yo(t_stack *a);
int			media(t_stack *a);

//printf
int			ft_printf(const char *c, ...);
size_t		conversions(va_list args, char c);
int			ft_int_putchar(char c);
int			ft_int_putstr(char *s);
int			ft_int_putnbr(int n);
size_t		countdigits(long int n);
int			int_percent(char c);
int			int_putnbr(long int a);
size_t		ft_puthexa(unsigned long n, int base);
size_t		ft_size_hex(long unsigned int n);
size_t		ft_print_p(unsigned long int p);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *str);

#endif