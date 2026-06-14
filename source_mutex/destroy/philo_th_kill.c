/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_th_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:46:31 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:54:52 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

void	philo_th_kill(t_monitor philo, int error, char *msg)
{
	if (error)
		ft_puterr(msg);
	philo_th_destroy(philo);
	exit(EXIT_FAILURE);
}
