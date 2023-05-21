/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:09 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/21 11:58:53 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_philo	*assign_philo(t_data **data)
{
	t_philo	*philo;
	int		i;
	int		nb_philo;

	i = 0;
	nb_philo = (*data)->nb_of_philo;
	philo = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		retrun (NULL);
	while (i < nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].
	}
}

pthread_mutex_t		*assign_fork(int nb_of_philo)
{
	pthread_mutex_t *mutex;
	int				i;
	
	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * nb_of_philo);
	if (!mutex)
		return (NULL);
	while (i < nb_of_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

int	set_data(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_of_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_of_time_must_eat = ft_atoi(av[5]);
	else
		data->nb_of_time_must_eat = -1;
	data->can_finish = 0;
	data->fork = assign_fork(data->nb_of_philo);
	data->philo = assign_philo(&data);
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
