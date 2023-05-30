/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:45:30 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/30 02:34:47 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_status(t_data *data)
{
	pthread_mutex_lock(data->finish);
	if (data->can_finish == 1)
	{
		pthread_mutex_unlock(data->finish);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(data->finish);
		return (0);
	}
		
}

void	ft_message(t_philo philo, char *str)
{
	long long	s;
	
	pthread_mutex_lock(&philo.data->m_print);
	s = get_time() - philo.data->start_time;
	printf("%lld %s %d", s, str, philo.id);
	pthread_mutex_unlock(&philo.data->m_print);
}

void	ft_sleep(t_philo *philo)
{
	ft_message(*philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	if (!check_status(philo->data))
	{
		pthread_mutex_lock(philo->check_death);
		ft_message(*philo, "is eating");
		philo->last_meal_to_eat = get_time();
		philo->nb_of_meal++;
		pthread_mutex_unlock(philo->check_death);
	}
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	pick_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_f);
		if (!check_status(philo->data))
			ft_message(*philo, "taking a fork");
		pthread_mutex_lock(&philo->right_f);
		if (!check_status(philo->data))
			ft_message(*philo, "taking a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right_f);
		if (!check_status(philo->data))
			ft_message(*philo, "taking a fork");
		pthread_mutex_lock((&philo->left_f));
		if (!check_status(philo->data))
			ft_message(*philo, "taking a fork");
	}
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(check_status(philo->data))
	{
		pick_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return ((void *)philo);
}