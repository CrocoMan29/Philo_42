/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:24:46 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/26 18:32:56 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	begin_simulation(t_data *data)
{
	int		i;

	pthread_mutex_init(&data->m_print, NULL);
	while (i < data->nb_of_philo)
	{
		data->start_time = get_time();
		pthread_create(&data->philo[i].id_thread, NULL, &routine, &data->philo[i]);
		if (i % 2 == 0)
			usleep(1000);
		i++:
	}
	
}
