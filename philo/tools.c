/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 05:53:16 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/09 06:22:23 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	i;
	int			signe;
	long long	nbr;

	signe = 1;
	nbr = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
		nbr = nbr * 10 + (str[i++] - 48);
	return (nbr * signe);
}

int	input_is_valid(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("must be 5 args or 6!!!!!!\n");
		return (1);
	}
	is_valide(av);
	return (0);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		time_ms;

	time_ms = 0;
	if (gettimeofday(&tv, NULL) == 0)
		time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_ms);
}

void	wait_ms(int ms)
{
	t_time	start_time;

	start_time = get_time();
	usleep(ms * 1000 * 0.9);
	while (get_time() - start_time < ms)
		usleep(30);
}

int	ft_modulo(int a, int b)
{
	while (a < 0)
		a += b;
	return (a % b);
}
