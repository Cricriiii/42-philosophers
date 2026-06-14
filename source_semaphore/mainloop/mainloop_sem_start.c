/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop_sem_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:38:48 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 11:39:49 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

static int	fork_wrp(t_monitor philo)
{
	pid_t	pid;
	char	*errmsg;

	pid = fork();
	if (pid == -1)
	{
		errmsg = "Fatal error while creating processes. Exiting...\n";
		philo_sem_kill(philo, EXIT_FAILURE, errmsg);
	}
	return (pid);
}

static void	start_monitors(t_monitor philo)
{
	pthread_create(&philo->sem_monitor_death, NULL, \
										(void *) mainloop_monitor_death, philo);
	if (philo->scenario->meal_target)
		pthread_create(&philo->sem_monitor_diner, NULL, \
										(void *) mainloop_monitor_diner, philo);
}

void	mainloop_sem_start(t_monitor philo)
{
	while (philo->cur_id < (unsigned int) philo->scenario->philosophers)
	{
		philo->pid_tbl[philo->cur_id] = fork_wrp(philo);
		if (philo->pid_tbl[philo->cur_id] == 0)
		{
			process_mainloop(philo);
		}
		else
		{
			philo->cur_id++;
		}
	}
	start_monitors(philo);
}
