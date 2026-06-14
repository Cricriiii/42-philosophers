/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_th_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:32:48 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/18 14:49:54 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

static void	destroy_thread(t_thread thread)
{
	if (thread)
	{
		if (thread->fork_cur)
		{
			pthread_mutex_destroy(&thread->fork_cur->mutex);
			pthread_mutex_destroy(&thread->fork_cur->state_lock);
			free(thread->fork_cur);
		}
		pthread_mutex_destroy(&thread->id_mutex);
		pthread_mutex_destroy(&thread->dead_mutex);
		pthread_mutex_destroy(&thread->meal_total_mutex);
		free(thread);
	}
}

static void	destroy_monitor(t_monitor philo)
{
	pthread_mutex_destroy(&philo->start_mutex);
	pthread_mutex_destroy(&philo->stop_mutex);
	pthread_mutex_destroy(&philo->print_mutex);
	free(philo->monitor);
}

void	philo_th_destroy(t_monitor philo)
{
	int	n;

	if (philo)
	{
		if (philo->scenario)
		{
			n = philo->scenario->philosophers - 1;
			if (philo->threads)
			{
				while (n >= 0)
					destroy_thread(philo->threads[n--]);
				free(philo->threads);
			}
			free(philo->scenario);
		}
		if (philo->monitor)
			destroy_monitor(philo);
		free(philo);
	}
}
