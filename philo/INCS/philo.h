/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:57 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/26 14:54:58 by jabecass         ###   ########.fr       */
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
# include <string.h>

typedef struct s_philo
{
	pthread_t		t1;
	int				id;
	int				status;
	int				eat_cont;
	time_t			time_to_die;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	c_time;
	pthread_mutex_t c_eat;
	struct s_philo	*next;
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
	struct s_philo	*philos;
	struct s_philo	*head;
	struct s_philo	*tail;
	pthread_mutex_t	*forks;
}					t_data;

//parse
void		parser(char **av);
void		err_handle(int status);
void		fork_init(t_data *data);
void		init(t_data *data);

//time
time_t		gettime(void);
void		my_usleep(int time_ms);

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
void		*ft_calloc(size_t nmemb, size_t size);
void		check_death(t_data *data);

#endif