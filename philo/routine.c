/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:45:30 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/05 05:47:29 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_status(t_data *data)
{
	pthread_mutex_lock(&data->finish);
	if (data->can_finish == 1)
	{
		pthread_mutex_unlock(&data->finish);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&data->finish);
		return (0);
	}
		
}

void	ft_message(t_philo philo, char *str)
{
	long long	s;
	
	pthread_mutex_lock(&philo.data->m_print);
	s = get_time() - philo.data->start_time;
	printf("%lld %d %s\n", s, philo.id, str);
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
		pthread_mutex_lock(&philo->check_death);
		ft_message(*philo, "is eating");
		philo->last_meal_to_eat = get_time();
		philo->nb_of_meal++;
		pthread_mutex_unlock(&philo->check_death);
	}
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->right_f);
	pthread_mutex_unlock(&philo->left_f);
}

void	pick_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->right_f);
		if (!check_status(philo->data))
			ft_message(*philo, "taking a fork");
		pthread_mutex_lock((&philo->left_f));
		if (!check_status(philo->data))
			ft_message(*philo, "taking a fork");
		return ;
	}else
	{
	pthread_mutex_lock(&philo->left_f);
	if (!check_status(philo->data))
		ft_message(*philo, "taking a fork");
	pthread_mutex_lock(&philo->right_f);
	if (!check_status(philo->data))
		ft_message(*philo, "taking a fork");
	}
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_of_philo == 1)
	{
		pthread_mutex_lock(&philo->left_f);
		ft_message(*philo, "take a fork");
		pthread_mutex_unlock(&philo->left_f);
		return ((void *)philo);
	}
	while(!check_status(philo->data))
	{
		if (check_status(philo->data))
			break;
		pick_fork(philo);
		ft_eat(philo);
		if (check_status(philo->data))
			break;
		ft_sleep(philo);
		if (check_status(philo->data))
			break;
		ft_message(*philo, "is think");
	}
	return ((void *)philo);
}