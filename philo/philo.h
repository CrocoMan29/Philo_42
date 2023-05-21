/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:01:22 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/21 11:43:23 by yismaail         ###   ########.fr       */
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

#define BLUE "\e[1;36m"
# define GREEN "\e[0;92m"
# define RED "\e[0;31m"
# define RESET "\e[0m"


// typedef enum s_state
// {
// 	EAT,
// 	SLEEP,
// 	THINK,
// 	FORK,
// 	DIE,
// 	END,
// }	t_state;

typedef struct s_data
{
	
	int				nb_of_philo;
	int				time_of_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		start_time;
	int				nb_of_time_must_eat;
	int				can_finish;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*fork;
	pthread_mutex_t finish;
	t_philo			*philo;
}			t_data;

typedef struct s_philo
{
	int				id;
	int				nb_of_meal;
	t_data			*data;
	pthread_t		*id_thread;
	pthread_mutex_t	left_f;
	pthread_mutex_t	right_f;
	pthread_mutex_t check_death;
	long long		last_meal_to_eat;
}				t_philo;


//*---------------Tools---------------*//
void	ft_exit(void);
int		input_is_valid(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_atol(const char *str);
int		is_num(char *str);
int		ft_isdigit(int c);

//*---------------Set Data---------------*//
int	set_data(t_all *all, int ac, char **av);

#endif
