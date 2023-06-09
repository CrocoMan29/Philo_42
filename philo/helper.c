/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:18:03 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/09 06:16:16 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isempty(char *str)
{
	if (ft_isspace(str) == 1)
		return (1);
	return (0);
}

int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	is_valide(char **av)
{
	int		i;
	int		nb_zero;

	i = 0;
	nb_zero = 0;
	while (av[++i])
	{
		if (ft_isempty(av[i]) == 1)
			ft_exit();
		if (is_number(av[i]) == 0)
			ft_exit();
	}
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (ft_issigne(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

void	ft_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(101);
}
