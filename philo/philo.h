/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:01:22 by yismaail          #+#    #+#             */
/*   Updated: 2023/05/14 02:03:07 by yismaail         ###   ########.fr       */
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

typedef enum s_state
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE,
	END,
}	t_state;

typedef struct s_data
{
	
	int				nb_of_philo;
	unsigned long	time_of_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	start_time;
	int				nb_of_time_must_eat;
	int				nb_of_done_of_eat;
	pthread_mutex_t	m_print;
	int				isanyonedead;
	
}			t_data;


typedef struct s_philo
{
	t_data			*data;
	t_fork			*fork;
	t_state			state;
	pthread_t		*id_thread;
	int				id;
	int				left_f;
	int				right_f;
	unsigned long	last_time_to_eat;
	int				eat_control;
	int				end;
	
}				t_philo;

typedef struct s_fork
{
	int				id_fork;
	int				gradedby;
	pthread_mutex_t	m_fork;
}					t_fork;

typedef struct s_all
{
	t_data		*a_data;
	t_philo		*a_philo;
	t_fork		*a_fork;
	pthread_t	*m_th_id;
};


//*---------------Tools---------------*//
void	ft_exit(void);
int		input_is_valid(int ac, char **av);
int	ft_atoi(const char *str);
int		is_num(char *str);
int	ft_isdigit(int c);

#endif
