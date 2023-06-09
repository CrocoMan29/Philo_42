/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:52:58 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/09 06:22:05 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_stop(t_data *data)
{
	bool	stop;

	pthread_mutex_lock(&data->mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->mutex);
	return (stop);
}

bool	close_to_death(t_philo *philo, bool use_mtx)
{
	int	time;

	if (use_mtx)
		pthread_mutex_lock(&philo->mutex);
	time = get_time() - philo->last_time_to_eat;
	if (use_mtx)
		pthread_mutex_unlock(&philo->mutex);
	if (time > philo->data->time_to_die)
		return (true);
	return (false);
}

void	ft_message(t_philo *philo, bool status, char *str)
{
	long long	time;

	if (!status && close_to_death(philo, false))
		return ;
	pthread_mutex_lock(&philo->data->m_print);
	time = get_time() - philo->data->init_time;
	if (!check_stop(philo->data))
		printf("%lld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[ft_modulo((philo->id - 1),
			philo->data->nb_of_philo)]);
	ft_message(philo, false, "take a fork R");
	pthread_mutex_lock(&philo->data->forks[ft_modulo((philo->id - 2),
			philo->data->nb_of_philo)]);
	ft_message(philo, false, "take a fork L");
	ft_message(philo, false, "is eating");
	pthread_mutex_lock(&philo->mutex);
	philo->last_time_to_eat = get_time();
	pthread_mutex_unlock(&philo->mutex);
	wait_ms(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[ft_modulo((philo->id - 2),
			philo->data->nb_of_philo)]);
	pthread_mutex_unlock(&philo->data->forks[ft_modulo((philo->id - 1),
			philo->data->nb_of_philo)]);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		count_eat;

	philo = (t_philo *)arg;
	count_eat = 0;
	if (philo->id % 2 == 0)
		usleep((philo->data->time_to_eat / 2) * 1000);
	while (!check_stop(philo->data))
	{
		ft_eat(philo);
		count_eat++;
		if (!philo->data->check_death
			&& count_eat >= philo->data->max_eat_count)
		{
			pthread_mutex_lock(&philo->mutex);
			philo->is_done = true;
			pthread_mutex_unlock(&philo->mutex);
			return (NULL);
		}
		ft_message(philo, false, "is sleeping");
		wait_ms(philo->data->time_to_sleep);
		ft_message(philo, false, "is thinking");
	}
	return (NULL);
}
