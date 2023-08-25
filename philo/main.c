/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:23:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/08/24 16:24:30 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	pickforks(t_philo *philo)
{
	if (philo->id < data()->nb_philo)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&philo->dead_mutex);
		if (!philo->status)
			printf("%ld %d has taken a fork\n", gettime(), philo->id);
		pthread_mutex_unlock(&philo->dead_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->dead_mutex);
		if (!philo->status)
			printf("%ld %d has taken a fork\n", gettime(), philo->id);
		pthread_mutex_unlock(&philo->dead_mutex);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->c_time);
	philo->time_to_die = gettime() + data()->time_to_die;
	pthread_mutex_unlock(&philo->c_time);
	if (philo->id % 2 == 0)
		my_usleep(200);
	while (!philo->status)
	{
		pickforks(philo);
		pthread_mutex_lock(&philo->dead_mutex);
		if (!philo->status)
			printf("%ld %d is eating\n", gettime(), philo->id);
		philo->time_to_die = gettime() + data()->time_to_die;
		pthread_mutex_unlock(&philo->dead_mutex);
		my_usleep(data()->time_to_eat);
		pthread_mutex_lock(&philo->c_eat);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->c_eat);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_lock(&philo->dead_mutex);
		if (!philo->status)
		{
			printf("%ld %d is sleeping\n", gettime(), philo->id);
			my_usleep(data()->time_to_sleep);
			printf("%ld %d is thinking\n", gettime(), philo->id);
		}
		pthread_mutex_unlock(&philo->dead_mutex);
	}
	return (NULL);
}

void	unalive_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{
		pthread_mutex_lock(&philo->dead_mutex);
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{
		philo->status = 1;
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{
		pthread_mutex_unlock(&philo->dead_mutex);
		philo = philo->next;
	}
}

void	check_death(t_data *data)
{
	int		reps;
	t_philo	*philo;

	philo = data->head;
	reps = 0;
	while (philo != NULL)
	{
		pthread_mutex_lock(&philo->c_time);
		if (philo->time_to_die && philo->time_to_die < gettime())
		{
			unalive_philo(data);
			printf("%ld %d died\n", gettime(), philo->id);
			pthread_mutex_unlock(&philo->c_time);
			return ;
		}
		pthread_mutex_unlock(&philo->c_time);
		pthread_mutex_lock(&philo->c_eat);
		if (philo->eat_count == data->nb_eat - 1)
			reps++;
		pthread_mutex_unlock(&philo->c_eat);
		philo = philo->next;
	}
	if (reps == data->nb_philo)
		unalive_philo(data);
}

int	philo_to_thread(t_data *data)
{
	t_philo	*philo;

	philo = data->head;
	while (philo != NULL)
	{
		pthread_create(&philo->t1, NULL, &routine, philo);
		philo = philo->next;
	}
	philo = data->head;
	usleep(50);
	while (!data->head->status)
		check_death(data);
	while (philo != NULL)
	{
		pthread_join(philo->t1, NULL);
		philo = philo->next;
	}
	philo = data->head;
	while (philo != NULL)
	{	
		data->head = philo->next;
		pthread_mutex_destroy(&philo->c_time);
		pthread_mutex_destroy(&philo->dead_mutex);
		pthread_mutex_destroy(philo->l_fork);
		pthread_mutex_destroy(philo->r_fork);
		free(philo); 
		philo = data->head;
	}
	pthread_mutex_destroy(data->forks);
	free(data->forks);
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = data()->head;
	data()->start_time = gettime();
	if (ac == 5 || ac == 6)
	{
		if (parser(av))
		{
			if (!data()->err)
			{
				init(data());
				while (philo != NULL)
				{
					pthread_mutex_init(&philo->c_time, NULL);
					pthread_mutex_init(&philo->dead_mutex, NULL);
					philo = philo->next;
				}
				philo_to_thread(data());
			}
			else
				printf("ERROR.\n");
		}
	}
	else
		printf("ERROR.\n");
}
