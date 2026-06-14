/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:46 by fox               #+#    #+#             */
/*   Updated: 2025/10/20 11:40:03 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	philo_sleep(struct s_process *proc)
{
	check_death(proc);
	if (proc->display.sleep)
	{
		sem_wait(proc->sem_print);
		printf("%-10ld %-3d is sleeping\n", \
								timenow(NULL) - proc->time_offset, proc->id);
		sem_post(proc->sem_print);
		proc->display.sleep = 0;
		proc->display.think = 1;
	}
	sleep_split(proc, proc->scenario.time_to_sleep);
}
