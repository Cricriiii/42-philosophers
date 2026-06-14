/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop_sem_stop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:17:01 by fox               #+#    #+#             */
/*   Updated: 2025/10/19 21:33:50 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

static void	unlock_diner_monitor(t_monitor philo)
{
	int		max_value;
	int		n;

	max_value = philo->scenario->philosophers * philo->scenario->meal_target;
	n = 0;
	while (n++ < max_value)
		sem_post(philo->sem_total_meals);
}

static void	join_monitors(t_monitor philo)
{
	pthread_join(philo->sem_monitor_death, NULL);
	if (philo->scenario->meal_target)
	{
		unlock_diner_monitor(philo);
		pthread_join(philo->sem_monitor_diner, NULL);
	}
}

void	mainloop_sem_stop(t_monitor philo)
{
	join_monitors(philo);
	kill_processes(philo);
	pthread_mutex_destroy(&philo->stop_mutex);
	semaphores_close(philo, NULL);
}
