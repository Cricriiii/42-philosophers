/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:49:39 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 12:01:16 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

static void	assign_global_parameters(t_monitor philo)
{
	int			n;
	int			philosophers;
	t_thread	thread;

	philosophers = philo->scenario->philosophers;
	n = 1;
	while (n <= philosophers)
	{
		thread = philo->threads[n - 1];
		if (n == 1)
			thread->fork_prev = philo->threads[philosophers - 1]->fork_cur;
		else
			thread->fork_prev = philo->threads[n - 2]->fork_cur;
		thread->scenario = philo->scenario;
		thread->start = &philo->start;
		thread->start_mutex = &philo->start_mutex;
		thread->stop = &philo->stop;
		thread->stop_mutex = &philo->stop_mutex;
		thread->print_mutex = &philo->print_mutex;
		thread->display.think = 1;
		thread->odd_total = philo->scenario->philosophers % 2;
		n++;
	}
}

void	threads_init(t_monitor philo)
{
	int	n;
	int	philosophers;

	philosophers = philo->scenario->philosophers;
	philo->threads = ft_calloc(philosophers, sizeof(pthread_t));
	if (philo->threads)
	{
		n = 0;
		while (++n <= philosophers)
		{
			philo->threads[n - 1] = ft_calloc(1, sizeof(struct s_thread));
			if (philo->threads[n - 1])
			{
				philo->threads[n - 1]->id = n;
				fork_init(philo, n);
			}
			else
				philo_th_kill(philo, EXIT_FAILURE, "Error at init. Exit...\n");
		}
		assign_global_parameters(philo);
	}
}
