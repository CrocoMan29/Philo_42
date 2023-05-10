/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:09 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/10 04:57:49 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	assign_arg(t_table *arg, char **av, int ac)
{
	arg->philosopher = malloc(sizeof(t_philo));
	if (!arg->philosopher)
		return ;
	arg->philosopher->nb_of_philo = ft_atoi(av[1]);
	arg->philosopher->time_of_die = ft_atoi(av[2]);
	arg->philosopher->time_to_eat = ft_atoi(av[3]);
	arg->philosopher->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		arg->philosopher->nb_of_time_must_eat = ft_atoi(av[5]);
}

int	input_is_valid(int ac, char **av)
{
	size_t	i;

	if (ac < 5 || ac > 6)
	{
		printf("must be 5 args or 6!!!!!!\n");
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (!is_num(av[i]) || !ft_atoi(av[i]))
		{
			printf ("error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(101);
}
