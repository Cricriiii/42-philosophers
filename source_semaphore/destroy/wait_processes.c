/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:55:14 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 14:01:59 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	wait_processes(t_monitor philo)
{
	int		n;

	n = 0;
	while (n < philo->scenario->philosophers)
		waitpid(philo->pid_tbl[n++], NULL, 0);
}
