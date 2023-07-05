/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:57 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/05 14:54:18 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	int				err;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				dead;
	int				*forks;
	int				*eat_count;
	int				*last_eat;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead_mutex;
}					t_data;

//parse
void		parser(char **av);
void		err_handle(int n, int err);

//data
t_data		*data(void);

//utils
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strdup(const char *s);

#endif