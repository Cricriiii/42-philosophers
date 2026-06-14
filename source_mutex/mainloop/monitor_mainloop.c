/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_mainloop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:22:47 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/18 14:47:50 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

static void	init_loop(t_monitor philo)
{
	pthread_mutex_lock(&philo->start_mutex);
	philo->start = 1;
	pthread_mutex_unlock(&philo->start_mutex);
	usleep(200);
	philo->time_offset = timenow(NULL);
}

static int	is_dead(t_monitor philo, t_thread thread, long tn)
{
	int	dead;
	int	id;

	pthread_mutex_lock(&thread->dead_mutex);
	dead = thread->dead;
	pthread_mutex_unlock(&thread->dead_mutex);
	if (dead)
	{
		pthread_mutex_lock(&philo->stop_mutex);
		philo->stop = 1;
		pthread_mutex_unlock(&philo->stop_mutex);
		pthread_mutex_lock(&thread->id_mutex);
		id = thread->id;
		pthread_mutex_unlock(&thread->id_mutex);
		pthread_mutex_lock(&philo->print_mutex);
		printf("%-10ld %-3d is dead\n", tn, id);
		pthread_mutex_unlock(&philo->print_mutex);
		return (DEAD);
	}
	else
		return (ALIVE);
}

static void	assess_diner_over(t_monitor philo, t_thread thread)
{
	int		meal_total;

	if (philo->scenario->meal_target >= 0)
	{
		pthread_mutex_lock(&thread->meal_total_mutex);
		meal_total = thread->meal_total;
		pthread_mutex_unlock(&thread->meal_total_mutex);
		if (meal_total < philo->scenario->meal_target)
			philo->diner_over = 0;
	}
}

static void	raise_end_flag(t_monitor philo)
{
	pthread_mutex_lock(&philo->stop_mutex);
	philo->stop = 1;
	pthread_mutex_unlock(&philo->stop_mutex);
}

void	*monitor_mainloop(t_monitor philo)
{
	int		n;
	long	tn;

	init_loop(philo);
	while (1)
	{
		n = 0;
		philo->diner_over = 1;
		tn = timenow(NULL) - philo->time_offset;
		while (n < philo->scenario->philosophers)
		{
			if (is_dead(philo, philo->threads[n], tn) == DEAD)
				return (NULL);
			assess_diner_over(philo, philo->threads[n++]);
		}
		if (philo->scenario->meal_target > 0 && philo->diner_over)
			return (raise_end_flag(philo), NULL);
		else
			usleep(100);
	}
}
