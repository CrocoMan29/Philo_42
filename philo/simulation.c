/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:24:46 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/30 05:54:35 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*monitor_loop(t_data *data, int *i)
{
	long long	curr_time;
	int			nbr_of_meal;
	int			j;

	j =  -1;
	while(j++ < data->nb_of_philo)
	{
		pthread_mutex_lock(&data->philo[j].check_death);
		nbr_of_meal = data->philo[j].nb_of_meal;
		if (data->nb_of_time_must_eat != -1 && nbr_of_meal >= data->nb_of_time_must_eat)
			(*i)++;
		curr_time = get_time();
		if (curr_time - data->philo[j].last_meal_to_eat > data->time_of_die)
		{
			pthread_mutex_lock(&data->finish);
			data->can_finish = 1;
			pthread_mutex_unlock(&data->finish);
			pthread_mutex_unlock(&data->philo[j].check_death);
			return (&data->philo[j]);
		}
		pthread_mutex_unlock(&data->philo[j].check_death);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int		i;
	
	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		philo = monitor_loop(data, &i);
		if (philo)
			return (philo);
		if (i == data->nb_of_philo)
		{
			pthread_mutex_lock(&data->finish);
			data->can_finish = 1;
			pthread_mutex_unlock(&data->finish);
			return (NULL);
		}
	}
}

void	begin_simulation(t_data *data)
{
	int		i;
	pthread_t	th_monitor;
	void	*res;

	pthread_mutex_init(&data->m_print, NULL);
	data->start_time = get_time();
	i = -1;
	while (i++ < data->nb_of_philo)
	{
		data->start_time = get_time();
		pthread_create(&data->philo[i].id_thread, NULL, &routine, &data->philo[i]);
		if (i % 2 == 0)
			usleep(1000);
	}
	pthread_create(&th_monitor, NULL, monitor, data);
	pthread_join(th_monitor, res);
	if (res)
		ft_message(*(t_philo *)res, "hi is dead");
	i = -1;
	while (i++ < data->nb_of_philo)
		pthread_join(data->philo[i].id_thread, NULL);
	i = 0;
	while(i++ <= data->nb_of_philo)
	{
		pthread_mutex_destroy(&data->philo[i].check_death);
		pthread_mutex_destroy(&data->fork[i]);
	}
	pthread_mutex_destroy(&data->m_print);
}
