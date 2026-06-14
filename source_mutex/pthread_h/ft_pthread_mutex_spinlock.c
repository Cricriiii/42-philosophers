/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_mutex_spinlock.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:32:58 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/19 11:14:30 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

int	ft_pthread_mutex_spinlock(t_mutex mutex)
{
	pthread_mutex_lock(&mutex->state_lock);
	if (mutex->state)
	{
		pthread_mutex_unlock(&mutex->state_lock);
		return (EBUSY);
	}
	else
	{
		mutex->state = 1;
		pthread_mutex_unlock(&mutex->state_lock);
		return (pthread_mutex_lock(&mutex->mutex));
	}
}
