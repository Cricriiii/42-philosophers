/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:27:47 by fox               #+#    #+#             */
/*   Updated: 2025/10/19 21:34:19 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	semaphores_close(t_monitor philo, struct s_process *proc)
{
	if (philo)
	{
		if (philo->sem_forks)
			sem_close(philo->sem_forks);
		if (philo->sem_print)
			sem_close(philo->sem_print);
		if (philo->sem_tbl_seat)
			sem_close(philo->sem_tbl_seat);
		if (philo->sem_total_meals)
			sem_close(philo->sem_total_meals);
	}
	else if (proc)
	{
		if (proc->sem_forks)
			sem_close(proc->sem_forks);
		if (proc->sem_print)
			sem_close(proc->sem_print);
		if (proc->sem_tbl_seat)
			sem_close(proc->sem_tbl_seat);
		if (proc->sem_total_meals)
			sem_close(proc->sem_total_meals);
	}
}
