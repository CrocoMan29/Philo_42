/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 05:55:46 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/09 06:19:43 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_data(&data, ac, av))
		return (2);
	if (!assign_philo(&data))
		return (1);
	if (!assign_mutex(&data))
		return (1);
	if (!assign_thread(&data))
		return (1);
	check_death(&data);
	join_thread(&data);
	return (0);
}
