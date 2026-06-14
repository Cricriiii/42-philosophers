/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structures.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:27:37 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/10 17:24:02 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTURES_H
# define PHILO_STRUCTURES_H

# include "philo.h"

struct s_scenario
{
	int		philosophers;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	meal_target;
};

struct s_display
{
	int	sleep;
	int	think;
};

struct s_monitor
{
	int					stop;
	pthread_mutex_t		stop_mutex;

	pthread_t			*monitor;

	t_scenario			scenario;

	int					init_fail;

	int					start;
	long				time_offset;

	t_thread			*threads;

	pthread_mutex_t		start_mutex;

	pthread_mutex_t		print_mutex;

	int					diner_over;

	unsigned int		cur_id;

	pid_t				*pid_tbl;
	pthread_t			sem_monitor_diner;
	pthread_t			sem_monitor_death;

	sem_t				*sem_total_meals;

	sem_t				*sem_print;
	sem_t				*sem_tbl_seat;
	sem_t				*sem_forks;
};

struct s_thread
{
	pthread_t			th;

	unsigned int		id;
	pthread_mutex_t		id_mutex;

	int					dead;
	pthread_mutex_t		dead_mutex;

	int					*start;
	pthread_mutex_t		*start_mutex;

	int					*stop;
	pthread_mutex_t		*stop_mutex;

	t_scenario			scenario;
	long				time_offset;

	t_mutex				fork_cur;
	t_mutex				fork_prev;

	long				last_meal;

	int					meal_total;
	pthread_mutex_t		meal_total_mutex;

	struct s_display	display;

	pthread_mutex_t		*print_mutex;

	int					odd_total;
};

struct s_mutex
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	state_lock;
	int				state;
};

struct s_process
{
	unsigned int		id;

	struct s_scenario	scenario;

	struct s_display	display;
	long				time_offset;

	long				last_meal;	
	int					meal_total;

	sem_t				*sem_total_meals;

	sem_t				*sem_print;
	sem_t				*sem_tbl_seat;
	sem_t				*sem_forks;	
};

#endif
