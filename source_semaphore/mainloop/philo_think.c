/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:47 by fox               #+#    #+#             */
/*   Updated: 2025/10/20 14:21:15 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	philo_think(struct s_process *proc)
{
	check_death(proc);
	if (proc->display.think)
	{
		sem_wait(proc->sem_print);
		printf("%-10ld %-3d is thinking\n", \
								timenow(NULL) - proc->time_offset, proc->id);
		sem_post(proc->sem_print);
		proc->display.think = 0;
		proc->display.sleep = 1;
		usleep(1000);
	}
}
