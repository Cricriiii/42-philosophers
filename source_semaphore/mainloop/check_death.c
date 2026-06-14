/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:46 by fox               #+#    #+#             */
/*   Updated: 2025/10/19 21:31:27 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

static void	print_dead(struct s_process *proc, long death_time)
{
	sem_wait(proc->sem_print);
	printf("%-10ld %-3d is dead\n", death_time, proc->id);
}

void	check_death(struct s_process *proc)
{
	long	tn;

	tn = timenow(NULL) - proc->time_offset;
	if (tn - proc->last_meal > proc->scenario.time_to_die / 1000)
	{
		print_dead(proc, tn);
		exit(EXIT_DEAD);
	}
}
