/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:00:54 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/26 11:29:02 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	num = 0;

void*	affiche(void)
{
	int n = 10;
	int *tty;
	tty = malloc(sizeof(int));
	*tty = n;
	for(int i = 0; i < 100000; i++)
	{
		num++;
	}
	// printf("ahlaan");
	return ((void *)tty);
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (input_is_valid(ac, av))
		return (1);
	if (set_data(data, ac, av))
		return (1);
	begin_simulation(data);
	return (0);
	
	// system("leaks philo");
	// while (1);
	// system("leaks philo");
	// pthread_create(&p1, NULL, affiche, NULL);
	// // printf("==> %d\n", num);
	// pthread_create(&p2, NULL, affiche, NULL);
	// pthread_join(p1, NULL);
	// pthread_join(p2, NULL);
	// printf("==> %d\n", num);
}
