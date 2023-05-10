/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:00:54 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/10 04:57:01 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	num = 0;

void*	affiche(void)
{
	for(int i = 0; i < 100000; i++)
	{
		num++;
	}
	// printf("ahlaan");
	return (NULL);
}

int	main(int ac, char **av)
{
	t_table		*arg;
	if (input_is_valid(ac, av))
	{
		return (0);
	}
	assign_arg(arg, av, ac);
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
