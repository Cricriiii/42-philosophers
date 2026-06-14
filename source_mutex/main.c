/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:03:43 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 15:35:24 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

int	main(int argc, char **argv)
{
	t_monitor	philo;

	exit_at_input(argc, argv + 1, philo_th_kill);
	philo = philo_th_init(argv);
	if (philo)
		mainloop_th_start(philo);
	philo_th_destroy(philo);
	return (EXIT_SUCCESS);
}
