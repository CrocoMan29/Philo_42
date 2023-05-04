/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:09 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/04 02:08:42 by yismaail         ###   ########.fr       */
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

void	input_is_valid(char **av)
{
	t_help	arg;
	int count = 0;
	
	arg.i = 0;
	while(av[++arg.i])
	{
		if (ft_isempty(av[arg.i]) == 1)
			ft_exit();
		if (ft_split(av[arg.i]) == 1)	
		count++;
	}
	printf("--> %d\n", count);
}

void	ft_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(101);
}
