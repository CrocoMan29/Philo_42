/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:09 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/14 23:43:45 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	assign_arg( *arg, char **av, int ac)
{
	
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
