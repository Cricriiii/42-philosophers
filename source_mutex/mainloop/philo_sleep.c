/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:46 by fox               #+#    #+#             */
/*   Updated: 2025/10/20 11:46:33 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

int	philo_sleep(t_thread thread)
{
	int	id;

	if (check_death(thread) || check_stop(thread))
		return (DEAD);
	if (thread->display.sleep)
	{
		pthread_mutex_lock(&thread->id_mutex);
		id = thread->id;
		pthread_mutex_unlock(&thread->id_mutex);
		pthread_mutex_lock(&(*(thread->print_mutex)));
		printf("%-10ld %-3d is sleeping\n", \
									timenow(NULL) - thread->time_offset, id);
		pthread_mutex_unlock(&(*(thread->print_mutex)));
		thread->display.sleep = 0;
		thread->display.think = 1;
	}
	sleep_split(thread, thread->scenario->time_to_sleep);
	return (ALIVE);
}
