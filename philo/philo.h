/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:01:22 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/10 04:54:53 by yismaail         ###   ########.fr       */
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

typedef struct s_philo
{
	int		nb_of_philo;
	int		time_of_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_of_time_must_eat;
	
}			t_philo;


typedef struct s_table
{
	t_philo		*philosopher;
	int			forks;
}				t_table;


//*---------------Tools---------------*//
void	ft_exit(void);
int		input_is_valid(int ac, char **av);
int	ft_atoi(const char *str);
int		is_num(char *str);
int	ft_isdigit(int c);

#endif
