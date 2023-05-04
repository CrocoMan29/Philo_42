/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:01:22 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/04 02:06:04 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define BLUE "\e[1;36m"
# define GREEN "\e[0;92m"
# define RED "\e[0;31m"
# define RESET "\e[0m"

typedef struct s_help
{
	int	i;
	int	j;
}		t_help;

//*---------------Tools---------------*//
void	ft_exit(void);
void	input_is_valid(char **av);
int		ft_isempty(char *str);
int		ft_isspace(char *str);

#endif
