/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop_th_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:38:48 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 16:02:32 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

void	mainloop_th_start(t_monitor philo)
{
	int			n;
	t_thread	td;
	char		*errmsg;

	n = 0;
	while (n < philo->scenario->philosophers)
	{
		td = philo->threads[n];
		if (pthread_create(&td->th, NULL, (void *) thread_mainloop, td))
		{
			errmsg = "Fatal error while creating thread. Exiting...\n";
			philo_th_kill(philo, EXIT_FAILURE, errmsg);
		}
		n++;
	}
	pthread_create(philo->monitor, NULL, (void *) monitor_mainloop, philo);
	n = 0;
	while (n < philo->scenario->philosophers)
	{
		td = philo->threads[n];
		pthread_join(td->th, NULL);
		n++;
	}
	pthread_join(*philo->monitor, NULL);
}
