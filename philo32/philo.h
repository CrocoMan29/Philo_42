/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 05:44:30 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/07 06:21:29 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<limits.h>
#include<string.h>
#include<sys/time.h>
#include<stdbool.h>

typedef long long	t_time;

struct				s_vars;

typedef struct s_philo
{
	int						id;
	bool					is_done;
	t_time					last_time_to_eat;
	pthread_t				thread;
	struct s_data			*data;
	pthread_mutex_t			mutex;
}	t_philo;

typedef struct s_data
{
	int				nb_of_philo;
	t_philo			*philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat_count;
	bool			check_death;
	bool			stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	mutex;
}	t_data;

//*---------------Tools---------------*//
void	ft_exit(void);
int		input_is_valid(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_atol(const char *str);
int		is_num(char *str);
int		ft_isdigit(int c);
long long	get_time(void);

#endif