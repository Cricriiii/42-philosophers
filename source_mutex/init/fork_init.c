/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:12:53 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:55:09 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

void	fork_init(t_monitor philo, int thread_n)
{
	t_thread	thread;

	thread = philo->threads[thread_n - 1];
	thread->fork_cur = ft_calloc(1, sizeof(struct s_mutex));
	if (thread->fork_cur)
	{
		if (pthread_mutex_init(&thread->fork_cur->mutex, NULL))
			philo_th_kill(philo, EXIT_FAILURE, "Error at init. Exit now...\n");
		if (pthread_mutex_init(&thread->fork_cur->state_lock, NULL))
			philo_th_kill(philo, EXIT_FAILURE, "Error at init. Exit now...\n");
	}
	else
		philo_th_kill(philo, EXIT_FAILURE, "Error at init. Exit now...\n");
}
