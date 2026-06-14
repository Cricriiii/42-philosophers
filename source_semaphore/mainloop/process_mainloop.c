/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mainloop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:15:31 by fox               #+#    #+#             */
/*   Updated: 2025/10/20 12:15:55 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

static void	copy_semaphores(t_monitor philo, struct s_process *proc)
{
	proc->sem_total_meals = philo->sem_total_meals;
	proc->sem_print = philo->sem_print;
	proc->sem_tbl_seat = philo->sem_tbl_seat;
	proc->sem_forks = philo->sem_forks;
}

static void	copy_scenario(t_monitor philo, struct s_process *proc)
{
	proc->scenario.philosophers = philo->scenario->philosophers;
	proc->scenario.time_to_die = philo->scenario->time_to_die;
	proc->scenario.time_to_eat = philo->scenario->time_to_eat;
	proc->scenario.time_to_sleep = philo->scenario->time_to_sleep;
	proc->scenario.meal_target = philo->scenario->meal_target;
}

static void	s_process_init(t_monitor philo, struct s_process *proc)
{
	memset(proc, 0, sizeof(struct s_process));
	copy_scenario(philo, proc);
	copy_semaphores(philo, proc);
	proc->id = philo->cur_id + 1;
	philo_sem_destroy(philo);
	proc->display.think = 1;
	proc->time_offset = timenow(NULL);
}

void	process_mainloop(t_monitor philo)
{
	struct s_process	proc;

	s_process_init(philo, &proc);
	while (1)
	{
		philo_eat(&proc);
		philo_sleep(&proc);
		philo_think(&proc);
	}
}
