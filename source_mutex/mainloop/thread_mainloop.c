/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mainloop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:23:39 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 14:06:57 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

static void	wait_loop(t_thread thread)
{
	int	start;

	start = 0;
	while (!start)
	{
		pthread_mutex_lock(thread->start_mutex);
		start = *thread->start;
		pthread_mutex_unlock(thread->start_mutex);
		usleep(50 + 50 * thread->id % 2);
	}
	thread->time_offset = timenow(NULL);
}

void	*thread_mainloop(t_thread thread)
{
	t_mutex	fork_1;
	t_mutex	fork_2;

	fork_1 = NULL;
	fork_2 = NULL;
	set_forks(thread, &fork_1, &fork_2);
	wait_loop(thread);
	if (thread->id % 2)
		sleep_split(thread, ODD_OFFSET * thread->scenario->time_to_eat);
	while (1)
	{
		if (philo_eat(thread, &fork_1, &fork_2) == DEAD)
			return (NULL);
		if (philo_sleep(thread) == DEAD)
			return (NULL);
		if (philo_think(thread) == DEAD)
			return (NULL);
		usleep(100);
	}
}
