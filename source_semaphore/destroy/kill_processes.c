/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:04:35 by fox               #+#    #+#             */
/*   Updated: 2025/10/19 21:04:49 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	kill_processes(t_monitor philo)
{
	int		n;

	n = 0;
	while (n < philo->scenario->philosophers)
	{
		kill(philo->pid_tbl[n], SIGTERM);
		n++;
	}
}
