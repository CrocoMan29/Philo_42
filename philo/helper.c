/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:05:08 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/14 23:41:45 by yismaail         ###   ########.fr       */
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
	while (ft_isdigit(str[i]))
	{
		final = final * 10 + str[i] - '0';
		i++;
	}
	if ((final * sign) < 0)
		return (-1);
	return (final);
}
