/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:45:59 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 13:56:46 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_SEM_H
# define PHILO_SEM_H

# include "philo.h"

# define EXIT_DEAD	2

# define SEM_TOTAL_MEALS	"/sem_total_meals"
# define SEM_PRINT			"/sem_print"
# define SEM_TBL_SEATS		"/sem_tbl_seats"
# define SEM_FORKS			"/sem_forks"

/*************************************************************
*					INIT / DESTROY							 *
**************************************************************/

t_monitor	philo_sem_init(char **argv);
void		philo_sem_destroy(t_monitor philo);
void		kill_processes(t_monitor philo);

void		semaphores_close(t_monitor philo, struct s_process *proc);
void		semaphores_unlink(void);
void		wait_processes(t_monitor philo);

/*************************************************************
*					MAINLOOP								 *
**************************************************************/

void		mainloop_sem_start(t_monitor philo);
void		mainloop_sem_stop(t_monitor philo);

void		monitor_mainloop(t_monitor philo);
void		process_mainloop(t_monitor philo);

void		mainloop_monitor_death(t_monitor philo);
void		mainloop_monitor_diner(t_monitor philo);

void		philo_eat(struct s_process *proc);
void		philo_sleep(struct s_process *proc);
void		philo_think(struct s_process *proc);

void		check_death(struct s_process *proc);
void		sleep_split(struct s_process *proc, long sleep_time);

/*************************************************************
*					ERRORS									 *
**************************************************************/

void		philo_sem_kill(t_monitor philo, int error, char *msg);

#endif
