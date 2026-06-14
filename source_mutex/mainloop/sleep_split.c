/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:04:35 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/18 14:49:25 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_th.h"

void	sleep_split(t_thread thread, long sleep_time)
{
	long	split_value;
	long	start;

	split_value = 1000;
	start = timenow(NULL);
	while (timenow(NULL) - start < sleep_time / 1000)
	{
		usleep(split_value);
		if (check_death(thread))
			break ;
	}
}
