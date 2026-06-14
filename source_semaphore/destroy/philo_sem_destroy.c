/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sem_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:32:48 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 13:55:28 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	philo_sem_destroy(t_monitor philo)
{
	if (philo)
	{
		if (philo->pid_tbl)
			free(philo->pid_tbl);
		if (philo->scenario)
			free(philo->scenario);
		if (philo->monitor)
			free(philo->monitor);
		free(philo);
	}
}
