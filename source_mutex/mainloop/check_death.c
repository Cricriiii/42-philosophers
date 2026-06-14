/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:28:00 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:55:55 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

int	check_death(t_thread thread)
{
	long	tn;

	tn = timenow(NULL) - thread->time_offset;
	if (tn - thread->last_meal > thread->scenario->time_to_die / 1000)
	{
		pthread_mutex_lock(&thread->dead_mutex);
		thread->dead = 1;
		pthread_mutex_unlock(&thread->dead_mutex);
		return (1);
	}
	else
		return (0);
}
