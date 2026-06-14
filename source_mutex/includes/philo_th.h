/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_th.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:45:59 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 13:13:30 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TH_H
# define PHILO_TH_H

# include "philo.h"

# define ODD_OFFSET 0.9f

/*************************************************************
*					INIT / DESTROY							 *
**************************************************************/

t_monitor	philo_th_init(char **argv);
void		threads_init(t_monitor philo);
void		fork_init(t_monitor philo, int thread_n);

void		philo_th_destroy(t_monitor philo);

/*************************************************************
*					MAINLOOP								 *
**************************************************************/

void		mainloop_th_start(t_monitor philo);
void		*monitor_mainloop(t_monitor philo);
void		*thread_mainloop(t_thread thread);
void		set_forks(t_thread thread, t_mutex *fork_1, t_mutex *fork_2);

int			philo_eat(t_thread thread, t_mutex *fork_1, t_mutex *fork_2);
int			philo_sleep(t_thread thread);
int			philo_think(t_thread thread);
int			check_stop(t_thread thread);
int			check_death(t_thread thread);

void		sleep_split(t_thread thread, long sleep_time);

/*************************************************************
*					PTHREAD_H								 *
**************************************************************/

int			ft_pthread_mutex_spinlock(t_mutex mutex);
int			ft_pthread_mutex_unlock(t_mutex mutex);

/*************************************************************
*					ERRORS									 *
**************************************************************/

void		philo_th_kill(t_monitor philo, int error, char *msg);

#endif