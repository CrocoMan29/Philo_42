/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:00:54 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/04 02:25:08 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (input_is_valid(ac, av))
		return (1);
	if (set_data(data, ac, av))
		return (1);
	// printf("hello\n");
	begin_simulation(data);
	free(data->fork);
	free(data->philo);
	free(data);
	return (0);
}
