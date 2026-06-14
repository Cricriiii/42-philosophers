/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_mainloop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:15:06 by fox               #+#    #+#             */
/*   Updated: 2025/10/20 11:34:51 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

int	is_stop(t_monitor philo)
{
	int	stop_value;

	pthread_mutex_lock(&philo->stop_mutex);
	stop_value = philo->stop;
	pthread_mutex_unlock(&philo->stop_mutex);
	return (stop_value);
}

void	set_stop(t_monitor philo)
{
	pthread_mutex_lock(&philo->stop_mutex);
	philo->stop = 1;
	pthread_mutex_unlock(&philo->stop_mutex);
}

void	mainloop_monitor_diner(t_monitor philo)
{
	int		n;

	n = 0;
	while (n < philo->scenario->philosophers * philo->scenario->meal_target)
	{
		if (is_stop(philo))
			return ;
		sem_wait(philo->sem_total_meals);
		++n;
	}
	set_stop(philo);
}

void	mainloop_monitor_death(t_monitor philo)
{
	int		n;
	int		rstatus;

	rstatus = 0;
	while (1)
	{
		n = 0;
		while (n < philo->scenario->philosophers)
		{
			if (is_stop(philo))
				return ;
			waitpid(philo->pid_tbl[n++], &rstatus, WNOHANG);
			if (rstatus)
				return (set_stop(philo));
		}
		usleep(100);
	}
}
