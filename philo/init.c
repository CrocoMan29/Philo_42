/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 06:09:25 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/09 06:19:34 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_data(t_data *data, int ac, char **av)
{
	if (input_is_valid(ac, av))
		return (1);
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->check_death = false;
		data->max_eat_count = ft_atoi(av[5]);
	}
	else
	{
		data->check_death = true;
		data->max_eat_count = 0;
	}
	if (data->nb_of_philo < 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		ft_exit();
	return (0);
}

int	assign_philo(t_data *data)
{
	int	i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!data->philo)
		return (0);
	i = 0;
	while (i < data->nb_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].thread = NULL;
		data->philo[i].is_done = false;
		data->philo[i].data = data;
		data->philo[i].last_time_to_eat = get_time();
		if (pthread_mutex_init(&(data->philo[i].mutex), NULL))
			return (0);
		i++;
	}
	return (1);
}

int	assign_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&(data->m_print), NULL))
		return (0);
	if (pthread_mutex_init(&(data->mutex), NULL))
		return (0);
	return (1);
}

int	assign_thread(t_data *data)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	data->stop = false;
	data->init_time = get_time();
	while (i < data->nb_of_philo)
	{
		thread = &data->philo[i].thread;
		if (pthread_create(thread, NULL, routine, &data->philo[i]))
			return (0);
		i++;
	}
	return (1);
}

void	force_stop(t_data *data)
{
	pthread_mutex_lock(&data->mutex);
	data->stop = true;
	pthread_mutex_unlock(&data->mutex);
}
