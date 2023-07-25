/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/25 18:51:28 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	print_error(int n)
{
	if (n == 0)
	{
		ft_putstr_fd("Usage: ./philo [number_of_philo] [time_to_die]", 2);
		ft_putstr_fd(" [time_to_eat] [time_to_sleep]", 2);
		ft_putstr_fd(" [number_of_times_each_philosopher_must_eat]\n", 2);
	}
}

void	print_program(void)
{
	printf("nb_philo: %d\n", data()->nb_philo);
	printf("time_to_die: %d\n", data()->time_to_die);
	printf("time_to_eat: %d\n", data()->time_to_eat);
	printf("time_to_sleep: %d\n", data()->time_to_sleep);
	if (data()->nb_eat)
		printf("nb_eat: %d\n", data()->nb_eat);
}

int	gettime(void)
{
	struct timeval	tv;
	int				time;

	time = 0;
	if (!gettimeofday(&tv, NULL))
	{
		time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		time = time - data()->start_time;
	}
	return (time);
}

void	pickforks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf("%d philo %d takes fork.\n", gettime(), philo->id);
	pthread_mutex_lock(philo->l_fork);
	printf("%d philo %d takes fork.\n", gettime(), philo->id);
}

void	*routine(void *philos_pointer)
{
	int				i;
	t_philo			*philo;

	philo = (t_philo *) philos_pointer;
	i = -1;
	while (++i < data()->nb_eat)
	{
		pickforks(philo);
		usleep(data()->time_to_eat * 1000);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		usleep(data()->time_to_sleep * 1000);
		printf("%d philo %d is thinking.\n", gettime(), philo->id);
	}
	return (0);
}

int	philo_to_thread(t_data *data)
{
	int		i;

	i = 0;
	data->tid = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->tid)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (0);
	fork_init(data);
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, data->philos))
			return (1);
		usleep(1);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->tid[i], NULL))
			return (2);
	}
	return (0);
}

void	fork_init(t_data *data)
{
	int	i;

	i = -1;
	while (i++ < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->nb_philo - 1];
	i = 0;
	while (++i < data->nb_philo)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[data->nb_philo - 1];
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	data()->start_time = gettime();
	if (ac == 5)
	{
		parser(av);
		philo_to_thread(data());
	}
	else if (ac == 6)
	{
		parser(av);
		philo_to_thread(data());
	}
	else
		print_error(0);
}
