/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:09 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/16 01:02:11 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	assign_arg(t_all *all, char **av, int ac)
{
	all->a_data = malloc(sizeof(t_data));
	if (!all->a_data)
		return (0);
	all->a_data->nb_of_philo = ft_atoi(av[1]);
	all->a_data->time_of_die = ft_atoi(av[2]);
	all->a_data->time_to_eat = ft_atoi(av[3]);
	all->a_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		all->a_data->nb_of_time_must_eat = ft_atoi(av[5]);
}

int	set_data(t_all *all, int ac, char **av)
{
	if (assign_arg(all, av, ac))
}

int	input_is_valid(int ac, char **av)
{
	if (ac != 5 || ac != 6)
	{
		printf("must be 5 args or 6!!!!!!\n");
		return (1);
	}
	if (ft_atol(av[1]) <= INT_MAX)
		return (1);
	if (ft_atol(av[2]) <= INT_MAX)
		return (1);
	if (ft_atol(av[3]) <= INT_MAX)
		return (1);
	if (ft_atol(av[4]) <= INT_MAX)
		return (1);
	if (ac == 6 && ft_atol(av[5]) <= INT_MAX)
		return (1);
	return (0);
}

void	ft_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(101);
}
