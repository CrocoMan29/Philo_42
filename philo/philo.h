/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 05:44:30 by yismaail          #+#    #+#             */
/*   Updated: 2023/06/08 06:13:47 by yismaail         ###   ########.fr       */
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
time_t	get_time(void);
void	wait_ms(int ms);
int	ft_modulo(int a, int b);

//*---------------Routine---------------*//
void	*routine(void *arg);
void	ft_eat(t_philo *philo);
void	ft_message(t_philo *philo, bool status, char *str);
bool	close_to_death(t_philo *philo, bool use_mtx);
bool	check_stop(t_data *data);
void	force_stop(t_data *data);
bool	check_finish(t_data *data);
void	check_death(t_data *data);
void	join_thread(t_data *data);
void	destroy_mutex(t_data *data);
//*---------------Parse Data---------------*//
int	parse_data(t_data *data, int ac, char **av);
int	assign_philo(t_data *data);
int	assign_mutex(t_data *data);
int	assign_thread(t_data *data);
#endif