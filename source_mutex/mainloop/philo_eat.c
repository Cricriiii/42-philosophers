/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:48 by fox               #+#    #+#             */
/*   Updated: 2025/10/13 10:55:55 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

static void	update_eat_values(t_thread thread, int *ate)
{
	thread->display.sleep = 1;
	if (thread->scenario->meal_target > 0)
	{
		pthread_mutex_lock(&thread->meal_total_mutex);
		thread->meal_total++;
		pthread_mutex_unlock(&thread->meal_total_mutex);
	}
	*ate = 1;
}

static void	eat(t_thread thread)
{
	long	tn;
	int		id;

	tn = timenow(NULL) - thread->time_offset;
	thread->last_meal = tn;
	pthread_mutex_lock(&thread->id_mutex);
	id = thread->id;
	pthread_mutex_unlock(&thread->id_mutex);
	pthread_mutex_lock(&(*(thread->print_mutex)));
	printf("%-10ld %-3d has taken a fork\n", tn, id);
	printf("%-10ld %-3d has taken a fork\n", tn, id);
	printf("%-10ld %-3d is eating\n", tn, id);
	pthread_mutex_unlock(&(*(thread->print_mutex)));
	sleep_split(thread, thread->scenario->time_to_eat);
}

int	philo_eat(t_thread thread, t_mutex *fork_1, t_mutex *fork_2)
{
	int		ate;
	int		stop;

	ate = 0;
	while (!ate)
	{
		if (check_death(thread) || check_stop(thread))
			return (DEAD);
		if (!ft_pthread_mutex_spinlock(*fork_1))
		{
			if (!ft_pthread_mutex_spinlock(*fork_2))
			{
				pthread_mutex_lock(&(*(thread->stop_mutex)));
				stop = *thread->stop;
				pthread_mutex_unlock(&(*(thread->stop_mutex)));
				if (!stop)
					eat(thread);
				ft_pthread_mutex_unlock(*fork_2);
				update_eat_values(thread, &ate);
			}
			ft_pthread_mutex_unlock(*fork_1);
		}
		usleep(50);
	}
	return (ALIVE);
}
