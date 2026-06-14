/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sem_kill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:46:31 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/19 19:39:01 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

void	philo_sem_kill(t_monitor philo, int error, char *msg)
{
	if (error)
		ft_puterr(msg);
	if (philo && philo->sem_tbl_seat)
		philo_sem_destroy(philo);
	exit(EXIT_FAILURE);
}
