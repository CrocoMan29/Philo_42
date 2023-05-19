/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:09 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/19 09:21:56 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	assign_arg(t_all *all, char **av, int ac)
{
	all->a_data = malloc(sizeof(t_data));
	if (!all->a_data)
		return (1);
	all->a_data->nb_of_philo = ft_atoi(av[1]);
	all->a_data->time_of_die = ft_atoi(av[2]);
	all->a_data->time_to_eat = ft_atoi(av[3]);
	all->a_data->time_to_sleep = ft_atoi(av[4]);
	all->a_data->nb_of_time_must_eat = -1;
	all->a_data->nb_of_done_of_eat = -1;
	if (ac == 6)
	{
		all->a_data->nb_of_time_must_eat = ft_atoi(av[5]);
		all->a_data->nb_of_done_of_eat = 0;	
	}
	all->a_data->isanyonedead = 0;
	pthread_mutex_init(&all->a_data->m_print, NULL);
	return (0);
}

int	assign_fork(t_all *all)
{
	int	i;
	int	nbr_ph;
	
	i = 0;
	nbr_ph = all->a_data->nb_of_philo;
	all->a_fork = (t_fork *)malloc(sizeof(t_fork) * nbr_ph);
	if (!all->a_fork)
		return (1);
	while (i < nbr_ph)
	{
		all->a_fork->id_fork = i + 1;
		all->a_fork->gradedby = 0;
		pthread_mutex_init(&all->a_fork->m_fork, NULL);
		i++;
	}
	return (0);
}

int	assign_philo(t_all *all)
{
	int	i;
	int nbr_ph;
	
	i = 0;
	nbr_ph = all->a_data->nb_of_philo;
	all->a_philo = (t_philo *)malloc(sizeof(t_philo) * nbr_ph);
	if (!all->a_philo)
		return (1);
	while (i < nbr_ph)
	{
		memset(&all->a_philo, 0, sizeof(t_philo));
		all->a_philo[i].data = all->a_data;
	printf ("hello\n");
		all->a_philo[i].fork = all->a_fork;
		all->a_philo[i].id_thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (!all->a_philo[i].id_thread)
			return (1);
		all->a_philo[i].id = i + 1;
		i++;
	}
	return (0);
}

int	assign_control(t_all *all)
{
	all->m_th_id = (pthread_t *)malloc(sizeof(pthread_t));
	if (!all->m_th_id)
		return (1);
	return (0);
}

int	check_assign(t_all *all)
{
	if (all->a_data->nb_of_philo < 0
		|| all->a_data->nb_of_philo > 200
		|| all->a_data->time_of_die < 60
		|| all->a_data->time_to_eat < 60
		|| all->a_data->time_to_sleep < 60
		|| all->a_data->nb_of_time_must_eat < -1)
		return (1);
	return (0);
}

int	set_data(t_all *all, int ac, char **av)
{
	if (assign_arg(all, av, ac))
		return (1);
	if (assign_fork(all))
		return (1);
	if (assign_philo(all))
		return (1);
	if (assign_control(all))
		return (1);
	if (check_assign(all))
		return (1);
	return (0);
}

int	input_is_valid(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("must be 5 args or 6!!!!!!\n");
		return (1);
	}
	if ((ft_atol(av[1]) <= 0) || (ft_atol(av[1]) >= INT_MAX))
		return (1);
	if ((ft_atol(av[2]) <= 0) || (ft_atol(av[2]) >= INT_MAX))
		return (1);
	if ((ft_atol(av[3]) <= 0) || (ft_atol(av[3]) >= INT_MAX))
		return (1);
	if ((ft_atol(av[4]) <= 0) || (ft_atol(av[4]) >= INT_MAX))
		return (1);
	if (ac == 6 && ((ft_atol(av[5]) <= 0) || (ft_atol(av[5]) >= INT_MAX)))
		return (1);
	return (0);
}

void	ft_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(101);
}
