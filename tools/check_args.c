/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:09 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/09 06:41:01 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

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

int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	if (ft_isspace(str) == 1)
		return (1);
	return (0);
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
			printf ("hello al ikhwan\n");
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
