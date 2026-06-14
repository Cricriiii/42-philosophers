/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:28:17 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:55:55 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

int	check_stop(t_thread thread)
{
	int	stop;

	pthread_mutex_lock(&(*(thread->stop_mutex)));
	stop = *(thread->stop);
	pthread_mutex_unlock(&(*(thread->stop_mutex)));
	return (stop);
}
