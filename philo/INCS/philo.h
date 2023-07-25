/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:57 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/25 18:43:26 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		t1;
	int				id;
	int				status;
	int				eat_cont;
	int				eating;
	int				time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}		t_philo;

typedef struct s_data
{
	time_t			start_time;
	int				err;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				dead;
	int				*eat_count;
	int				*last_eat;
	pthread_t		*tid;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead_mutex;
}					t_data;

//parse
void		parser(char **av);
void		err_handle(int status);
void		fork_init(t_data *data);

//data
t_data		*data(void);

//utils
int			ft_atoi(const char *str, int *e);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strdup(const char *s);

#endif