/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:00:54 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/19 09:19:44 by yismaail         ###   ########.fr       */
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
	{
		// printf ("%d\n", ac);
		return (1);
	}
	if (set_data(&all, ac, av))
	{
	printf("======================\n");
		
			// printf("********************************************************************\n");
			// if (all.a_data)
			// {
			// 	printf("               DATA                \n");
			// 	printf("nb_of_philo = %d\n", all.a_data->nb_of_philo);
			// 	printf("time_of_die = %lu\n", all.a_data->time_of_die);
			// 	printf("time_to_eat = %lu\n", all.a_data->time_to_eat);
			// 	printf("time_to_sleep = %lu\n", all.a_data->time_to_sleep);
			// 	printf("start_time = %lu\n", all.a_data->start_time);
			// 	printf("nb_of_time_must_eat = %d\n", all.a_data->nb_of_time_must_eat);
			// 	printf("nb_of_done_of_eat = %d\n", all.a_data->nb_of_done_of_eat);
			// 	printf("isanyonedead = %d\n", all.a_data->isanyonedead);
			// }
			// printf("********************************************************************\n");
			// if (all.a_fork)
			// {
			// 	printf("               FORK                \n");
			// 	for (size_t i = 0; i < all.a_data->nb_of_philo; i++)
			// 	{
			// 		printf("id_fork = %d\n", all.a_fork[i].id_fork);
			// 		printf("gradedby = %d\n", all.a_fork[i].gradedby);
			// 	}
			// }
			// printf("********************************************************************\n");
			// if (all.a_philo)
			// {
			// 	printf("               FORK                \n");
				
			// }
	}
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
