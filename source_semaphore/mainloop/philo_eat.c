/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:48 by fox               #+#    #+#             */
/*   Updated: 2025/10/19 11:06:22 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

static void	post_meal(struct s_process *proc)
{
	int		meal_target;

	meal_target = proc->scenario.meal_target;
	if (++proc->meal_total <= meal_target)
		sem_post(proc->sem_total_meals);
}

static void	join_table(struct s_process *proc)
{
	check_death(proc);
	sem_wait(proc->sem_tbl_seat);
	check_death(proc);
	sem_wait(proc->sem_forks);
	check_death(proc);
	sem_wait(proc->sem_forks);
}

static void	leave_table(struct s_process *proc)
{
	sem_post(proc->sem_forks);
	sem_post(proc->sem_forks);
	sem_post(proc->sem_tbl_seat);
}

static void	_philo_eat(struct s_process *proc)
{
	long	tn;

	sem_wait(proc->sem_print);
	tn = timenow(NULL) - proc->time_offset;
	printf("%-10ld %-3d has taken a fork\n", tn, proc->id);
	printf("%-10ld %-3d has taken a fork\n", tn, proc->id);
	printf("%-10ld %-3d is eating\n", tn, proc->id);
	sem_post(proc->sem_print);
	proc->display.think = 1;
	proc->last_meal = tn;
	sleep_split(proc, proc->scenario.time_to_eat);
}

void	philo_eat(struct s_process *proc)
{
	join_table(proc);
	_philo_eat(proc);
	leave_table(proc);
	post_meal(proc);
}
