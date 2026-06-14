/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:47 by fox               #+#    #+#             */
/*   Updated: 2025/10/20 14:29:07 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

int	philo_think(t_thread thread)
{
	int			id;
	long		extra_sleep;
	t_scenario	scene;

	if (check_death(thread) || check_stop(thread))
		return (DEAD);
	if (thread->display.think)
	{
		pthread_mutex_lock(&thread->id_mutex);
		id = thread->id;
		pthread_mutex_unlock(&thread->id_mutex);
		pthread_mutex_lock(&(*(thread->print_mutex)));
		printf("%-10ld %-3d is thinking\n", \
									timenow(NULL) - thread->time_offset, id);
		pthread_mutex_unlock(&(*(thread->print_mutex)));
		thread->display.think = 0;
	}
	scene = thread->scenario;
	if (thread->odd_total)
		extra_sleep = 2 * (scene->time_to_eat - scene->time_to_sleep) + 2000;
	else
		extra_sleep = scene->time_to_eat - scene->time_to_sleep + 2000;
	if (extra_sleep >= 0)
		sleep_split(thread, extra_sleep);
	return (ALIVE);
}
