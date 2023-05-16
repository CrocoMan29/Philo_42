/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:00:54 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/16 00:39:03 by yismaail         ###   ########.fr       */
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
	// pthread_t t1;
	// int *n1;
	// if (pthread_create(&t1, NULL, &affiche, NULL) != 0)
	// 	return (0);
	// if (pthread_join(t1, (void **)&n1) != 0)
	// 	return (1);
	// 	printf ("====> %d\n", *n1);
	t_all		all;
	if (input_is_valid(ac, av))
		return (0);
	if (set_data(&all, ac, av))
	
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
