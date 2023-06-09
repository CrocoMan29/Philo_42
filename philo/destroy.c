/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 06:11:38 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/09 06:18:35 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_finish(t_data *data)
{
	int		i;
	bool	is_done;

	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_mutex_lock(&data->philo[i].mutex);
		is_done = data->philo[i].is_done;
		pthread_mutex_unlock(&data->philo[i].mutex);
		if (!is_done)
			return (false);
		i++;
	}
	return (true);
}

void	check_death(t_data *data)
{
	int	i;

	while (true)
	{
		i = 0;
		while (i < data->nb_of_philo)
		{
			if (close_to_death(&data->philo[i], true))
			{
				ft_message(&data->philo[i], true, "is died");
				force_stop(data);
				return ;
			}
			i++;
		}
		if (!data->check_death && check_finish(data))
		{
			force_stop(data);
			return ;
		}
	}
}

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int	ft_issigne(int c)
{
	return (c == '+' || c == '-');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
