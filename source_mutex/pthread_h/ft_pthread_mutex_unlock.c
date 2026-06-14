/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_mutex_unlock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:53:39 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:55:55 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

int	ft_pthread_mutex_unlock(t_mutex mutex)
{
	pthread_mutex_lock(&mutex->state_lock);
	if (mutex->state)
	{
		mutex->state = 0;
		pthread_mutex_unlock(&mutex->mutex);
	}
	return (pthread_mutex_unlock(&mutex->state_lock));
}
