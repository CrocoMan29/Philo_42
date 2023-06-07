/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 05:53:16 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/07 06:21:18 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	i;
	int					signe;
	unsigned long long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	i = 0;
	while (ft_isdigit(str[i]) == 1)
		nbr = nbr * 10 + (str[i++] - 48);
	return (nbr * signe);
}

int		is_num(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_atol(const char *str)
{
	int	i;
	int	sign;
	long int	final;
	
	i = 0;
	sign = 1;
	final = 0;
	while ((str[i] >= 9 && str[i] <= 12) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i] == '-')
			sign = -1;
		i++;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10 + (str[i++] - 48);
	}
	if ((final * sign) < 0)
		return (-1);
	return (final);
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

long long	get_time(void)
{
	struct timeval tv;
	long long	time_ms;
	
	time_ms = 0;
	if (gettimeofday(&tv, NULL) == 0)
		time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_ms);
}