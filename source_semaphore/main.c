/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:42:09 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 14:01:28 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

int	main(int argc, char **argv)
{
	t_monitor	philo;

	exit_at_input(argc, argv + 1, philo_sem_kill);
	philo = philo_sem_init(argv);
	if (philo)
	{
		mainloop_sem_start(philo);
		mainloop_sem_stop(philo);
		wait_processes(philo);
	}
	philo_sem_destroy(philo);
	return (EXIT_SUCCESS);
}
