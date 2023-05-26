/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:45:30 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/26 19:03:27 by yismaail         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(check_status(philo->data))
	{
		pick_fork(philo);
		ft_eat(philo);
		ft_think(philo);
		ft_sleep(philo);
	}
	return ((void *)philo);
}